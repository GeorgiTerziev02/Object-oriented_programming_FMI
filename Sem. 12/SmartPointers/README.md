credits: [darimachine](https://github.com/darimachine)

#  Умни указатели в C++

Умен указател е обвиващ клас за обикновен указател, който **менажира автоматично паметта** на обекта, към който сочи.

**Цел:** Да не използваме директно `new` и `delete`, с цел да не пропуснем да изтрием даден ресурс.

При създаване с `new`, умният указател поема собствеността над обекта. При изтриване — автоматично извиква деструктора му.

---

## 1.  `auto_ptr` – deprecated (остарял)

> Не се използва в modern C++, запазен само за поддръжка на стар код.

### Пример:
```cpp
#include <memory>
auto_ptr<A> ptr(new A());
```
## 2.  `unique_ptr` – точно един указател за точно един ресурс

`unique_ptr` гарантира, че **само един указател притежава даден ресурс**.  
Не позволява копиране – само **прехвърляне на собственост** чрез `std::move`.

---

###  Основни характеристики

- Автоматично освобождава ресурс при излизане от обхват
- **Няма копиране** (`copy constructor` и `operator=` са изтрити)
- Има **move семантика**
- Идеален за случаите, когато ресурс се използва **само на едно място**

---

![Unique_Ptr](Unique_Ptr.png)

### Синтаксис с `make_unique`

```cpp
#include <iostream>
class A {
public:
    A(int a, bool b) { /*...*/ }
    ~A() { /*...*/ }
};

int main() {
    std::unique_ptr<A> up = std::make_unique<A>(2, true);
    // автоматично извиква конструктора A(2, true)
} // При изход от main() се извиква ~A()
```
```c++
make_unique<T>(....) - се използва вместо new
```

###  Защо да използваме `make_unique` вместо `new`?
 - Избягва memory leak при изключения
```c++
std::unique_ptr<A> up(new A(2, true));
// ако между new и инициализация възникне изключение — паметта не се освобождава
```

`make_unique<A>(...)` прави всичко в една стъпка, така че ако нещо се обърка — няма теч на памет.

- Функцията `make_unique<T>(параметри за констуктора)` - шаблонна функция, която приема параметрите, нужни за създаването на `T`, извика вътрешно `new` и връща unique_ptr към обекта.
  
- Забранени са `Копиращ Конструктор` и `оп=`, защото искаме да е един, трябва да има move семантика
##### Забранено копиране

```cpp
std::unique_ptr<A> up1 = std::make_unique<A>(2, true);
std::unique_ptr<A> up2 = up1;              // ❌ Грешка: забранено копиране
std::unique_ptr<A> up3 = std::move(up1);   // ✅ Прехвърляне на собственост
```
  
- Ще се счупи, ако към към предварително създаден обект насочиме два `unique_ptr`. Нито един от тях не подозира за съществуването на другия тоест при изтриването на единия паметта ще се изтрие и деструкторът на втория ще гръмне.
##### Два `unique_ptr` към един и същи обект

```c++
#include <iostream>
using namespace std;
class A {
};
int main()
{
    A* a = new A();
    unique_ptr<A> up1(a);
    unique_ptr<A> up2(a);
} -> ще гръмне, защото се опитва да изтрие празни данни(вече е бил изтрит от up2 и up1 гърми).
```

#####  Грешен пример с `make_unique`

```c++
class A{

}
int main() {
    A* a = new A();
    unique_ptr<A> up1=make_unique<A>(а); // Това ще даде грешка защото търси конструктор A(A*)
    unique_ptr<A> up2=make_unique<A>(а); // съшото
} 
```
`make_unique<A>(a)` се опитва да извика конструктор `A(A*)`, който не съществува → компилационна грешка.

---

## 3. `shared_ptr` – 1 обект, но много указатели (споделена собственост)

деф: Клас, който пази указател към обект и брояч колко указатели са насочени към обекта.

`shared_ptr` е умен указател, който позволява **много указатели към един и същ обект**.  
Всеки `shared_ptr` увеличава вътрешния **референтен брояч**, и когато той достигне 0 – обектът се изтрива.

---

###  Основни характеристики

- Обектът се създава при първия `shared_ptr`
- Новите `shared_ptr` копират (shallow) оригинала и увеличават брояча
- Обектът се изтрива, когато последният `shared_ptr` изчезне (когато брояча стане 0)

---
### Синтаксис - Пример

```cpp
#include <iostream>
#include <memory>

class A {
public:
    A(int x, int y) { std::cout << "A(" << x << "," << y << ")
"; }
    void f() { std::cout << "A::f()
"; }
};

int main() {
    std::shared_ptr<A> sp = std::make_shared<A>(2, 3);
    std::shared_ptr<A> sp2 = sp;
    std::shared_ptr<A> sp3 = sp;

    sp2.reset();
    sp3.reset();

    sp->f(); // Вика метода, ако обектът още съществува
}
```

Реализира се с:
`ìnt* ref`

##  Как да използваме `SharedPtr`

### 1. Създавай **точно един** `SharedPtr` от суров указател  
```cpp
A* p = new A();           // 1) заделяне на обекта
SharedPtr<A> sp1(p);         // 2) създаваме контролен блок (refCount = 1)
```
### 2. Всички останали споделени указатели се правят `чрез копиране`
```c++
SharedPtr<A> sp2 = sp1;      // copy-ctor / operator= → refCount става 2
```
## ВАЖНО!!!
```c++
Никога не конструирай втори SharedPtr от същия T*!
Това ще създаде нов брояч и при освобождаване ще доведе до двойно delete.
```
#### Пример:
```c++
int* p = new int(42);

std::shared_ptr<int> s1(p);   // control-block #1, use_count = 1
std::shared_ptr<int> s2(p);   // control-block #2, use_count = 1  ← ГРЕШКА!

// при освобождаване:
// s1 -> delete p
// s2 -> delete p  (втори път)  → Undefined Behavior.
```
### 3. Животът на обекта приключва, когато броячът стигне 0
```c++
{               // вътрешен обхват
    SharedPtr<A> sp3 = sp1;  // refCount = 3
}               // sp3 излиза от обхват → refCount = 2

// … код …

// При излизане от обхвата на sp2 и sp1:
// 1) refCount → 1, после → 0
// 2) освобождава се обектът и самият брояч

```
### 4. Типични грешки

| Грешка                          | Какво става                                                  | Как да я избегнеш                          |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------ |
| `A obj; SharedPtr<A> s1(&obj);` | Управляваш **stack**-обект → `delete` на адрес от стека → UB | Заделяй само с `new`                       |
| `SharedPtr<A> s2(&*s1);`        | втори независим брояч → двойно освобождаване                 | `SharedPtr<A> s2 = s1;`                    |
| Забравен `new` без `SharedPtr`  | изтичане на памет                                            | Винаги обвивай `new` в `SharedPtr` веднага |


###  Защо да използваме `make_shared` вместо `new`?

```cpp
// Препоръчително:
std::shared_ptr<A> sp = std::make_shared<A>(2, 3);

// Остарял По-рисков начин:
std::shared_ptr<A> sp(new A(2, 3));
```

| Критерий                       | ✅ `std::make_shared`                     | ❌ `std::shared_ptr(new T(...))`         |
|-------------------------------|-------------------------------------------|-------------------------------------------|
| **Брой алокации на памет**     | 1 (обект + контролен блок заедно)        | 2 (отделни malloc-и)                      |
| **Ефективност**                | По-бързо, по-добър кеш                   | По-бавно                                  |
| **Безопасност при изключения** | Да – няма шанс за memory leak            | Не – възможен leak                        |
| **Синтаксис**                  | Кратък и ясен                            | По-дълъг и по-рисков                      |
| **Custom deleter**             | Не директно                              | Да – подава се в конструктора             |

---


#### `shared_ptr` има предефинирани оператори `*` и `->`, копиране и местене.
- Всеки `shared_ptr` увеличава вътрешния брояч
- `Триене`
  - трием указателя => намаляваме брояча
  - последния указател изтрива обекта
  - при изтриването на последния указател, трябва да се изтрие и counter-a
- Броячът НЕ е `static`, защото ще се споделя между различни обекти`shared_ptr`
![Shared_Ptr](shared_counter1.png)  

- пазим указател към външна памет, която пази бройката
![Shared_Ptr2](shared_counter2.png)


## 4.  `weak_ptr` – слаба (non-owning) връзка
`weak_ptr` е умен указател, който **не притежава обекта**, а само го наблюдава.

###  Основни характеристики

- Сочи към обект, менажиран от `shared_ptr`
- Не увеличава референтния брояч
- не влияе на триенете и може да сочи към вече изтрит обект
- `weak_ptr` трябва да има проверки дали обектът е изтрит
- Използва се за:
  - проверка дали обектът още съществува(като индикатор дали дадено нещо е живо или не.)
  - избягване на циклични зависимости

---

##### Реализация:
има брояч за броя на `shared_ptr` сочещи към обекта + брояч за броя на `weak_ptr` сочещи към обекти

**Counter** - Съдържащ 2 int числа някъде в паметта

![Weak_Ptr](Weak_Ptr.png)

![Shared_Weak2](Shared_Weak.png)

###  Пример с `weak_ptr`

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;

    if (auto locked = wp.lock()) {
        std::cout << "Обектът е жив: " << *locked << std::endl;
    } else {
        std::cout << "Обектът е изтрит
";
    }
}
```

###  Как работи вътрешно?

- Контролният блок съдържа:
  - `use_count` → брой `shared_ptr`
  - `weak_count` → брой `weak_ptr`\
    - 1, use_count>=1
    - 0, use_count=0

- `shared_ptr` отговаря за изтриването на `A`  а weak_ptr отговаря за изтриване на `Counter`
- Кога се трие обекта: `use_count = 0`
- Кога се трие брояча: `weak_count = 0`
- Контролният блок се изтрива при: `use_count == 0 && weak_count == 0`

---


![Shared_Weak1](Shared_Weak1.png)


## 5. `PolymorphicPtr<T>` – (наша 'измишльотина', няма го в stl) собствена имплементация на полиморфен указател

`PolymorphicPtr<T>` е собствена имплементация на **умен указател с полиморфно поведение**, който:

- Позволява **стойностно копиране** на обекти от базов тип (напр. `Base`) без нужда от `shared_ptr`, `unique_ptr` или `clone()` извън класа.
- **Изисква единствено обектите да поддържат метод `clone()`**, който връща копие на текущия обект (`T* clone() const`).
- Може да се използва безопасно в **хетерогенни контейнери** като `Vector<PolymorphicPtr<Base>>`.
- Замества `Base**` в **хетерогения контейнер** със `Vector<PolymorphicPtr<Base>>` и не трябва да пишем `BIG 6`

---

### 🛠️ Интерфейс и поведение

```cpp
template <class T>
class PolymorphicPtr {
    T* data = nullptr;

    void free();                        // Освобождава обекта
    void moveFrom(PolymorphicPtr&&);   // Прехвърля собственост
    void copyFrom(const PolymorphicPtr&); // Използва clone()

public:
    PolymorphicPtr() = default;
    PolymorphicPtr(T* ptr);                      // Конструктор от суров указател
    PolymorphicPtr(const PolymorphicPtr& other); // Копиращ конструктор (deep copy)
    PolymorphicPtr(PolymorphicPtr&& other);      // Move конструктор

    PolymorphicPtr& operator=(const PolymorphicPtr& other); // Копиращо присвояване
    PolymorphicPtr& operator=(PolymorphicPtr&& other);      // Move присвояване

    T* operator->();               // достъп до член-функции
    const T* operator->() const;

    T& operator*();                // достъп до обекта
    const T& operator*() const;

    T* get();
    const T* get() const;

    void reset(T* ptr);           // подмяна на обекта
    T* release();                 // освобождаване на указателя

    ~PolymorphicPtr();            // деструктор
};
```

---

### Предимства

- Позволява **стойностна семантика за обекти с виртуални методи**
- Безопасно **копиране, преместване и унищожаване**
- Работи с **хетерогенни контейнери** (`std::vector<PolymorphicPtr<Base>>`)
- Позволява използване на обекти с **виртуален интерфейс**, без `shared_ptr`, `unique_ptr`, `dynamic_cast`, и без `new` в клиентския код

---

### Пример за употреба

```cpp
struct Shape {
    virtual void draw() const = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    void draw() const override { std::cout << "Circle\n"; }
    Shape* clone() const override { return new Circle(*this); }
};

struct Square : Shape {
    void draw() const override { std::cout << "Square\n"; }
    Shape* clone() const override { return new Square(*this); }
};

int main() {
    Vector<PolymorphicPtr<Shape>> shapes; // замества Shape ** в хетерогения контейнер
    shapes.emplace_back(new Circle());
    shapes.emplace_back(new Square());

    for (const auto& s : shapes)
        s->draw();
}
```

---

### Изисквания към `T` (базовия клас)

- Трябва да има **виртуален деструктор**
- Трябва да има публичен метод:
```cpp
virtual T* clone() const = 0;
```



