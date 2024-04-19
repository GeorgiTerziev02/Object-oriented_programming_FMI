Блиц тест 

За задачите може да се възползвате от следното изображение:
![exceptions](./img/exceptions.jfif)

Задача 1. Какво ще се случи след изпълнението на кода?
```
int main()
{
    try
	{
		throw std::invalid_argument("invalid argument");
		throw std::runtime_error("runtime error");
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << ia.what();
	}
	catch (const std::runtime_error& re)
	{
		std::cout << re.what();
	}
}
```
A) Ще се изпише "ivalid argumentruntime error"

B) Ще се изпише "invalid argument"

C) Ще се изпише "runtime error"

D) Извикването ще се терминира - std::terminate()

Задача 2. Какъв ще е резултатът на конзолата от изпълнение на:
```c++
int main()
{
	try
	{
		throw std::invalid_argument("ERROR");
	}
	catch (const std::runtime_error&)
	{
		std::cout << "Runtime error";
	}
	catch (const std::logic_error&)
	{
		std::cout << "Logic error";
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Invalid argument";
	}
	catch (const std::exception&)
	{
		std::cout << "Exception";
	}
}
```
А) "Runtime error"

B) "Logic error"

C) "Invalid argument"

D) "Exception"

Задача 3: Какво ще се изведе на конзолата след изпълнението на следния код?

```c++
class A {
	int a;
public:
	A() {
		std::cout << "Default of A\n";
		throw "test";
	}
	A(int a) : a(a) {}
};
class B {
	A a;
public:
	B() {
		std::cout << "Default constructor of B\n";
	}
	B(A a) {
		this->a = a;
		std::cout << "Constr with param\n";
	}

	B(const B& other) {
		std::cout << "Copy constr\n";
		this->a = other.a;
	}

};
int main() {

	B t1(10);
	B t2(t1);

	return 0;
}
```

Задача 4: Какво ще се случи след изпълнението на следния код:
```c++
class User {
	char* name;
public:
	User(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	User(const User& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}

	User(User&& other) noexcept {
		name = other.name;
		other.name = nullptr;
		throw "test";
		std::cout << "Move constr\n";
	}

	User& operator=(const User& other) = delete;
	~User() {
		delete[] name;
	}

};
int main() {

	User user1("Ivan");
	User user2(std::move(user1));
```


Задача 1. Трябва да разработите система за обработка на поръчки.

Създайте клас Order, който описва поръчка. Всяка поръчка има:

име на ресторант, за който е предназначена
брой продукти
списък с продуктите
всеки продукт е низ с произволна дължина (използвайте ваш клас String)
Функция за добавяне на продукт
Функция за пресмятане на време за доставка в минути - времето за доставка е равно на броя продукти в поръчката, събрана с дължините на всеки един продукт. (Помислете длаи може да се оптимизира изпълнението на тази функция)
Подходящи getters, setters и други помощни функции (ако се налага)
Създайте клас Restaurant, който описва ресторант. Всеки ресторант има:

име (с максимална дължина 25 символа);
списък от продукти (с произволна дължина, която се подава в конструктора);
Функция за добавяне на продукт
Функция за получаване на поръчка
Ако получим поръчка с продукт, който ресторантът не предлага, се хвърля изключение
Ако получим поръчка с несъответстващо име на ресторант се хвърля изключение
Подходящи getters, setters и други помощни функции (ако се налага)
Създайте клас Foodpanda, който има списък с ресторанти (отново с произволна дължина, която се задава в конструктора). Трябва да има функции за:

Добавяне на нов продукт в даден ресторант.
Добавяне на нов ресторант във Foodpanda.
Добавяне на поръчка - Класът намира за кой ресторант е поръчката, ако има такъв и му я изпраща. В противен случай се хвърля грешка, че поръчката е невалидна, понеже такъв ресторант не съществува.
Подходящи getters, setters и други помощни функции (ако се налага)
За всеки от класовете реализирайте нужните конструктори, copy + move семантики и функционалности. При невалидни входни данни хвърляйте подходящи изключения.

Създайте конзолно приложение за работа с поръчки. То трябва да обработва всички възникнали изключения (не трябва да позволи exception да достигне до крайният потребител).