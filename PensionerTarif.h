#ifndef KURSACH2_PENSIONERTARIF_H
#define KURSACH2_PENSIONERTARIF_H
#include "Tarif.h"

class PensionerTarif : public Tarif{



public:

    PensionerTarif(){
    NameTarif = "Pensioner";
    Price = 10;
    minutes = 300;
    internet = 2000;
    }

    ~PensionerTarif(){}

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



#endif //KURSACH2_PENSIONERTARIF_H
