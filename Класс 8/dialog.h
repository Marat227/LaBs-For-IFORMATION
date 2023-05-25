#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector {
protected:
	int endState;
public:
	Dialog();
	~Dialog() {};
	void getEvent(tEvent& event);
	int execute();
	void handleEvent(tEvent& event);
	void clearEvent(tEvent& event);
	int valid();
	void endExec();
};



Dialog::Dialog() : Vector() {
	endState = 0;
}
void Dialog::getEvent(tEvent& event) {
	string opInt = "+-szqm";
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];
	if (opInt.find(code) >= 0) {
		event.eventWhat = eventMessage;
		switch (code) {
		case 'm':
			event.command = c_makeGroup;
			break;
		case '+':
			event.command = c_addObj;
			break;
		case '-':
			event.command = c_delObj;
			break;
		case 's':
			event.command = c_showGroup;
			break;
		case 'z':
			event.command = c_getAttr;
			break;
		case 'q':
			event.command = c_quit;
			break;
		}
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.param = A;
		}
	}
	else event.eventWhat = eventNothing;
}

int Dialog::execute() {
	tEvent event;
	do {
		endState = 0;
		getEvent(event);
		handleEvent(event);
	} while (!valid());
	return endState;
}

int Dialog::valid() {
	if (endState == 0) return 0;
	else return 1;
}

void Dialog::clearEvent(tEvent& event) {
	event.eventWhat = eventNothing;
}

void Dialog::endExec() {
	endState = 0;
}

void Dialog::handleEvent(tEvent& event) {
	if (event.eventWhat == eventMessage) {
		switch (event.command) {
		case c_makeGroup:
			size = event.param;
			vector = new Object * [size];
			curr = 0;
			clearEvent(event);
			break;

		case c_addObj:
			add();
			clearEvent(event);
			break;
		case c_delObj:
			del();
			break;
		case c_showGroup:
			show();
			clearEvent(event);
			break;
		case c_quit:
			endExec();
			clearEvent(event);
			break;

		default:
			Vector::handleEvent(event);
		}
	}
}

