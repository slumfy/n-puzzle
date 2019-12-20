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

int mini(vector <int> tabl, int i, int len)
{
	int j = i;
	int min = tabl[j];

	while (i < len)
	{
		if (tabl[i] < min)
		{
			min = tabl[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	Taquin::getInvCount() 
{ 
	int parity = 1;
	int min;
	int tmp;
	vector <int> tabl;

	for(int i = 0; i < (int)tab.size();i++)
 	{
 		for (int j = 0; j < (int)tab[i].size(); j++)
 			tabl.push_back(tab[i][j]);
 	}
	for (int j = 1; j < _len * _len - 1; j++)
	{
		if (tabl[j] == 0)
			tabl[j] = _len * _len;
	}
	for (int i = 0; i < (int)tabl.size(); i++)
		cout << tabl[i] << " ";
	cout << endl << endl;
	for (int j = 0; j < _len * _len; j++)
	{
		if (tabl[j] != j + 1)
		{
			parity *= -1;
			min = mini(tabl, j, _len * _len);
			tmp = tabl[j];
			tabl[j] = tabl[min];
			tabl[min] = tmp;
			for (int i = 0; i < (int)tabl.size(); i++)
				cout << tabl[i] << " ";
			cout << endl;
		}
	}
	return (parity == 1 ? 0 : 1); 
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
	int pos = find0Position();
	int posX = pos % _len;
	int posY = pos / _len;
	//printf("%d %d\n", posX, posY);
	//printf("%d %d\n", abs(_len - 1 - posX), abs(_len - 1 - posY));
	int modulo = abs(_len - 1 - posX) + abs(_len - 1 - posY);

//	printf("%d %d %d %d %d\n", posX, posY, invCount, modulo, _len);
	return (((modulo + _len) % 2 == 0) == invCount);
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
