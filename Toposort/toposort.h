#ifndef TOPOSORT_H
#define TOPOSORT_H

#include <iostream>
#include "../STL/vector.h"
#include "../STL/queue.h"
#include "../STL/pair.h"

#define ll long long

class Toposort {
    public:
        vector<vector<pair<ll, ll>>> adj;
        vector<ll> inDegree;
        vector<char> cor;
        bool orientado;

        /* inicializa atributos necessários para o toposort a partir dos parâmetros*/
        void pre_sort(ll n, bool orientado);
        /* aplica a ordenação topológica sobre o grafo */
        void sort();
        /* verifica se grafo é orientado */
        bool valid();
};

#endif