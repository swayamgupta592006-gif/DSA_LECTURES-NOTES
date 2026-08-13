#include <iostream>
using namespace std;

class DSU{
public:
	int* parent, *rank;
	int n;
	DSU(int N){
		n = N;
		parent = new int[n+1];
		rank = new int[n+1];
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int get(int u){
		if(parent[u] == u){
			return u;
		}

		return get(parent[u]);
	}

	void set_union(int u,int v){
		int leader_u = get(u);
		int leader_v = get(v);
		if(leader_u == leader_v) return;

		if(rank[leader_v] > rank[leader_u]){
			swap(leader_u, leader_v);
		}
		parent[leader_v] = leader_u;

		if(rank[leader_v] == rank[leader_u]){
			rank[leader_u]++;
		}
	}
};

int main(){


	return 0;
}
















