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
#define NOMBRE_CIU "Ciudades.txt"

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
void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n)
{
int mi, i;
for (mi = 0, i = 0; i < n; ++i)
    if (arr[i] > arr[mi])
            mi = i;
return mi;
}
void pancakeSort(int *arr, int n)
{
    for (int curr_size = n; curr_size > 1;
                               --curr_size)
    {

        int mi = findMax(arr, curr_size);
        if (mi != curr_size-1)
        {

            flip(arr, mi);
            flip(arr, curr_size-1);
        }
    }
}

int main()
{
    Quadratic <string, int> quad_hash(10, string("empty"), myHash);
    vector<string> ciudades;
    vector<int> vectorid;
    ifstream archivo(NOMBRE_CIU);
    string linea;
    int e = 0;
    getline(archivo, linea);
    cout<<"TEC Waze"<<endl;
    cout<<"Encuentra la ruta más cercana entre localizaciones."<<endl;
    
    while(getline(archivo, linea)){
    ciudades.push_back(linea);
    quad_hash.put(string(ciudades[e]), e);
    e++;
    }
    archivo.close();
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

    int decision=0;
    if(ciudades.size()==8){
    cout<<"¿Qué desea hacer hoy?: "<<endl;
    cout<<"1. Despliega lista completa de ciudades."<<endl;
    cout<<"2. Encontrar ruta más cercana entre dos ciudades por id."<<endl;
    cout<<"3. Ver lista de líneas de autobuses disponibles para servicio."<<endl;
    cout<<"4. Eliminar historial de búsqueda de rutas. "<<endl;
    cin>>decision;
    
    while((decision<=0)||(decision>4)){
    cout<<endl<<"Digite un número correcto."<<endl;
    cout<<"¿Qué desea hacer hoy?: "<<endl;
    cout<<"1. Despliega lista completa de ciudades."<<endl;
    cout<<"2. Encontrar ruta más cercana entre dos ciudades por id."<<endl;
    cout<<"3. Ver lista de líneas de autobuses disponibles para servicio."<<endl;
    cout<<"4. Eliminar historial de búsqueda de rutas."<<endl;
    cin>>decision;
    }
    
    if(decision==1){
      cout<<"------------------------------------------------"<<endl;
      cout<<"ID: Ciudad"<<endl;
      cout<<quad_hash.toString().c_str();
    }

    else if(decision==2){
    ofstream myfile("historial.txt", ios::app);
    cout<<"¿Cuál es el id de la ciudad de inicio?: "<<endl;
    cin>>inicio;
    cout<<"¿Cuál es id de la la ciudad de destino?: "<<endl;
    cin>>dest;
    while((inicio>=8)||(inicio<0)||(dest>=8)||(dest<0)){
    cout<<endl<<"Digite ids dentro del rango existente."<<endl;
    cout<<"¿Cuál es el id de la ciudad de inicio?: "<<endl;
    cin>>inicio;
    cout<<"¿Cuál es id de la la ciudad de destino?: "<<endl;
    cin>>dest;
    }

    string iniciotxt, destxt;
    iniciotxt=to_string(inicio);
    destxt=to_string(dest);
    myfile<<"Del ID "<<iniciotxt<<" al "<<destxt<<": ";
    int ii=0;
    int i=0;
    vectorid=printShortestDistance(adj, inicio, dest, v);
    while(ii<vectorid.size()){
      i=0;
      while(i<8){
        if(quad_hash.get(ciudades[i])==vectorid[ii]){
          cout<<ciudades[i];
          myfile<<ciudades[i]; 
        }
        i++;
      }

      ii++;
      if(ii<vectorid.size()){
        cout<<"->";
        myfile<<"->";
      }
    }
    myfile<<endl;
    myfile.close();
    cout<<endl<<endl;
    }

    else if(decision==3){
    int arr[] = {1542, 9574, 3274, 6784, 1032};
    int n = sizeof(arr)/sizeof(arr[0]);
 
      pancakeSort(arr, n);
      cout<<"------------------------------------------------"<<endl;
      cout << "Desglose de líneas terrestres."<<endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << ": ";
        if(arr[i]==1542){
          cout << "Primera Plus."<<endl;
        }
        else if(arr[i]==9574){
          cout << "ETN."<<endl;
        }
        else if(arr[i]==3274){
          cout << "Omnibus de México."<<endl;
        }
        else if(arr[i]==6784){
          cout << "Estrella Roja."<<endl;
        }
        else if(arr[i]==1032){
          cout << "Turistar."<<endl;
        }
        else{
          cout << "ID de Línea de autobús no registrado"<<endl;
        }
    }

    }

    else if(decision==4){
    std::ofstream ofs;
    ofs.open("historial.txt", std::ofstream::out | std::ofstream::trunc);
    ofs<<"Historial de Búsqueda entre Ciudades:"<<endl;
    ofs.close();
    cout<<"------------------------------------------------"<<endl;
    cout<<"Historial correctamente eliminado." <<endl; 
    }
    cout<<"------------------------------------------------"<<endl;
    main();}
    else{
      cout<<"El archivo de ciudades fue modificado erróneamente. Coloque 8 ciudades con un Enter entre cada una para utilizar el programa."<<endl;
    }
    return 0;
}
