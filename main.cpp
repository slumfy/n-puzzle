#include "Taquin.h"

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

int	main(int ac, char** av)
{
	Taquin puzzle;
	fstream file;
	string line;
	int number;

	if (ac != 2)
		return (0);
	file.open(av[1], ios::in);
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
	puzzle.print_taquin();
	puzzle.isTaquin() ? cout << "ok" << "\n" : cout << "bad format"<< "\n";
	puzzle.isSolvable() ? cout << "Solvable" : cout << "not Solvable";
	return (0);
}
