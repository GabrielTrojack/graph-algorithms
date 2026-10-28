#ifndef CFC_H
#define CFC_H

#include <cstdint>
#include <random>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "../STL/vector.h"
#include "../STL/pair.h"

#define ll long long

class Componente {
    public:
        uint32_t cor;
        vector<ll> vertices;
};

class CFC {
    public:
        vector<vector<pair<ll, ll>>> adj;
        vector<vector<pair<ll, ll>>> adjTrans;
        vector<char> cor;
        vector<ll> d;
        vector<ll> f;
        vector<ll> ordem;
        vector<Componente> componentes;
        bool orientado;

        /* aplica o algoritmo de componentes fortemente conexas */
        void cfc();
        /* gera uma cor aleatória para o componente */
        void defineCor(Componente &comp);
        /* imprime os componentes em ordem decrescente */
        void imprime(vector<Componente> &componentes);
        /* insere o maior em primeiro na lista de componentes */
        void insere_ordenado(Componente &comp);
        /* busca em profundidade utilizada no percuso do grafo normal e do transposto,
            e se for no grafo transposto, adiciona os nós no componente informado
        */
        void dfs(ll x, vector<vector<pair<ll, ll>>> &adjl,
                 Componente *comp);
};

#endif
