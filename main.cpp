
#include "BFS/BFS.h"
#include "DFS/DFS.h"
#include "Djikstra/Djikstra.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define ll long long

int main(){
    ll n, m, orientado;
    cin >> n >> m >> orientado;

    BFS b;
    DFS d;
    Djikstra dj;

    b.adj.resize(n);
    d.adj.resize(n);
    dj.adj.resize(n);

    bool tem_peso_negativo = false;

    for (ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;

        if (u<0 || u>=n || v<0 || v>=n){
            cout << "Vertice invalido: deve estar entre 0 e " << n-1 << "." << endl;
            return 0;
        }

        if (w<0){
            tem_peso_negativo = true;
        }

        b.adj[u].push_back(v);
        d.adj[u].push_back(v);
        dj.adj[u].push_back({w,v});

        if (orientado==0){
            b.adj[v].push_back(u);
            d.adj[v].push_back(u);
            dj.adj[v].push_back({w,u});
        }
    }

    ll origem;
    cin >> origem;

    if (origem<0 || origem>=n){
        cout << "Vertice invalido: deve estar entre 0 e " << n-1 << "." << endl;
        return 0;
    }

    d.pre_dfs(n, origem);
    b.pre_bfs(n, origem);

    d.imprimir();
    b.imprimir();

    if (tem_peso_negativo){
        cout << "Dijkstra: o algoritmo nao se aplica, pois o grafo possui aresta com peso negativo." << endl;
    } else {
        dj.pre_djikstra(n, origem);
        dj.imprimir();
    }

    return 0;
}
