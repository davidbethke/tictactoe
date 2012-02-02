#ifndef POSITION
#define POSITION
struct Position
{
	int row, col;
	Position(int r=0, int c=0);
	//Position();
	Position(const Position&);
	Position& operator=(const Position&);
	bool operator==(Position & other);
	bool operator!=(Position & other);
	Position  operator+(Position& other);
};
//myInc function prototypes
void acrossInc(Position&);
void downInc(Position&);
void diagInc(Position&);
void diagDec(Position&);
#endif
