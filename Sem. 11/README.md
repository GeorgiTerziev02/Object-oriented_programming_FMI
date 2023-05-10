## Статично и динамично свързване.

```c++
#include <iostream>

struct A
{ 
    void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : A
{
    void f() const 
    {
	std::cout << "B::f()" << std::endl;
    }	
};

void func(const A& obj) 
{
     obj.f();
}	

int main()
{
	B* bPtr = new B();

	A* aPtr = bPtr;
	
	func(*aPtr); // A::f()
	func(*bPtr); // A::f()
}
 ```

 - **Статично** свързване(Static binding/Early binding) - изборът на функцията, която трябва да се изпълни става **по време на компилация(Compile time)**
 - **Динамично** свързване(Dynamic binding/Late binding) – изборът на функцията, която трябва да се изпълни става **по време на изпълнение на програмата(Run time)**.

```c++
#include <iostream>
using namespace std;

struct A
{
    virtual void f() const 
    {
	std::cout << "A::f()" << std::endl;
    }	
};

struct B : public A
{
    void f() const 
    {
       std::cout << "B::f()" << std::endl;
    }	
};

int main()
{
	А* ptrs[2];
	ptrs[0] = new A();
	ptrs[1] = new B();
	
	ptrs[0]->f(); // A::f()
	ptrs[1]->f(); // B::f()
}
 ```

## Virtual functions(Виртуални функции)

Член-функция, която е декларирана в основен клас(Base class) и е предефинирана от производен клас(Derived class). <br />
Гарантират, че правилната функция ще се извика за даден обект, независимо от типа reference/pointer(типа препратка), <br />
използван за извикване на функцията. Те се използват главно за постигане на Runtime polymorphism. <br />

### Правила за виртуални функции
  - **не могат** да бъдат static.
  - Прототипът на виртуалните функции трябва да бъде един и същ както в базовия, така и в производния клас.
  - Винаги се дефинират в базовия клас, като се предефинират в производния. Не е задължително производния клас да заменя или предефинира виртуалната функция, в такъв случай се използва версията на базовия клас.
  - Достъпът до виртуалните функции трябва да се осъществява използвайки reference/pointer към базовия клас, за да се осъществи Runtime polymorphism.
  - **Класът може да има виртуален деструктор, но не може да има виртуален конструктор.**

### Virtual pointer(vPtr) | Virtual table(vTable)

![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2012/img/vtable-1.png)

```c++
class Base
{
public:
    virtual void print() const
    {
        std::cout << "print base class\n";
    }

    void show() const
    {
        std::cout << "show base class\n";
    }
};

class Derived : public Base
{
public:
    void print() const override
    {
        std::cout << "print derived class\n";
    }

    void show() const
    {
        std::cout << "show derived class\n";
    }
};

int main()
{
    Base* bptr;
    Derived d;
    bptr = &d;

    // Virtual function, binded at runtime
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();

    return 0;
}
```
Output:
```
print derived class
show base class
```

## Полиморфизъм
Едни и същи действия се реализират по различен начин, в зависимост от обектите, върху които се прилагат. <br />
An entity(object or function) behaves differently in different scenarios. <br />
 - Действията се наричат **полиморфни**.
 - Реализира се чрез виртуални функции.
 - Класовете, върху които ще се прилага, трябва да имат общ родител или прародител, **да са наследници на един и същ клас**.
 - В класа се дефинира виртуален метод, съответстващ на полиморфното действие.
 - Всеки клас предефинира или не виртуалния метод.
 - "Активирането" става чрез указател към базов клас, на който може да се присвоят адресите на обекти на който и да е от базовите класове от йерархията.

### Compile time polymorphism vs Runtime polymorphism
- Compile time - дадена функция се извиква по време на компилация на програмата(function overload/operator overload).
- Runtime - функциите се извикват в момента на изпълнение на програмата (Dynamic binding/Late binding).

**Важно!** При полиморфна йерархия ще изтриваме обектите чрез указатели от базовия клас. За да се извикват правилните деструкори задължително **деструкторът на базовият клас** трябва е деклариран като виртуален!
```c++
#include <iostream>

class Base {
public:
    Base()
    {
        std::cout << "Constructing base\n";
    }
    virtual ~Base()
    {
        std::cout << "Destructing base\n";
    }
};

class Derived : public Base {
public:
    Derived()
    {
        std::cout << "Constructing derived\n";
    }
    ~Derived()
    {
        std::cout << "Destructing derived\n";
    }
};

int main()
{
    Derived* d = new Derived();
    Base* b = d;
    delete b;
}
```

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const
	{
		std::cout << "Hello, I am a random animal" << std::endl;
	}

	virtual ~Animal(){} //virtual destructor
};

struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal {};

int main()
{
	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a random animal!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}
```

## Абстрактен клас
 
 - Чисто виртуална функция (**pure virtual function**) - виртуална функция без тяло.
 - Клас е **абстрактен**, ако в него има поне една **чисто виртуална функция**.

Тогава класът е предназначен единствено за наследяване и няма да може да създаваме обекти от него.
Така във всеки наследник ще трябва да се разпише имплементация на функцията. Ако някой наследник няма собствена имплементация, то и той става абстрактен клас.

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const = 0;
	
	virtual ~Animal(){} 
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a mouse!" << std::endl;
	}
};

struct PrehistoricAnimal : public Animal
{};

int main()
{
	// Animal* pa1 = new Animal(); No! Animal is an abstract class!
	// Animal* pa2 = new PrehistoricAnimal(); No! PrehistoricAnimal is also an abstract class!

	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a mouse!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}
```

### Pure virtual destructor

```c++
// Initilization of base class
class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};

// Initilization of derived class
class Derived : public Base {
public:
    ~Derived() {
        std::cout << "~Derived() is executed";
    }
};

int main()
{
    // base class pointer which is
    // allocating fresh storage
    // for Derived function object's
    Base* b = new Derived();
    delete b;
}
```
Output: **Compile error**

Pure virtual destructor трябва **изрично** да бъде дефиниран.(explicitly defined)
```c++
// Initilization of base class
class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};
Base::~Base() // Explicit destructor call
{
    std::cout << "Pure virtual destructor is called" << std::endl;
}

// Initilzation of derived class
class Derived : public Base {
public:
    ~Derived() {
        std::cout << "~Derived() is executed" << std::endl;
    }
};

int main()
{
    // Calling of derived member function
    Base* b = new Derived();
    delete b;
}
```

### Interface vs Abstract Classes:
Интерфейсът няма реализация на нито един от своите методи.Tой може да се разглежда като колекция от декларации на методи. <br />
В C++ интерфейсът може да бъде симулиран, като всички методи се правят като чисто виртуални. <br />
                               
Допълнително информация:
В Java има отделна ключова дума за интерфейс.
- keyword interface за интерфейс
- keyword abstract за aбстракция (function can be made pure virtual or abstract with keyword abstract)

## Diamond problem
![alt text](https://github.com/Justsvetoslavov/Object-oriented_programming_FMI_2021-2022/blob/main/Sem.%2012/img/diamond-problem.png)
```c++
//indicate problem

#include <iostream>

class SuperClass {
public:
    SuperClass() {
        std::cout << "SuperClass default constructor is called" << std::endl;
    }
};

class A : public SuperClass {
public:
    A() {
        std::cout << "A default constructor is called" << std::endl;
    }
};

class B : public SuperClass {
public:
    B(){
        std::cout << "B default constructor is called" << std::endl;
    }
};

class C : public A, public B {
public:
    C() {
        std::cout << "C default constructor is called" << std::endl;
    }
};

int main() {
    C obj;
}
```
Output:
```
SuperClass default constructor is called
A default constructor is called
SuperClass default constructor is called //<------------
B default constructor is called
C default constructor is called
```
Конструктора на SuperClass бива извикан 2 пъти, а ако имахме и деструктор - той също щеше да бъде извикан 2 пъти. <br />
Тоест, обектът obj има 2 копия на всички данни на базовия клас SuperClass, което предизвиква двусмислия/неяснотии(ambiguous behaviour)
```c++
#include <iostream>

class SuperClass {
public:
    SuperClass() {
        std::cout << "SuperClass default constructor is called" << std::endl;
    }
};

class A : virtual public SuperClass {
public:
    A() {
        std::cout << "A default constructor is called" << std::endl;
    }
};

class B : virtual public SuperClass {
public:
    B(){
        std::cout << "B default constructor is called" << std::endl;
    }
};

class C : public A, public B {
public:
    C() {
        std::cout << "C default constructor is called" << std::endl;
    }
};

int main() {
    C obj;
}
```
Output:
```
SuperClass default constructor is called
A default constructor is called
B default constructor is called
C default constructor is called
```
Solution - virtual. <br />
Класовете А и В трябва да бъдат виртуални базови класове(virtual inheritance), за да избегнем 2-те копия на SuperClass. <br />

Важно:
Когато използваме keyword: virtual, **конструкторът по подразбиране на прародителя се извиква по подразбиране**, дори ако родителските класове извикват изрично конструктор с параметри.

## Specifiers - override & final
- override указва, че дадена функция презаписва функция от базовия клас. Ако в базовия клас няма такава функция, то кодът няма да се компилира.
- final указва, че дадена функция не може да се презависва надолу по йерархията или че даден клас не може да се наследява.
