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
	std::vector< std::vector <int> > tab;

	Taquin();
	Taquin(int n);
	~Taquin();
	void	move(int *troue, int *tuile);
	void	print_taquin(void);
	int		getInvCount();
	int		findXPosition();
	int		findYPosition();
	bool	isSolvable();
	bool	isTaquin();
};

bool	isSolvable(Taquin puzzle);
