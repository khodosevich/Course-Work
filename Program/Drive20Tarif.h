#ifndef KURSACH2_DRIVE20TARIF_H
#define KURSACH2_DRIVE20TARIF_H
#include "Tarif.h"

class Drive20Tarif : public Tarif
{

public:

    Drive20Tarif(){
         NameTarif = "Drive20";
         Price = 23.59;
         minutes = 200;
         internet = 20000;
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


#endif //KURSACH2_DRIVE20TARIF_H
