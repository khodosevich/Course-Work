#ifndef KURSACH2_USER_H
#define KURSACH2_USER_H
#include "Client.h"
#include "Tarif.h"
#include "MyException.h"
#include <stdlib.h>


class User: public Client{


public:

    User(){}
    ~User(){}

    void ForNewUser(){

        Client person1;
        int choice = 100;
        while (choice != 0){

            cout << "Menu for new client:" << endl;
            cout << "1 - create" << endl;
            cout << "2 - view client" << endl;
            cout << "3 - change tarif" << endl;
            cout << "4 - change number" << endl;
            cout << "5 - view balance" << endl;
            cout << "6 - deposit balance" << endl;
            cout << "7 - save change in base and go to main menu" << endl;
            cout << "0 - main menu" << endl;


            try{
                if(!(cin >> choice) )
                    throw MyException();
            }

            catch (const MyException& Ex){
                MyException::TypeErrorInt();
            }

            switch (choice) {

                case 1:{person1.CreateClient(person1);break;}

                case 2:
                {
                    PrintViewClient();
                    person1.GetClient();
                    break;
                }

                case 3:
                {
                    AllTarif();
                    person1.setTarif();
                    break;
                }

                case 4:{person1.SetNumber();break;}

                case 5:{cout << person1.GetBalance() << endl; break;}

                case 6:{person1.DepositBalance();break;}

                case 7:{
                    person1.WriteFile(person1);
                    choice = 0;
                    break;
                }

                case 0:{choice = 0;break;}

                default:{continue;}
            }
        }

    }

    void ForBasicUser(){


        vector<Client> persons = LoadPeopleInVector();

        string PasportID;
        Client x;
        int index;
        int choice = 100;

        cout << "Enter your pasport ID:";
        cin >> PasportID;

        for (int i = 0; i < persons.size(); ++i) {
            if(!(persons[i].GetPasport().compare(PasportID))){
                index = i;
            }
        }

        if(!(persons[index].GetPasport().compare(PasportID))){
            cout << "You can continue!" << endl;
            PrintViewClient();
            persons[index].GetClient();
        }else{
            cout << "You not in base!" << endl;
            choice = 0;
        }




        while (choice != 0){

            cout << "Menu for old client:" << endl;
            cout << "1 - view client" << endl;
            cout << "2 - change tarif" << endl;
            cout << "3 - change number" << endl;
            cout << "4 - view balance" << endl;
            cout << "5 - deposit balance" << endl;
            cout << "6 - save changes and go to main menu" << endl;
            cout << "7 - delete this account" << endl;
            cout << "0 - main menu " << endl;

            cin >> choice;

            switch (choice) {

                case 1:{
                    PrintViewClient();
                    persons[index].GetClient();
                    break;
                }

                case 2:
                {
                    cout<< "Change tarif." << endl;
                    AllTarif();
                    persons[index].setTarif();
                    break;
                }

                case 3:
                {
                    cout << "Change number." << endl;
                    persons[index].SetNumber();
                    break;
                }

                case 4:{
                    cout << persons[index].GetBalance() << endl;
                    break;
                }

                case 5:{
                    persons[index].DepositBalance();
                    break;
                }

                case 6:{
                    WtiteFilesPersons(persons);
                    choice = 0;
                    break;
                }


                case 7:{
                    DeleteThisPerson(persons[index]);
                    choice = 0;
                    break;
                }

                case 0:{
                    choice = 0;
                    break;
                };

                default:{
                    continue;
                }

            }
        }

        persons.clear();

    }

    void DeleteThisPerson(Client personDelete){

        vector<Client> persons = LoadPeopleInVector();

        string Path = "myFiles.txt";

        fstream fout;

        fout.open(Path, ios::trunc | ios::out | ios::in);

        for (int i = 0; i < persons.size(); ++i) {

            if(persons[i].GetPasport().compare(personDelete.GetPasport())){
                 fout << persons[i];
            }

        }

        fout.close();
        persons.clear();
    }

    vector<Client> LoadPeopleInVector(){
        vector<Client> persons;
        Client x;
        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path);

        while(!(fin.eof())){
            fin >> x;
            persons.push_back(x);
        }

        fin.close();

        return persons;

    }

    void WtiteFilesPersons(vector<Client> persons){

        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path,  ios::trunc | ios::out);

        for (int i = 0; i < persons.size(); ++i) {

            fin << persons[i];

        }

        fin.close();
        persons.clear();
    }


};

#endif //KURSACH2_USER_H
