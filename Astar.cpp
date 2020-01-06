#include "Taquin.h"
#include "State.h"
#include "List.h"

void	State::astar()
{
	State *self = this;
	while(1)
	{
		if (self->pound == 0)
			break;
		if (self->child.empty())
			self->create_child();
		int length = (int)self->child.size();
		int diff = 0;
		//cout << length << "\n";
		for (int idx = 0; idx < length;idx++)
		{
			if (self->child[idx].pound == 0)
			{
				self = &self->child[idx];
				break ;
			}
		}
		if (self->pound == 0)
			break ;
		State *low_pound = &self->child[0];
		for (int idx = 0; idx < length;idx++)
			if (self->child[idx].pound != -1)
				low_pound = &self->child[idx];
		for (int idx = 0; idx < length;idx++)
		{
			if (self->child[idx].pound == -1)
				diff++;
			if (self->child[idx].pound != -1 && self->child[idx].pound < low_pound->pound)
			{
				low_pound = &self->child[idx];
			}
		}
		if (diff == length)
		{
			self->pound = -1;
			self = self->parent;
		}
		else
		self = low_pound;
	}
	show_solution(self);
}


void	State::show_solution(State *self)
{
	int nb_move = -1;
	vector <State*> solution;
	for (State *dad = self; dad != NULL; dad = dad->parent)
	{
		solution.insert(solution.begin(), dad);
		nb_move++;
	}

	cout << "nombre de move: " << nb_move << "\n";
}

