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

        /* encontra o representante do conjunto de x fazendo path compression */
        ll find(ll x);
        /* une os conjuntos de x e y por tamanho */
        void unite(ll x,ll y);
        /* ordena as arestas por peso utilizando mergesort */
        void ordenar(ll l,ll r);
        /* percorre as arestas ordenadas e monta a árvore geradora mínima */
        void kruskal();
        /* inicializa os atributos necessários, ordena as arestas e executa o kruskal */
        void pre_kruskal(ll u);
        /* imprime o peso total e as arestas da árvore geradora mínima */
        void imprimir();
};

#endif
