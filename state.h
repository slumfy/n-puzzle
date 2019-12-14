#ifndef State_h
# define State_h

class State
{
	public:
	Taquin	puzzle;
	State	*parent;
	State	**child;
	int	pound;
	int	total_pound;

	int	manhattan();
	int	check_map();
};


#endif
