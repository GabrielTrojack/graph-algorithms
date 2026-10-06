#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class vector{
    public:
        vector();
        vector(const vector<T> &outro);
        vector<T>& operator=(const vector<T> &outro);
        ~vector();

        void push_back(const T &valor);
        void resize(long long n);
        void resize(long long n, const T &valor);
        long long size() const;
        T& operator[](long long i);
        const T& operator[](long long i) const;
        T* begin();
        T* end();
        const T* begin() const;
        const T* end() const;

    private:
        T* dados;
        long long tamanho;
        long long capacidade;

        void copiar_de(const vector<T> &outro);
        void liberar();
        void garantir_capacidade(long long nova_capacidade);
};

template <typename T>
vector<T>::vector(){
    dados = nullptr;
    tamanho = 0;
    capacidade = 0;
}

template <typename T>
vector<T>::vector(const vector<T> &outro){
    dados = nullptr;
    tamanho = 0;
    capacidade = 0;
    copiar_de(outro);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T> &outro){
    if (this!=&outro){
        liberar();
        copiar_de(outro);
    }
    return *this;
}

template <typename T>
vector<T>::~vector(){
    liberar();
}

template <typename T>
void vector<T>::copiar_de(const vector<T> &outro){
    capacidade = outro.capacidade;
    tamanho = outro.tamanho;
    if (capacidade>0){
        dados = new T[capacidade];
        for (long long i = 0; i < tamanho; i++){
            dados[i] = outro.dados[i];
        }
    } else {
        dados = nullptr;
    }
}

template <typename T>
void vector<T>::liberar(){
    delete[] dados;
    dados = nullptr;
    tamanho = 0;
    capacidade = 0;
}

template <typename T>
void vector<T>::garantir_capacidade(long long nova_capacidade){
    if (nova_capacidade<=capacidade){
        return;
    }
    long long nova = capacidade==0 ? 1 : capacidade*2;
    if (nova<nova_capacidade){
        nova = nova_capacidade;
    }
    T* novo_dados = new T[nova];
    for (long long i = 0; i < tamanho; i++){
        novo_dados[i] = dados[i];
    }
    delete[] dados;
    dados = novo_dados;
    capacidade = nova;
}

template <typename T>
void vector<T>::push_back(const T &valor){
    garantir_capacidade(tamanho+1);
    dados[tamanho] = valor;
    tamanho++;
}

template <typename T>
void vector<T>::resize(long long n){
    garantir_capacidade(n);
    if (n>tamanho){
        for (long long i = tamanho; i < n; i++){
            dados[i] = T();
        }
    }
    tamanho = n;
}

template <typename T>
void vector<T>::resize(long long n, const T &valor){
    garantir_capacidade(n);
    if (n>tamanho){
        for (long long i = tamanho; i < n; i++){
            dados[i] = valor;
        }
    }
    tamanho = n;
}

template <typename T>
long long vector<T>::size() const{
    return tamanho;
}

template <typename T>
T& vector<T>::operator[](long long i){
    return dados[i];
}

template <typename T>
const T& vector<T>::operator[](long long i) const{
    return dados[i];
}

template <typename T>
T* vector<T>::begin(){
    return dados;
}

template <typename T>
T* vector<T>::end(){
    return dados+tamanho;
}

template <typename T>
const T* vector<T>::begin() const{
    return dados;
}

template <typename T>
const T* vector<T>::end() const{
    return dados+tamanho;
}

#endif
