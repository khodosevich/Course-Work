#ifndef KURSACH2_USER_H
#define KURSACH2_USER_H
#include "Client.h"
#include "Tarif.h"
#include "MyException.h"
#include "InCorrectIntInput.h"





class User: public Client{


public:

    User(){}
    ~User(){}

    void ForNewUser(){

        Client person1;
        person1.CreateClient(person1);

        int choice = 100;

        while (choice != 0){


            while(true) {

                cout << "Menu for new client:" << endl;

                cout << "1 - view client" << endl;
                cout << "2 - change tarif" << endl;
                cout << "3 - change number" << endl;
                cout << "4 - view balance" << endl;
                cout << "5 - deposit balance" << endl;
                cout << "6 - save change in base and go to main menu" << endl;


                try{
                    if(!(cin >> choice))
                        throw MyException("Sorry, enter int!");
                    break;
                }
                catch(MyException& ex){
                    ex.show();
                    rewind(stdin);
                    cin.clear();
                    continue;
                }

            }


            switch (choice) {

                case 1:
                {
                    PrintViewClient();
                    person1.GetClient();
                    break;
                }

                case 2:
                {
                    CheckOnSameTarif(person1);
                    person1.SetBalance();
                    break;
                }

                case 3:{person1.SetNumber();break;}

                case 4:{cout <<"Your balance:"<< person1.GetBalance() << " byn" << endl; break;}

                case 5:{person1.DepositBalance();break;}

                case 6:{

                    if(CheckIsEmptyClient(person1))
                       person1.WriteFile(person1);
                    choice = 0;

                    break;
                }

                default:{continue;}
            }
        }

    }

    void ForBasicUser(){


        vector<Client> persons = LoadPeopleInVector();

        string PasportID,CheckPassword;

        int index;
        int choice = 100;

        cout << "Enter your pasport ID:";
        cin >> PasportID;
        rewind(stdin);
        cin.clear();
        cout << "Choice password:";
        cin >> CheckPassword;




        for (int i = 0; i < persons.size(); ++i) {
            if( persons[i].GetPasport() == PasportID) {
                if (persons[i].GetPassword() == CheckPassword)
                    index = i;
            }
        }

        if(!persons.empty()) {
            if (persons[index].GetPasport() == PasportID) {
                if (persons[index].GetPassword() == CheckPassword) {
                    cout << "You are can continue!" << endl;
                    PrintViewClient();
                    persons[index].GetClient();
                }
            } else {
                cout << "You сant continue";
                choice = 0;
            }
        }

        while (choice != 0){


            while(true) {

                cout << "Menu for old client:" << endl;
                cout << "1 - view client" << endl;
                cout << "2 - change tarif" << endl;
                cout << "3 - change number" << endl;
                cout << "4 - view balance" << endl;
                cout << "5 - deposit balance" << endl;
                cout << "6 - save changes and go to main menu" << endl;
                cout << "7 - delete this account" << endl;


                try {
                    rewind(stdin);
                    cin.clear();
                    if (!(cin >> choice))
                        throw MyException("Sorry, enter int!");
                    break;
                }
                catch (MyException &ex) {
                    ex.show();
                    continue;
                }

            }


            switch (choice) {

                case 1:{
                    PrintViewClient();
                    persons[index].GetClient();
                    break;
                }

                case 2:
                {
                    CheckOnSameTarif(persons[index]);
                    persons[index].SetBalance();
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

        int count;

        try {
            if (!fout.is_open())
                throw InCorrectOpenFiles("Files is not open!");

        }
        catch (InCorrectOpenFiles& ex){
            ex.show();
            exit(1);
        }

        for (int i = 0; i < persons.size(); ++i) {

            if(persons[i].GetPasport() != personDelete.GetPasport()){
                 fout << persons[i];
            }
            else{
                cout << endl<< endl <<"Clients was delete." << endl;
            }

        }

        fout.close();
        persons.clear();
    }

    void WtiteFilesPersons(vector<Client> persons){

        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path,  ios::trunc | ios::out);

        try {
            if (!fin.is_open())
                throw InCorrectOpenFiles("Files is not open!");

        }
        catch (InCorrectOpenFiles& ex){
            ex.show();
            exit(1);
        }

        for (int i = 0; i < persons.size(); ++i) {

            fin << persons[i];

        }

        fin.close();
        persons.clear();
    }

    bool CheckIsEmptyClient(Client person){

        if(person.GetPasport() == "empty" && person.GetName() == "empty")
            return false;

        return true;
    }

    void CheckOnSameTarif(Client &person){

        cout << endl << endl << "Change tarif." << endl;
        cout << "Your tarif now:" << person.GetTarif() << endl;

        string OldTarif = person.GetTarif();
        string NowTatif =  person.GetTarif();

        AllTarif();
        person.setTarif();
        NowTatif =  person.GetTarif();

        while(1){
            if(OldTarif != NowTatif)
                break;

            else{
                cout << "You cant choice same tarif! Please, choice other tarif!" << endl;
                AllTarif();
                person.setTarif();
                NowTatif =  person.GetTarif();
                continue;
            }
        }



    }

};

#endif //KURSACH2_USER_H
