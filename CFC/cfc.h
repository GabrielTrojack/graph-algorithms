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
        vector<vector<ll>>adj;
        vector<vector<ll>> adjTrans;
        vector<char>cor;
        vector<ll>d;
        vector<ll>f;
        vector<ll> ordem;
        vector<Componente> componentes;
        bool orientado;

        void cfc();
        void defineCor(Componente &comp);
        void imprime(vector<Componente> &componentes);
        void insere_ordenado(Componente &comp);
        void dfs(ll x, vector<vector<ll>> &adjl, Componente *comp);
};

#endif