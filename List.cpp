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
	pound = newState.pound;
	for (vector<State>::iterator it = open_list.begin(); it != open_list.end(); ++it) 
	{
		if (it->pound >= pound)
		{
			open_list.insert(it, newState);
			break ;
		}
	}
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
	// int i = 0;

	addToOList(first);
	while (open_list.size())
	{
		current = open_list[0];
		printf("pound : %d nb_coups : %d size : %d\n", current.pound, current.nb_move, current.size);
		current.print_taquin();
		// i = 0;
		// printf("OPEN LIST : size = %d\n", (int)open_list.size());
		// while (i < (int)open_list.size())
		// {
		// 	open_list[i].print_taquin();
		// 	printf("\n");
		// 	i++;
		// }
		// printf("CLOSED LIST : size = %d\n", (int)closed_list.size());
		// i = 0;
		// while (i < (int)closed_list.size())
		// {
		// 	closed_list[i].print_taquin();
		// 	printf("\n");
		// 	i++;
		// }
		// usleep(1000000);
		popOList();
		if (current.pound== 0)
		{
			printf("finished in %d moves\n", current.nb_move);
			return ;
		}
		current.create_child();
		for (vector<State>::iterator it = current.child.begin(); it != current.child.end(); it++)
		{
			if (!in_closed_list(*it))
				addToOList(*it);
			else
				printf("sorry\n");
		}
		addToCList(current);
	}
}


/*  Fonction cheminPlusCourt(g:Graphe, objectif:Nœud, depart:Nœud)
       closedList = File()
       openList = FilePrioritaire(comparateur=compare2Noeuds)
       openList.ajouter(depart)
       tant que openList n'est pas vide
           u = openList.depiler()
           si u.x == objectif.x et u.y == objectif.y
               reconstituerChemin(u)
               terminer le programme
           pour chaque voisin v de u dans g
               si v existe dans closedList ou si v existe dans openList avec un cout inférieur
                    neRienFaire()
               sinon
                    v.cout = u.cout +1 
                    v.heuristique = v.cout + distance([v.x, v.y], [objectif.x, objectif.y])
                    openList.ajouter(v)
           closedList.ajouter(u)
       terminer le programme (avec erreur)
*/