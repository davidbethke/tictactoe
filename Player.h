#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Mark.h"
#include "PlayerHelper.h"

class GameBoard;
class Player
{
public:
	Player(std::string n="Computer"); //default Player is Computer
	~Player(void);
	bool move(int, int, GameBoard*);
	bool move(GameBoard*); // Im a friend of GameBoard
	void setName(std::string);
	void setMark(Mark);
	Mark getMark();
	std::string getName();
	
private:
	std::string name;
	Mark myMark;
	void (*myMove)(int &, int &, const int &, const int &);
};

#endif //PLAYER_H