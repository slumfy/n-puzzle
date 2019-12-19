#ifndef State_h
# define State_h

class State
{
	public:
	vector <vector <int> >	map;
	State			*parent;
	vector <State>		child;
	int	size;
	int	pound;
	int	total_pound;
	t_move last_move;

	State(vector <vector <int> >new_map, int len, State *dad, t_move move);
	void	manhattan();
	void	check_map();
	void	move(t_move move);
	int	find0Position();
	void	hasAllreadyHappened();
};


#endif
