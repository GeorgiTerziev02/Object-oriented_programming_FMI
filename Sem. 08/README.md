# Ключова дума static. Изключения.

## Exception handling

- когато пишем код за многократно използване, е важно да обработваме грешките, които възникват
- един от най-разпространените начини за обработка на потенциални грешки е чрез връщане на специфични кодове, но не винаги има подходяща стойност, която можем да върнем 
- друг вариант е да се подава параметър по референция, но тогава функцията става неудобна за използване
- трябва непрекъснато да се проверява каква е върнатата стойност
- обработката на изключения (exception handling) предоставя механизъм за отделяне на логиката за обработване на грешки от логиката на останалия код
- `exception` - сигнал, че е възникнал някакъв проблем
- синтаксис: `throw <object>`

### Обработка на грешки
```cpp
void f() {
    throw 3;
}

int main() {
    try {
        f(); // проблемен код
        ...
    }
    catch (int n) {
        ... // обработване на хвърлен int
    }
    catch (const A& a) {
        ... // задължително по референция
        // обработване на хвърлена инстанция на клас A
    }
    catch (...) {

    }
}
```
- в `try` блока се намира проблемният код
- ако се хвърли грешка, останалата част от try блока не се изпълнява
- в `catch` блоковете грешката се обработва
- може да има няколко catch блока, влизаме в този, който приема като параметър обекта, който е хвърлен (ако се хване грешката, проверката надолу спира)
- `catch (...)` хваща всичко, ако до момента не е хванато - слага се накрая

### Stack unwinding
- при хвърляне на грешка изпълнението на функцията се прекратява
- програмата проверява дали текущата функция или някоя от извикващите функции нагоре по стека може да се справи с изключението (има try-catch блок)
- ако бъде намерен съответстващ блок за обработка на изключение, изпълнението се прескача от момента, в който е хвърлено изключението, до началото на съответстващия блок за обработка
- това изисква **stack unwinding** (премахване на текущата функция от стека на повикванията) толкова пъти, колкото е необходимо, за да може функцията, обработваща изключението, да бъде най-горе в call stack-а
- когато текущата функция се премахне от call stack-а, всички успешно създадени локални променливи се унищожават както обикновено, но не се връща стойност

```cpp
void g() {
    X x;
    throw 3;
}

void f() {
    A obj1;
    B obj2;
    g();
    C obj3;
}

int main() {
    try {
        f(); // ~X() ~B() ~A()
    }
    catch (int n) {

    }
    catch (...) {

    }    
}
```
- ако не може да бъде намерен блок за обработка на изключение за дадена функция, се извиква `std::terminate()` и програмата се прекратява
- call stack-ът може да бъде или да не бъде разгънат, т.е. локалните променливи може да **не бъдат унищожени**

### Exceptions vs. assert
- assert - системни/наши грешки
- assert(bool) - ако е true, ще спре програмата
- в release build се пропуска
- exception - идеята е да сигнализираме на външния свят, че нещо се е случило некоректно

### Видове грешки
![](https://flylib.com/books/2/253/1/html/2/images/16fig11.jpg)
- `std::bad_alloc` - грешка при заделяне на памет
- `std::bad_cast` - грешка при кастване
- `std::runtime_error` - грешка по време на изпълнение
- `std::logic_error` - грешка, която нарушава инвариантите на класа (условията, които трябва да са изпълнени) и може да бъде предотвратена
- когато подреждаме catch блоковете, класовете по-нагоре в йерархията трябва да са по-надолу, защото са по-общи и хващат повече видове грешки

```cpp

void f(int n) {
    if (n < 0) {
        throw std::invalid_argument("Number should be positive!");
    }
}

int main() {
    try {
        f();
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl; // съобщението на грешката
    }
    catch (std::logic_error& e) {

    }
    catch (std::exception& e) {

    }    
}
```
### Частни случаи
- трябва да се внимава при хвърлянето на изключения в контрукторите - при хвърляне на изключение се изчиства паметта само за успешно създадените обекти
- тоест ако сме заделили някаква памет с new и се хвърли грешка в constructor трябва да си я изтрием!

```cpp
class X {
    A a;
    B b;
    char* first_name;
    char* last_name;

public:
    X(...) : a(...), b(...) {
        first_name = new char[...]; // if it doesn't allocate => doesn't matter
        strcpy(...);
        try {
            last_name = new char[...]; // if it fails to allocate => we have to delete first_name
            strcpy(...);
        }
        catch(std::std::bad_alloc& ex) {
            delete[] first_name;
        }
    }
}


```
- ако в `last_name = new char[...];` се хвърли `bad_alloc`ще се извикат деструкторите на `a` и `b`, но не и на `x`, тъй като не е успешно създаден, fist_name няма да се изтрие и ще има отечка на памет
- При stack unwinding се унищожават обектите от всяка стек рамка, което води до извикване на деструктури. В случай, че дадедн деструктор хвърли грешка по време на stack unwiding(който stack unwiding се случва понеже вече е хвърлена грешка), то ще се появи второ изключение.

- в деструкторите НИКОГА НЕ хвърляме грешки - може да се поддържа само едно изключение едновременно и ако се хвърли ново, се вика `std::terminate()` и програмата се прекратява
- От C++ 11 - Деструкторът винаги е noexcept - тоест хвърляне на грешка в деструктор ще доведе до извикване на `std::terminate` и програмата се прекратява


### [Exception guarantees](https://en.cppreference.com/w/cpp/language/exceptions#Exception_safety)
Когато се хвърли грешка е добре да знаем какво се е случило със състоянието на програмата(или обекта хвърлил грешката). Има 4 добре познати Exception guarantees, които се използват за индикация какво ще стане със състоянието при грешка. (Или по друг начин казано какво е станало с обекта, след като е хвърлил грешка от член функция).

- Nothrow (nofail) guarantee - функцията никога няма да хвърли грешка
- Strong exception guarantee - ако функция хвърли грешка, състоянието на програмата ще е същото, както преди да се извика функцията.
- Basic exception guarantee - възможно е да се хвърли изключение и обектът ще може да се ползва (тоест е във валидно за използване състояние), но не се гарантира, че ще бъде в същото състояние, в което е било преди извикване на функцията
- No exception guarantee - няма гаранция за нищо

## Static
### Static локални променливи 
- държи се в паметта на глобалните/статичните променливи
- променяме продължителността на локалната променлива от automatic (т.е. до края на scope-а) на static (променливата се създава в началото на програмата и се унищожава в края на програмата, точно като глобалните променливи) 
- инициализира се само веднъж - при първото влизане в съответния scope и запазва стойността си дори след като излезе от scope-а

```cpp
int increment() {
    int value = 0;
    ++value;
    return value;
}

int main() {
    std::cout << increment() << std::endl; //1
    std::cout << increment() << std::endl; //2
    std::cout << increment() << std::endl; //3
}
```

### Static функции
- обвързва се с една компилационна единица и не може да се използва от други файлове
- тоест не можем да използваме тази функция в друг .cpp файл
- пример [тук](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2008/Examples/Static%20function)

### Static член-данна на клас
- не е обвързана с конкретен обект, а с целия клас
- всички обекти от класа използват една и съща инстанция
- инициализира се извън класа

### Static член-функция на клас
- не е обвързана с конкретен обект, а с целия клас
- използва се за достъпване на статичните член-данни
- няма указател **this**
- не е нужен обект, за да се достъпи

```cpp
class Test {
private:
    static int x; 
public:
    static void f() { 
        x *= 2; // може да достъпва само статичните член-данни
    }
};

int Test::x = 0; // трябва да я инициализираме извън класа

int main() {
    Test::f(); // не ни трябва обект
}
```

За да бъде по-прегледно и очевидно, когато ползваме static член-данни или static член-функции на един клас, винаги ще ги достъпваме чрез името на класа. 



 ## Задачи
**Задача 1 (ImmutableString)**: Напишете клас за стринг, който не може да се променя. При създаването на 2 еднакви стринга, те да споделят една и съща памет.

**Задача 2 (Exception handling task)**: Напишете програма, която по подаден път до папка, сканира тази папка на всеки 10 минути за файл с име **inputFlights.txt**.
inputFlights има произволен брой редове, всеки от които е в следния формат: ```<origin> <dest> <priceInEuro>```.
```
sof bER 43
mUN Lon 123
aTH sCH 3
```
**origin** и **destination** са стрингове само от латински букви с дължина 3, а priceInEuro е цяло число. Данните от всеки ред трябва да се конкатенират във файл outputFlights като двата стринга са същите, но всички малки букви са заместени с главни, а цената да е в лева (по курс 1.95). 

```
SOF BER 83.85
MUN LON 239.85
ATH SCH 5.85
```
Напишете всяка функция за възможно най-общо предназначение и имплменетирайте приложението, така че да бъде **коректно от към обработка на изключения**.
