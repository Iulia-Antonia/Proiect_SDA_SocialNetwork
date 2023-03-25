//
// Created by asus on 5/14/2022.
//

#ifndef PROIECT_SDA_FRIENDSHIP_H
#define PROIECT_SDA_FRIENDSHIP_H
#include "User.h"


class Friendship {
private:
    User prieten1;
    User prieten2;
public:
    ///Constructor fara parametrii
    Friendship();


    /// Constructor cu parametrii
    /// \param prieten1 unul din userii intre care se va lega prietenia
    /// \param prieten2 celalalt dintr userii intre care se va lega prietenia
    Friendship(User prieten1, User prieten2);


    /// Constructor de copiere
    /// \param friendship prietenia pe care vrem sa o dam instantei actuale
    Friendship(const Friendship &friendship);


    /// Destructorul
    virtual ~Friendship();


    /// Ia primul prieten al prieteniei
    /// \return primul prieten din prietenie
    const User &getPrieten1() const;


    /// Seteaza pentru obiectul curent primul prieten
    /// \param prieten1 primul prieten pe care vrem sa il setam
    void setPrieten1(const User &prieten1);


    /// Ia al doilea prieten al prieteniei
    /// \return al doinea prieten din prietenie
    const User &getPrieten2() const;


    /// Seteaza pentru obiectul curent al doilea prieten
    /// \param prieten2 al doilea prieten pe care vrem sa il setam
    void setPrieten2(const User &prieten2);


        /// Suprascriere operatorul =
    Friendship& operator=(Friendship &friendship);


    /// Suprascriere operatorul ==
    bool operator==(const Friendship &rhs) const;


    /// Suprascriere operatorul !=
    bool operator!=(const Friendship &rhs) const;
};


#endif //PROIECT_SDA_FRIENDSHIP_H
