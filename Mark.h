#ifndef MARK_H
#define MARK_H

struct Mark
{
	enum Values{
		BLANK,
		OH,
		EX,
		W
	};

};
char * markValues[]={"*","O","X","W"};
#endif