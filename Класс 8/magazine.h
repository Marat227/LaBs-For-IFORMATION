#pragma once
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Object {
public:
	virtual void input() = 0;
	virtual void output() = 0;
	virtual void handleEvent(const tEvent& e) = 0;
};

class Print : public Object
{
protected:
	string name;
	string author;

public:
	Print();
	Print(string, string);
	Print(const Print&);

	string getName();
	void setName(string);
	string getAuthor();
	void setAuthor(string);

	void handleEvent(const tEvent& e) {
		if (e.eventWhat == eventMessage) {
			switch (e.command) {
			case c_getAttr:
				output();
			}
		}
	}

	void input() override {
		cin >> name;
		cin >> author;
	}
	void output() override {
		cout << "name: " << name << endl;
		cout << "author: " << author << endl;
	}

	Print& operator=(const Print&);
	friend ostream& operator<<(ostream&, const Print&);
	friend istream& operator>>(istream&, Print&);
};
