#  Преговор на указатели, референции и динамична памет. Увод в ООП. Обекти. Структури и обединения. Представяния в паметта. Работа с функции, които приемат обекти.

<img align="right" width="500" height="600" src="img/memory-types.png">

###  **Преговор. Указатели, референции, динамична памет.**

Паметта, която можем да използваме в **C++** има 4 основни типа:
<br />

*	**Глобална (Статична)**: в тази памет се записват статичните/глобалните променливи.

*	**Стекова (stack)**: тя съдържа "локалните" променливи, т.е. онези, които са дефинирани в телата на функции и са същевременно нестатични.
	  * Заделя се в момента на дефиниция на променливите и се освобождава в момента на изход от scope-a, в която е дефинирана;
	  * Последно заделената памет се освобождава първа (First in Last out);
	  * Количеството заделена памет е определена по време на компилация;
	  * Ние нямаме контрол над управлението над паметта
 
*	**Динамична (heap)**: е "свободната" част от паметта, която се използва (<em>динамично</em>) в хода на програмата. 
	* Заделя се и се освобождава по всяко време на изпълнение на програмата;
	* Областта за динамична памет е набор от свободни блокове памет;
	* Програмата може да заяви блок с произволна големина;
	* Имаме контрол над управлението на паметта;
	  
*	**Program Code**: памет, в която се пази нашият компилиран код
	* Може да се достъпва с function pointer-и
<br/><br/>
#### **Създаване на променливи (в статичната и динамичната памет)**
 ```c++
int main()
{
	int a = 10; // int in the stack
	int* ptr = new int(30); // int in the dyniamic memory
                            // we use a pointer on the stack to point to the int

	// print the value of the int in the stack and the one in the heap
	std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;
	
	// ptr holds an address in the dynamic memory where the int is placed
	std::cout << "Address of second number" << ptr << std::endl;
	
	delete ptr; // delete the int in the stack to prevent memory leak
	
	ptr = &a;   // redirect the pointer to int in the stack
	std::cout << "Address of first number" << ptr << std::endl; // now ptr holds the address that is in the stack
	
	int& b = a; // creates int which data is on the address of a => they share the same memory
	b = 30;
	
	std::cout << "First number" << a << std::endl // 30
}
 ```

#### **Подаване на параметри във функция**

##### **Подаване по копие.**

 ```c++
#include <iostream>

void f(int a)
{
	a++; // a++ will increment the value of the copy
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //10
}
 ```
##### **Подаване по референция.**

 ```c++
 #include <iostream>
 
void f(int& a)
{
	a++; // a++ will increment the actual value of the passed variable
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //11
}
 ```
##### **Подаване по указател.**

 ```c++
#include <iostream>

void f(int* a)
{
	(*a)++; // a++ will increment the value at the address where the pointer points at
}

int main()
{
	int a = 10;
	f(&a); // &a gives us the address of a which can be assigned to a pointer variable
	std::cout << a << std::endl; //11
}
 ```
 
## **Обектно-ориентирано програмиране**

OОП е **програмна парадигма**.

Принципи:
- Абстракция
- Капсулация
- Наследяване
- Полиморфизъм

**Техническият дълг** е концепция в програмирането, която отразява допълнителната разработка, която възниква, когато се използва лесен за изпълнение код в краткосрочен план, вместо да се прилага най-доброто цялостно решение. <br/>

##  [**Структури**](https://en.cppreference.com/w/c/language/struct)

Структурите в C++ се използват за групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип и с различна дължина.

```c++
struct Box
{
	double height;
	double width;
	double length;
	// double height, width, length; is also possible
}
 ```

###  **Деклариране на обекти от новия тип**
 ```c++
Box b; // default values to height and width and length

Box b2 = {3, 4, 3.4} // height = 3, width = 3, length = 3.4;

Box b3;
b3.height = 13;
b3.width = 14;
b3.lenght = 20;
 ```
	
#### **Подаване във функции**
Ако няма да променяме обекта го подаваме по **константна референция.**
 ```c++
double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}
```
Може и само по **референция**, но тогава може да се правят промени върху подадения аргумент. 
   
 ```c++
void readBox(Box& b)
{
    cin >> b.height >> b.width >> b.length;
}
 ```
Може и да го подаваме по **копие**.
 ```c++
Box revertBox(Box b)
{
    int temp = b.height;
    b.height = b.width;
    b.width = temp;

    return b;
}
```
#### **Създаване на динамични обекти**
 ```c++
#include <iostream>

struct Box
{
	double height;
	double width;
	double length;
};

double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}

int main()
{
	Box* boxPtr = new Box();

	// different types of assigning a value to a property when you have a pointer
	(*boxPtr).height = 3;
	(*boxPtr).width = 1;
	boxPtr->length = 4;
	
	std::cout << calculcateVolume(*boxPtr) << std::endl;
	
	delete boxPtr;
}
```

#### **Влагане на обекти**
 ```c++
struct Box
{
	double height;
	double width;
	double length;
};

struct Warehouse
{
	char name[1024];
	Box b1;
	Box b2;
};

int main()
{
	Warehouse w = { "Ekont", { 1, 2, 3 }, { 4, 5, 3 } };

	std::cout << w.name;
}
```

#### **Масиви от обекти**
 ```c++
struct Box
{
	double height;
	double width;
	double length;
};

int main()
{
	Box arr1[30]; // 30 boxes
	Box* arr2 = new Box[20] // 20 boxes in dynamic mem.
	
	std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

	delete[] arr2;
}
```
## **Представяне в паметта и подравняване.**

*	Паметта е байт-адресируема, т.е. може да достъпва всеки байт индивидуално;
*	Колко памет може да прочете процесорът за един memory read cycle-a зависи от архектурата му (x32 - 4 bytes, x64 - 8 bytes);
*	В паметта променливите са разположени в същия ред, в който са декларирани в структурата;
*	Подравняването на една структура става по **големината на най-голямата член-данна (даже и в случая на вложена структура)** на структурата (с цел минимизация на подравняването);
*	За да бъде минимална паметта, която ползва една структура, трябва да подредим нейните член-данни в нарастващ или намаляващ ред по големина на променливата

```c++
struct Example1
{
    bool b;         // 1 byte
    int c;	        // 4 bytes
} ex1;

struct Example2
{
    short int s;    //2 bytes
    char c;         //1 byte
    int i;          //4 bytes
} ex2;

// How can the following struct use less memory?
struct Example3
{
    char c;         //1 byte
    double d;       //8 bytes
    int s;          //4 bytes
} ex3;

// the padding is equal to the biggest variable, if it is an int => 4 bytes
std::cout << sizeof(ex1) << std::endl; // 8
std::cout << sizeof(ex2) << std::endl; // 8
std::cout << sizeof(ex3) << std::endl; // 24
```
<i>Представяне на ExampleA в паметта:</i> <br />
![Padding}](img/padding.png)

## [**Обединения**](https://en.cppreference.com/w/cpp/language/union)
Обединенията са част от паметта, която се поделя при съхранение на две или повече променливи. <br />
Променливите, поделящи паметта могат да са от различни типове.<br />
Във всеки един момент обаче може да се ползва само една променлива от състава на обединението.<br />

Използва едно и също място в паметта за всеки от своите членове.

```c++
union Example
{
	int a;
	char b;
} var;

int main()
{
	var.a = 65;
	std::cout << var.a << " " << var.b; // 65 A
}
```

```c++
union Example
{
	int a;
	char b;
	double c;
	float d;
};

int main()
{
	std::cout << sizeof(union Example); //8
}
```

```c++
union Example
{
	int a;
	char b;
} var;

int main()
{
	var.a = 90;
	union Example *p = &var;
	std::cout << p->a << " " << p->b; //90 Z
}
```

<div style="background-color: white; max-width: 300px;"> 
    <img src="img/union.jpg"/>
</div>

## **Задачи**

**Задача 1:** Въвежда се цяло число **N**  и после **N** тригъгълника в равнината, определени от 3 точки ( 6 координати). <br />
Отпечатайте тригълниците **сортирани по лицата им.**
![Selection-sort](img/selection-sort.png)

**Задача 2:** Резлизирайте структура Rational, която е за работа с рационални числа. <br />
Имплементирайте функции за събиране, изваждане, умножение и деление. <br />
Имеплементирайте функция, която приема истанция(обект) от новия тип и връща дали е валидно рационално число, както и функция, която връща дали е цяло число. <br />
