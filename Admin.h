#ifndef KURSACH2_ADMIN_H
#define KURSACH2_ADMIN_H
#include "Client.h"
#include "Tarif.h"
#include "User.h"
#include "MyException.h"
#include "InCorrectIntInput.h"
#include "OwnContainer.h"
#include <iostream>


using namespace std;

class Admin:public User{

private:
    string Password = "admin1";

public:

    Admin()= default;
    ~Admin()= default;;

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

            while (1) {
                cout << endl << endl << "Menu for admin:" << endl;
                cout << "1 - view all clients" << endl;
                cout << "2 - Delete client by pasport" << endl;
                cout << "3 - Find user by ID" << endl;
                cout << "4 - Find user by Number" << endl;
                cout << "5 - Find user by Lastname" << endl;
                cout << "6 - Find user by tarif" << endl;
                cout << "0 - main menu" << endl;

                try {
                    if (!(cin >> choice))
                        throw InCorrectIntInput("Sorry, enter int!");
                    break;
                }
                catch (InCorrectIntInput &ex) {
                    ex.show();
                    rewind(stdin);
                    cin.clear();
                    continue;
                }
            }

            switch (choice) {

                case 1: {ReadFileAdmin();break;}
                case 2: {DeleteFileAdmin();break;}
                case 3:{ReadFileAdminPasport();break;}
                case 4:{ReadFileAdminNumber();break;}
                case 5:{ReadFileAdminLastName();break;}
                case 6:{ReadFileAdminTarif();break;}
                case 0:{choice = 0;break;}

                default:{continue;}
            }
        }
    }


     void ReadFileAdmin(){

        Client x;
        vector<Client>persons;

        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path);

         try {
             if (!fin.is_open())
                 throw InCorrectOpenFiles("Files is not open!");
         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }


        while(!(fin.eof())){
            fin >> x;
            if(x.GetPasport() == "empty")
                continue;
            persons.push_back(x);
        }

        fin.close();

         if(!persons.empty()){
             PrintViewClient();
             for (int i = 0; i < persons.size(); ++i) {
                 persons[i].GetClient();
             }
         }else{
             cout << endl<< endl<< "In base 0 clients now!" << endl;
         }

         persons.clear();


     }

     void ReadFileAdminPasport(){

        vector<Client> persons;
        Client x;
        string Indificator;

        cout << "Enter Pasport for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

         try {
             if (!fin.is_open())
                 throw InCorrectOpenFiles("Files is not open!");

         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }

        while(!(fin.eof())){
            fin >> x;
            if( x.GetPasport() == Indificator){
                persons.push_back(x);
            }
        }

         fin.close();

        if(!persons.empty()){
            PrintViewClient();
            for (int i = 0; i < persons.size(); ++i) {
                persons[i].GetClient();
            }
        }else{
            cout<< endl<< endl << "No this client in base!" << endl;
        }

        persons.clear();

    }

     void ReadFileAdminNumber(){

        vector<Client> persons;
        Client x;
        string Indificator;

        cout << "Enter number for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

         try {
             if (!fin.is_open())
                 throw InCorrectOpenFiles("Files is not open!");

         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }

        while(!(fin.eof())){
            fin >> x;
            if(x.GetNumber() == Indificator){
                persons.push_back(x);
            }
        }

        fin.close();

         if(!persons.empty()){
             PrintViewClient();
             for (int i = 0; i < persons.size(); ++i) {


                 persons[i].GetClient();
             }
         }else{
             cout << endl << endl << "No this client in base!" << endl;
         }

         persons.clear();

    }

     void ReadFileAdminLastName(){

        vector<Client> persons;
        Client x;
        string Indificator;

        cout << "Enter lastname for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

         try {
             if (!fin.is_open())
                 throw InCorrectOpenFiles("Files is not open!");

         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }


        while(!(fin.eof())){
            fin >> x;
            if(x.GetLastName() == Indificator){
                persons.push_back(x);
            }
        }

        fin.close();

         if(!persons.empty()){
             PrintViewClient();
             for (int i = 0; i < persons.size(); ++i) {

                 persons[i].GetClient();
             }
         }else{
             cout << endl << endl << "No this client in base!" << endl;
         }

         persons.clear();

    }

    void ReadFileAdminTarif(){

        vector<Client> persons;
        Client x;
        string Indificator;

        cout << "Enter tarif for search:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        try {
            if (!fin.is_open())
                throw InCorrectOpenFiles("Files is not open!");

        }
        catch (InCorrectOpenFiles& ex){
            ex.show();
            exit(1);
        }


        while(!(fin.eof())){
            fin >> x;
            if(x.GetTarif() == Indificator){
                persons.push_back(x);
            }
        }

        fin.close();

        if(!persons.empty()){
            PrintViewClient();
            for (int i = 0; i < persons.size(); ++i) {

                persons[i].GetClient();
            }
        }else{
            cout<< endl << endl << "Are not this tarif in base!" << endl << endl;
        }

        persons.clear();

    }

     void DeleteFileAdmin(){

        vector<Client> persons;

        string PasportID;
        cout << "Enter pasport ID for delete:";
        cin >> PasportID;

        Client x;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

         try {
             if (!fin.is_open())
                 throw InCorrectOpenFiles("Files is not open!");
         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }

         int count = 0;
        while(!(fin.eof())){
            fin >> x;
            if(x.GetPasport() == PasportID){
                count += 1;
                continue;

            }else{
                persons.push_back(x);
            }
        }
        fin.close();

        if(count == 0){
            cout << endl<< endl << "No this client in base" << endl;
        }
        else
          cout << endl<< endl << "Was delete " << count << "clients." << endl;

        fstream fout;

        fout.open(Path, ios::trunc | ios::out | ios::in);

         try {
             if (!fout.is_open())
                 throw InCorrectOpenFiles("Files is not open!");

         }
         catch (InCorrectOpenFiles& ex){
             ex.show();
             exit(1);
         }



        for (int i = 0; i < persons.size(); ++i) {

            fout << persons[i];

        }

        fout.close();

        persons.clear();
    }

};

#endif //KURSACH2_ADMIN_H
