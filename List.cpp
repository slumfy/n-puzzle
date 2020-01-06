#include "List.h"
#include <unistd.h>

Lists::Lists()
{
}

int compare(State a, State b)
{
	if (a.pound > b.pound)
		return (1);
	else if (a.pound < b.pound)
		return (-1);
	else
	{
		if (a.total_pound > b.total_pound)
			return (1);
		else if (a.total_pound < b.total_pound)
			return (-1);
		else
			return (0);
	}
}

void Lists::addToOList(State newState)
{
	int dicho;
	int a = 0;
	int b = open_list.size();
	int i;

	if (b == 0)
	{
		open_list.push_back(newState);
		return ;
	}
	if (compare(open_list.front(), newState) <= 0)
	{
		open_list.push_front(newState);	
		return ;
	}
	if (compare(open_list.back(), newState) >= 0)
	{
		open_list.push_back(newState);
		return ;
	}

	list<State>::iterator ite = open_list.begin();
	
	dicho = (b + a) / 2;
	while (b - a > 1)
	{
		dicho = (b + a) / 2;
		i = 0;
		ite = open_list.begin();
		while (i++ < dicho)
			ite++;
		if (compare(*(ite), newState) < 0)
			b = dicho;
		else if	(compare(*(ite), newState) > 0)
			a = dicho;
		else
		{
			open_list.insert(ite, newState);
			return ;
		}
	}
	if (compare(*(ite), newState) < 0)
		open_list.insert((ite), newState);
	else if	(compare(*(ite), newState) > 0)
		open_list.insert(++ite, newState);
}

int Lists::isInOList(State newState)
{
	if (open_list.size() == 0)
		return (0);
	for (list<State>::iterator it = open_list.begin(); it != open_list.end(); ++it) 
	{
		if (it->pound == newState.pound)
			if(it->map == newState.map && it->nb_move <= newState.nb_move)
				return (1);
	}
	if(open_list.end()->map == newState.map && open_list.end()->nb_move <= newState.nb_move)
		return (1);
	return (0);
}

void Lists::addToCList(State newState)
{
	for (list<State>::iterator it = closed_list.begin(); it != closed_list.end(); ++it) 
		if (it->pound == newState.pound)
			if (it->map == newState.map)
				return ;
	closed_list.push_back(newState);
}

void Lists::popOList()
{
	open_list.pop_back();
}

int Lists::in_closed_list(State state)
{
	for (list<State>::iterator it = closed_list.begin(); it != closed_list.end(); ++it) 
		if (it->pound == state.pound)
			if (it->map == state.map)
				return (1);
	return (0);
}


void Lists::astar(State first)
{
	State current;
	// static int min_pound = 100000;
	int i;

	addToOList(first);
	while (open_list.size())
	{
		current = open_list.back();
		// printf("------ CURENT --------\n");
		// printf("pound : %d nb_coups : %d total_pound : %d\n", current.pound, current.nb_move, current.total_pound);
		// current.print_taquin();
		popOList();
		if (current.pound == 0)
		{
			current.unravel();
			printf("finished in %d moves\n", current.nb_move);
			return ;
		}
		current.create_child();
		i = 0;
		for (vector<State>::iterator it = current.child.begin(); it != current.child.end(); it++)
		{
			if (!in_closed_list(*it))
			{
				addToOList(*it);
				i++;
			}
		}
		addToCList(current);
		// printf("OPEN LIST : size = %d, increase : %2d, pound %2d, total_pound %3d\n", (int)open_list.size(), i - 1, current.pound, current.total_pound);
		// i = 0;
		// while (i < (int)open_list.size())
		// {
		 	// printf("pound : %d nb_coups : %d total_pound : %d\n", open_list[i].pound, open_list[i].nb_move, open_list[i].total_pound);
			// open_list[i].print_taquin();
			// printf("\n");
		// 	i++;
		// }
		// printf("CLOSED LIST : size = %d\n", (int)closed_list.size());
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