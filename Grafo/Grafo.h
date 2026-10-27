#ifndef GRAFO_H
#define GRAFO_H

#include "../STL/vector.h"
#include "../STL/pair.h"
#include<string>
#define ll long long

struct Aresta{
    ll u;
    ll v;
    ll w;
};

class Grafo{
    public:
        ll n = 0;
        bool orientado = false;
        bool carregado = false;
        bool peso_negativo = false;
        vector<vector<pair<ll,ll>>>adj;
        vector<Aresta>arestas;

        bool carregar(const std::string &caminho);
        void inserir_ordenado(ll u, ll v, ll w);
        void imprimir_info();
};

#endif