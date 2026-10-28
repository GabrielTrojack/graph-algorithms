#ifndef DRAW_GRAPH_H
#define DRAW_GRAPH_H

#define ll long long

#include "../STL/vector.h"
#include "../STL/pair.h"

#include <gvc.h>
#include <iostream>
#include <string>
#include "../Grafo/Grafo.h"
#include "../CFC/cfc.h"
#include "../Kruskal/Kruskal.h"

/* função central que recebe o grafo, e atributos para colorir os nós e arestas. 
    utiliza a biblioteca graphviz
*/
void draw(Grafo graph, std::string attributes, std::string edgeAtt);
/* função que recebe informações dos componentes conexos e repassa para a função de desenho
    central com atributos para colorir os nós das componentes */
void draw_cfc(CFC cfc);
/* função que recebe informações do algoritmo kruskal e repassa para a função de desenho central
 com atributos para colorir as arestas da mst*/
void draw_kruskal(Kruskal kruskal);
/* função que vai criar a definição do grafo a ser lido pela biblioteca graphviz em linguagem DOT.
  recebe o grafo, e atributos para colorir os nós e arestas*/
std::string getDOTstr(Grafo graph, std::string attributes, std::string edgeAtt);

#endif