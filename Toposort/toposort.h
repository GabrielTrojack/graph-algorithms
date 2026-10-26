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

        void pre_sort(ll n, bool orientado);
        void sort(bool directedCycle);
        bool valid(bool directedCycle);
};

#endif