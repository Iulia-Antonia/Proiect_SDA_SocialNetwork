//
// Created by asus on 5/13/2022.
//

#ifndef PROIECT_SDA_REPOSITORYLIST_H
#define PROIECT_SDA_REPOSITORYLIST_H
#include "../TAD/List.h"
#include "vector"

template <class T>
class RepositoryList {
private:
    List<T> listElems;
public:
    /// Constructor fara parametrii
    RepositoryList(){
    };
    /// Constructor de copiere
    RepositoryList(const List<T> &listElems) : listElems(listElems) {}
    /// Destructor
    virtual ~RepositoryList() = default;


    /// Setter pentru elementele memorate
    void setListElems(const List<T> &listElems) {
        RepositoryList::listElems = listElems;
    }


    /// Returneaza toate elementele din lista
    /// \return - un vector cu elementele din lista
    vector<T> getListElems(){
        vector<T> elemente;
        for(int i = listElems.size()-1;i>=0;i--){
            elemente.push_back(listElems.get(i));
        }
        return elemente;
    }


    /// Adauga un element in lista
    /// \param element - elementul pe care dorim sa il adaugam in lista
    void add(T element){
        listElems.add(element);
    }


    /// Modifica(updateaza) un element din lista
    /// \param oldElem - elementul pe care dorim sa il modificam
    /// \param newElem - valoarea noua pe care vrem sa o dam elementului
    void update(T oldElem, T newElem){
        listElems.update(oldElem, newElem);
    }


    /// Sterge un element din lista, cu toate aparitiile lui
    /// \param element - elementul pe care dorim sa il stergem
    void remove(T element){
        listElems.remove(element);
    }


    /// Afla nr de elemente din lista
    /// \return nr de elemente din lista
    int getSize(){
        return listElems.size();
    }


    /// Verifica daca un element este sau nu in lista
    /// \param element - elementul pe care il cautam in lista
    /// \return true - daca elementul dat este in lista, false - in caz contrar
    bool search(T element){
        for(int i=0;i<getSize();i++)
            if(listElems.get(i)==element)return true;
        return false;
    }


    /// Cauta elementul de pe o pozitie data
    /// \param pozitie - pozitia de pe care vrem sa luam elementul
    /// \return elementul de pe pozitia pozitie
    T getElem(int pozitie){
        return listElems.get(pozitie);
    }

};


#endif //PROIECT_SDA_REPOSITORYLIST_H
