#ifndef KURSACH2_PLUSTARIF_H
#define KURSACH2_PLUSTARIF_H
#include "Tarif.h"

class PlusTarif : public Tarif
{


public:

    PlusTarif(){
       NameTarif = "Plus";
       Price = 17.59;
       minutes = 100;
       internet = 10000;
    }

    ~PlusTarif(){}

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

#endif //KURSACH2_PLUSTARIF_H
