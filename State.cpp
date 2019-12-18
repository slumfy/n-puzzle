#include "Taquin.h"
#include "State.h"


State::State(vector <vector <int> > new_map, int len, State *dad)
{
	map = new_map;
	size = len;
	parent = dad;
	pound = manhattan();
	if (parent)
		total_pound += parent->pound;
}

vector <vector <int> > State::move(t_move move)
{
	vector <vector <int> > res = map;
	int i;
	int j;
	int pos;
	int tmp;

	pos = find0Position();
	j = pos % size;
	i = (pos - j) / size;
	if (move == UP && i != 0)
	{
		tmp = res[i][j];
		res[i][j] = map[i - 1][j];
		res[i - 1][j] = tmp;
	}
	else if (move == DOWN && i != size - 1)
	{
		tmp = res[i][j];
		res[i][j] = res[i + 1][j];
		res[i + 1][j] = tmp;
	}
	else if (move == RIGHT && j != size - 1)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j + 1];
		res[i][j + 1] = tmp;
	}
	else if (move == LEFT && j != 0)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j - 1];
		res[i][j - 1] = tmp;
	}
	return (res);
}

int State::find0Position()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (map[i][j] == 0)
				return (size * i + j);
	return (-1);
}

int	State::manhattan()
{
	int	pound = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] != 0)
				{
				pound += abs(i - (map[i][j] - 1) / size);
			cout  << "valuei " << pound << "\t";
				pound += abs(j - (map[i][j] - 1) % size);
			cout  << "valuej " << pound << "\n";
				}
}
	}
	cout << "manhattan pound " << pound << "\n";
	return (pound);
}

int	State::check_map()
{
	int pound = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0;j < size; j++)
		if(map[i][j] != 0){
			if(map[i][j] != i * size + (j + 1)){
				pound++;}}
	}
	cout << "map pound " << pound << "\n";
	return (pound);
}
