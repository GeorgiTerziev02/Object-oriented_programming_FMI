## Шаблони
Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас
```c++
#include <iostream>
using namespace std;

template <class T>
T sum(const T& a,const T& b) {
    return a + b;
}

int main() {
    int a = 4;
    int b = 9;
    cout << sum<int>(a, b) << endl;

    double c = 3.14;
    double d = 4.5;
    cout << sum<double>(c,d) << endl;
	
    return 0;
}
```
Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

**Задача:**
Релизирайте структурата от данни FixedLengthStack

<br />

**Пример**:
 ```c++
int main()
{
   FixedLengthStack<int, 5> st;

   for(size_t i = 0; i < 5; i++) // if i < 6 it should throw an error
        st.push(i);
   Stack st1 = st;
   Stack st2;
   st2 = st1;
   Stack st3 = std::move(st1);

   while (!st2.empty())
         std::cout << st2.pop() << ' ';
   std::cout << std::endl;
   return 0;
}
 ```
