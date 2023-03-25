2-5
2 - Lista cu elemente generice cu reprezentare înlănțuită
5 - Multi Dictionar cu elemente generice cu reprezentare înlănțuită

Am folosit cele doua tad-uri in Repository, ca structuri ce
se ocupa cu persistenta datelor in memorie
- RepositoryList (cel ce foloseste tad-ul 2; Repository - RepositoryList.h - linia 13)
   l-am folosit ca sa retin lista de utilizatori in Service (Service - Service.h - linia 17)
- RepositoryMultimap (cel ce foloseste tad-ul 5; Repository - RepositoryMultimap.h - linia 12)
   l-am mostenit in RepositoryMessages.h  (linia 14) si in RepositoryFriendship.h (linia 11)

[In cmake-build-debug sunt salvate fisierele din care se vor importa utilizatorii, prieteniile si mesajele]