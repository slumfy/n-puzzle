#ifndef State_h
# define State_h

class State
{
	public:
	vector <vector <int> >	map;
	State			*parent;
	vector <State>		*child;
	int	size;
	int	pound;
	int	total_pound;

	State(vector <vector <int> >new_map, int len, State *dad);
	int	manhattan();
	int	check_map();
	vector <vector <int> > move(t_move move);
	int	find0Position();
};


#endif
