## Задача 0
В показаните долу илюстративни примери какво ще се изведе на конзолата?

```c++
#include <iostream>

class A {
	int a;
public:
	A() {
		std::cout << "Default Constructor of A\n";
	}
	A(const A& other) {
		std::cout << "Copy constructor of A\n";
	}
	A& operator=(const A& other) {
		std::cout << "Operator= of A\n";
		return *this;
	}
};

class B {
	int b;
public:
	B() {
		std::cout << "Default constructor of B\n";
	}
	B(const B& other) {
		std::cout << "Copy constructor of B\n";
	}
	B& operator=(const B& other) {
		std::cout << "Operator= of B\n";
		return *this;
	}
};

class C {
	A a;
	B b;
public:
	C() {
		std::cout << "Default Constructor of C\n";
	}
	C(const C& other) { 
		a = other.a;
		b = other.b;
		std::cout << "Copy constructor of C\n";
	}
};

int main() {

	C c1;
	std::cout << std::endl;
	C c2(c1);

	return 0;
}
```
```c++
#include <iostream>

class A {
	int a;
public:
	A() {
		std::cout << "Default Constructor of A\n";
	}
	A(const A& other) {
		std::cout << "Copy constructor of A\n";
	}
	A& operator=(const A& other) {
		std::cout << "Operator= of A\n";
		return *this;
	}
};

class B {
	int b;
public:
	B() {
		std::cout << "Default constructor of B\n";
	}
	B(const B& other) {
		std::cout << "Copy constructor of B\n";
	}
	B& operator=(const B& other) {
		std::cout << "Operator= of B\n";
		return *this;
	}
};

class C {
	A a;
	B b;
public:
	C() {
		std::cout << "Default Constructor of C\n";
	}
	C(const C& other) : a(other.a), b(other.b) { 
		std::cout << "Copy constructor of C\n";
	}
};

int main() {

	C c1;
	std::cout << std::endl;
	C c2(c1);

	return 0;
}
```

```c++
#include <iostream>

class A {
	int a;
public:
	A() {
		std::cout << "Default Constructor of A\n";
	}
	A(const A& other) {
		std::cout << "Copy constructor of A\n";
	}
	A& operator=(const A& other) {
		std::cout << "Operator= of A\n";
		return *this;
	}
};

class B {
	int b;
public:
	B() {
		std::cout << "Default constructor of B\n";
	}
	B(const B& other) {
		std::cout << "Copy constructor of B\n";
	}
	B& operator=(const B& other) {
		std::cout << "Operator= of B\n";
		return *this;
	}
};

class C {
	A a;
	B b;
public:
	C() {
		std::cout << "Default Constructor of C\n";
	}
	C(const C& other) : a(other.a), b(other.b) {
		std::cout << "Copy constructor of C\n";
	}
	//you have to explicitly call a and b operator=
	// otherwise nothing will be called
	C& operator=(const C& other) {
		//a=other.a;
		//b=other.b;
		std::cout << "Operator= of C\n";
		return *this;
	}
};

int main() {

	C c1, c2;
	std::cout << std::endl;
	c2 = c1;

	return 0;
}
```

## Задача 1: Ю-Ги-О! 
Сето Кайба организира турнир по **Ю-Ги-О!**, но е съкратил бюджета в компютърния отдел и помолил нас да организираме базата данни с всички дуелисти в турнира.<br />
Трябва да реализирате 2 класа Ю-Ги-О! карти: <br />

**Карта чудовище**
- Име (низ с произволна дължина)
- Атакуващи точки (неотрицателно целочислено число)
- Защитни точки (неотрицателно целочислено число)

**Магическа карта**
- Име (низ с дължина до 25 символа).
-Ефект (низ с дължина до 100 символа).
- Тип (може да е един следните 3: “trap”, “buff”, “spell”)

Реализирайте клас **deck**.Тестето трябва да има:
- Масив от карти чудовища (максимално – 20 карти).
- Масив от магически карти (максимално – 20 карти).
- Метод, който връща като резултат броя на магическите карти в тестето.
- Метод, който връща като резултат броя на картите чудовища в тестето.
- Метод, който добавя магическа карта към тестето.
- Метод, който добавя карта чудовище към тестето.
- Метод, който променя магическа карта от тестето, като за параметри приема индекс и нова карта.
- Метод, който променя карта чудовище от тестето, като за параметри приема индекс и нова карта.
- Метод, който премахва магическата карта на определена позиция от тестето
- Метод, който премахва картата чудовище на определена позиция от тестето

Реализирайте клас **Duelist**. Той трябва трябва да има:
1. Име (Низ с произволна дължина).
2. Тесте(deck)
3. Дуелистът трябва да има същите методи като в deck, с които да променяме тестето 
му

## Примери
```c++
//40 cards = 20 MonsterCards/20 MagicCards
Deck d;

// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
//ATK: 3000 DEF: 2500
d.changeMonsterCard(4, "Blue-eyes white dragon", 3000, 2500);

// 5-th card in the Magic deck is added/changed to "Monster reborn"
d.changeMagicCard(5, "Monster reborn", “revive”, spell);

//Returns the amount of MagicCards in the deck
d.getMagicCardCount(); //1

//Returns the amount of MonsterCards in the deck
d.getMonsterCardCount(); //13

Duelist player1("Seto Kaiba");

///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
MonsterCard DarkMagician("Dark Magician", 2500, 2100);
player1.changMonsterInDeck(2, DarkMagician);

Duelist player2("Yugi Muto");

//Changes the 2-nd magic card in the Magic deck to “Reflection”
MagicCard Reflection(Reflection", “Reflects the last played spell”, trap);
Player2.changeMagicCardInDeck(2, Reflection );
```

## Задача 2. 
Създайте клас NumberSeries, който моделира работата с числова редица. В конструктора на класа ще приемате цяло число - начална стойност на редицата (a_0) и указател към функция на преход, приемаща цяло число и връщаща цяло число (a_i = f(a_i-1)).

Трябва да имате следните функционалности:

* Генериране на i-то число от редицата.
* Проверка дали подадено число е част от редицата.
* Setter-и за нова начална стойност и нова функция на преход.

 Генерирането на стойности трябва да бъде оптимизирано откъм скорост:

* За коректна работа с фунцкионалността за генериране на i-то по ред число, трябва да поддържате динамичен масив в класа, в който да пазите досега генерираните стойности.
* Ако числото вече е било генерирано, трябва да го върнете като резултат без да го генерирате повторно.
* Ако числото го няма в масива, генерирайте и добавете към масива всички числа, които липсват до a_i в редицата и върнете генерираната стойност.
* Ако в масива няма достатъчно място, за да се съхранят новите стойности, преоразмерете го по подходящ начин.
* При set-ване на нова начална стойност или функция на преход, трябва да изтривате динамичния масив и да започвате процеса на запазване отначало.

Помислете как трябва да се handle-не коректно копирането на обекти от вашия клас.

## Задача 3
Напишете клас `MultiSet`, който съдържа мултимножество от числа в диапазона от 0 до n-1. Стойността на n се приема от конструктора на класа. Всяко число може да се среща най-много 3 пъти в рамките на мултимножеството.

Във всеки един момент обект от вашия клас трябва да има задължително минимален възможен размер.

Трябва да имате следната функционалност:

* Добавяне на число, ако се среща по-малко от 3 пъти в множеството.
* Премахване на число, ако се съдържа.
* Проверка колко пъти се съдържа число.
* Принтиране на всички числа, които съдържа множеството.
* Функция, която приема две множества и връща тяхното сечение.
* Функция, която приема две множества и връща тяхното обединение.