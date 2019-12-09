#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Taquin
{
	public:
	int _len; 
	vector< vector <int> > tab;

	Taquin();
	Taquin(int n);
	~Taquin();
	void	move(int *troue, int *tuile);
	void	print_taquin(void);
	int		getInvCount();
	int		findXPosition();
	bool	isSolvable();
};

bool	isSolvable(Taquin puzzle);
