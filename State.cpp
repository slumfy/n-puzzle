#include "Taquin.h"
#include "State.h"
#include <unistd.h>

State::State(vector <vector <int> > new_map, int len, State *dad, t_move lst_move)
{
	pound = 0;
	last_move = lst_move;
	map = new_map;
	size = len;
	parent = dad;
	total_pound = 0;

	if (parent)
		closedList = parent->closedList;
	hasAllreadyHappened();
	if (pound == -1)
		return ;
	closedList.push_back(new_map);
	// print_closed_list();
	if (parent)
		parent->closedList = closedList;
	// usleep(500000);
	manhattan(map);
	if (parent && pound != -1)
		total_pound = parent->total_pound + parent->pound;
	else if (pound == -1)
		total_pound = -1;
	else
		total_pound = 0;
	printf("pound : %d\ntotal_pound : %d\n",pound,  total_pound);
}

void State::print_closed_list()
{
	for (int k = 0; k < (int)closedList.size(); k++)
	{
		printf("list %d \n", k);
		for(int i = 0; i < (int)closedList[k].size();i++)
		{
			for (int j = 0; j < (int)closedList[k][i].size(); j++)
				cout << closedList[k][i][j] << " ";
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

	if (pound == 0)
		return ;
	pos = find0Position();
	j = pos % size;
	i = (pos - j) / size;
	if (move == UP && i != 0 && last_move != DOWN)
	{
		tmp = res[i][j];
		res[i][j] = map[i - 1][j];
		res[i - 1][j] = tmp;
		State new_map(res, size, this, UP);
		if (new_map.pound == -1)
		{
			printf("bouuucle\n");
			return ;
		}
		printf("move UP\n");
		print_taquin();
		printf("\n");
		new_map.print_taquin();
		child.push_back(new_map);
	}
	else if (move == DOWN && i != size - 1 && last_move != UP)
	{
		tmp = res[i][j];
		res[i][j] = res[i + 1][j];
		res[i + 1][j] = tmp;
		State new_map(res, size, this, DOWN);
		if (new_map.pound == -1)
		{
			printf("bouuucle\n");
			return ;
		}
		printf("move DOWN\n");
		print_taquin();
		printf("\n");
		new_map.print_taquin();
		child.push_back(new_map);
	}
	else if (move == RIGHT && j != size - 1 && last_move != LEFT)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j + 1];
		res[i][j + 1] = tmp;
		State new_map(res, size, this, RIGHT);
		if (new_map.pound == -1)
		{
			printf("bouuucle\n");
			return ;
		}
		printf("move RIGHT\n");
		print_taquin();
		printf("\n");
		new_map.print_taquin();
		child.push_back(new_map);
	}
	else if (move == LEFT && j != 0 && last_move != RIGHT)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j - 1];
		res[i][j - 1] = tmp;
		State new_map(res, size, this, LEFT);
		if (new_map.pound == -1)
		{
			printf("bouuucle\n");
			return ;
		}
		printf("move LEFT\n");
		print_taquin();
		printf("\n");
		new_map.print_taquin();
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

void	State::hasAllreadyHappened()
{
	int len;

	len = closedList.size();
	for(int i = 0; i < (int)len;i++)
	{
		if (map == closedList[i])
		{
			pound = -1;
			printf("stoooop\n");
			return;
		}
	}

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
