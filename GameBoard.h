#ifndef GAMEBOARD
#define GAMEBOARD
#include "GameParameters.h"
#include "GameSquare.h"
#include "GameResults.h"
#include "Direction.h"
#include "Position.h"
#include <string>
#include "Player.h"
#include "GridT.h"

class GameBoard
{
	friend bool Player::move(GameBoard *); //makes move a little read nicer
public:
	
	GameBoard(GameParameters& gP);
	~GameBoard(void);
	bool markBoard(int,int,Mark);
	bool checkFull(void) const;
	bool checkAllGeneric(void);
	void clearBoard(void);
	void displayBoard(std::string n="") const;
	
private:

	static const int NUMBEROFFUNCS=4;// funcs for inc, across, down, diag1, diag2
	GameParameters& gameParams; 
#ifdef NEWGAMEBOARD
	GridT<GameSquare> gameBoard;
#endif //NEWGAMEBOARD
#ifdef OLDGAMEBOARD
	GameSquare **gameBoard;
#endif //OLDGAMEBOARD
	void(**searchFunctionArr)(Position&);
	bool searchGeneric(Position,void(*fun)(Position&));
	bool inBounds(const Position &) const;

};


#endif

