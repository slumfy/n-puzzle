#include "Taquin.h"

Taquin::Taquin(): _len(1)
{
}

Taquin::Taquin(int n, vector<vector<int> > tabl): _len(n)
{
	tab = tabl;
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


// c'est la case vide qu'on bouge
void	Taquin::move(t_move move)
{
	int i;
	int j;
	int pos;
	int tmp;

	pos = find0Position();
	j = pos % _len;
	i = (pos - j) / _len;
	if (move == UP && i != 0)
	{
		tmp = tab[i][j];
		tab[i][j] = tab[i - 1][j];
		tab[i - 1][j] = tmp; 
	}
	else if (move == DOWN && i != _len - 1)
	{
		tmp = tab[i][j];
		tab[i][j] = tab[i + 1][j];
		tab[i + 1][j] = tmp; 
	}
	else if (move == RIGHT && j != _len - 1)
	{
		tmp = tab[i][j];
		tab[i][j] = tab[i][j + 1];
		tab[i][j + 1] = tmp; 
	}
	else if (move == LEFT && j != 0)
	{
		tmp = tab[i][j];
		tab[i][j] = tab[i][j - 1];
		tab[i][j - 1] = tmp; 
	}
}

Taquin Taquin::new_move(t_move move)
{
	Taquin res(_len, tab);
	int i;
	int j;
	int pos;
	int tmp;

	pos = res.find0Position();
	j = pos % res._len;
	i = (pos - j) / res._len;
	if (move == UP && i != 0)
	{
		tmp = res.tab[i][j];
		res.tab[i][j] = res.tab[i - 1][j];
		res.tab[i - 1][j] = tmp; 
	}
	else if (move == DOWN && i != _len - 1)
	{		
		tmp = res.tab[i][j];
		res.tab[i][j] = res.tab[i + 1][j];
		res.tab[i + 1][j] = tmp; 
	}
	else if (move == RIGHT && j != _len - 1)
	{
		tmp = res.tab[i][j];
		res.tab[i][j] = res.tab[i][j + 1];
		res.tab[i][j + 1] = tmp; 
	}
	else if (move == LEFT && j != 0)
	{
		tmp = res.tab[i][j];
		res.tab[i][j] = res.tab[i][j - 1];
		res.tab[i][j - 1] = tmp; 
	}
	return (res);
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

int Taquin::find0Position()
{
	for (int i = 0; i < _len; i++) 
		for (int j = 0; j < _len; j++) 
			if (tab[i][j] == 0) 
				return (_len * i + j);
	return (-1);
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

bool Taquin::isTaquin()
{
	int max = (_len * _len) - 1;
	int itab[max + 1];
	for (int i = 0; i < max + 1; i++)
		itab[i] = i;
	for(int i = 0; i < (int)tab.size();i++)
	{
		for (int j = 0; j < (int)tab[i].size(); j++)
		{
			for(int k = 0; k < max + 1; k++)
			{
				if (tab[i][j] == itab[k])
					itab[k] = 0;
			}
		}
	}
	for (int f = 0; f < max + 1; f++)
		if (itab[f] != 0)
			return (0);
	return (1);
}
