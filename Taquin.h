#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <set>
#include <queue>
#include <map>
#include <utility>
#include <list>
#include <functional>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <limits>


using namespace std;

typedef enum e_move
{
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
}			t_move;

class Taquin
{
	public:
	int _len; 
	vector< vector <int> > tab;
	vector <int> flattab;

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

void	astar(vector <int>  initial_state, list<vector <int> > *best_path, int *nbiter, int len);
int	distance(map<vector <int>,int> dist, vector <int>state);
int	manhattan(vector <int> map,int len);
int	check_map(vector <int> map);



