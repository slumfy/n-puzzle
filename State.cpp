#include "Taquin.h"
#include "State.h"


int	State::manhattan()
{
	int	pound = 0;
	for (int i = 0; i < puzzle._len; i++)
	{
		for (int j = 0; j < puzzle._len; j++)
		{
			if (puzzle.tab[i][j] != 0)
				{
				pound += abs(i - (puzzle.tab[i][j] - 1) / puzzle._len);
			cout  << "valuei " << pound << "\t";
				pound += abs(j - (puzzle.tab[i][j] - 1) % puzzle._len);
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
	for (int i = 0; i < puzzle._len; i++)
	{
		for (int j = 0;j < puzzle._len; j++)
		if(puzzle.tab[i][j] != 0){
			if(puzzle.tab[i][j] != i * puzzle._len + (j + 1)){
				pound++;}}
	}
	cout << "map pound " << pound << "\n";
	return (pound);
}
