#ifndef LIST_H
# define LIST_H

#include "Taquin.h"
#include "State.h"


class List
{
	public:
	vector <State >		open_list;
	vector <State >		closed_list;

	List();
	int		isInOList(State newState);
	void	addToOList(State newState);
	void	popOList();
	void	addToCList(State newState);
	int		in_closed_list(State state);
	void	astar(State first);
};

#endif