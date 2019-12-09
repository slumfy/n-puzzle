#include "Taquin.h"

Taquin::Taquin(): _len(1)
{
}

Taquin::Taquin(int n): _len(n)
{

}

Taquin::~Taquin()
{
}

void	Taquin::print_taquin()
{
	for(int i = 0; i < (int)tab.size();i++)
	{
		for (int j = 0; j < (int)tab[i].size(); j++)
			cout << tab[i][j] << " ";
		cout << "\n";
	}
}

int	Taquin::getInvCount() 
{ 
	int inv_count = 0;
	vector <int> tabl;

	for(int i = 0; i < (int)tab.size();i++)
	{
		for (int j = 0; j < (int)tab[i].size(); j++)
			tabl.push_back(tab[i][j]);
	}
	for (int i = 0; i < (_len * _len) - 1; i++) 
	{ 
		for (int j = i + 1; j < _len * _len; j++) 
		{ 
			// count pairs(i, j) such that i appears 
			// before j, but i > j. 
			if (tabl[j] && tabl[i] && tabl[i] > tabl[j]) 
				inv_count++; 
		} 
		cout << tabl[i] << " count " << inv_count << "\n";
	} 
	return inv_count; 
} 

// find Position of blank from bottom 
int Taquin::findXPosition()
{ 
	for (int i = _len - 1; i >= 0; i--) 
		for (int j = _len - 1; j >= 0; j--) 
			if (tab[i][j] == 0) 
				return _len - i;
	return (-1);
}

int Taquin::findYPosition()
{ 
	for (int i = _len - 1; i >= 0; i--) 
		for (int j = _len - 1; j >= 0; j--) 
			if (tab[i][j] == 0) 
				return j;
	return (-1);
}

// This function returns true if given 
// instance of N*N - 1 puzzle is solvable 
bool Taquin::isSolvable() 
{ 
	// Count inversions in given puzzle 
	int invCount = getInvCount(); 


	int posX = findXPosition();
	int posY = findYPosition();
	int modulo = abs(_len - posX - 1) + abs(_len - posY -1);
	return ((modulo % 2 == 0) == (invCount % 2 == 0));
}
