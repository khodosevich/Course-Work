#ifndef KURSACH2_MYEXCEPTION_H
#define KURSACH2_MYEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;

class MyException:public exception{

public:


public:
    string message;

    MyException() {
        message = "Fatal error!";
    }


    MyException(string _msg)
    {
        message = _msg;
    }

    ~MyException() {}

     void show()
    {
        cout << "Error: " << message << endl;
    }


};

#endif //KURSACH2_MYEXCEPTION_H
