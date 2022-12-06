#ifndef KURSACH2_DRIVE5TARIF_H
#define KURSACH2_DRIVE5TARIF_H
#include "Tarif.h"

class Drive5Tarif : public Tarif{

private:
    string NameTarif = "Drive5";
    double Price = 15;
    int minutes = 50;
    int internet = 5000;

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


#endif //KURSACH2_DRIVE5TARIF_H
