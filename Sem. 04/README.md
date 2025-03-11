# Член-функции. Жизнен цикъл на обект. Конструктори и деструктор. **Капсулация**. Модификатори за достъп. Член-функции **get** и **set**.

## Член-функции.
Член-функциите са функции, които работят с член-данните на обекта от дадена структура.
```c++
struct Point {
	int x, y;
};

bool IsInFirstQuadrant(const Point& p) {
	return p.x >= 0 && p.y >= 0;
}

int main() {
	Point p1 = {3, 4};
	Point p2 = {-9, 8};
	std::cout << IsInFirstQuadrant(p1) << std::endl;
	std::cout << IsInFirstQuadrant(p2) << std::endl;
}
```
 
Може функцията да бъде член-функция:
```c++
struct Point {
	int x, y;

	bool IsInFirstQuadrant() const {
		return x >= 0 && y >= 0;
	}
};

int main() {
	Point p1 = {3, 4};
	Point p2 = {-9, 8};
	std::cout << p1.IsInFirstQuadrant() << std::endl;
	std::cout << p2.IsInFirstQuadrant() << std::endl;
}
```
  
**Член-функциите**:
 - Работят с член-данните на класа.
 - Извикват се с обект на класа
 - Компилаторът преобразува всяка **член-функция** на дадена структура в
   обикновена функция с уникално име и един допълнителен параметър
   – **константен указател към обекта**.

```c++
bool Point::isInFirstQuadrant() const {
	return x >= 0 && y >= 0;
}
```

се превежда в:

```c++
bool Point::isInFirstQuadrant(const Point* const this) {     
	//remember since this is a pointer (const) to Point we use the -> operator instead, which is equivalent to (*this).member;
	return this->x >= 0 && this->y >= 0;
}
```

Като забележете, че this е const указател към Point, т.е. не можем да меним this, но можем да променяме обекта, който е сочен от него (четем декларациите на указателите отдясно наляво).
и съответно

```c++
pt.isInFirstQuadrant();
```

се превежда в:

```c++
Point::isInFirstQuadrant(&pt);
```

**Константни член-функции**:

 - Не променят член-данните на структурата.
 - Оказва се чрез записването на ключовата  дума **const** в декларацията и в края на заглавието(суфикс) в дефиницията им
 - Могат да се извикват от константни обекти.
 
```c++
struct obj {
	void inspect() const;   //This member-function promises not to change *this
	void mutate();          //This member-function might change *this
};

void Test(obj& changeable, const obj& unchangeable) {
	changeable.inspect();   // Okay: doesn't change a changeable object
	changeable.mutate();    // Okay: changes a changeable object
	
	unchangeable.inspect(); // Okay: doesn't change an unchangeable object
	unchangeable.mutate();  // ERROR: attempt to change unchangeable object
}
```
- **const** индикира, че **this** е указател към **const**. <br />
Член-функции, които използват **const** по този начин не могат да променят обекта, върху който са извикани! <br />
 
