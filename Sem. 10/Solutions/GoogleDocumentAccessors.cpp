#include <iostream>
#include "MyString/MyString.h"

// Google docs
struct Comment {
	MyString text;
	MyString createdBy;
};

class GoogleDocsDocument {
private:
	MyString data;
    Comment comments[30];
    size_t count = 0;

public:
	const MyString& getData() const {
		return data;
	}

	void addComment(const Comment& comment) {
        if(count == 30) {
            return;
        }

        comments[count++] = comment;
	}

	void addComment(Comment&& comment) {
        if(count == 30) {
            return;
        }

        comments[count++] = std::move(comment);
	}

	void setText(const MyString& text) {
		data = text;
	}

	void setText(MyString&& text) {
		data = std::move(text);
	}
};

class Viewer {
public:
	void viewDocument(const GoogleDocsDocument& doc) const {
		std::cout << doc.getData();
	}
};

class Commenter : public Viewer {
	MyString userName;
public:
	void addComment(GoogleDocsDocument& doc) {
		doc.addComment({ "ada", userName });
	}
};

class Editor : public Commenter {
public:
	void edit(GoogleDocsDocument& doc) {
		doc.setText("wleeeeeeeeeee");
	}
};