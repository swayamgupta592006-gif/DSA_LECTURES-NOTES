#include <iostream>
using namespace std;

class DSU{
public:
	int* parent, *size;
	int n;
	DSU(int N){
		n = N;
		parent = new int[n+1];
		size = new int[n+1];
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = i;
			size[i] = 1;
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

		if(size[leader_v] > size[leader_u]) swap(leader_u, leader_v);
		
		parent[leader_v] = leader_u;
		size[leader_u] += size[leader_v];
	}
};

int main(){


	return 0;
}
















