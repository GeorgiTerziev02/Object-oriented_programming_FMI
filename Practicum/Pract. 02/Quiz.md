## Куиз 1

## Въпроси

1. При подаване на обект като параметър на функция, ако няма да правим промени по обекта го подаваме като:
   - a) Константна референция  
   - b) Копие  
   - c) Референция  

2. Оптимална ли е от към памет структурата Graph?
```c++
struct Graph {
    int value;
    bool isDirected;
    int verticesCount;
    double spanningTreeSum;
    int edgesCount;
};
```
   - a) Не  
   - b) Да  

3. При подаване на обект като параметър на функция, ако ще правим промени по обекта го подаваме като:
   - a) Копие  
   - b) Константна референция  
   - c) Референция  

4. Какво ще се отпечата на конзолата?
```c++
struct Graph {
    bool isDirected;
    int verticesCount;
    int edgesCount;
    double spanningTreeSum;
};
int main() {
    std::cout << sizeof(Graph);
}
```

5. Какво ще се отпечата на конзолата? (приемаме, че работим на 64-битова архитектура)
```c++
struct PirateShip {
    char* name;
    uint32_t pirates;
    double crew;
};
struct Pirate {
    int age;
    char* name;
    PirateShip* ship;
};
int main() {
    std::cout << sizeof(Pirate);
}
```

6. Какво ще се отпечата на конзолата? (приемаме, че работим на 64-битова архитектура)
```c++
struct PirateShip {
    char code;
    uint32_t pirates;
};
struct Pirate {
    int age;
    bool isCaptured;
    char* name;
    PirateShip* ship;
};
int main() {
    std::cout << alignof(Pirate);
}
```

7. Какво ще се отпечата на конзолата? (приемаме, че работим на 64-битова архитектура)
```c++
struct PirateShip {
    char code;
    uint32_t pirates;
    double value;
};
struct Pirate {
    int age;
    bool isCaptured;
    char name[25];
    PirateShip ship;
};
int main() {
    std::cout << alignof(Pirate);
}
```

8. Какво ще се изведе на конзолата?
```c++
enum Animal {
    CAT,
    DOG
};
enum Vehicle {
    CAR,
    PLANE
};
int main() {
    Animal a  = Animal::CAT;
    Vehicle v = Vehicle::CAR;
    std::cout << (a == v); 
}
```