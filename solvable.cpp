#include "Taquin.h"

int getInvCount(Taquin puzzle) 
{ 
	int inv_count = 0;
	vector <int> tab;

	for(int i = 0; i < puzzle.tab.size();i++)
	{
		for (int j = 0; j < puzzle.tab[i].size(); j++)
			tab.push_back(puzzle.tab[i][j]);
	}
	for(int i = 0; i < tab.size();i++)
		cout << "tab: " << tab[i] << "\n";
	for (int i = 0; i < (puzzle._len * puzzle._len) - 1; i++) 
	{ 
		for (int j = i + 1; j < puzzle._len * puzzle._len; j++) 
		{ 
			// count pairs(i, j) such that i appears 
			// before j, but i > j. 
			if (tab[j] && tab[i] && tab[i] > tab[j]) 
				inv_count++; 
		} 
	} 
	return inv_count; 
} 

// find Position of blank from bottom 
int findXPosition(Taquin puzzle) 
{ 
	// start from bottom-right corner of matrix 
	for (int i = puzzle._len - 1; i >= 0; i--) 
		for (int j = puzzle._len - 1; j >= 0; j--) 
			if (puzzle.tab[i][j] == 0) 
				return puzzle._len - i; 
} 

// This function returns true if given 
// instance of N*N - 1 puzzle is solvable 
bool isSolvable(Taquin puzzle) 
{ 
	// Count inversions in given puzzle 
	int invCount = getInvCount(puzzle); 

	cout << "invC " << invCount << "\n";
	// If grid is odd, return true if inversion 
	// count is even. 
	if (puzzle._len & 1) 
		return !(invCount & 1); 

	else     // grid is even 
	{ 
		int pos = findXPosition(puzzle); 
	cout << "pos " << pos << "\n";
		if (pos & 1) 
			return !(invCount & 1); 
		else
			return invCount & 1; 
	} 
}
