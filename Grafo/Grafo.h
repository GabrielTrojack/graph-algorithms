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

        /* carrega o grafo a partir de um arquivo no formato orientado=sim|nao, V=n, (u,v):w */
        bool carregar(const std::string &caminho);
        /* insere a aresta (v,w) na lista de adjacência de u mantendo a ordenação */
        void inserir_ordenado(ll u, ll v, ll w);
        /* imprime informações gerais do grafo carregado */
        void imprimir_info();
};

#endif