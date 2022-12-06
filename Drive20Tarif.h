#ifndef KURSACH2_DRIVE20TARIF_H
#define KURSACH2_DRIVE20TARIF_H
#include "Tarif.h"

class Drive20Tarif : public Tarif
{
private:
    string NameTarif = "Drive20";
    double Price = 23.59;
    int minutes = 200;
    int internet = 20000;

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


#endif //KURSACH2_DRIVE20TARIF_H
