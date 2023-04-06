#include <iostream>
#pragma warning(disable:4996)

using std::cout;
using std::endl;

class Account {
protected:
	char* accNum;
	int balance;

public:
	Account(const char* num, int bal) {
		accNum = new char[strlen(num) + 1];
		strcpy(accNum, num);
		balance = bal;
		
		cout << "Account()" << endl;
	}

	~Account() {
		delete[]accNum;
		cout << "~Account()" << endl;
	}
};

class KBAccount : public Account {
private: 
	int transLimit;

public:
	KBAccount(const char* num, int bal, int limit) : Account(num, bal) {
		cout << "KBAccount()" << endl;
		transLimit = limit;
	}
	
	void ShowData() const {
		cout << "KBAccount(" << accNum << ", " << balance << ", " << transLimit << ")" << endl;
		cout << endl;
	}

	~KBAccount() {
		cout << "~KBAccount()" << endl;
	}

};

class SHAccount : public Account {
private:
	char* name;

public:
	SHAccount(const char* num, int bal, const char* n) : Account(num, bal) {
		cout << "SHAccount()" << endl;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	void ShowData() const {
		cout << "SHAccount(" << accNum << ", " << balance << ", " << name << ")" << endl;
		cout << endl;
	}

	~SHAccount() {
		delete[]name;
		cout << "~SHAccount()" << endl;
	}
};

int main() {
	KBAccount kb("12345", 10000, 50000);
	kb.ShowData();

	SHAccount sh("3456-789", 100000, "TUKorea");
	sh.ShowData();
}