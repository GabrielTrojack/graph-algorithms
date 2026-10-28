
#include "Djikstra.h"
#include<iostream>
using std::cout;
using std::endl;

#define ll long long

void Djikstra::djikstra(ll node){
    fila.push({0,node});
    cor[node]='C';
    d[node]=0;

    while (!fila.empty()){
        auto [cur_w, cur_node] = fila.top();fila.pop();
        cur_w*=-1;

        if (cur_w>d[cur_node]){
            continue;
        }

        for (auto [next_w, next_node] : adj[cur_node]){
            if (d[cur_node]+next_w<d[next_node]){
                d[next_node]=d[cur_node]+next_w;
                pai[next_node]=cur_node;
                fila.push({-d[next_node],next_node});
            }
        }
    }
}

void Djikstra::pre_djikstra(ll u, ll origem){
    cor.resize(u,'B');
    pai.resize(u, -1);
    d.resize(u, 1e9);

    djikstra(origem);
}

void Djikstra::imprimir(){
    cout << "Dijkstra:" << endl;
    for (ll v = 0; v < d.size(); v++){
        cout << v << ": ";
        if (d[v]>=1e9){
            cout << "infinito";
        } else {
            cout << d[v];
        }
        cout << endl;
    }
}
