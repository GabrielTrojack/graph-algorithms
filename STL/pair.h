#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
struct pair{
    A first;
    B second;

    bool operator<(const pair<A,B> &outro) const{
        if (first<outro.first){
            return true;
        }
        if (outro.first<first){
            return false;
        }
        return second<outro.second;
    }
};

#endif
