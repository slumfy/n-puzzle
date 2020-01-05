#include "List.h"
#include <unistd.h>

List::List()
{
}

void List::addToOList(State newState)
{
	int pound;

	if (open_list.size() == 0)
	{
		open_list.push_back(newState);
		return ;
	}
	pound = newState.total_pound;
	for (vector<State>::iterator it = open_list.begin(); it != open_list.end(); it++) 
	{
		if (it->total_pound >= pound)
		{
			open_list.insert(it, newState);
			return ;
		}
	}
	open_list.insert(open_list.end(), newState);
}

int List::isInOList(State newState)
{
	if (open_list.size() == 0)
		return (0);
	for (vector<State>::iterator it = open_list.begin(); it != open_list.end(); ++it) 
	{
		if(it->map == newState.map && it->nb_move <= newState.nb_move)
			return (1);
	}
	if(open_list.end()->map == newState.map && open_list.end()->nb_move <= newState.nb_move)
		return (1);
	return (0);
}

void List::addToCList(State newState)
{
	for (vector<State>::iterator it = closed_list.begin(); it != closed_list.end(); ++it) 
		if (it->map == newState.map)
			return ;
	closed_list.push_back(newState);
}

void List::popOList()
{
	open_list.erase(open_list.begin());
}

int List::in_closed_list(State state)
{
	for (vector<State>::iterator it = closed_list.begin(); it != closed_list.end(); ++it) 
		if (it->map == state.map)
			return (1);
	return (0);
}


void List::astar(State first)
{
	State current;
	// static int min_pound = 100000;
	int i;

	addToOList(first);
	while (open_list.size())
	{
		current = open_list[0];
		// printf("------ CURENT --------\n");
		// printf("pound : %d nb_coups : %d total_pound : %d\n", current.pound, current.nb_move, current.total_pound);
		// current.print_taquin();
		popOList();
		if (current.pound == 0)
		{
			printf("finished in %d moves\n", current.nb_move);
			current.unravel();
			return ;
		}
		current.create_child();
		i = 0;
		for (vector<State>::iterator it = current.child.begin(); it != current.child.end(); it++)
		{
			if (!(in_closed_list(*it) || isInOList(*it)))
			{
				addToOList(*it);
				i++;
			}
		}
		addToCList(current);
		// i = 0;
		printf("OPEN LIST : size = %d, increase : %d, pound %d, total_pound %d\n", (int)open_list.size(), i - 1, current.pound, current.total_pound);
		// while (i < (int)open_list.size())
		// {
		// 	printf("pound : %d nb_coups : %d total_pound : %d\n", open_list[i].pound, open_list[i].nb_move, open_list[i].total_pound);
		// 	open_list[i].print_taquin();
		// 	printf("\n");
		// 	i++;
		// }
		printf("CLOSED LIST : size = %d\n", (int)closed_list.size());
		// i = 0;
		// while (i < (int)closed_list.size())
		// {
		// 	printf("pound : %d nb_coups : %d total_pound : %d\n", closed_list[i].pound, closed_list[i].nb_move, closed_list[i].total_pound);
		// 	closed_list[i].print_taquin();
		// 	printf("\n");
		// 	i++;
		// }
		// printf("------ END CURENT --------\n");
		//  usleep(500000);
	}
}