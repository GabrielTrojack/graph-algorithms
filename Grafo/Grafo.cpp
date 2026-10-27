#include "Grafo.h"
#include<cstdio>
#include<fstream>
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::string;

#define ll long long

bool Grafo::carregar(const string &caminho){
    ifstream arquivo(caminho);
    if (!arquivo){
        return false;
    }

    string linha;

    getline(arquivo, linha);
    if (linha.find("orientado=sim")!=string::npos){
        orientado = true;
    } else if (linha.find("orientado=nao")!=string::npos){
        orientado = false;
    } else {
        return false;
    }

    getline(arquivo, linha);
    if (sscanf(linha.c_str(), " V = %lld", &n)!=1 || n<=0){
        return false;
    }

    adj.resize(n);

    while (getline(arquivo, linha)){
        ll u, v, w;
        if (sscanf(linha.c_str(), " ( %lld , %lld ) : %lld", &u, &v, &w)!=3 || u<0 || u>=n || v<0 || v>=n){
            return false;
        }

        inserir_ordenado(u, v, w);
        if (!orientado && u!=v){
            inserir_ordenado(v, u, w);
        }
        arestas.push_back({u, v, w});

        if (w<0){
            peso_negativo = true;
        }
    }

    carregado = true;
    return true;
}

void Grafo::inserir_ordenado(ll u, ll v, ll w){
    adj[u].push_back({v, w});
    ll i = adj[u].size()-1;
    while (i>0 && adj[u][i]<adj[u][i-1]){
        pair<ll,ll> temp = adj[u][i];
        adj[u][i] = adj[u][i-1];
        adj[u][i-1] = temp;
        i--;
    }
}

void Grafo::imprimir_info(){
    cout << "Grafo carregado: ";
    if (orientado){
        cout << "orientado";
    } else {
        cout << "nao orientado";
    }
    cout << ", " << n << " vertices, " << arestas.size() << " arestas." << endl;
}