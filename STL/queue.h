#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue{
    public:
        queue();
        ~queue();

        void push(const T &valor);
        T& front();
        void pop();
        bool empty() const;

    private:
        struct No{
            T valor;
            No* proximo;
        };

        No* inicio;
        No* fim;
};

template <typename T>
queue<T>::queue(){
    inicio = nullptr;
    fim = nullptr;
}

template <typename T>
queue<T>::~queue(){
    while (!empty()){
        pop();
    }
}

template <typename T>
void queue<T>::push(const T &valor){
    No* novo = new No{valor, nullptr};
    if (fim==nullptr){
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
}

template <typename T>
T& queue<T>::front(){
    return inicio->valor;
}

template <typename T>
void queue<T>::pop(){
    No* antigo = inicio;
    inicio = inicio->proximo;
    if (inicio==nullptr){
        fim = nullptr;
    }
    delete antigo;
}

template <typename T>
bool queue<T>::empty() const{
    return inicio==nullptr;
}

#endif
