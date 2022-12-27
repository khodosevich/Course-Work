#include <iostream>
#include "User.h"
#include "Admin.h"
#include "InCorrectIntInput.h"
using namespace std;


int main() {

    system("clear");

    int choice = 100  , x ;

    User user;
    Admin admin;

    while(choice != 0){


        while(1) {
            cout << endl  << "Menu for:" << endl;
            cout << "1 - admin" << endl;
            cout << "2 - user" << endl;
            cout << "0 - end of program" << endl;


            try {
                if (!(cin >> choice))
                    throw InCorrectIntInput("Sorry, enter int!");
                break;
            }


            catch (InCorrectIntInput ex) {
                ex.show();
                rewind(stdin);
                cin.clear();
                continue;
            }
        }

        switch (choice) {
            case 1:{admin.CheckAdmin();break;}
            case 2:

            {
                x = 100;
                while(x != 0){


                    while(1) {

                        cout << endl << endl << "Menu user:" << endl;
                        cout << "1 - log in account" << endl;
                        cout << "2 - create new client" << endl;
                        cout << "0 - main menu" << endl;

                        try {
                            if (!(cin >> x))
                                throw InCorrectIntInput("Sorry, enter int!");
                            break;
                        }
                        catch (InCorrectIntInput ex){
                            ex.show();
                            rewind(stdin);
                            cin.clear();
                            continue;
                        }

                    }
                    switch (x) {
                        case 1:{user.ForBasicUser();break;}

                        case 2:{user.ForNewUser();break;}

                        case 0:{x = 0;break;}

                        default:{continue;}
                    }
                }
                break;
            }
            case 0:
                break;

            default:{continue;}
        }
    }

return 0;
}
