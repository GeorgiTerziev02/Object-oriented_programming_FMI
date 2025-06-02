# Solid Principles

SOLID е акроним за пет принципа на проектиране, предназначени да направят софтуерния дизайн по-разбираем, гъвкав и поддържащ. <br />
Въпреки че се прилагат за всеки обектно-ориентиран дизайн, принципите SOLID могат също да формират основна философия за гъвкаво развитие. <br />

- [Single Responsibility principle](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/SOLID%20Principles#single-responsibility-principle)
- [Open-Closed Principle](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/SOLID%20Principles#open-closed-principle)
- [Liskov Substitution Principle](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/SOLID%20Principles#liskov-substitution-principle)
- [Interface Segregation Principle](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/SOLID%20Principles#interface-segregation-principle)
- [Dependency Inversion Principle](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2015/SOLID%20Principles#dependency-inversion-principle)

## Single Responsibility principle
```
A class should have only one reason to change
```

![image](https://github.com/user-attachments/assets/03bffa1a-fac5-4bf0-9bc1-54164de40ff3)

Както подсказва името, той изисква всеки модул, да кажем клас, да носи отговорност за една и само една цел. <br />
Казано по друг начин, класът трябва да има само една "причина" за промяна(под "причина" може да имаме предвид промяна в спецификацията на дадена изискване). <br />
Този принцип позволява да пишем софтуер с висока кохезия и стабилност, тъй като той няма да бъде толкова повлиян с развиването на системата. <br /> 

Strong cohesion, loose coupling

```c++
//Example of a Single Responsibility
class DatabaseManager {
public:
   virtual ~DatabaseManager() = default;
   virtual void addUser(string username) = 0;
   virtual vector<string> getAllUsers() = 0;
};

class MyDatabaseManager : public DatabaseManager {
public:
   MyDatabaseManager(MyDatabaseManager& database);
   void addUser(string username) override;
   vector<string> getAllUsers() override;
};

class UsernameFormatter {
public:
   virtual ~UsernameFormatter() = default;
   virtual string format(string username) = 0;
   virtual string getReadableName(string input) = 0;
};
```

## Open-Closed Principle
```
Software entities should be open for extension, but closed for modification
```
Принципът диктува, че софтуерните модули са отворени за разширение, но затворени за модификация. <br />
Това позволява добавянето на нова функционалност без промяна на съществуващия изходен код. <br />

На практика най-добрият начин да постигнете това със C++ е полиморфизмът. <br />
По-специално, с използването на абстрактни класове, можем да разширим клас и да специализираме неговото поведение, без да променяме спецификацията на интерфейса. <br />
Този принцип позволява софтуер за многократна употреба и поддръжка. <br />

Контрапример/Лош пример за Open-Closed
```c++
enum class SensorModel {
   Good,
   Better
};

class DistanceSensor {
public:
   DistanceSensor(SensorModel model) : mModel{model} {}
   int getDistance() {
       switch (mModel) {
           case SensorModel::Good :
               // Business logic for "Good" model
           case SensorModel::Better :
               // Business logic for "Better" model
       }
   }
};
```

Пример/Добър пример за Open-closed
```c++
class DistanceSensor {
public:
   virtual ~DistanceSensor() = default;
   virtual int getDistance() = 0;
};

class GoodDistanceSensor : public DistanceSensor {
public:
   int getDistance() override {
       // Business logic for "Good" model
   }
};

class BetterDistanceSensor : public DistanceSensor {
public:
   int getDistance() override {
       // Business logic for "Better" model
   }
};
```

## Liskov Substitution Principle
```
If S is a subtype of T, then objects of type T in a program may be replaced with objects of type S
without altering any of the desirable properties of that program (e.g. correctness)
```
![image](https://github.com/user-attachments/assets/aa590bf8-861e-4a17-82cf-a733723126c9)


Този принцип изисква подкласовете не само да задоволяват синтактичните очаквания, но и поведенческите на своите родители.                             
Kато потребител на клас би трябвало да може да използваме всяко от неговите деца, които могат да ни бъдат предадени, без да се интересувам кое конкретно дете се използва.                  
Това означава, че трябва да гарантираме, че аргументите, както и всички върнати стойности на децата са последователни.                 

```c++
/*
The problem begins when different sensors, that is, the different children that implement the interface, return the orientation in different ranges.
For example, we have a Gyroscope that returns an orientation that is always positive, between 0 and 360 degrees,
while the Accelerometer provides an output that can be negative. Something between -180 and positive 180.
*/

class InertialMeasurementUnit {
public:
   virtual ~InertialMeasurementUnit() = default;
   virtual int getOrientation()       = 0;
};
class Gyroscope : public InertialMeasurementUnit {
public:
   /**
    * @return orientation in degrees [0, 360)
    */
   int getOrientation() override;
};
class Accelerometer : public InertialMeasurementUnit {
public:
   /**
    * @return orientation in degrees [-180, 180)
    */
   int getOrientation() override;
};
```

```c++
class InertialMeasurementUnit {
public:
   virtual ~InertialMeasurementUnit() = default;
   
   /**
    * Sets the orientation
    * @throw std::out_of_range exception if orientation is invalid
   */
   virtual void setOrientation(double) = 0;
   
    /**
    * Provides the valid range
    * @return <minimum orientation, maximum orientation>
    */
   virtual pair<double, double> getFrequencyRange() const = 0;
};

class Gyroscope : public InertialMeasurementUnit {
public:
   /**
    * @return orientation in degrees [0, 360)
    */
   int getOrientation() override;
};
class Accelerometer : public InertialMeasurementUnit {
public:
   /**
    * @return orientation in degrees [-180, 180)
    */
   int getOrientation() override;
};
```

## Interface Segregation Principle
```
No client should be forced to depend on methods it does not use
```
Класове с точно и ясно предназначение - специфични класове/методи. <br />
Трябва да избягваме класове/методи, които да правят "всичко". <br />
По-конкретно, по-добре е да имате много интерфейси с едно предназначение, отколкото един (или няколко) многоцелеви. <br />
Това позволява на нашия софтуер да бъде по-преизползваем и персонализиран, тъй като не е нужно да разчитаме или да прилагаме функционалност, която не използваме. <br />

```c++
struct IMachine {
    virtual void print(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
};

struct MultiFunctionPrinter : IMachine {      // OK
    void print(Document &doc) override { //code }
    void fax(Document &doc) override { //code }
    void scan(Document &doc) override { //code }
};

struct Scanner : IMachine {                   // Not OK
    void print(Document &doc) override { /* Blank */ }
    void fax(Document &doc) override { /* Blank */ }
    void scan(Document &doc) override {  
        // Do scanning ...
    }
};
```

```c++
/* -------------------------------- Interfaces ----------------------------- */
struct IPrinter {
    virtual void print(Document &doc) = 0;
};
struct IScanner {
    virtual void scan(Document &doc) = 0;
};
/* ------------------------------------------------------------------------ */
struct Printer : IPrinter {
    void print(Document &doc) override;
};
struct Scanner : IScanner {
    void scan(Document &doc) override;
};

struct IMachine : IPrinter, IScanner { };

struct Machine : IMachine {
	 IPrinter&   m_printer;
    IScanner&   m_scanner;
    
    Machine(IPrinter &p, IScanner &s) : printer{p}, scanner{s} { }
    
    void print(Document &doc) override {
		printer.print(doc);
    }
    
    void scan(Document &doc) override {
		scanner.scan(doc);
    }
};
```

## Dependency Inversion Principle
```
High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g. interfaces).
Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.
```

Принципът на инверсията на зависимостта гласи, че нашите класове трябва да зависят от интерфейси или абстрактни класове, вместо от конкретни класове и функции.

```c++
class Cloud {
public:
   virtual ~Cloud() = default;
   virtual void upload(string filepath) = 0;
};

class AwsCloud : public Cloud {
public:
   void upload(string filepath) override { /* ... */ }
};

class FileUploader {
public:
   FileUploader(Cloud& cloud);
   void scheduleUpload(string filepath);
};
```

