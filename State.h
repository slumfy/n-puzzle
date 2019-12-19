#ifndef State_h
# define State_h

#include <vector>

class State
{
	public:
	vector <vector <int> >	map;
	State			*parent;
	vector <State>		child;

	int	size;
	int nb_move;
	int	pound;
	int	total_pound;
	t_move last_move;

	State();
	State(vector <vector <int> >new_map, int len, State *dad, t_move move);
	void	manhattan(vector <vector <int> > vecmap);
	void	check_map();
	void	move(t_move move);
	int		find0Position();
	void	hasAllreadyHappened();
	void	create_child();
	void	astar();
	void	print_taquin(void);
	void 	print_closed_list();
	void	show_solution(State *self);
};


#endif
