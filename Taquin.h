#ifndef TAQUIN_H
# define TAQUIN_H

# include <iostream>
# include <cstdio>
# include <fstream>
# include <vector>
# include <string>
# include <sstream>

using namespace std;

typedef enum e_move
{
	UP = 0,
	DOWN,
	RIGHT,
	LEFT,
	NONE
}			t_move;

class Taquin
{
	public:
	int _len; 
	vector< vector <int> > tab;

	Taquin();
	Taquin(int n, vector<vector<int> > tabl);
	~Taquin();
	void	move(int *troue, int *tuile);
	void	print_taquin(void);
	int		getInvCount();
	void	move(t_move move);
	Taquin new_move(t_move move);
	int 	find0Position();
	int		findXPosition();
	int		findYPosition();
	bool	isSolvable();
	bool	isTaquin();
};

bool	isSolvable(Taquin puzzle);

#endif