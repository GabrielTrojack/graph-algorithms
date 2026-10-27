#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../STL/vector.h"
#include "../Grafo/Grafo.h"
#define ll long long

class Kruskal{
    public:
        ll n=0;
        ll sum=0;
        ll cons=0;
        vector<ll>parent;
        vector<Aresta>arestas;
        vector<Aresta>aux;
        vector<Aresta>arvore;

        ll find(ll x);
        void unite(ll x,ll y);
        void ordenar(ll l,ll r);
        void kruskal();
        void pre_kruskal(ll u);
        void imprimir();
};

#endif
