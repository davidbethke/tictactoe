#ifndef GAMEPARAMETERS_H
#define	GAMEPARAMETERS_H	


struct GameParameters
{
	GameParameters(int r=3,int c=3, int rw=3,int np=2);
	~GameParameters(void);
	const int NUMROWS;
	const int NUMCOLS;
	const int INAROWTOWIN;
	const int NUMPLAYERS;
	//const int NUMSEARCHFUNCS;
	int NUMBEROFPLAYS;
	int NUMBEROFWINS;
	int NUMBEROFXWINS;
	int NUMBEROFOWINS;
	
	//Player players**; //list of players
	//int *playerOrder; // order of players
	//void(**searchFunctionArr)(Position&); //functions to inc and find winner

};

#endif
