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
        bool directedCycle;

        /* executa a busca em profundidade a partir do nó informado, marcando ciclo quando orientado */
        void dfs(ll node);
        /* inicializa os atributos necessários e executa o dfs a partir da origem, cobrindo componentes desconexos */
        void pre_dfs(ll u, ll origem);
        /* imprime a ordem de visitação da busca em profundidade */
        void imprimir();
};

#endif