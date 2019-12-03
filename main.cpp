#include "Taquin.h"
using namespace std;
int	main(int ac, char** av)
{
	Taquin puzzle;
	fstream file;
	string line;
	vector<int> vec;
	int number;

	if (ac != 2)
		return (0);
	file.open(av[1], ios::in);
	while (getline(file,line))
	{
	stringstream iss(line);
	while (iss >> number)
		vec.push_back(number);
	}
	file.close();
	for (int i = 0;i < vec.size(); i++)
		cout << vec.at(i) << " ";
}
