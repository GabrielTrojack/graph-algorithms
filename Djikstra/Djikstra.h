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

        void djikstra(ll node);
        void pre_djikstra(ll u, ll origem);
        void imprimir();
};

#endif