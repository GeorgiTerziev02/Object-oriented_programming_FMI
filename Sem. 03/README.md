# Файлове (част 2). Двоични файлове.

## Двоични файлове.

Използваме функциите:

1. .read(char* memoryBlock, size_t size);
2. .write(const char* memoryBlock, size_t size);

Обърнете внимание, че функцията приема **char***. Ако искаме да запазим променлива от друг вид, ще трябва експлицитно да преобразуваме указателя към тип char* (без значение, че указателят не сочи към елементи от тип char)

### Пример за писане в двоичен файл:
 ```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "file.dat";

int main() {
	std::ofstream out(FILE_NAME, std::ios::binary);

	int a = 155555;
	out.write((const char*)&a, sizeof(a));

	out.close();
}
 ```
 ### Пример за четене от двоичен файл:
 
  ```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "file.dat";

int main() {
	std::ifstream in(FILE_NAME, std::ios::binary);

	int a;
	in.read((char*)&a, sizeof(int));

	std::cout << a << std::endl;

	in.close();
}
 ```

### Съдържанието на двоичния файл:
 ![enter image description here](https://i.ibb.co/G3R72qG/sudurjanie.png "Binary file example")
 
Байтовете се записват в **обратна посока**. Най-старшият байт е последен. Следователно запаметеното число е **00025fa3**, което е точно шестнайсетичният запис на числото **155555**.
 
### Примери за запазване на структури във файл.
 
- запазване на структура, която не използва динамична памет

```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "testObj.bat";

struct Test {
	bool b;
	int x;
};

int main() {
	{
		Test t = { true, 45 };
		std::ofstream file(FILE_NAME, std::ios::binary);

		if (!file.is_open()) {
			return -1;
		}

		file.write((const char*)&t, sizeof(t));
	}

	{
		Test t;
		std::ifstream file(FILE_NAME, std::ios::binary);

		if (!file.is_open()) {
			return -1;
		}

		file.read((char*)&t, sizeof(t));
		std::cout << t.b << " " << t.x << std::endl;
	}
}
```

```c++
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable: 4996)

constexpr char FILE_NAME[] = "testObj.bat";

struct Student {
	char name[25];
	int fn;
	int age;
};

int main() {
	{
		Student st;
		strcpy(st.name, "Ivan");
		st.fn = 1234;
		st.age = 33;

		std::ofstream file(FILE_NAME, std::ios::binary);

		if (!file.is_open()) {
			std::cout << "Error while writing to binary file!" << std::endl;
			return -1;
		}

		//since the data is grouped in the struct, we can save it like this.
		file.write((const char*)&st, sizeof(st));
	}

	{
		Student st;
		std::ifstream file(FILE_NAME, std::ios::binary);

		if (!file.is_open()) {
			std::cout << "Error while reading from binary file!" << std::endl;
			return -1;
		}

		file.read((char*)&st, sizeof(st));
		std::cout << st.name << " " << st.fn << " " << st.age << std::endl;
	}
}
```
      
- запазване на структура, която използва динамична памет

# TODO: TBA

### Пример за запазване на масив от структури във файл.
  
- запазване на масив от обекти, които не използват динамична памет

# TODO: tba

- четене на масив от обекти, които не използват динамична памет

  # TODO: tba

### Подравняване
```c++
#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "testObj.bat";

struct Test {
 	char ch;
 	int a;
};

int main() {
    std::ofstream f(FILE_NAME, std::ios::binary);
    
    if(!f.is_open()) {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    
    Test arr[3] = {{'a', 400},{'b', 500},{'c', 600}};
    
    f.write((const char*)&arr, sizeof(arr));
    
    f.close();
}
 ```

След изпълнението на програмата, файлът (**output.dat**) изглежда така:

![Image of the binary file after running the code](https://i.ibb.co/0JthLd6/3-A978-D14-7-C7-A-4-ABD-8-B0-C-DA27-F6-E9-CD0-A.png "Binary file")

### Задачи

**Задача 1:** Да се напишат програми, които запазват/четат масиви от обекти, които не използват динамична памет.

**Задача 2:** Да се напише функция, която намира големината на файл.

**Задача 3:** Да се напише функция, която заменя всяко срещане на символ във файл с друг символ. Съдържанието на файла не трябва да се зарежда в паметта.

**Задача 4**: 

Да се реализира програма за изглед и модификация на двоични файлове (hex viewer). При стартиране на програмата трябва да се въведе път до двоичен файл и да зареди съдържанието на файла в паметта. След като файлът се е заредил в паметта, трябва да поддържате следните операции:
 
 - Преглед на файла (view)  отпечатва байтовете на файла (в шестнайсетична бройна система). След това да се отпечатат интерпретацията на байтовете като символи. Ако байтът отговаря на малка/голяма латинска буква, то да се отпечата символа. В противен случай да се отпечатва точка.  
 -  Промяна на байт по индекс (change ). 
 -  Премахване на последния байт (remove) 
 -  Добавяне на байт в края (add ). 
 -  Запазване на промените в същия файл (save) 
 -  Запазване на промените в друг файл (save as )

Нека имаме двоичен файл, myData.dat, който се е получил след изпълнението на следния c++ код: 
 ```c++
int x = 25409;
ofstream file(“myData.dat”, std::ios::binary);
file.write( (const char*)&x, sizeof(x));
```

Да се реализира прост интерфейс, с който да се извикват написаните фунцкии през конзолата.

**Важно** Не се ползволява използването на stl, както и std::hex.

**Пример** (входът от потребителя започва с '>'):

 ```
Enter a file path:
> myData.dat
File loaded successfully! Size: 4 bytes 
> view
41 63 00 00
A  c  .  . 
>change 1 65 
Operation successfully executed!
> view 
41 65 00 00 
A  e  .  . 
> remove 
> view
 41 65 00 
 A  e   . 
 >save 
 File successfully saved
```

**Забележка:** Не се изисква поддържането на конзолен интерфейс. Можете само да реализирате функциите и да ги изпробвате в main функцията. 

