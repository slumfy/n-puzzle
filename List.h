#ifndef LIST_H
# define LIST_H

#include <unistd.h>
#include <list>
#include "Taquin.h"
#include "State.h"


class Lists
{
	public:
	std::list<State >		open_list;
	std::list<State >		closed_list;

	Lists();
	int		isInOList(State newState);
	void	addToOList(State newState);
	void	popOList();
	void	addToCList(State newState);
	int		in_closed_list(State state);
	void	astar(State first);
};

#endif