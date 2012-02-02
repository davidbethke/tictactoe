
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
	bool isBlank() const;
	bool hasValue() const;
	bool setValue(Mark::Values);
	Mark::Values getValue() const;
	std::string getSValue() const;

private:
	Mark::Values mark;
};
#endif

