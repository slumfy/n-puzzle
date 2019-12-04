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

	void	move(int *troue, int *tuile);
};

bool	isSolvable(Taquin puzzle);
