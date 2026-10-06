
#include "BFS.h"
#include<iostream>
using std::cout;
using std::endl;

#define ll long long

void BFS::bfs(ll node){
    fila.push(node);
    cor[node]='C';
    d[node]=0;
    ordem.push_back(node);

    while (!fila.empty()){
        auto cur = fila.front();fila.pop();

        for (auto next : adj[cur]){
            if (cor[next]=='B'){
                cor[next]='C';
                d[next]=d[cur]+1;
                pai[next]=cur;
                ordem.push_back(next);
                fila.push(next);
            }
        }

        cor[cur]='P';
    }
}

void BFS::pre_bfs(ll u, ll origem){
    cor.resize(u,'B');
    pai.resize(u, -1);
    d.resize(u, 1e9);

    bfs(origem);

    for (ll node = 0; node < u; node++){
        if (cor[node]=='B'){
            bfs(node);
        }
    }
}

void BFS::imprimir(){
    cout << "Busca em largura: ";
    for (ll i = 0; i < ordem.size(); i++){
        if (i>0){
            cout << " - ";
        }
        cout << ordem[i];
    }
    cout << endl;
}