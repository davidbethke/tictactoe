
#include "GameSquare.h"
#include "Direction.h"
#include "Position.h"
#ifndef GAMEBOARD
#define GAMEBOARD
class GameBoard
{
public:
	GameBoard(int,int,int,int);
	GameBoard(void);
	~GameBoard(void);
	bool markBoard(int,int,Mark::Values);
	bool checkFull(void);
	//bool checkAll(Mark::Values &);
	//bool checkAllNew(Mark::Values &);
	bool checkAllGeneric(Mark::Values &);
	//bool check(Direction, Mark::Values &);
	void clearBoard(void);
	void displayBoard();
	//test
	bool checkBlank();
	int getMarks();
private:
	const int NUMOFROWS;
	const int NUMOFCOLS;
	const int INAROWTOWIN;
	const int NUMBEROFFUNCS;
	int numberOfMarks;
	GameSquare **gameBoard;
	void(**searchFunctionArr)(Position&);
	//utility functions
	//bool checkAcross(Mark::Values&);
	//bool checkDown(Mark::Values&);
	//bool checkDiag(Mark::Values&);
	//bool searchBunch(Position,Position,int,void(*inc)(Position&),void(*fun)(Position&),Mark::Values&);
	//bool searchRange(Position, Position,int,void(*fun)(Position&),Mark::Values&);
	bool searchGeneric(Position,int,void(*fun)(Position&),Mark::Values&);
	bool inBounds(const Position &);
	int max(int,int);

};


#endif

