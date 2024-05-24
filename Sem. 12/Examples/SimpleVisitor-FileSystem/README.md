## Задача

**Note 1:** Всички примери са псевдо код.
**Note 2:** Имплементирането на така зададената задача с Visitor е леко overengineering, но все пак е добър пример.

Имаме файлова система с файлове и директории.

- Файлът има име.
- Директорията има име и масив, в който може да има и директории и файлове.

Заради масивът на директорията, ще ни трябва общ базов клас, за да можем да направим масив, в който едновременно може да има и директории и файлове.

Засега псевдо кодът ни изглежда така:

```c++
class FileSystemEntity {
	std::string name;
public:
	FileSystemEntity(std::string name) : name(name) {}
	const std::string& getName() const {
		return name;
	}
	virtual ~FileSystemEntity() = 0;
};
FileSystemEntity::~FileSystemEntity() {}

class File : public FileSystemEntity { };

class Directory : public FileSystemEntity {
public:
	FileSystemEntity** children;
	size_t size;
};
```

Имаме следната задача:

Искаме да имаме функционалност за принтиране на имената на файлове и директории. В случая с директории и имената на всички наследници навътре в директория.
Принтирането трябва да става на база случайно подаден елемент от цялата дървовидна йерархия на файловата система.
Нека принтирането става на с помощта на принтиращ обект посетител (който ако потрябва в бъдеще може да прави и повечко неща при посещение на файл :), а не с print функция във FileSystemEntity. Все пак в следната задача print функция e ок решение.

Тоест, ако нашият принтиращ обект:
1. Получи файл - просто да му принтира името
2. Получи директория - принтира името на директория и след това трябва да принтира имената на наследниците си
(ако в тях има директории те трябва да изпълнят отново точка 2.)

Нека ползваме следния пример за файлова система.
![image](https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/assets/49128895/443cee93-02b2-416d-bfc8-655dcdf78a53)

Ако някой ни подаде File 4. Принтираме File 4.
Ако някой ни подаде Directory 1, принтираме Directory 1, Directory 3, File 4, Directory 4, File 5.
Аналогично за останалите.

Т.е. нашият visitor ще изглежда по следния начин:
```c++
class FileSystemEntityVisitor {
public:
	void visitFile(File* f) {
		std::cout << f->getName();
	}

	void visitDirectory(Directory* d) {
		std::cout << d->getName();
		// then iterate through the children and start printing their names
		for (size_t i = 0; i < d->size; i++) {
			d->children[i]->accept(this); // each children migth be directory or file! so we pass the visitor
		}
	}
};
```
