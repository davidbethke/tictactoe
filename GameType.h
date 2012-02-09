#ifndef GAMETYPE_H
#define GAMETYPE_H

struct GameParameters; //forward declaration
class Player;			//forward declaration
class GameType
{
public:
	
	GameType(GameParameters& gP); //default GameParameters if none specified
	~GameType(void);
	void play(void);
private:
	GameParameters &gameParams; // can I declare a reference here, pointer instead maybe, let's me forward declare above
	void displayGameResults() const;
	void displayGameStats() const;
	
};

//helper
void swapPlayerIndex(int &,int &);
void setPlayerOrder(int &, int&);
void setPlayerNames(Player **);
#endif