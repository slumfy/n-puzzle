#include "Taquin.h"
#include "State.h"


int	State::manhattan()
{
	int	pound = 0;
	for (int i = 0; i < puzzle._len - 1; i++)
	{
		for (int j = 0; i < puzzle._len - 1; j++)
			if (map[i] != 0)
				pound += abs((i + 1) / len - map[i] / len)
					+ abs((i + 1) % len - map[i] % len);
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
		if(map[i] != 0){
			if(map[i] != (i+1) * _len + (j+1) * _len){
				pound++;}}
	}
	return (pound);
}
