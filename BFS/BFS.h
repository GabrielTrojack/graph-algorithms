#ifndef BFS_H
#define BFS_H

#include "../STL/vector.h"
#include "../STL/queue.h"
#define ll long long

class BFS{
    public:
        ll timestamp = 0;
        vector<vector<ll>>adj;
        vector<char>cor;
        vector<ll>pai;
        vector<ll>d;
        vector<ll>ordem;
        queue<ll>fila;

        void bfs(ll node);
        void pre_bfs(ll u, ll origem);
        void imprimir();
};

#endif