#include <iostream>
#include <string>
#include <climits>

using namespace std;

// classe que guarda o grafo
class Graph{

    public:
        int number_vertices;
        int **edges;
        // constroi o grafo com V vertices e E arestas
        Graph(int V){
            this->number_vertices = V;
            this->edges = new int *[V];
            for(int i = 0; i < V; i++){
                this->edges[i] = new int[V];
                for(int j = 0; j < V; j++){
                    this->edges[i][j] = INT_MAX;
                }
                this->edges[i][i] = 0;
            }
        }

        ~Graph(){
            for(int i = 0; i < number_vertices; i++)
                delete[] edges[i];
            delete[] edges;
        }
        // adiciona uma dada aresta ao grafo
        void addEdge(int src, int dist, int weight){
            this->edges[src][dist] = weight;
        }
};

void print_distance(int distance[], int V)
{
    cout << "\nA distancia da matrix para o F-W" << endl;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(distance[i*V+j] != INT_MAX)
                cout << distance[i*V+j] << "\t";
            else
                cout << "INF" << "\t";
        }
        cout << endl;
    }
}

void F_W_(Graph graph)
{
    int V = graph.number_vertices;
    int distance[V][V];
    // incializa a distancia
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            distance[i][j] = graph.edges[i][j];
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++)
                if(distance[i][k] != INT_MAX && distance[k][j] != INT_MAX && 
                distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
        }
    }
    // vai converter a matrix em uma array
    int distance1[V*V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            distance1[i*V+j] = distance[i][j];
        }
    }

    print_distance(distance1, V);
}

// funcao principal

int main()
{
    int V, E, src, dist, weight;
    cout<< "Digite o numero de vertices: ";
    cin >> V;
    cout<< "Digite o numero de arestas: ";
    cin >> E;
    Graph G(V);
    for(int i = 0; i < E; i++){
        cout<< "\nAresta " << i + 1 << "\nDigite a fonte: ";
        cin >> src;
        cout << "Digite o destino: ";
        cin >> dist;
        cout << "Digite o peso: ";
        cin >> weight;
        G.addEdge(src, dist, weight);
    }

    F_W_(G);
}