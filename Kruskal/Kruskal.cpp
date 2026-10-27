#include "Kruskal.h"
#include<iostream>
using std::cout;
using std::endl;

#define ll long long

//encontra o pai do no atual e faz path compressing
ll Kruskal::find(ll x){
    if (parent[x]<0)return x;
    return find(parent[x]);
}

//une dois nós separados 
void Kruskal::unite(ll x,ll y){
    if(x==y)return;
    if (parent[x]<=parent[y]){
        parent[x]+=parent[y];
        parent[y]=x;
    }else{
        parent[y]+=parent[x];
        parent[x]=y;
    }
}

//ordena por mergesort
void Kruskal::ordenar(ll l,ll r){
    if (r-l<=1)return;
    ll m=(l+r)/2;
    ordenar(l,m);
    ordenar(m,r);

    ll i=l,j=m,k=l;
    while (i<m && j<r){
        if (arestas[i].w<=arestas[j].w)aux[k++]=arestas[i++];
        else aux[k++]=arestas[j++];
    }

    while (i<m)aux[k++]=arestas[i++];
    while (j<r)aux[k++]=arestas[j++];

    for (ll t = l; t < r; t++)arestas[t]=aux[t];
}

//passa por todas as arestas e monta a arvore 
void Kruskal::kruskal(){
    for (auto e: arestas){
        ll a=find(e.u),b=find(e.v);
        if(a!=b){
            unite(a,b);
            sum+=e.w;
            arvore.push_back(e);
            cons++;
            if(cons==n-1)break;
        }
    }
}

//inicialização
void Kruskal::pre_kruskal(ll u){
    n=u;
    parent.resize(n,-1);
    aux.resize(arestas.size());

    ordenar(0,arestas.size());
    kruskal();
}

//Impressão
void Kruskal::imprimir(){
    cout<<"peso total: "<<sum<<endl;
    cout<<"arestas:";
    for (auto e: arvore){
        cout<<" ("<<e.u<<","<<e.v<<")";
    }
    cout<<endl;
    if (cons<n-1){
        cout<<"O grafo e desconexo: o resultado e uma floresta geradora minima."<<endl;
    }
}