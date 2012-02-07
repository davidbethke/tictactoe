#ifndef GAMEBOARD
#define GAMEBOARD
#include "GameParameters.h"
#include "GameSquare.h"
#include "GameResults.h"

#include "Direction.h"
#include "Position.h"
#include <string>

class GameBoard
{
public:
	
	GameBoard(GameParameters& gP=GameParameters());
	~GameBoard(void);
	bool markBoard(int,int,Mark::Values);
	bool checkFull(void) const;
	bool checkAllGeneric(void);
	void clearBoard(void);
	void displayBoard(std::string n="") const;
	
private:
	static const int NUMBEROFFUNCS=4;// funcs for inc, across, down, diag1, diag2
	GameParameters gameParams;
	GameSquare **gameBoard;
	void(**searchFunctionArr)(Position&);
	bool searchGeneric(Position,void(*fun)(Position&));
	bool inBounds(const Position &) const;

};


#endif

