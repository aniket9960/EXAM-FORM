#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector< vector<int> > FormAdjList()
    {
    vector< vector<int> > adjList;
    
    const int n = 9;
    
    for(int i = 0; i < n; i++)
        {
        vector<int> row;
        adjList.push_back(row);
        }

    adjList[0].push_back(2);
    adjList[0].push_back(4);
    adjList[0].push_back(6);
    
    adjList[1].push_back(4);
    adjList[1].push_back(7);
    
    adjList[2].push_back(0);
    adjList[2].push_back(5);
    
    adjList[3].push_back(4);
    adjList[3].push_back(5);
    
    adjList[4].push_back(1);
    adjList[4].push_back(3);
    adjList[4].push_back(0);
    
    adjList[5].push_back(2);
    adjList[5].push_back(3);
    adjList[5].push_back(8);
    
    adjList[6].push_back(0);
    
    adjList[7].push_back(1);
    
    adjList[8].push_back(5);
    
    return adjList;
    }
    
vector< vector<int> > FormAdjMatrix()
    {
    vector< vector<int> > adjMatrix;
    
    const int n = 9;
    
    for(int i = 0; i < n; i++)
        {
        vector<int> row;
        adjMatrix.push_back(row);
        
        
        for(int j = 0; j < n; j++)
            {
            int value = 0;
            
            if(i == j) 
                { value = 1; }
            
            adjMatrix[i].push_back(value);
            }
        }
    
    
    adjMatrix[0][2] = 1;
    adjMatrix[2][0] = 1;
    
    adjMatrix[0][4] = 1;
    adjMatrix[4][0] = 1;
    
    adjMatrix[0][6] = 1;
    adjMatrix[6][0] = 1;
    
    adjMatrix[1][4] = 1;
    adjMatrix[4][1] = 1;
    
    adjMatrix[1][7] = 1;
    adjMatrix[7][1] = 1;
    
    adjMatrix[2][5] = 1;
    adjMatrix[5][2] = 1;
    
    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;
    
    adjMatrix[3][5] = 1;
    adjMatrix[5][3] = 1;
    
    adjMatrix[5][8] = 1;
    adjMatrix[8][5] = 1;
    
    return adjMatrix;
    }
    
void AdjListBFS(vector< vector<int> > adjList, int start)
    {
    cout << "\nDoing a BFS on an adjacency list.\n";
    
    int n = adjList.size();
    bool visited[n] = { false };
    
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while(q.empty() == false)
        {
        int vertex = q.front();
        q.pop();

        cout << vertex+1 << " ";

        for(int i = 0; i < adjList[vertex].size(); i++)
            {
            int neighbor = adjList[vertex][i];
            
            if(visited[neighbor] == false)
                {
                q.push(neighbor);
                visited[neighbor] = true;
                }
            }
        }
    cout << endl << endl;
    return;
    }
    
void AdjListDFS(vector< vector<int> > &adjList, int &vertex, vector<bool> &visited)
    {

    visited[vertex] = true;
    cout << vertex+1 << " ";

    for(int i = 0; i < adjList[vertex].size(); i++)
        {
        int neighbor = adjList[vertex][i];

        if(visited[neighbor] == false)
            {
            AdjListDFS(adjList, neighbor, visited);
            }
        }
    }    

void AdjListDFSInitialize(vector< vector<int> > &adjList, int start)
    {
    cout << "\nDoing a DFS on an adjacency list.\n";
    
    int n = adjList.size();

    vector<bool> visited;
    
    for(int i = 0; i < n; i++)
        {
        visited.push_back(false);
        }
    
    AdjListDFS(adjList, start, visited);
    
    cout << endl << endl;
    return;
    }
    
int main() 
    {
    cout << "Program started.\n";
    
    vector< vector<int> > adjList = FormAdjList();

    AdjListBFS(adjList, 4);
    AdjListDFSInitialize(adjList, 4);
    
    cout << "Program ended.\n";
    return 0;
    }