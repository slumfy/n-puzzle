#include "Taquin.h"

class State
{
	public:
	Taquin	puzzle;
	State	*parent;
	State	**child;
	int	pound;
	int	total_pound;

}
