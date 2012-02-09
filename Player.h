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
	void setName(std::string);
	void setMark(Mark::Values);
	Mark::Values getMark();
	std::string getName();
	bool move(int, int, GameBoard*);
private:
	std::string name;
	Mark::Values myMark;
	void (*myMove)(int &, int &, const int &, const int &);
};

#endif //PLAYER_H