#ifndef KURSACH2_ADMIN_H
#define KURSACH2_ADMIN_H
#include "Client.h"
#include "Tarif.h"
#include "User.h"
#include <iostream>
using namespace std;

class Admin:public User{

private:
    string Password = "admin1";

public:

    void CheckAdmin(){

        string _password;
        cout << endl << endl << "Enter password for admin:" ;
        cin >> _password;

        if(!(Password.compare(_password)))
            ForAdmin();
        else cout << endl << "Incorrect password!!! You are not admin. \n Choice other operation!" << endl << endl;

    }

    void ForAdmin() {
        int choice = 100;
        Client person;

        while (choice != 0) {

            cout << "Menu for admin:" << endl;
            cout << "1 - view all clients" << endl;
            cout << "2 - Delete client by pasport" << endl;
            cout << "3 - Find user by ID" << endl;
            cout << "4 - Find user by Number" << endl;
            cout << "5 - Find user by Lastname" << endl;
            cout << "0 - main menu" << endl;

            try{
                if(!(cin >> choice) )
                    throw MyException();
            }

            catch (const MyException& Ex){
                MyException::TypeErrorInt();
            }

            switch (choice) {

                case 1: {
                    person.PrintViewClient();
                    ReadFileAdmin();
                    break;
                }
                case 2: {
                    DeleteFileAdmin();
                    break;
                }
                case 3:{
                    ReadFileAdminPasport();
                    break;
                }

                case 4:{
                    ReadFileAdminNumber();
                    break;
                }
                case 5:{
                    ReadFileAdminLastName();
                    break;
                }

                case 0:{
                    choice = 0;
                    break;
                }


                default:{
                    continue;
                }

            }
        }
    }


    void ReadFileAdmin(){

        Client x;

        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path);

        while(!(fin.eof())){
            fin >> x;
            x.GetClient();
        }

        fin.close();

    }


    void ReadFileAdminPasport(){

        Client x,y;
        string Indificator;

        cout << "Enter Pasport for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        x.PrintViewClient();
        while(!(fin.eof())){
            fin >> x;
            if(!(x.GetPasport().compare(Indificator))){
                x.GetClient();
            }
        }
        fin.close();

    }

    void ReadFileAdminNumber(){

        Client x,y;
        string Indificator;

        cout << "Enter number for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        x.PrintViewClient();
        while(!(fin.eof())){
            fin >> x;
            if(!(x.GetNumber().compare(Indificator))){
                x.GetClient();
            }
        }
        fin.close();

    }

    void ReadFileAdminLastName(){

        Client x,y;
        string Indificator;

        cout << "Enter lastname for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        x.PrintViewClient();
        while(!(fin.eof())){
            fin >> x;
            if(!(x.GetLastName().compare(Indificator))){
                x.GetClient();
            }
        }
        fin.close();

    }


    void DeleteFileAdmin(){

        rewind(stdin);
        cin.clear();

        vector<Client> persons;

        string PasportID;
        cout << "Enter pasport ID for delete:";
        cin >> PasportID;

        Client x;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        while(!(fin.eof())){
            fin >> x;
            if(!(x.GetPasport().compare(PasportID))){
                continue;
            }else{
                persons.push_back(x);
            }
        }
        fin.close();


        fstream fout;

        fout.open(Path, ios::trunc | ios::out | ios::in);

        for (int i = 0; i < persons.size(); ++i) {

            fout << persons[i];

        }

        fout.close();

        persons.clear();
    }

};

#endif //KURSACH2_ADMIN_H
