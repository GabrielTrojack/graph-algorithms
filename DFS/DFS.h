#ifndef DFS_H
#define DFS_H

#include "../STL/vector.h"
#define ll long long

class DFS{
    public:
        ll timestamp = 0;
        vector<vector<ll>>adj;
        vector<char>cor;
        vector<ll>pai;
        vector<ll>d;
        vector<ll>f;
        vector<ll>ordem;

        void dfs(ll node);
        void pre_dfs(ll u, ll origem);
        void imprimir();
};

#endif