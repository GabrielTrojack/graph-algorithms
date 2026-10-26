#include "toposort.h"

void Toposort::pre_sort(ll n, bool orientado) {
    this->orientado = orientado;
    this->adj.resize(n);
    this->inDegree.resize(n, 0);
}

bool Toposort::valid(bool directedCycle) {
    if (!this->orientado) {
        std::cout << "Toposort: Nao foi possivel realizar o algoritmo pois o grafo nao e orientado\n";
        return false;
    }

    if (directedCycle) {
        std::cout << "Toposort: Nao foi possivel realizar o algoritmo pois o grafo possui ciclo\n";
        return false;
    }

    return true;
}

void Toposort::sort(bool directedCycle) {
    // verifica se é orientado e se é aciclico
    if (!valid(directedCycle)) return;

    queue<ll> q;

    for(ll i = 0; i < this->inDegree.size(); i++) {
        if(inDegree[i] == 0) q.push(i);
    }

    std::cout << "Ordem topologica: ";
    ll i = 0;
    while(!q.empty()) {
        ll x = q.front();
        if (i>0) std::cout << " - ";
        std::cout << x;
        q.pop();

        for(ll i = 0; i < this->adj[x].size(); i++) {
            ll y = this->adj[x][i].first;

            this->inDegree[y]--;
            if (this->inDegree[y]==0) q.push(y);
        }

        i++;
    }

    std::cout << "\n";
};