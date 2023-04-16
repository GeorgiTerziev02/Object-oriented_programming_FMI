# Задача
## Big number :eight::six::seven::six::two::four::eight::eight::five::seven::five:...:eight::seven:

Реализирайте клас `BigNumber`, който представя цяло число (положително или отрицателно) с голяма дължина - "дълго число". Както знаем, най-големият примитивен тип, използван за цели числа в С++, е `long long int`, но той поддържа "само" :clown_face: числата от -(2^63) до (2^63)-1. Целта на нашата задача е да работим дори с още по-големи числа, които практически нямат ограничение в дължината си.

За представяне на числата трябва да използвате саморазширяващи се масиви с елементи от тип `char`, като всеки един символ представя една десетична цифра.

### Конструктори :hammer_and_wrench:

Един обект от класа `BigNumber` трябва да може да се конструира по всеки един от следните три начина:

```c++
/**
 * @brief Default constructor, sets the value of the number to 0
 */
BigNumber();

/**
 * @brief Constructor with parameter
 * 
 * @param number a number represented as a string
 */
BigNumber(const char* number);

/**
 * @brief Constructor with parameter
 * 
 * @param number a number represented as an integer
 */
BigNumber(long long int number);
```

### Копиране и унищожаване :infinity:

Гарантирайте, че обектите от тип `BigNumber` могат да се копират и унищожават коректно. Ако е нужно, реализирайте експлицитно всички функции от Rule of 3 (бонус: гарантирайте, че работят коректно всички от Rule of 5). Ако това не е нужно, следвайте Rule of 0.

### Оператори :heavy_plus_sign::heavy_minus_sign::heavy_multiplication_x::heavy_division_sign:

Предефинирайте следните оператори:

```c++
// Mandatory
bool operator == (const BigNumber& other) const;
bool operator != (const BigNumber& other) const;
bool operator < (const BigNumber& other) const;
bool operator > (const BigNumber& other) const;

BigNumber& operator += (const BigNumber& other);
BigNumber operator + (const BigNumber& other) const;
BigNumber& operator -= (const BigNumber& other);
BigNumber operator - (const BigNumber& other) const;
BigNumber& operator *= (const BigNumber& other);
BigNumber operator * (const BigNumber& other) const;

// Optional
BigNumber& operator /= (const BigNumber& other);
BigNumber operator / (const BigNumber& other) const;
BigNumber& operator %= (const BigNumber& other);
BigNumber operator % (const BigNumber& other) const;
```

### Четене и писане от конзолата :keyboard::printer:

Реализирайте подходящи методи за:

- четене на дълго число от конзолата 
- отпечатването на дълго число на конзолата


### Демо :sunglasses:

Демонстрирайте реализацията на вашия клас чрез кратка програма, тестваща функционалността на всички изброени по-горе методи и оператори.

### Малко тестове :heavy_check_mark::x:

Ако реализацията на вашия клас е правилна, всички редове би трябвало да върнат `true`:

```c++
std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") > BigNumber("4767846784647856547476")) << std::endl;
std::cout << std::boolalpha << (BigNumber("4767846784647856547476") < BigNumber("7643276342876783246893247")) << std::endl;
std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") != BigNumber("4767846784647856547476")) << std::endl;
std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") == BigNumber("7643276342876783246893247")) << std::endl;

std::cout << std::boolalpha << ((BigNumber("12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("12350033579332211025")) << std::endl;
std::cout << std::boolalpha << ((BigNumber("12345678901234567890") - BigNumber("4354678097643135")) == BigNumber("12341324223136924755")) << std::endl;
std::cout << std::boolalpha << ((BigNumber("12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("53761457511741137249987999149935150")) << std::endl;
std::cout << std::boolalpha << ((BigNumber("12345678901234567890") / BigNumber("4354678097643135")) == BigNumber("2835")) << std::endl;
std::cout << std::boolalpha << ((BigNumber("12345678901234567890") % BigNumber("4354678097643135")) == BigNumber("166494416280165")) << std::endl;

std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("-12341324223136924755")) << std::endl;
std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("-53761457511741137249987999149935150")) << std::endl;
```

### :warning: Забележки

- Погрижете се за правилното използване на динамична памет и не допускайте memory leaks
- Целете се към максимално спазване на чист код
- Не е позволено използването на `std::string`
- Позволено е използването на библиотеките `<cstring>`, `<cassert>` и `<cstddef>`
