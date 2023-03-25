//
// Created by asus on 5/12/2022.
//

#include "TestsTAD.h"
#include <assert.h>
#include "../TAD/List.h"
#include "../TAD/MultiMap.h"
#include <vector>

/// Testeaza implementarea clasei List
void testList(){
    List<int>* lista=new List<int>();
    assert(lista->size()==0);
    lista->add(1);
    lista->add(54);
    lista->add(3);
    lista->add(8);

    assert(lista->size()==4);

    assert(lista->search(54)==1);
    assert(lista->search(8)==3);
    assert(lista->search(5)==-1);

    assert(lista->get(0) == 1);
    assert(lista->get(2) == 3);
    assert(lista->get(4) == 0);

    lista->remove(1);
    lista->remove(3);
    assert(lista->size()==2);

    lista->update(54, 20);
    assert(lista->size()==2);
    assert(lista->search(20)==0);
    assert(lista->get(0)==20);

}

/// Testeaza implementarea clasei MultiMap
void testMultiMap(){
    Multimap<string,string> mp;

    assert(mp.getSize() == 0);
    mp.put("casa", "locuinta");
    assert(mp.getSize() == 1);
    mp.put("casa", "loc de dormit");
    mp.put("masa", "loc de mancat");
    mp.put("student", "persoana care studiaza");
    assert(mp.getSize() == 3);

    assert(mp.searchValue("casa", "locuinta"));
    assert(!mp.searchValue("casa", "ana"));
    assert(!mp.searchValue("masa", "loc"));

    vector<string> lista = mp.searchMapNodeAdress("casa");
    assert(lista.size()==2);
    assert(lista[1]=="locuinta");
    assert(lista[0]=="loc de dormit");

    mp.remove("casa", "locuinta");
    assert(mp.getSize()==3);
    vector<string> v = mp.searchMapNodeAdress("casa");
    assert(v.size()==1);
    assert(v[0]=="loc de dormit");

    mp.remove("student");
    assert(mp.getSize()==2);
    vector<string> listaKey = mp.keyList();
    assert(listaKey.size()==2);
    assert(listaKey[0]=="casa");
    assert(listaKey[1]=="masa");
}

/// Apelarea tuturor testelor pentru TAD-uri
void testsTAD(){
    testList();
    testMultiMap();
}