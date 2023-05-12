//#include "abonament.h"
//#include "persoana.h"
#include "clienti.h"
#include "container.cpp"

/*
---------TASKS---------
    FUNCTIE TEMPLATE 
    CLASA TEMPLATE <--- DONE

   2/3 DESIGN PATTERNS
   3 daca e cv simplu
   idei: meniu sa fie un design pattern de genul logger
   eventual sa am abonament builder
*/


int main()
{
    ClientiContainer listaClienti;

    std::string menuItem = "";


    while (true) {
        system("cls");
        std::cout << "Ce vrei sa faci?: \n";
        std::cout << " 1-> Adauga o persoana noua\n 2-> Afiseaza toti abonatii\n 3-> Afiseaza abonatii normali\n 4-> Afiseaza abonatii premium\n 5-> Afiseaza profitul total\n 6-> Iesi\n";
        std::cout << "Input: ";
        std::cin >> menuItem;

        if (menuItem == "1") {
            try {
                Abonat abonat;
                std::cin >> abonat;
                std::unique_ptr<Abonat> abonatToAdd = std::make_unique<Abonat>(abonat);
                listaClienti.appendElement(abonatToAdd);
                std::cout << "Am citit abonamentul cu succes. Apasa ENTER pentru a continua\n";
            }
            catch (std::exception& err) {
                std::cout <<"A APARUT O EROARE: " << err.what();
                std::cout << "Citirea abonamentului a esuat. Apasa ENTER pentru a continua\n";
            }
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "2") {
            system("cls");
            listaClienti.print();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "3") {
            system("cls");
            listaClienti.printStandard();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "4") {
            system("cls");
            listaClienti.printPremium();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "5") {
            std::cout << listaClienti.castigTotal() << std::endl;
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "6") {
            break;
        }
        else {
            std::cout << "input gresit\n";
        }
    }
    return 0;
}
