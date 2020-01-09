#include "Npuzzle.h"

int find0Position(int x, State first)
{
	for (int i = 0; i < first.size; i++)
		for (int j = 0; j < first.size; j++)
			if (g_done[i][j] == x)
				return (first.size * i + j);
	return (-1);
}

void makeMove(int move, State first)
{
	int i;
	int j;
	int pos;
	int tmp;

	pos = find0Position(0, first);
	j = pos % first.size;
	i = (pos - j) / first.size;
	if (move == 0 && i != 0)
	{
		tmp = g_done[i][j];
		g_done[i][j] = g_done[i - 1][j];
		g_done[i - 1][j] = tmp;
	}
	else if (move == 1 && i != first.size - 1)
	{
		tmp = g_done[i][j];
		g_done[i][j] = g_done[i + 1][j];
		g_done[i + 1][j] = tmp;
	}
	else if (move == 2 && j != first.size - 1)
	{
		tmp = g_done[i][j];
		g_done[i][j] = g_done[i][j + 1];
		g_done[i][j + 1] = tmp;
	}
	else if (move == 3 && j != 0)
	{
		tmp = g_done[i][j];
		g_done[i][j] = g_done[i][j - 1];
		g_done[i][j - 1] = tmp;
	}
}

int	is_number(string str)
{
	string::const_iterator tmp = str.begin();
	while(tmp != str.end())
	{
		if (!isdigit(*tmp))
			return (0);
		tmp++;
	}
	return (1);
}

int	is_comment(string str)
{
	int n = str.length();
	char array[n + 1];
	strcpy(array, str.c_str());
	for (int i = 0; i < n; i++)
	{
		if (array[i] != '#' && !isdigit(array[i]) && !isspace(array[i]))
			return (2);
		if (i == 0 && array[i] == '#')
			return (1);
		if (atoi(array) != 0)
			return (0);
	}
	return(1);
}

int	get_puzzle_size(State *puzzle, fstream *file)
{
	string line;
	int err;
	while(getline(*file,line))
	{
		err = is_comment(line);
		if (err == 1)
			continue ;
		if (err == 2)
			return (1);
		if (err == 0)
		{
			string comment;
			stringstream iss(line);
			while(iss >> comment)
			{
			static int i = 0;
			i++;
				if (is_comment(comment) == 2)
					return (1);
				if (puzzle->size == 0)
				{
					puzzle->size = atoi(comment.c_str());
				}
				else
					return (1);
			}
			return (0);
		}
	}
	return (1);
}

int		manage_arg(int ac,char **arg)
{
	for (int i = 1; i < ac; i++)
	{
		if (arg[i][0] == '-')
		{
			if (arg[i][1] == 'm')
			{
				g_option = 1;
				return(i + 1);
			}
			else if (arg[i][1] == 'l')
			{
				g_option = 2;
				return(i + 1);
			}
			else if (arg[i][1] == 'b')
			{
				g_option = 3;
				return(i + 1);
			}
			else if (arg[i][1] == 'g')
			{
				g_option = 4;
				return(i + 1);
			}

		}
		else
			return (0);
	}
	return (0);
}
