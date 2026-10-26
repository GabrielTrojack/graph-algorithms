
#include "DFS.h"
#include<iostream>
using std::cout;
using std::endl;

#define ll long long


void DFS::dfs(ll node){
    cor[node]='C';
    timestamp++;
    d[node]=timestamp;
    ordem.push_back(node);
    for (auto next : adj[node]){
        if (cor[next]=='B'){
            pai[next]=node;
            dfs(next);
        }
        else { // Ciclo quando é orientado
            directedCycle = true;
        }
    }
    timestamp++;
    f[node]=timestamp;
    cor[node]='P';
}

void DFS::pre_dfs(ll u, ll origem){
    cor.resize(u,'B');
    pai.resize(u, -1);
    d.resize(u, 0);
    f.resize(u, 0);

    dfs(origem);

    for (ll node = 0; node < u; node++){
        if (cor[node]=='B'){
            dfs(node);
        }
    }
}

void DFS::imprimir(){
    cout << "Busca em profundidade: ";
    for (ll i = 0; i < ordem.size(); i++){
        if (i>0){
            cout << " - ";
        }
        cout << ordem[i];
    }
    cout << endl;
}