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

void draw(Grafo graph, std::string attributes, std::string edgeAtt);
void draw_cfc(CFC cfc);
void draw_kruskal(Kruskal kruskal);
std::string getDOTstr(Grafo graph, std::string attributes, std::string edgeAtt);

#endif