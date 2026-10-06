#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "vector.h"

template <typename T>
class priority_queue{
    public:
        void push(const T &valor);
        T& top();
        void pop();
        bool empty() const;

    private:
        vector<T> dados;

        void subir(long long i);
        void descer(long long i);
};

template <typename T>
void priority_queue<T>::push(const T &valor){
    dados.push_back(valor);
    subir(dados.size()-1);
}

template <typename T>
T& priority_queue<T>::top(){
    return dados[0];
}

template <typename T>
void priority_queue<T>::pop(){
    dados[0] = dados[dados.size()-1];
    dados.resize(dados.size()-1);
    if (dados.size()>0){
        descer(0);
    }
}

template <typename T>
bool priority_queue<T>::empty() const{
    return dados.size()==0;
}

template <typename T>
void priority_queue<T>::subir(long long i){
    while (i>0){
        long long pai = (i-1)/2;
        if (dados[pai]<dados[i]){
            T temp = dados[pai];
            dados[pai] = dados[i];
            dados[i] = temp;
            i = pai;
        } else {
            break;
        }
    }
}

template <typename T>
void priority_queue<T>::descer(long long i){
    long long n = dados.size();
    while (true){
        long long esquerdo = 2*i+1;
        long long direito = 2*i+2;
        long long maior = i;
        if (esquerdo<n && dados[maior]<dados[esquerdo]){
            maior = esquerdo;
        }
        if (direito<n && dados[maior]<dados[direito]){
            maior = direito;
        }
        if (maior==i){
            break;
        }
        T temp = dados[maior];
        dados[maior] = dados[i];
        dados[i] = temp;
        i = maior;
    }
}

#endif
