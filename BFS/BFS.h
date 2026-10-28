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

        /* executa a busca em largura a partir do nó informado */
        void bfs(ll node);
        /* inicializa os atributos necessários e executa o bfs a partir da origem, cobrindo componentes desconexos */
        void pre_bfs(ll u, ll origem);
        /* imprime a ordem de visitação da busca em largura */
        void imprimir();
};

#endif