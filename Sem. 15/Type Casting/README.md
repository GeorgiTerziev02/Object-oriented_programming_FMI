
# Type casting

Унарен оператор(unary operator), който принуждава един тип данни да бъде преобразуван в друг тип данни.
- [static_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#static-cast)
- [dynamic_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#dynamic-cast)
- [const_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#const-cast)
- [reinterpret_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#reinterpret-cast)
- [(T) - C-style cast](https://en.cppreference.com/w/cpp/language/explicit_cast)

## Static cast
- Default cast-a за implicit conversions
- Използва се за преобразуването на примитивни типове и 
- Може да е implicit или explicit
- Compile time проверява типовете между които преобразува
- Опасен за използване при downcasting

```c++
float f = 3.5;
int a = f; // C-style casting /implicit
int b = static_cast<int>(f); //explicit static_cast
```

```c++
class Base {
public:
	virtual ~Base() = default;
};
class Derived1 : public Base {};
class Derived2 : public Base { public: int a; };

// some random class
class Test {};

int main() {
	Base* b = new Derived1();
	Derived2* d = static_cast<Derived2*>(b); // possible even though behind the scenes is Dervided1
	// Test* t = static_cast<Test*>(b); // compile time error
	std::cout << d->a; // undefined
}
```

Както знаем, static_cast извършва строга проверка на типа по време на компилация:
```c++
class Base {};
class Derived : private Base {}; // Inherited private/protected not public

Derived d1;
Base* b1 = (Base*)(&d1); // allowed
Base* b2 = static_cast<Base*>(&d1);
```
Дори и ако наследяваме protected, кодът няма да се компилира.(само при public, като при горния пример няма да има проблем).
```
[Error] Conversion to inaccessible base class is not allowed
```

To and from void pointer:
```c++
int i = 10;
void* v = static_cast<void*>(&i);
int* ip = static_cast<int*>(v);
```

## Dynamic cast
- използва се при полиморфизъм при cast-ване към Derived(наследник) клас.
- нужна е поне една виртуална функция.
- Проверява типовете runtime, в случай, че не може да преобразува (при upcast/downcast) - връща nullptr

| Downcasting  | Upcasting |
|  :---: |  :---: |
| Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting.| Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting.  |

Същия пример от преди малко, но вече и Derived1 има член-данна a:
```c++
#include <iostream>
class Base {
public:
	virtual ~Base() = default; // removing virtual here will result in compile time error that dynamic_cast needs a polymorphic type
};
class Derived1 : public Base { public: int a = 5; };
class Derived2 : public Base { public: int a = 5; };

// some random class
class Test {};

int main() {
	Base* b = new Derived1();

	// correct downcast
	Derived1* d1 = dynamic_cast<Derived1*>(b); // sets Derived d1 pointer
	std::cout << d1->a << std::endl; // 5

	// correct upcast
	Base* b2 = dynamic_cast<Base*>(b);

	std::cout << (b == b2) << std::endl; // 1

	// wrong downcast
	Derived2* d2 = dynamic_cast<Derived2*>(b2); // sets nullptr
	std::cout << d2->a; // error deref of nullptr

	// bad_cast example
	//try
	//{
	//	Derived2& d2 = dynamic_cast<Derived2&>(*d1);
	//}
	//catch (std::exception& e) {
	//	std::cout << e.what() << std::endl;
	//}
}
```

Ако премахнем virtual методите от базовия клас, ще получим компилационна грешка, че dynamic_cast се нуждае от полиморфен тип.

## Const cast
- използва се за добавяне/премахване на const към променлива
- добавяне/премахване на constness на променлива

Променяне на non-const members в const member function
```c++
    #include <iostream>

    class Student {
    private:
        int roll;
    public:
        Student(int r) :roll(r) {}

        // A const function that changes roll with the help of const_cast
        void f() const {
            (const_cast<Student*>(this))->roll = 5;
        }

        int getRoll() const { return roll; }
    };

    int main() {
        Student s(3);
        std::cout << "Old roll number: " << s.getRoll() << std::endl;

        s.f();
        std::cout << "New roll number: " << s.getRoll() << std::endl;
    }
```

Подаване на const data на функция, която не приема const:
```c++
    #include <iostream>

    int fun(int* ptr) {
        return (*ptr + 10);
    }

    int main() {
        const int VAL = 10;
        const int* ptr = &VAL;

        std::cout << fun(const_cast<int*>(ptr));
    }
```

Модифициране на променлива, която е първочално декларирана като const - **Undefined behaviour**
```c++
    #include <iostream>

    int fun(int* ptr) {
        *ptr = *ptr + 10;
        return (*ptr);
    }
    
    int main() {
        const int VAL = 10;
        
        const int *ptr = &VAL;
        
        fun(const_cast<int*>(ptr));
        
        std::cout << VAL;

        return 0;
    }
```

Modify a non-const:
```c++
    #include <iostream>

    int fun(int* ptr) {
        *ptr = *ptr + 10;
        return (*ptr);
    }
    
    int main() {
        int val = 10;

        const int *ptr = &val;
        
        fun(const_cast<int*>(ptr));
        
        std::cout << val;

        return 0;
    }
```

Type of cast is not the same as original object:
```
    int a1 = 40;
    const int* b1 = &a1;
    char* c1 = const_cast <char*>(b1); // compiler error
    *c1 = 'A';
```

```
[ERROR]: invalid const_cast from type 'const int*' to type 'char*'
```

## Reinterpret cast
Използва се за преобразуването на pointer oт даден тип към pointer oт друг тип, дори когато типовете несъвпадат.
Не проверява дали 2-та типа са еднакви.

- reinterpret bit patterns(битови модели)
- it can typecast any pointer to any other data type.
- It is used when we want to work with bits.

```
Е.g:
   Превръщане на поток от необработени данни в действителни данни;
   Съхраняване на данни в ниските битове на подравнен указател;
```

### Basic example:
```c++
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    std::cout << *p << std::endl; //65
    std::cout << *ch << std::endl; //A
    std::cout << p << std::endl; //0x1609c20 - address
    std::cout << ch << std::endl; //A
```

### Struct/Class example:
```c++
    #include <iostream>

    // Creating structure myStruct
    struct myStruct {
        int x;
        int y;
        char c;
        bool b;
    };

    int main() {
        myStruct s;

        // Assigning values
        s.x = 5;
        s.y = 10;
        s.c = 'a';
        s.b = true;

        // data type must be same during casting as that of original

        // converting the pointer of 's' to pointer of int type in 'p'.
        int* p = reinterpret_cast<int*>(&s);

        // printing the value currently pointed by *p
        std::cout << *p << std::endl;

        // incrementing the pointer by 1
        p++;

        // printing the next integer value
        std::cout << *p << std::endl;

        // incrementing the pointer by 1
        p++;

        // we are casting back char* pointed by p using char *ch.
        char* ch = reinterpret_cast<char*>(p);

        // printing the character value pointed by (*ch)
        std::cout << *ch << std::endl;

        // incrementing the pointer by 1
        ch++;

        //since (*ch) now points to boolean value,
        //it is required to access the value using same type conversion
        //so we have used data type of *n to be bool.

        bool* n = reinterpret_cast<bool*>(ch);
        std::cout << *n << std::endl;

        // we can also use this line of code to print the value pointed by (*ch).
        std::cout << *(reinterpret_cast<bool*>(ch));
    }
```

### Class/Inheritance example:
```c++
    #include <iostream>
    
    class A {
    public:
        void fun_a(){
            std::cout << "in class A\n";
        }
    };
    
    class B {
    public:
        void fun_b(){
            std::cout << "in class B\n";
        }
    };
    
    int main() {
        B* x = new B();
    
        A* new_a = reinterpret_cast<A*>(x);
    
        new_a->fun_a();

        return 0;
    }
```


