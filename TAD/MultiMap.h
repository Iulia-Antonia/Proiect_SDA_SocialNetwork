//
// Created by asus on 5/9/2022.
//

#ifndef PROIECT_SDA_MULTIMAP_H
#define PROIECT_SDA_MULTIMAP_H

#include <iostream>
#include <vector>
using namespace std;
template <class Key, class Value>
class Multimap {
private:
    template <class K, class V>
    class MapNode {
    public:
        K key;
        V value;
        MapNode<K,V>* next;
        /// Constructorul unui nou nod al multidictionarului
        MapNode(K key, V value) : key(key), value(value){ this->next= nullptr;}
    };

    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        /// Constructorii si destructorul pentru lista de noduri a unui nod al multidictionarului
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
        ~ListNode(){
        };
    };

    int size;
    MapNode<Key,ListNode<Value>*>* first;

    /// afla adresa unei chei (cheia e unica)
    /// \param k cheia careia vrem sa ii aflam adresa
    /// \return adresa cheii k
    MapNode<Key, ListNode<Value>*>* searchAdress(Key k){
        if(this->size == 0) return nullptr;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p->next != nullptr){
            if(p->key == k) return p;
            p = p->next;
        }
        return p;
    };

    /// Veerifica daca o cheie exista sau nu in multidictionar
    /// \param k cheia cautata
    /// \return true - daca cheia k exista in multidictionar
    ///         false - daca cheia k nu exista in multidictionar
    bool searchAdressTrueFalse(Key k){
        if(this->size == 0) return false;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p->next != nullptr){
            if(p->key == k) return true;
            p = p->next;
        }
        if(p->key == k) return true;
        return false;
    };


public:
    /// Constructorul fara parametrii al multidictionarului
    Multimap(){
        this->first = nullptr;
        this->size = 0;
    }
    /// Destructorul multidictionarului
    ~Multimap(){};

    /// Adauga in multidictionar o pereche cheie valoare, daca cheia data nu exista deja, sau adauga noile valori daca cheia exista deja
    /// \param key cheia din perechea de adugat
    /// \param value valoarea din perechea de adugat
    void put(Key key, Value value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if(poz == nullptr){
            this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
            this->size++;
        }
        else{
            if(poz->key == key){  //cazul:exista in disctionar o pereche cu cheia egala cu key
                ListNode<Value>* node = new ListNode<Value>(value, poz->value);
                poz->value = node;
            }else{
                poz->next = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
                this->size++;
            }
        }
    }

    /// Sterge din multidictionar o cheie si valoarea acesteia
    /// \param key cheia pe care dorim sa o stergem
    void remove(Key key){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if(poz != nullptr && poz->key == key){
            MapNode<Key, ListNode<Value>*>* p = first;
            if(poz == first) this->first = poz->next;
            else {
                while(p->next != poz) p = p->next;
                p->next = poz->next;
            };
            while(poz->value != nullptr){
                ListNode<Value>* node = poz->value;
                poz->value = node->next;
                delete node;
            }
            this->size--;
            delete poz;
        }
    }

    /// Sterge din multidictionar una dintre valorile listei de la adresa key
    /// \param key cheia unde se afla valoarea pe care vrem sa o stergem
    /// \param value valoarea pe care dorim sa o stergem
    void remove(Key key, Value value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
        while(searchValue(key,value)) {
            if (poz != nullptr && poz->key == key) {
                ListNode<Value> *p = poz->value;
                if (p->info == value) {
                    ListNode<Value> *nodeToDelete = poz->value;
                    poz->value = p->next;
                    delete nodeToDelete;
                    nodeToDelete = nullptr;
                } else {
                        ListNode<Value> *nodeToDelete = nullptr;
                        while (p->next->info != value && p->next != nullptr) {
                            p = p->next;
                        }
                        if (p->next != nullptr) {
                            nodeToDelete = p->next;
                            p->next = p->next->next;
                            delete nodeToDelete;
                            nodeToDelete = nullptr;
                        }
                }
            }
        }
    }

    /// Cauta lista de valori de la adresa key
    /// \param key cheia de unde luam valorile
    /// \return lista de valori de la cheia key
    vector<Value> searchMapNodeAdress(Key key){
        vector<Value> result;
        if(searchAdressTrueFalse(key)) {
            MapNode<Key, ListNode<Value> *> *poz = searchAdress(key);
            if (poz != nullptr) {
                ListNode<Value> *p = poz->value;
                while (p != NULL && p->next != nullptr) {
                    result.push_back(p->info);
                    p = p->next;
                }
                if (p != NULL)result.push_back(p->info);
            }
        }
        return result;
    }

    /// Cauta o valoare la adresa key
    /// \param key cheia unde cautam valoarea
    /// \param value valoarea pe care o cautam
    /// \return true - daca exista valoarea value la cheia key
    ///         false -  in caz contrar
    bool searchValue(Key key,Value value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
        ListNode<Value>* p = poz->value;
        while(p!= NULL && p->next!= nullptr){
            if(p->info == value)return true;
            p = p->next;
        }
        if(p!=NULL && p->info == value)return true;
        return false;
    }

    /// Returneaza numarul de key din multidictionar
    /// \return numarul de key din multidictionar
    int getSize(){
        return size;
    }

    /// Formeaza o lista cu toate cheile din multidictionar
    /// \return lista de chei din multidictionar
    vector<Key> keyList(){
        vector<Key> result;
        MapNode<Key, ListNode<Value>*>* poz = this->first;
        while(poz->next!= nullptr){
            result.push_back(poz->key);
            poz = poz->next;
        }
        result.push_back(poz->key);
        return result;
    }

};



#endif //PROIECT_SDA_MULTIMAP_H
