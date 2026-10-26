#include "./draw.h"

const char* getDOTstr(Graph graph) {
    std::string s;

    std::string edgeop;
    if (graph.orientado) {
        s += "digraph";
        edgeop = "->";
    }
    else {
        s += "graph";
        edgeop = "--";
    }

    s += "{";
    for(ll i = 0; i < graph.adj.size(); i++) {
        for(ll j = 0; j < graph.adj[i].size(); j++) {
            ll b = graph.adj[i][j].first, w = graph.adj[i][j].second;
            s += std::to_string(i) + edgeop + std::to_string(b) + "[label=" + std::to_string(w) + "];";
        }
    }

    s += "}";
    
    return s.c_str();
}

void draw(Graph graph) {
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();

    const char* c = getDOTstr(graph);

    // const char*c = R"(
    //     digraph G {
    //         a [color=blue, fontcolor=blue];
    //         b [color=blue, fontcolor=blue];

    //         c [color=red, fontcolor=red];
    //         d [color=red, fontcolor=red];

    //         a -> b;
    //         c -> d;
    //     }
    //     )";

    g = agmemread(c);
    gvLayout(gvc, g, "dot");
    gvRenderFilename (gvc, g, "png", "out.png");    
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}