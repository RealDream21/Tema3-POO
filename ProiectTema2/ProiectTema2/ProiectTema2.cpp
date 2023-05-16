//#include "abonament.h"
//#include "persoana.h"
#include "meniu.h"

/*
---------TASKS---------
    FUNCTIE TEMPLATE 
    CLASA TEMPLATE <--- DONE

sugestie functie template: la afisare tip in meniu sa nu mai am standard sau premium ci direct tip pt template

   2/3 DESIGN PATTERNS
   1.Abonat builder <--- DONE
   2.Meniu singleton <---DONE
   3. ??
*/


int main()
{
    ClientiContainer listaClienti;

    std::string menuItem = "";
    Meniu* MyMenu = Meniu::getInstance();

    std::cout << "Salut, ce vrei sa faci?\n";
    MyMenu->enterMenu();
    std::cout << "Alt program, alte functii, etc..\nApasa ENTER pentru a continua\n";
    std::cin.get();
    std::cin.get();
    MyMenu->enterMenu();

    return 0;
}
