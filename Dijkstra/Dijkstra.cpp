/*
Implementation Dijkstra Algorithm with Priority Queue
Teacher: Rian Gabriel
Class: Graph Theory
*/
// Info about the arcs
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <utility>
#define MAX_V 9999
#define INF 9999

using namespace std;

typedef struct
{
    int v;
    int weight; // Weight
}TAdj;

vector <TAdj> adj[MAX_V]; // adjacent list
int degree[MAX_V];

void initialize_Graph(int qtdVertex)
{
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < qtdVertex; i++){
        adj[i].clear();
    }
}
// create arc of A to B with weight w
void arc(int A, int B, int w)
{
    TAdj aux;
    aux.v = B;
    aux.weight = w;
    degree[A]++;
    adj[A].push_back(aux);
}

int dist[MAX_V];
int pred[MAX_V]; // stores predecessor of each vertex
// Dijkstra algorithm
void Dijkstra(int src, int vertices)
{
    priority_queue< pair< int, int > > heap; // distance and vertex
    vector<int> dist(vertices, INF);
    int s, t, w;
    memset(pred,-1, sizeof(pred));
    // make the distance of src equal 0
    heap.push(make_pair(dist[src] = 0, src));
    while(!heap.empty()){
        s = heap.top().second;
        heap.pop();
        for(int i = 0; i < degree[s]; i++){
            t = adj[s][i].v;
            w = adj[s][i].weight;
            if(dist[s] + w < dist[t]){
                dist[t] = dist[s] + w;
                pred[t] = s;
                heap.push(make_pair(-dist[t], t));
            }
        }
    }
    cout << "\nVertex Distance from the source\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "\t\n" << i << " " << dist[i] << endl;
    }
}

int main()
{
    int qtdVertex, arcs, A, B, w, src, vertices;
    cout << "Enter with number of vertices: ";
    cin >> qtdVertex;
    cout << "Enter with number of arcs: ";
    cin >> arcs;
    vector <TAdj> adj[MAX_V];
    initialize_Graph(qtdVertex);
    for(int i = 0; i < arcs; i++){
        cout <<"\nArcs " << i + 1 << "\nEnter the source: ";
        cin >> A;
        cout << "Destination: ";
        cin >> B;
        cout << "Enter with weights: ";
        cin >> w;
        arc(A, B, w);
    }
    cout << "Enter the initial vertex: ";
    cin >> src;
    Dijkstra(src, qtdVertex);
}