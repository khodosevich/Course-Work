#ifndef KURSACH2_MYEXCEPTION_H
#define KURSACH2_MYEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;

class MyException:public exception{

public:
    string message;

public:


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
        cout << endl << endl << "Error: " << message << endl << endl;
    }


};

#endif //KURSACH2_MYEXCEPTION_H
