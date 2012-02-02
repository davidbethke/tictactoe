
#include "Mark.h"
#include <string>
#ifndef GAMESQUARE
#define GAMESQUARE
using namespace std;
class GameSquare
{
public:
	GameSquare(void); // need to pass a Mark, typedef enumType Mark
	~GameSquare(void);
	bool isBlank();
	bool hasValue();
	bool setValue(Mark::Values);
	Mark::Values getValue();
	std::string getSValue();

private:
	Mark::Values mark;
};
#endif

