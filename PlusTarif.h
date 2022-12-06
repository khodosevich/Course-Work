#ifndef KURSACH2_PLUSTARIF_H
#define KURSACH2_PLUSTARIF_H
#include "Tarif.h"

class PlusTarif : public Tarif
{
private:
    string NameTarif = "Plus";
    double Price = 17.59;
    int minutes = 100;
    int internet = 10000;

public:

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
