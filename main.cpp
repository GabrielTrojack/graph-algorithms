#include "Grafo/Grafo.h"
#include "BFS/BFS.h"
#include "DFS/DFS.h"
#include "Djikstra/Djikstra.h"
#include "Toposort/toposort.h"
#include "Kruskal/Kruskal.h"
#include "CFC/cfc.h"
#include "draw/draw.h"
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

#define ll long long

void copiar_vizinhos(Grafo &g, vector<vector<ll>> &adj){
    adj.resize(g.n);
    for (ll u = 0; u < g.n; u++){
        for (auto par : g.adj[u]){
            adj[u].push_back(par.first);
        }
    }
}

void copiar_para_cfc(Grafo &g, vector<vector<pair<ll, ll>>> &adj) {
    adj.resize(g.n);

    for (ll u = 0; u < g.n; u++) {
        for (auto par : g.adj[u]) {
            adj[u].push_back({par.first, par.second});
        }
    }
}

void copiar_vizinhos_transposto(Grafo &g, vector<vector<pair<ll, ll>>> &adj) {
    adj.resize(g.n);
    for (ll u = 0; u < g.n; u++){
        for (auto par : g.adj[u]){
            adj[par.first].push_back({u, par.second});
        }
    }
}

void copiar_para_djikstra(Grafo &g, vector<vector<pair<ll,ll>>> &adj){
    adj.resize(g.n);
    for (ll u = 0; u < g.n; u++){
        for (auto par : g.adj[u]){
            adj[u].push_back({par.second, par.first});
        }
    }
}

bool ler_numero(ll &x){
    if (cin >> x){
        return true;
    }
    if (!cin.eof()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida: digite um numero." << endl;
    }
    return false;
}

bool ler_origem(Grafo &g, ll &origem){
    cout << "Vertice de origem (0 a " << g.n-1 << "): ";
    if (!ler_numero(origem)){
        return false;
    }
    if (origem<0 || origem>=g.n){
        cout << "Vertice invalido: deve estar entre 0 e " << g.n-1 << "." << endl;
        return false;
    }
    return true;
}

void imprimir_menu(Grafo &g){
    cout << endl;
    cout << "1 - Carregar grafo" << endl;
    if (g.carregado){
        cout << "2 - Busca em profundidade" << endl;
        cout << "3 - Busca em largura" << endl;
        cout << "4 - Ordenacao topologica" << endl;
        cout << "5 - Dijkstra" << endl;
        cout << "6 - Kruskal" << endl;
        cout << "7 - CFC" << endl;
    }
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
}

int main(){
    Grafo atual;

    while (true){
        imprimir_menu(atual);

        ll opcao;
        if (!ler_numero(opcao)){
            if (cin.eof()){
                break;
            }
            continue;
        }

        if (opcao==0){
            break;
        }

        if (opcao!=1 && (!atual.carregado || opcao<0 || opcao>7)){
            cout << "Opcao invalida." << endl;
            continue;
        }

        switch (opcao){
            case 1: {
                string caminho;
                cout << "Caminho do arquivo: ";
                cin >> std::ws;
                getline(cin, caminho);

                Grafo novo;
                if (novo.carregar(caminho)){
                    atual = novo;
                    atual.imprimir_info();
                } else {
                    cout << "Erro: nao foi possivel carregar o grafo do arquivo." << endl;
                }
                break;
            }
            case 2: {
                ll origem;
                if (ler_origem(atual, origem)){
                    DFS d;
                    copiar_vizinhos(atual, d.adj);
                    d.pre_dfs(atual.n, origem);
                    d.imprimir();

                    draw(atual, "", "");
                }
                break;
            }
            case 3: {
                ll origem;
                if (ler_origem(atual, origem)){
                    BFS b;
                    copiar_vizinhos(atual, b.adj);
                    b.pre_bfs(atual.n, origem);
                    b.imprimir();

                    draw(atual, "", "");
                }
                break;
            }
            case 4: {
                DFS d;
                copiar_vizinhos(atual, d.adj);
                d.pre_dfs(atual.n, 0);

                Toposort ts;
                ts.pre_sort(atual.n, atual.orientado);
                ts.adj = atual.adj;
                for (auto a : atual.arestas){
                    ts.inDegree[a.v]++;
                }
                ts.sort();
                
                draw(atual, "", "");
                break;
            }
            case 5: {
                if (atual.peso_negativo){
                    cout << "Nao foi possivel realizar o algoritmo,  pois o grafo possui aresta com peso negativo." << endl;
                    break;
                }
                ll origem;
                if (ler_origem(atual, origem)){
                    Djikstra dj;
                    copiar_para_djikstra(atual, dj.adj);
                    dj.pre_djikstra(atual.n, origem);
                    dj.imprimir();

                    draw(atual, "", "");
                }
                break;
            }
            case 6: {
                if (atual.orientado){
                    cout << "O algoritmo nao se aplica, pois o grafo e orientado." << endl;
                    break;
                }
                Kruskal k;
                k.arestas = atual.arestas;
                k.pre_kruskal(atual.n);
                k.imprimir();
                
                draw_kruskal(k);
                break;
            }
            case 7: {
                if (!atual.orientado) {
                    cout << "O algoritmo nao se aplica, pois o grafo nao e orientado" << endl;
                    break;
                }

                CFC c;
                copiar_para_cfc(atual, c.adj);
                copiar_vizinhos_transposto(atual, c.adjTrans);
                c.cfc();

                draw_cfc(c);

                break;
            }
        }
    }

    return 0;
}