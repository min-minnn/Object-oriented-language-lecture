#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using std::cout;
using std::endl;

class Student {
private:
	int id;
	char* name;
	char* major;

public:
	Student(int i, const char* n, const char* m) {
		id = i;
		name = new char[strlen(n) + 1];
		major = new char[strlen(m) + 1];

		strcpy(name, n);
		strcpy(major, m);
	}
	
	Student(const Student& S) {
		id = S.id;
		name = new char[strlen(S.name) + 1];
		major = new char[strlen(S.major) + 1];

		strcpy(name, S.name);
		strcpy(major, S.major);
	}

	~Student() {
		delete[]name;
		delete[]major;
	}

	void ShowData() {
		cout << "(" << id << ", " << name << ", " << major << ")" << endl;
	}
};

int main() {
	Student Hong(1234, "È«±æµ¿", "Computer Engineering");
	Student Hong2(Hong);

	cout << "¿ø·¡ °´Ã¼ = ";
	Hong.ShowData();
	cout << "º¹»ç °´Ã¼ = ";
	Hong2.ShowData();
}