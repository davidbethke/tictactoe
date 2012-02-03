
#ifndef GAMESQUARE
#define GAMESQUARE
#include "Mark.h"
#include <string>
using namespace std;
class GameSquare
{
public:
	GameSquare(void); 
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

