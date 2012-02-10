
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
	void setValue(Mark);
	Mark getValue() const;
	std::string getSValue() const;

private:
	Mark mark;
};
#endif

