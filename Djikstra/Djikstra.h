#ifndef Djikstra_H
#define Djikstra_H

#include "../STL/vector.h"
#include "../STL/pair.h"
#include "../STL/priority_queue.h"
#define ll long long

class Djikstra{
    public:
        ll timestamp = 0;
        vector<vector<pair<ll,ll>>>adj;
        vector<char>cor;
        vector<ll>pai;
        vector<ll>d;
        priority_queue<pair<ll,ll>>fila;

        /* executa o algoritmo de menor caminho com uma fila de prioridade */
        void djikstra(ll node);
        /* inicializa os atributos necessários e executa o djikstra a partir da origem */
        void pre_djikstra(ll u, ll origem);
        /* imprime a menor distância da origem até cada vértice */
        void imprimir();
};

#endif