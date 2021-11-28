#include <bits/stdc++.h>
using namespace std;
#include "quadratic.h"
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
 
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{
    list<int> queue;
 
    bool visited[v];
 

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
vector<int> printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{
    vector<int> vectorids;
    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 

    cout << "\nEl camino más corto paso a paso es:\n";
    for (int i = path.size() - 1; i >= 0; i--){
        vectorids.push_back(path[i]);}
        
    return vectorids;
}
 
unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main()
{
    Quadratic <string, int> quad_hash(10, string("empty"), myHash);
    vector<string> ciudades;
    vector<int> vectorid;
    cout<<"TEC Waze"<<endl;
    cout<<"Encuentra la ruta más cercana entre localizaciones."<<endl;
    cout<<endl<<"Id de ciudad: "<<endl;
    ciudades.push_back("Cuernavaca");
    ciudades.push_back("Ciudad de México");
    ciudades.push_back("Puebla");
    ciudades.push_back("Toluca");
    ciudades.push_back("Querétaro");
    ciudades.push_back("Uruapan");
    ciudades.push_back("Morelia");
    ciudades.push_back("Irapuato");
    int i=0;
    
    while(i<8){
    quad_hash.put(string(ciudades[i]), i);
    i++;
    }
    cout<<quad_hash.toString().c_str();

    int v = 8;

    vector<int> adj[v];
 
    int inicio = 0;
    int dest = 0;
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    cout<<"¿Cuál es el id de la ciudad de inicio?: "<<endl;
    cin>>inicio;
    cout<<"¿Cuál es id de la la ciudad de destino?: "<<endl;
    cin>>dest;
    int ii=0;
    vectorid=printShortestDistance(adj, inicio, dest, v);
    while(ii<vectorid.size()){
      i=0;
      while(i<8){
        if(quad_hash.get(ciudades[i])==vectorid[ii]){
          cout<<ciudades[i];
        }
        i++;
      }

      ii++;
      if(ii<vectorid.size()){
        cout<<"->";
      }
    }
    cout<<endl<<endl;
    cout<<"------------------------------------------------"<<endl;
    main();
    return 0;
}