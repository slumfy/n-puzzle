#include "Npuzzle.h"

int **g_done;
int g_option = 0;

void		print_usage()
{
	cout << "N-puzzle Usage: ./N-puzzle [option] [map file]\n";
	cout << "option : -m manhattan\n" << "\t -l linear inter\n" << "\t -b basic\n" << "\t -g generator [size]\n";
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
	{
		print_usage();
		return (0);
	}
	else if (g_option != 4)
	{
		file.open(av[arg], ios::in);
		if (get_puzzle_size(&first, &file))
		{
			cout << "bad format"<< "\n";
			return(1);
		}
		printf("taquin size = %d\n", first.size);
		while (getline(file,line))
		{
			vector<int> vec;
			stringstream iss(line);
			while (iss >> number)
				vec.push_back(number);
			if (vec.size() == (size_t)first.size)
			{
				first.map.push_back(vec);
			}
		}
		file.close();
		if (first.isTaquin() == 0)
		{
			cout << "bad format"<< "\n";
			return (1);
		}
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
	first.print_taquin(first.map);
	g_done =  first.create_end_map();
	if (g_option != 4)
	{
		if (g_option == 1)
			first.manhattan(first.map);
		else if(g_option == 2)
			first.heuristic(first.map);
		else if(g_option == 3)
			first.check_map(first.map);
		list.astar(first);
	}
	else
	{
		int random = 0;
		srand(time(NULL));
		for (int i = 0 ;i < first.size * 1000;i++)
		{
			random = rand() % 4;
			makeMove(random, first);
		}
		print_done(first.size);
	}
	return (0);
}
