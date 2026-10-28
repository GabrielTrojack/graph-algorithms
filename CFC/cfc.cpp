
#include "cfc.h"

void CFC::dfs(ll x, vector<vector<pair<ll, ll>>> &adjl,
              Componente *comp) {
    cor[x] = 'C';

    if (comp != NULL) {
        comp->vertices.push_back(x);
    }

    for (ll i = 0; i < adjl[x].size(); i++) {
        ll next = adjl[x][i].first;

        if (cor[next] == 'B') {
            dfs(next, adjl, comp);
        }
    }

    ordem.push_back(x);
    cor[x] = 'P';
}

void CFC::defineCor(Componente &comp) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 255);

    uint32_t cor = (dist(rng) << 16)
                 | (dist(rng) << 8)
                 | dist(rng);

    comp.cor = cor;
}

void CFC::insere_ordenado(Componente &comp) {
    componentes.push_back(comp);

    if (componentes.size() > 1) {
        for (ll i = componentes.size() - 2; i >= 0; i--) {
            Componente atual = componentes[i + 1];

            if (atual.vertices.size() < componentes[i].vertices.size()) {
                Componente temp = componentes[i];
                componentes[i] = atual;
                componentes[i + 1] = temp;
            }
            else {
                break;
            }
        }
    }
}

void CFC::imprime(vector<Componente> &componentes) {
    for (ll i = componentes.size() - 1, k = 1;
         i >= 0; i--, k++) {
        std::cout << "Componente " << k << ": ";

        for (ll j = 0; j < componentes[i].vertices.size(); j++) {
            std::cout << componentes[i].vertices[j]
                      << ((j == componentes[i].vertices.size() - 1)
                          ? " " : ", ");
        }

        std::cout << std::endl;
    }
}

void CFC::cfc() {
    cor.resize(adj.size());
    componentes.resize(0);
    ordem.resize(0);

    for (ll i = 0; i < cor.size(); i++) {
        cor[i] = 'B';
    }

    for (ll i = 0; i < adj.size(); i++) {
        if (cor[i] == 'B') {
            dfs(i, adj, NULL);
        }
    }

    for (ll i = 0; i < cor.size(); i++) {
        cor[i] = 'B';
    }

    for (ll i = ordem.size() - 1; i >= 0; i--) {
        ll x = ordem[i];

        if (cor[x] == 'B') {
            Componente comp;
            defineCor(comp);

            dfs(x, adjTrans, &comp);

            insere_ordenado(comp);
        }
    }

    imprime(componentes);
}
