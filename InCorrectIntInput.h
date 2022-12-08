#ifndef KURSACH2_INCORRECTINTINPUT_H
#define KURSACH2_INCORRECTINTINPUT_H
#include "MyException.h"

class InCorrectIntInput:public MyException{

public:
    InCorrectIntInput(string message){
        this->message = message;
    }
};

#endif //KURSACH2_INCORRECTINTINPUT_H
