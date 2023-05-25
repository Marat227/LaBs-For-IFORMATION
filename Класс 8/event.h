#pragma once

const int eventNothing = 0;
const int eventMessage = 100;
const int c_addObj = 1;
const int c_delObj = 2;
const int c_getAttr = 3;
const int c_showGroup = 4;
const int c_makeGroup = 6;
const int c_quit = 101;

struct tEvent {
	int eventWhat;
	union {
		int command;
		struct {
			int message;
			int param;
		};
	};
};
