#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename T>
class DSU{
public:
	map<T,T> parent;
	map<T,int> size;

	DSU(T *nodes){
		
		for (int i = 0; nodes[i] != '\0'; ++i)
		{
			parent[nodes[i]] = nodes[i];
			size[i] = 1;
		}
	}

	T get(int u){
		if(parent[u] == u){
			return u;
		}

		// Path compression
		return parent[u] = get(parent[u]);
	}

	void set_union(T u,T v){
		T leader_u = get(u);
		T leader_v = get(v);
		if(leader_u == leader_v) return;

		if(size[leader_v] > size[leader_u]) swap(leader_u, leader_v);
		
		parent[leader_v] = leader_u;
		size[leader_u] += size[leader_v];
	}
};

class info{
public:
	char u, v;
	int weight;
};

bool compare(info &a, info &b){
	return a.weight < b.weight;
}

int main(){

	char nodes[] = "ABCDEFG";
	vector<info> adj = {
		{'A','B',1},
		{'A','C',2},
		{'C','D',3},
		{'C','G',11},
		{'F','G',1},
		{'B','D',8},
		{'F','D',1},
		{'B','E',2},
	};

	sort(adj.begin(), adj.end(), compare);

	// for (int i = 0; i < adj.size(); ++i)
	// {
	// 	cout << adj[i].u <<", "<<adj[i].v <<", "<<adj[i].weight << endl;
	// }
	
	DSU<char> d(nodes);

	int ans = 0;
	for (int i = 0; i < adj.size(); ++i)
	{
		char lu = d.get(adj[i].u);
		char lv = d.get(adj[i].v);

		if(lu != lv){
			ans += adj[i].weight;
			d.set_union(lu, lv);
		}
	}

	cout << ans << endl;

	return 0;
}
















