#include<bits/stdc++.h>
using namespace std;

//Function to create a new edge of undirected graph.

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Function to print adjacency list.

void printGraph(vector<int> adj[], int v){
    for(int i=0;i<v;i++){
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

//Function to print Breadth First Traversal of graph.

void BFS(vector<int> adj[], int v, int s){
    bool visited[v] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

//Function to print the BFS of a graph if source node is not given and graph may be disconnected.

void BFS(vector<int> adj[], int s, bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

//This function passes i as source and the visited array to the above function to print BFS of a graph.

int DisBFS(vector<int> adj[], int v){
    bool visited[v];
    int count = 0;
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int i=0;i<v;i++){
        if(visited[i] == false){
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

//Function to print Depth FIrst Traversal of a graph.

void recDFS(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for(int u : adj[s]){
        if(visited[u] == false){
            recDFS(adj, u, visited);
        }
    }
}

//This function passes i as source and visited array to tha above function to print DFS.
//This function also return the number of islands in a graph.

int DFS(vector<int> adj[], int v){
    bool visited[v];
    int count = 0;
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    for(int i=0;i<v;i++){
        if(visited[i] == false){
            count++;
            recDFS(adj, i, visited);
        }
    }
    return count;
}

//Function to detect cycle in an undirected graph using DFS.
//This function returns true if we find an element visited in traversal and its not the parent.

bool DFSrec(vector<int>adj[], int s, bool visited[], int parent){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u] == false){
            if(DFSrec(adj, u, visited, s)){
                return true;
            }
        }
        else if(u != parent){
            return true;
        }
    }
    return false;
}

bool DFSdetection(vector<int>adj[], int v){
    bool visited[v] = {false};
    for(int i=0;i<v;i++){
        if(visited[i] == false){
            if(DFSrec(adj, i, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

//Function to create a new edge of a directed graph.

void directedAddEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

//Function to detect cycle in a directed graph.
//This function manages a recst bool array which manages the ancestors of a particular element.
//If an ancestor is appeared twice the it return true.

bool DFSRec(vector<int> adj[], int s, bool visited[], bool recst[]){
    visited[s] = true;
    recst[s] = true;

    for(int u : adj[s]){
        if(visited[u] == false and DFSRec(adj, u, visited, recst)){
            return true;
        }
        else if(recst[u]){
            return true;
        }
    }
    recst[s] = false;
    return false;
}

bool directedDFS(vector<int>adj[], int v){
    bool visited[v] = {false};
    bool recst[v] = {false};

    for(int i=0;i<v;i++){
        if(visited[i] == false){
            if(DFSRec(adj, i, visited, recst)){
                return true;
            }
        }
    }
    return false;
}

//KAHN'S ALGORITHM

//Topological Sorting is done for Directed Acyclic Graph (DAG).
//To understand Topological Sort we can assume that the vertices are jobs and the edges are dependencies.
//So the dependent jobs can only be done after the completeion of the previous job.

//In Topological Sort using BFS - 
//1. We maintain an indegree array to store the indegrees of every vertice.(Indegree is nothing but the number of times the
//vertice appears in the adjacent list)
//2. Create a queue.
//3. Add all the 0 indegree vertices to the queue.
//After this the code is pretty simple we reduce the indegree by 1 of every adjacent vertices and push vertices with 0 
//indegree in the queue.

void topologicalBFS(vector<int> adj[], int v){
    int indegree[v] = {0};
    for(int i=0;i<v;i++){
        for(int u : adj[i]){
            indegree[u]++;
        }
    }

    queue<int> q;

    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int j : adj[u]){
            --indegree[j];
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
}

//In Topological Sort using DFS -
//1. Create an empty stack.
//2. For every vertex u, do the following
//       if(u is not visited)
//           DFS(u, st)
//while st is not empty
//Pop an item from it and print it.
//DFS(u, st)
//1. Mark u as visited.
//2. For every adjacent v of u
//      if(v is not visited)
//           DFS(v, st)
//3. Push u to st.

void DFSTopo(vector<int> adj[], int s, bool visited[], stack<int> &st){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u] == false){
            DFSTopo(adj, u, visited, st);
        }
    }
    st.push(s);
}

void topologicalDFS(vector<int>adj[], int v){
    bool visited[v] = {false};
    stack<int> st;

    for(int i=0;i<v;i++){
        if(visited[i] == false){
            DFSTopo(adj, i, visited, st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

//Cycle detection using Kahn's Algo
//If there is a cycle in the graph then there will be a point when the queue will be empty and there will be no vertex 
//available with inorder 0. So, we will not have count variable equal to the number of vertices.

bool cycleDetection(vector<int> adj[], int v){
    int indegree[v] = {0};
    int count = 0;
    for(int i=0;i<v;i++){
        for(int u : adj[i]){
            indegree[u]++;
        }
    }

    queue<int> q;

    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j : adj[u]){
            --indegree[j];
            if(indegree[j] == 0){
                q.push(j);
            }
        }
        count++;
    }
    return(count != v);
}


int main(){
    // int v = 5;
    // vector<int> adj[v];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 2, 4);
    // addEdge(adj, 3, 4);
    // printGraph(adj, v);
    // BFS(adj, v, 0);
    // int v = 7;
    // vector<int> adj[v];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 4, 5);
    // addEdge(adj, 4, 6);
    // int connectedVertices = DisBFS(adj, v);
    // cout<<connectedVertices<<" ";
    // cout<<DFS(adj, v)<<" ";
    // cout<<DFSdetection<<" ";
    // int v = 6;
    // vector<int> adj[v];
    // directedAddEdge(adj, 0, 1);
    // directedAddEdge(adj, 2, 1);
    // directedAddEdge(adj, 2, 3);
    // directedAddEdge(adj, 3, 4);
    // directedAddEdge(adj, 4, 5);
    // directedAddEdge(adj, 5, 3);
    int v = 5;
    vector<int> adj[v];
    directedAddEdge(adj, 0, 2);
    directedAddEdge(adj, 0, 3);
    directedAddEdge(adj, 1, 3);
    directedAddEdge(adj, 2, 3);
    directedAddEdge(adj, 1, 4);
    directedAddEdge(adj, 3, 4);
    //printGraph(adj, v);
    // cout<<directedDFS<<" ";
    // topologicalBFS(adj, v);
    // cout<<"\n";
    // topologicalDFS(adj, v);
    cout<<cycleDetection(adj, v);

    return 0;
}