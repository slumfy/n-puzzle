#include "Taquin.h"
#include "State.h"
#include "List.h"


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

int	get_puzzle_size(Taquin *puzzle, fstream *file)
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
				puzzle->_len = atoi(comment.c_str());
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
				cout << "manhattan\n";
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
	cout << "To Use N-puzzle solver:\n" << "./n-puzzle -X puzzle.txt\n" << "where X is the name of the heuristic function\n" << "and puzzle.txt the file where the puzzle is\n";

}

int	main(int ac, char** av)
{
	Taquin puzzle;
	List  list;
	Taquin move;
	fstream file;
	string line;
	int number;
	int arg = 0;

	if ((arg = manage_arg(ac, av)) == 0 || !av[arg])
		print_usage();
	file.open(av[arg], ios::in);
	if (get_puzzle_size(&puzzle, &file))
		return(1);
	printf("taquin size = %d\n", puzzle._len);
	while (getline(file,line))
	{
		vector<int> vec;
		stringstream iss(line);
		while (iss >> number)
			vec.push_back(number);
		puzzle.tab.push_back(vec);
	}
	file.close();
	puzzle.isTaquin() ? cout << "ok" << "\n" : cout << "bad format"<< "\n";
	if (!(puzzle.isSolvable()))
	{
		cout << "not Solvable\n";
		return (0);
	}
	cout << "Solvable\n";
	//	puzzle.print_taquin();
	/*
	   int pos = puzzle.find0Position();
	   int j = pos % puzzle._len;
	   int i = (pos - j) / puzzle._len;
	   printf("%d %d\n", i, j);
	   puzzle.print_taquin();
	   printf("move UP :\n");
	   move = puzzle.new_move((t_move)UP);
	   move.print_taquin();
	   printf("move DOWN :\n");
	   move = puzzle.new_move((t_move)DOWN);
	   move.print_taquin();
	   printf("move RIGHT :\n");
	   move = puzzle.new_move((t_move)RIGHT);
	   move.print_taquin();
	   printf("move LEFT :\n");
	   move = puzzle.new_move((t_move)LEFT);
	   move.print_taquin();
	 */
	State first(puzzle.tab, puzzle._len, NULL, NONE);
	list.astar(first);
	return (0);
}
