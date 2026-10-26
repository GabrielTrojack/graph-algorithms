#ifndef DRAW_GRAPH_H
#define DRAW_GRAPH_H

#define ll long long

#include "../STL/vector.h"
#include "../STL/pair.h"

#include <gvc.h>
#include <iostream>
#include <string>

class Graph {
    public:
        vector<vector<pair<ll,ll>>>adj;        
        bool orientado;
};

void draw(Graph graph);
const char* getDOTstr(Graph graph);

#endif