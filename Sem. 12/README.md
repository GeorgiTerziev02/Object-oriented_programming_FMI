# Колекции от обекти в полиморфна йерархия. Копиране, триене, разпознаване и прихващане. Шаблони. Умни указатели.

## Колекции от обекти в полиморфна йерархия. Копиране и триене.

### Колекция.

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. <br />
Указателите трябва да са от типа на базовия клас. <br />

```c++
class Fruit {
public:
	virtual void printColor() const = 0;
	virtual ~Fruit() = default;
};

class Apple : public Fruit {
public:
	void printColor() const override {
		std::cout << "Red or green!\n ";
	}
};

class Orange : public Fruit {
public:
	void printColor() const override {
		std::cout << "Orange!\n";
	}
};

class Lemon : public Fruit {
public:
	size_t sourness;

	Lemon(size_t sourness) : sourness(sourness) {}
	
	void printColor() const override {
		std::cout << "Yellow!\n";
	}
};

class FruitStore {
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
public:
	FruitStore();
	FruitStore(const FruitStore&);
	FruitStore& operator=(const FruitStore&);
	~FruitStore();
	
	void addApple();
	void addOrange();
	void addLemon(size_t sourness);
private:          
	void copyFrom(const FruitStore& other);
	void free();
};

void FruitStore::addApple() {
	fruits[count++] = new Apple();
}

void FruitStore::addOrange() {
	fruits[count++] = new Orange();
}

void FruitStore::addLemon(size_t sourness) {
	fruits[count++] = new Lemon(sourness);
}
```

## Триене
Понеже имаме виртуален деструктор в базовия клас, не се интересуваме в колекцията какви са обектите, които трием.

```c++
void FruitStore::free() {
	for(size_t i = 0; i < count; ++i) {
		delete fruits[i];
	}
	
	delete[] fruits;
}
```

## Копиране
Искаме да реализираме копиране на колекцията. <br />
Това трябва да стане без да нарушаваме абстракцията - искаме обеките да се копират без да се налага да запитваме за техния тип. <br />
За това дефинираме виртуална функция clone, която ще връща копие на обекта. Тази функция я разписваме във всеки от наследниците. <br />

```c++
class Fruit {
public:
    virtual void printColor() const = 0;
    virtual Fruit* clone() const = 0;

    virtual ~Fruit() = default
};

class Apple : public Fruit {
public:
    void printColor() const override {
	    std::cout << "Red or green!\n";
    }

    Fruit* clone() const override {
        return new Apple(*this);
    }
};

class Orange : public Fruit {
public:
    void printColor() const override {
	    std::cout << "Orange!\n";
    }
	
    Fruit* clone() const override {
	    return new Orange(*this);
    }
};

class Lemon : public Fruit {
public:
    size_t sourness;

    Lemon(size_t sourness) : sourness(sourness) {}
	
    void printColor() const override {
	    std::cout << "Yellow!\n";
    }
	
    Fruit* clone() const override {
	    return new Lemon(*this);
    }
};
```

От тук копирането става тривиално:

```c++
void FruitStore::copyFrom(const FruitStore& other) {
	fruits = new Fruit*[other.capacity];
	
	for(size_t i = 0; i < other.count; ++i) {
		fruits[i] = other.fruits[u]->clone();
	}
		
	count = other.count;
	capacity = other.capacity;
}
```

## Разпознаване и прихващане
В даден момент ще достигнем до следната ситуация било то с фигури или друга йерархия. Нека за пример имаме следната йерархия:

Базов клас: Shape

Наследници на Shape: Circle, Rectangle, Triangle

Представете си, че имаме колекция от фигури (Shape**), в която всеки поинтър сочи към различен наследник на фигура.
Искаме да изберем две произволни фигури от колекцията и да разберем дали се пресичат. Тук се появява следният проблем, няма еднаква формула, по която да определим дали една фигура се пресича с друга. Проверката дали се пресичат зависи изцяло от това кои конкретни наследници на Figure са двете фигури. Тоест дали триъгълник се пресича със кръг е една формула, триъгълник с триъгълник е друга формула и т.н.

Всичко това води до ситуацията ние да разберем какви фигури стоят от двете страни, за да знаем коя формула да приложим.

**Вариант 1: Да нарушим абстракцията.**

Директно да разберем към какво сочи всеки Shape* с 3 if проверки и dynamic_cast. Сами можем да предположим, че това не е правилното решение.

**Вариант 2: Visitor design pattern.**
- Накратко какво е design pattern - шаблон (това не е парче код, което copy-paste и да тръгне магически), по който се решават често срещани проблеми в обектно-ориентирания свят. В нашия случай не знаем какво седи зад двата поинтъра, но искаме да изпълним действие в зависимост какво седи отзад, без да нарушаваме абстракция - Visitor design patter.
- [Visitor explained - Refactoring Guru](https://refactoring.guru/design-patterns/visitor)

В нашата ситуация искаме да постигнем

```c++
Shape* s1 = generateRandomShape(), Shape* s2 = generateRandomShape();
s1.intersectWith(s2);
```

Решение е в базовия клас да се добавят следниет функции:

```c++
virtual bool intersectsWith(const Shape* other) const = 0;

virtual bool intersectsWithTriangle(const Triangle* other) const = 0;
virtual bool intersectsWithRect(const Rectangle* other) const = 0;
virtual bool intersectsWithCircle(const Circle* other) const = 0;
```

Последните 3 са конкретните имплементации на това как нашата фигура(съответно някой от наследниците) дали се пресича с всички останали. Всяка фигура трябва да даде тяхна имплементация.

В нашият случай с s1 и s2 и от двете страни седят базови поинтъри(абстракции) и не знаем към какво сочат, а искаме да достигнем до конкретна intersectWithX функция, която да даде резултат (т.е. да свалим абстракциите от двете страни и да достигнем да конкретика и от двете страни, за да знаем коя е функцията.

На първо място на s1 и s2 извикваме intersect, понеже тя е pure virtual ние ще идем до **конкретна** имплементация в наследник. Достигайки там, ние вече ще знаем в кой клас се намираме (благодарение на this pointer).

Нека за примера приемем, че ```s1 е Circle``` и при ```s1.intersectWith(s2)``` достигаме до intersectWith на Circle
```c++
bool Circle::intersectsWith(const Shape* other) const {
	return other->intersectsWithCircle(this);
}
```

В тази функция ние знаем, че this е ```Circle* const```. Вече знаем, че s1 е кръг, но нямаме идея какво е s2 (в scope-a на функцията това е ```const Shape* other``` параметъра). Следователно извикваме функцията за сечение с кръг на s2. От там отново ще достигнем до конкретна имплементация на ```intersectsWithCircle``` на някой от наследниците, която ще държи логиката за това дали се пресича кръг със съответния наследник на Shape.
Т.е. В тази функция ще знаем и s2 кой от трите наследни е.

Извод:
При всяко извикване на virtual функция на Base* ние стигаме до **конкретна** имплементация на наследник(т.е. "разкриваме" така да кажем какво седи отзад). В нашата задача и от двете страни седеше абстракция, съответно ни трябваше извикване на две virtual функции, за да достигнем до контретиката.

Демо код (по-скоро псевдо код) за по-прости версии на Visitor [Person visiting building](./Examples/SimpleVisitor-Buildings), [File system iterator visiting a file system node](.//Examples/SimpleVisitor-FileSystem)

Демо код за ситуацията с Фигурите [тук](./Solutions/ShapeCollection)

## Шаблони
Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас
```c++
#include <iostream>
using namespace std;

template <class T>
T sum(const T& a, const T& b) {
    return a + b;
}

int main() {
    int a = 4;
    int b = 9;
    cout << sum<int>(a, b) << endl;

    double c = 3.14;
    double d = 4.5;
    cout << sum<double>(c,d) << endl;
	
    return 0;
}
```
Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

#### Темплейтна специализация
Различно поведение на темплейтния клас/функция за определени типове

```c++
#include <iostream>

template<typename T>
void print(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<> // !!!
void print(char* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ---- ";
	}
	std::cout << std::endl;
}

int main() {
	int arr1[] = { 1, 2 };
	print<int>(arr1, 2);
	char arr2[] = { 'a', 'b' };
	print<char>(arr2, 2);
}

// This is not a specialization
// void print(char* arr, size_t size) {
// 	for (size_t i = 0; i < size; i++) {
// 		std::cout << arr[i] << " ---- ";
// 	}
// 	std::cout << std::endl;
// }
```

#### Необходима функция

```c++

struct Test {
	void func() {}
}

template<typename T>
void f1(Test& t) {
	t.func();
}

template<typename T>
void f2(T& t) {
	t.func1();
}

int main() {
	Test t;
	f1<Test>(t); // ok
	f2<Test>(t); // compile error
}

```

#### Примери за шаблони в stl

- Функции
    - std::sort
    - std::swap
- Структури
    - std::vector
    - std::queue
    - std::stack
    - std::optional
    - std::pair
    - smart pointers - unique_ptr, shared_ptr, weak_ptr

## Умни указетели
Допълнителен материал за умни указетели може да откриете [тук](./SmartPointers)

## Задачи

**Задача 1:**
Релизирайте структурата от данни опашка. Опашката трябва да работи с **произволни типове**. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

**Пример**:
 ```c++
int main() {
	quene<int> q;
	q.push(3);
	q.push(5);
	q.push(10);

	cout << q.peek() << endl; //3
	q.pop();
	
	cout << q.peek() << endl; //5
	q.pop();

	cout << q.peek() << endl; //10
	q.pop();
	
	cout << q.isEmpty() << endl; //1	
}
 ```

**Задача 2:**
Релизирайте структурата от данни FixedLengthStack <br />

**Пример**:
 ```c++
int main() {
   FixedLengthStack<int, 5> st;

   for(size_t i = 0; i < 5; ++i) { // if i < 6 it should throw an error
        st.push(i);
   }

   Stack st1 = st;
   Stack st2;
   st2 = st1;
   Stack st3 = std::move(st1);

   while (!st2.empty()) {
         std::cout << st2.pop() << ' ';
   }
   std::cout << std::endl;
   return 0;
}
 ```


**Задача 3:**
 Създайте **шаблонна** опашка с k приоритета. При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет.
 
  ```c++
int main() {
	kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
	
	q.push('A',0): //adds A with lowest priority: 0
	q.push('B',3);
	q.push('C',2);
	q.push('D',2);
	q.push('E',1);
	
	//q.push('F', 5); //error! No such priority!
	
	q.peek(); // B
	q.pop();
	
	q.peek(); // C
	q.pop();
	
	q.peek(); // D
	q.pop();
	
	q.peek(); // E
	q.pop();
	
	q.peek(); // A
	q.pop();
}
 ```
