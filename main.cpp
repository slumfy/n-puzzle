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

int	get_puzzle_size(Taquin *puzzle, fstream *file)
{
	string line;

	while(getline(*file,line))
	{
		string comment;
		stringstream iss(line);
		while(iss >> comment)
		{
			if (is_number(comment))
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
	puzzle.isSolvable() ? cout << "Solvable" << std::endl : cout << "not Solvable" << std::endl;
	return (0);
}
