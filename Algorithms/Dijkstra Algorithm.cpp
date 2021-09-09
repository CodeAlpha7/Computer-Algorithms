#include<iostream>
#include<vector>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int main() {
    int v;
    cout<<"Enter Number of Vertices: ";
    cin>>v;

    vector<vector<int>> graph(v, vector<int>(v, -1));

    int e;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter edges (V1, V2, W):\n";
    for(int i=0; i<e; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        if(x<=v && y<=v)
            graph[x-1][y-1] = z;
        else {
            cout<<"Invalid Input! Try again\n";
            bool check = false;
            while(!check) {
                cin>>x>>y>>z;
                if(x>0 && x<=v && y>0 && y<=v) {
                    graph[x][y] = z;
                    check = true;
                }
                else
                    cout<<"Invalid Input! Try again\n";
            }
        }
    }

    vector<bool> visited(v, false); 
    vector<int> shortestPath(v, INT_MAX);
    vector<int> path;
    shortestPath[0] = 0;
    path.push_back(1);
    visited[0] = true;
    
    int countVisit = 1;
    int index = 0;

    while(countVisit != v) {
        for(int i=0; i<v; i++) {
            if(graph[index][i] != -1) {
                if(!visited[i]) {
                    int dist = shortestPath[index] + graph[index][i];

                    if(dist < shortestPath[i]) {
                        shortestPath[i] = dist;
                    }
                }
            } 
        }
        int min = INT_MAX, minIndex = -1;
        for(int i=0; i<v; i++) {
            if(!visited[i]) {
                if(min > shortestPath[i]) {
                    min = shortestPath[i];
                    minIndex = i;
                }
            }
        }
        index = minIndex;
        visited[index] = true;
        countVisit++;
        path.push_back(index+1);
    }
    cout<<"\nShortest path: \n";
    for(int i=0; i<v; i++) {
        if(i == v-1) {
            cout<<path[i];
        }
        else
            cout<<path[i]<<"->";
    }
    cout<<"\n\nAll distance: \n";
    for(int i=0; i<v; i++) {
        cout<<"Vertex "<<i+1<<"->"<<shortestPath[i]<<"\n";
    }
}