#include "Npuzzle.h"

void	State::print_taquin(vector <vector <int> > tab)
{
	for(int i = 0; i < (int)tab.size();i++)
	{
		for (int j = 0; j < (int)tab[i].size(); j++)
			cout << tab[i][j] << " ";
		cout << "\n";
	}
}

int	State::getInvCount() 
{ 
	int inv = 0;
	vector <int> tabl;

	for(int i = 0; i < (int)map.size();i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			tabl.push_back(map[i][j]);
	}
	for (int j = 0; j < size * size; j++)
		for (int i = j; i < size * size; i++)
			if (tabl[i] && tabl[i] < tabl[j])
				inv++;
	return (inv); 
} 

bool State::isSolvable() 
{ 
	int invCount = getInvCount();
	int pos = find0Position(0);
	int posY = size - pos/size - 1;

	return (((size % 2) && ((invCount % 2) != 0)) || ((size % 2 == 0) && ((posY % 2 == 0) == ((invCount % 2) == 0))));
}

bool State::isTaquin()
{
	int max = (size * size) - 1;
	int itab[max + 1];

	if (map.size() == (size_t)size)
	{
		for(size_t i = 0; i < map.size(); i++)
			if (map[i].size() != (size_t)size)
				return (0);
	}
	else
		return (0);
	for (int i = 0; i < max + 1; i++)
		itab[i] = i;
	for(int i = 0; i < (int)map.size();i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
		{
			for(int k = 0; k < max + 1; k++)
			{
				if (map[i][j] == itab[k])
					itab[k] = 0;
			}
		}
	}
	for (int f = 0; f < max + 1; f++)
		if (itab[f] != 0)
			return (0);
	return (1);
}
