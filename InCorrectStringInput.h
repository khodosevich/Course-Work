#ifndef KURSACH2_INCORRECTSTRINGINPUT_H
#define KURSACH2_INCORRECTSTRINGINPUT_H
#include "MyException.h"

class InCorrectStringInput : public MyException {

public:

    InCorrectStringInput(string message){

        this->message = message;

    }

};

#endif
