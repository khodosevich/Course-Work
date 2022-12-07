#ifndef KURSACH2_STUDENTTARIF_H
#define KURSACH2_STUDENTTARIF_H
#include "Tarif.h"

class StudentTarif : public Tarif{

public:

    StudentTarif(){
        NameTarif = "Student";
        Price = 20;
        minutes = 75;
        internet = 25000;
    }

    ~StudentTarif(){}

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


#endif //KURSACH2_STUDENTTARIF_H
