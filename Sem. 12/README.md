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
