#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void calculateDistance(int dist[], int V, int src)
{
	for (int i = 0; i < V; i++) {
        cout<<src <<" \t\t "<<dist[i]<<" \t\t "<<i<<"\n";
    }
}
void dijkstra(vector<vector<int>> graph, int src, int V)
{
	int dist[V]; 

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet, V);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	calculateDistance(dist, V, src);
}

void printGraph(vector<vector<int>> graph, int V) {
    cout<<"\n\nprinting graph (u  --Link Cost-->  v):\n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(graph[i][j] != -1)
                cout<<i<<"  --"<<graph[i][j]<<" -->  "<<j<<"\n";
        }
    }
    cout<<"\n\n";
}



int main()
{
    int V;
    cout<<"Enter number of Vertices: ";
    cin>>V;
	vector<vector<int>> graph(V, vector<int>(V, -1));
    int n;
    cout<<"Enter number of edges: ";
    cin>>n;

    int adj[V][V];
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            adj[i][j] = 0;
        }
    }
    
    cout<<"enter edges (source, destination, cost)\n";
    for(int i=0; i<n; i++) {
        int a,b,c;

        cin>>a>>b>>c;

        adj[a][b] = 1;
        graph[a][b] = c;
        graph[b][a] = c;

    }
    printGraph(graph, V);

    cout<<"Adjacency matrix is: "<<endl;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"\nPrinting Routing Table: \n";
    cout<<"Advertiser \t Cost \t Destination\n";
    for(int i=0; i<V; i++) {
        dijkstra(graph, i, V);
    }

	return 0;
}