#include "./draw.h"

std::string getDOTstr(Grafo graph, std::string attributes, std::string edgeAtt) {
    std::string s = "strict ";

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

    if (attributes!= "") {
        s += attributes;
    }
    
    for(ll i = 0; i < graph.adj.size(); i++) {
        for(ll j = 0; j < graph.adj[i].size(); j++) {
            ll b = graph.adj[i][j].first, w = graph.adj[i][j].second;
            s += std::to_string(i) + edgeop + std::to_string(b) + "[label=" + std::to_string(w) + "];";
        }
    }

    if (edgeAtt != "") s += edgeAtt;

    s += "}";
    
    return s;
}

void draw_kruskal(Kruskal kruskal) {
    Grafo g;
    g.orientado = false;
    g.adj.resize(kruskal.n);

    for(auto a: kruskal.arestas) {
        g.adj[a.u].push_back({a.v, a.w});
    }

    std::string attributes = "";
    for(auto a: kruskal.arvore) {
        attributes += std::to_string(a.u);
        attributes += " -- ";
        attributes += std::to_string(a.v);
        attributes += " [color=red];";
    }

    draw(g, "", attributes);
}

void draw_cfc(CFC cfc) {
    Grafo g;
    g.orientado = true;
    g.adj = cfc.adj;

    std::string attributes = "";
    for(ll i = 0; i < cfc.componentes.size(); i++) {
        for(ll j = 0; j < cfc.componentes[i].vertices.size(); j++) {
            ll x = cfc.componentes[i].vertices[j];
            attributes += std::to_string(x);
            attributes += " [color=\"";
            
            std::stringstream ss;
            ss << "#" << std::uppercase << std::hex
            << std::setw(6) << std::setfill('0') << cfc.componentes[i].cor;

            std::string corHex = ss.str();

            attributes += corHex;
            attributes += "\", fontcolor=\"";
            attributes += corHex;
            attributes += "\"];";
        }
    }

    draw(g, attributes, "");
}

void draw(Grafo graph, std::string attributes, std::string edgeAtt) {
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();

    std::string c = getDOTstr(graph, attributes, edgeAtt);

    g = agmemread(c.c_str());
    gvLayout(gvc, g, "dot");
    gvRenderFilename (gvc, g, "png", "out.png");    
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}