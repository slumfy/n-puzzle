#include "Npuzzle.h"

int **g_done;
int g_option = 0;

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
				puzzle->size = atoi(comment.c_str());
				return (0);
			}
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

void		print_usage()
{
	cout << "N-puzzle Usage: ./N-puzzle [option] [map file]\n" << "option : -m manhattan\n" << "\t -g generator\n";
}

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
	int **res = g_done;
	int i;
	int j;
	int pos;
	int tmp;

	pos = find0Position(0, first);
	j = pos % first.size;
	i = (pos - j) / first.size;
	if (move == 0 && i != 0)
	{
		tmp = res[i][j];
		res[i][j] = res[i - 1][j];
		res[i - 1][j] = tmp;
	}
	else if (move == 1 && i != first.size - 1)
	{
		tmp = res[i][j];
		res[i][j] = res[i + 1][j];
		res[i + 1][j] = tmp;
	}
	else if (move == 2 && j != first.size - 1)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j + 1];
		res[i][j + 1] = tmp;
	}
	else if (move == 3 && j != 0)
	{
		tmp = res[i][j];
		res[i][j] = res[i][j - 1];
		res[i][j - 1] = tmp;
	}
	g_done = res;
}

void	print_done(int size)
{
	cout << size << "\n";
	for (int i = 0; i < size; i++)
	{
		for (int j =0;j < size;j++)
			cout << g_done[i][j] << " ";
		cout << "\n";
	}
}

int	main(int ac, char** av)
{
	Lists  list;
	fstream file;
	string line;
	int number;
	int arg = 0;

	State first(vector <vector <int> >(), 0, NULL, NONE);
	if ((arg = manage_arg(ac, av)) == 0 || !av[arg])
		print_usage();
	else if (g_option != 4)
	{
		file.open(av[arg], ios::in);
		if (get_puzzle_size(&first, &file))
			return(1);
		cout << g_option << "\n";
		printf("taquin size = %d\n", first.size);
		while (getline(file,line))
		{
			vector<int> vec;
			stringstream iss(line);
			while (iss >> number)
				vec.push_back(number);
			first.map.push_back(vec);
		}
		file.close();
		first.isTaquin() ? cout << "ok" << "\n" : cout << "bad format"<< "\n";
		if (!(first.isSolvable()))
		{
			cout << "not Solvable\n";
			return (0);
		}
		cout << "Solvable\n";
	}
	else 
	{
		if ((number = atoi(av[arg])) < 2)
		{
			print_usage();
			return (1);
		}
		first.size = number;
	}
	g_done =  first.create_end_map();
	if (g_option != 4)
	{
		first.manhattan(first.map);
		list.astar(first);
	}
	else
	{
		int random = 0;
		for (int i = 0 ;i < 1000;i++)
		{
			srand(time(NULL));
			random = rand() % 4;
			makeMove(random, first);
		}
		print_done(first.size);
	}
	return (0);
}
