#include <stdlib.h>

class cells{

	
private:
	int Coordx;
	int Coordy;
	int etat;
	int NextEtat;
public:
	int getCoordx(){return(Coordx);};
	int getCoordy(){return(Coordy);};
	int IsitAlive(){return (etat);};
	
	/*void Place(int x, int y);
	void Die(){etat = 0;};
	void nait();*/
};

int   main()
{
   cells ncell;

}
