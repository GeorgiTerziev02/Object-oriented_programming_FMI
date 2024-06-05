
# Type casting

Унарен оператор(unary operator), който принуждава един тип данни да бъде преобразуван в друг тип данни.
- [static_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#static-cast)
- [dynamic_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#dynamic-cast)
- [const_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#const-cast)
- [reinterpret_cast](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/Type%20Casting#reinterpret-cast)
- [(T) - C-style cast](https://en.cppreference.com/w/cpp/language/explicit_cast)

## Static cast
- Default cast-a за implicit conversions
- Използва се за преобразуването на примитивни типове
- Може да е implicit или explicit
- Compile time

```c++
    float f = 3.5;
    int a = f; // C-style casting /implicit
    int b = static_cast<int>(f); //explicit static_cast
```

```c++
    class Base {};
    class Derived : public Base {};

    Derived d1;
    Base* b1 = (Base*)(&d1);
    Base* b2 = static_cast<Base*>(&d1);
```
Ще се комплира без проблем.
- взехме адреса на d1 и експлицитно го преобразувахме към Base.
- взехме адреса на d1 и използвахме static_cast, за да го преобразувахме към Base.

Както знаем, static_cast извършва строга проверка на типа:
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
```
	int i = 10;
	void* v = static_cast<void*>(&i);
	int* ip = static_cast<int*>(v);
```

## Dynamic cast
- използва се при полиморфизъм
- при cast-ване към Derived(наследник) клас.
- нужна е поне една виртуална функция.

| Downcasting  | Upcasting |
|  :---: |  :---: |
| Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting.| Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting.  |

### Dynamic_cast - no virtual function example:
```c++
// no virtual function used in the Base class
    #include <iostream>
    
    // Base class declaration
    class Base {
    public:
        void print() {
            std::cout << "Base\n";
        }
    };
    
    // Derived Class 1 declaration
    class Derived1 : public Base {
    public:
        void print() {
            std::cout << "Derived1\n";
        }
    };
    
    // Derived class 2 declaration
    class Derived2 : public Base {
    public:
        void print() {
            std::cout << "Derived2\n";
        }
    };
    
    int main() {
        Derived1 d1;
    
        // Base class pointer hold Derived1 class object
        Base* bp = dynamic_cast<Base*>(&d1);
    
        // Dynamic casting
        Derived1* dp1 = dynamic_cast<Derived1*>(bp);
        if (dp1 == nullptr)
            cout << "null" << endl;
        else
            cout << "not null" << endl;
    
        return 0;
    }
```

### Dynamic_cast - with virtual function example:
```c++
    // Dynamic casting and it returns a value of type: new_type
    #include <iostream>

    // Base Class declaration
    class Base {
    public:
        virtual void print() {
            std::cout << "Base\n";
        }
    };
    
    // Derived1 class declaration
    class Derived1 : public Base {
    public:
        void print() {
            std::cout << "Derived1\n";
        }
    };
    
    // Derived2 class declaration
    class Derived2 : public Base {
    public:
        void print() {
            std::cout << "Derived2\n";
        }
    };
    
    int main() {
        Derived1 d1;
    
        // Base class pointer holding Derived1 Class object
        Base* bp = dynamic_cast<Base*>(&d1);
    
        // Dynamic_casting
        Derived1* dp1 = dynamic_cast<Derived1*>(bp);
        if (dp1 == nullptr) {
            std::cout << "null\n";
        } else {
            std::cout << "not null\n";
        }
    }
```

### Dynamic_cast - if it fails - returns a nullptr
```c++
    // If the cast fails and new_type is a pointer type,
    // it returns a null pointer of that type
    #include <iostream>
    
    // Base class declaration
    class Base {
    public:
        virtual void print() {
            std::cout << "Base\n";
        }
    };
    
    // Derived1 class declaration
    class Derived1 : public Base {
    public:
        void print() {
            std::cout << "Derived1\n";
        }
    };
    
    // Derived2 class declaration
    class Derived2 : public Base {
    public:
        void print() {
            std::cout << "Derived2\n";
        }
    };
    
    int main() {
        Derived1 d1;
        Base* bp = dynamic_cast<Base*>(&d1);
    
        // Dynamic Casting
        Derived2* dp2 = dynamic_cast<Derived2*>(bp);
        if (dp2 == nullptr) {
            std::cout << "null\n";
        } else {
            std::cout << "not null\n";
        }
    
        return 0;
    }
```

### Handle cast fail - std::bad_cast
```c++
    #include <exception>
    #include <iostream>

    // Base class declaration
    class Base {
    public:
        virtual void print() {
            std::cout << "Base\n";
        }
    };
    
    // Derived1 class
    class Derived1 : public Base {
    public:
        void print() {
            std::cout << "Derived1\n";
        }
    };
    
    // Derived2 class
    class Derived2 : public Base {
    public:
        void print() {
            std::cout << "Derived2\n";
        }
    };
    
    int main() {
        Derived1 d1;
        Base* bp = dynamic_cast<Base*>(&d1);
    
        // Type casting
        Derived1* dp1 = dynamic_cast<Derived1*>(bp);
        if (dp1 == nullptr) {
            std::cout << "null\n";
        } else {
            std::cout << "not null\n";
        }
    
        // Exception handling block
        try {
            Derived2& r1 = dynamic_cast<Derived2&>(d1);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
```

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
        // constructor
        Student(int r) :roll(r) {}

        // A const function that changes roll with the help of const_cast
        void f() const {
            (const_cast<Student*>(this))->roll = 5;
        }

        int getRoll() const {
            return roll;
        }
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


