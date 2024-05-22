// The whole example is for demo purpose
// treat it like a pseudo code!
#include <iostream>
#include <string> // NOT ALLOWED IN THE COURSE !

class FileSystemEntityVisitor;

class FileSystemEntity {
	std::string name;
public:
	FileSystemEntity(std::string name) : name(name) {}
	const std::string& getName() const {
		return name;
	}

	virtual void accept(FileSystemEntityVisitor* visitor) = 0;

	virtual ~FileSystemEntity() = 0;
};
FileSystemEntity::~FileSystemEntity() {}

class File : public FileSystemEntity {
public:
	void accept(FileSystemEntityVisitor* visitor) override {
		visitor->visitFile(this);
	}
};

class Directory : public FileSystemEntity {
public:
	FileSystemEntity** children;
	size_t size;
	// !!!not good encapsulation
	// !!!missing stuff here
	void accept(FileSystemEntityVisitor* visitor) override {
		visitor->visitDirectory(this);
	}
};

class FileSystemEntityVisitor {
public:
	void visitFile(File* f) {
		std::cout << f->getName();
	}

	void visitDirectory(Directory* d) {
		std::cout << d->getName();
		// then iterate through the children and start printing their names
		for (size_t i = 0; i < d->size; i++) {
			d->children[i]->accept(this);
		}
	}
};

int main() { }