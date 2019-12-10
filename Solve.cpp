#include "Taquin.h"

void	astar(vector <int> initial_state, list<vector <int> > *best_path, int *nbiter, int len)
{
	int	s = len;
	map<vector <int>,vector <int> > parent;
	parent[initial_state] = initial_state;

	map<vector <int>, int> d;
	d[initial_state] = manhattan(initial_state,s);

	set <vector <int> > black;

	priority_queue< pair< int , vector <int> >,
		vector< pair< int, vector <int> > >,
		greater< pair< int, vector <int> > > > grey;
	grey.push({ d[initial_state], initial_state }); // initially the source is grey

	vector< vector <int> > neighbors;

	(*nbiter) = 0;



	while( !grey.empty() )
	{
		vector <int> current_state = grey.top().second;

		(*nbiter)++;

		if( check_map(current_state) == 0)
		{
			best_path->clear();
			while(current_state != initial_state)
			{
				best_path->push_front(current_state);
				current_state = parent[current_state];
			}
			best_path->push_front(initial_state);
			cout << "ok\n";
			return;
		}

		black.insert(current_state); // current_state becomes black...
		grey.pop();     // ...it is no more grey

		neighbors.clear();

		int pos0 = find( current_state.begin(), current_state.end(), 0 ) - current_state.begin();

		if( (pos0 + 1) < current_state.size() &&
				((pos0 + 1) % s) != 0 )
		{
			vector <int> neighbor = current_state;
			swap( neighbor[pos0] , neighbor[pos0 + 1] );
			neighbors.push_back(neighbor);
		}

		if( (pos0 - 1) >= 0 &&
				((pos0 - 1) % s) != (s-1) )
		{
			vector <int> neighbor = current_state;
			swap( neighbor[pos0] , neighbor[pos0 - 1] );
			neighbors.push_back(neighbor);
		}

		if( (pos0 + s) < current_state.size() )
		{
			vector <int> neighbor = current_state;
			swap( neighbor[pos0] , neighbor[pos0 + s] );
			neighbors.push_back(neighbor);
		}

		if( (pos0 - s) >= 0 )
		{
			vector <int> neighbor = current_state;
			swap( neighbor[pos0] , neighbor[pos0 - s] );
			neighbors.push_back(neighbor);
		}

		for(vector <int> neighbor : neighbors )
		{
			if(black.end() != black.find(neighbor))
				continue ;
			int new_cost = d[current_state] + 1 - manhattan(current_state,s) + manhattan(neighbor,s);
			if (distance(d,neighbor) > new_cost)
			{
				d[neighbor] = new_cost;
				parent[neighbor] = current_state;
				grey.push({d[neighbor], neighbor});
			}
		}
	}
}

int	distance(map<vector <int>,int> dist, vector <int> state)
{
	map< vector <int> , int>::const_iterator it = dist.find(state);	
	if(dist.end() == it)
	{
		return numeric_limits<int>::max();
	}
	return(it->second);
}

int	manhattan(vector <int> map, int len)
{
	int	pound = 0;
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] != 0)
			pound += abs((i + 1) / len - map[i] / len)
				+ abs((i + 1) % len - map[i] % len);
	}
	cout << "manhattan pound " << pound << "\n";
	return (pound);
}

int	check_map(vector <int> map)
{
	int pound = 0;
	for (int i = 0; i < map.size(); i++)
	{
	cout << map[i] << " ";
		if(map[i] != 0){
			if(map[i] != i + 1){
				pound++;}}
	}
	cout << "pound " << pound << "\n";
	return (pound);
}
