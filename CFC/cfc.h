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

class Componentes {
    uint32_t cor;
    vector<ll> vertices;
};

class CFC {
    public:
        vector<vector<pair<ll, ll>>>adj;
        vector<vector<pair<ll, ll>>> adjTrans;
        vector<char>cor;
        vector<ll>pai;
        vector<ll>d;
        vector<ll>f;
        vector<Componentes> componentes;
        bool orientado;

        void cfc();
        void dfs();
};

#endif