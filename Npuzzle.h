#ifndef NPUZZLE_H
#define NPUZZLE_H


# include <iostream>
# include <cstdio>
# include <fstream>
# include <vector>
# include <string>
# include <sstream>
# include <list>
# include <vector>

extern int **g_done;

using namespace std;

typedef enum e_move
{
	UP = 0,
	DOWN,
	RIGHT,
	LEFT,
	NONE
}			t_move;


class State
{
	public:
	vector <vector <int> >	map;
	State *parent;
	vector <vector <vector <int> > > dads;
	vector <State>		child;

	int	size;
	int nb_move;
	int	pound;
	int	total_pound;
	t_move last_move;

	State();
	State(vector <vector <int> >new_map, int len, State* dads, t_move move);
	void	unravel(void);
	void	manhattan(vector <vector <int> > vecmap);
	void	heuristic(vector <vector <int> >vecmap);
	int		**create_end_map();
	int		**getEndMap();
	void	check_map();
	void	move(t_move move);
	int		find0Position(int x);
	int		findEndPos(int x);
	void	hasAllreadyHappened();
	void	create_child();
	void	print_taquin(void);
	void 	print_closed_list();
	void	show_solution(State *self);

	void	print_taquin(vector <vector <int> > tab);
	int		getInvCount();
	bool	isSolvable();
	bool	isTaquin();

};

bool	isSolvable(State puzzle);

class Lists
{
	public:
	list<State >		open_list;
	list<State >		closed_list;

	Lists();
	int		isInOList(State newState);
	void	addToOList(State newState);
	void	popOList();
	void	addToCList(State newState);
	int		in_closed_list(State state);
	void	astar(State first);
};


#endif
