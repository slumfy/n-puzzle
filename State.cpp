#include "Taquin.h"
#include "State.h"
#include <unistd.h>


State::State()
{
	nb_move = 0;
	pound = 0;
	total_pound = 0;
	last_move = (t_move)NONE;
	size = 0;
	parent = NULL;
}

State::State(vector <vector <int> > new_map, int len, State *dad, t_move lst_move)
{
	pound = 0;
	last_move = lst_move;
	map = new_map;
	size = len;
	parent = dad;

	manhattan(map);
	total_pound = 0;
	if (!parent)
		dads.push_back(new_map);
	if (pound == 0)
	{
		if (parent)
		{
			dads = parent->dads;
			dads.push_back(new_map);
			nb_move = parent->nb_move + 1;
		}
		return ;
	}
	if (parent && pound != -1)
	{
		dads = parent->dads;
		dads.push_back(new_map);
		nb_move = parent->nb_move + 1;
		total_pound = pound + nb_move;
	}
	else if (pound == -1)
	{
		total_pound = -1;
		nb_move = -1;
	}
	else
	{
		nb_move = 0;
		total_pound = 0;
	}
	// printf("pound : %d\ntotal_pound : %d\n",pound, total_pound);
}

void	State::unravel(void)
{
	// cout << "coucou";
	for (int k = 0; k < (int)dads.size(); k++)
	{
		for(int i = 0; i < (int)dads[k].size();i++)
		{
			for (int j = 0; j < (int)dads[k][i].size(); j++)
				cout << dads[k][i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";

}

void State::move(t_move move)
{
	vector <vector <int> > res = map;
	int i;
	int j;
	int pos;
	int tmp;

	pos = find0Position();
	j = pos % size;
	i = (pos - j) / size;
	if (move == UP && i != 0 && last_move != DOWN)
	{
		tmp = res[i][j];
		res[i][j] = map[i - 1][j];
		res[i - 1][j] = tmp;
		State new_map(res, size, this, UP);
		child.push_back(new_map);
	}
	else if (move == DOWN && i != size - 1 && last_move != UP)
	{
		tmp = res[i][j];
		res[i][j] = res[i + 1][j];
		res[i + 1][j] = tmp;
		State new_map(res, size, this, DOWN);
		child.push_back(new_map);
	}
	else if (move == RIGHT && j != size - 1 && last_move != LEFT)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j + 1];
		res[i][j + 1] = tmp;
		State new_map(res, size, this, RIGHT);
		child.push_back(new_map);
	}
	else if (move == LEFT && j != 0 && last_move != RIGHT)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j - 1];
		res[i][j - 1] = tmp;
		State new_map(res, size, this, LEFT);
		child.push_back(new_map);
	}
}

void	State::create_child()
{
	for (int i = 0; i < 4; i++)
	{
		move((t_move)i);
	}
}

void	State::print_taquin()
{
	for(int i = 0; i < (int)map.size();i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int State::find0Position()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (map[i][j] == 0)
				return (size * i + j);
	return (-1);
}

void	State::manhattan(vector <vector <int> >vecmap)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (vecmap[i][j] != 0)
			{
				pound += abs(i - (vecmap[i][j] - 1) / size);
				pound += abs(j - (vecmap[i][j] - 1) % size);
			}
		}
	}
}

void	State::check_map()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0;j < size; j++)
		if(map[i][j] != 0){
			if(map[i][j] != i * size + (j + 1)){
				pound++;}}
	}
}
