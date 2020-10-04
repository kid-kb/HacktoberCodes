#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> g, int v, bool* visited, int vertex)
{
	visited[vertex] = true;
	cout << vertex << " ";
	for (int i = 0; i < v; i++)
	{
		if (g[vertex][i] == 1 && !visited[i])
			dfs(g, v, visited, i);
	}
	return;
}

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> g(v);
	for (int i = 0; i < v; i++)
	{
		g[i].resize(v);
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			g[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	  
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			dfs(g, v, visited, i);
	}

	cout << endl;

}
