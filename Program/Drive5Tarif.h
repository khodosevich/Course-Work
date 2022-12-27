#ifndef KURSACH2_DRIVE5TARIF_H
#define KURSACH2_DRIVE5TARIF_H
#include "Tarif.h"

class Drive5Tarif : public Tarif{




public:

    Drive5Tarif(){
         NameTarif = "Drive5";
         Price = 15;
         minutes = 50;
         internet = 5000;
    }

    string NameOfTarif() override{
        return NameTarif;
    }

    double Balance() override
    {
        return Price;
    }


    int MinBalance() override
    {
        return minutes;
    }

    int MbBalance() override
    {
        return internet;
    }



};


#endif //KURSACH2_DRIVE5TARIF_H
