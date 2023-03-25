//
// Created by asus on 5/14/2022.
//

#ifndef PROIECT_SDA_REPOSITORYMULTIMAP_H
#define PROIECT_SDA_REPOSITORYMULTIMAP_H
#include "../TAD/MultiMap.h"

template <class Key, class Value>
class RepositoryMultiMap {
private:
    Multimap<Key, Value> multiMapElems;
public:
    /// Constructor fara parametri
    RepositoryMultiMap(){};

    /// Constructor cu parametri
    RepositoryMultiMap(const Multimap<Key, Value> &multiMapElems) : multiMapElems(multiMapElems) {}

    /// Destructor
    virtual ~RepositoryMultiMap() = default;

    /// Returneaza toate elementele din lista de la o key data
    /// key - keya data
    /// \return - un vector cu elementele din lista
    vector<Value> getKeyElems(Key key){
        return multiMapElems.searchMapNodeAdress(key);
    }

    /// Returneaza lista de kei
    /// \return keyle din multidictionar
    vector<Key> getKeys(){
        return multiMapElems.keyList();
    }

    /// Adauga un element in lista, la o anumita cheie
    /// \param key - keya la care dorim sa adaugam noua valoare
    /// \param value - noua valoare pe care vrem sa o adaugam la cheia data
    void add(Key key, Value value){
        multiMapElems.put(key, value);
    }

    /// Sterge o cheie si lista de valori
    /// \param key - cheia pe care dorim sa o stergem alaturi de lista de valori
    void removeKey(Key key){
        multiMapElems.remove(key);
    }

    /// Sterge o valoare de la o cheie data
    /// \param key keia de la care dorim sa stergem o valoare
    /// \param value valoarea pe care dorim sa o stergem
    void removeValue(Key key, Value value){
        multiMapElems.remove(key, value);
    }

    /// Afla nr de elemente din multidictionar(nr de key)
    /// \return nr de elemente din multidictionar
    int getSize(){
        return multiMapElems.getSize();
    }

};


#endif //PROIECT_SDA_REPOSITORYMULTIMAP_H
