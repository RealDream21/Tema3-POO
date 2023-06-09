#include "meniu.h"

Meniu* Meniu::meniu_ = nullptr;

ClientiContainer Meniu::listaClienti;

AbonatBuilder* Meniu::ab_builder;

BuilderManager Meniu::build_manager;

template <typename T>
int cate()
{
    std::unique_ptr<T> a = std::make_unique<T>();
    return a->cateAbonamente();
}

Meniu::Meniu()
{
	ab_builder = new AbonatBuilder();
}

Meniu::~Meniu()
{
    delete ab_builder;
    delete meniu_;
}

Meniu* Meniu::getInstance()
{
	if (meniu_ == nullptr)
		meniu_ = new Meniu();
	return meniu_;
}

void Meniu::tasta1()const
{
	build_manager.set_builder(ab_builder);
	build_manager.buildItem();
	Abonat abonat = *ab_builder->buildProduct();
	std::unique_ptr<Abonat> abonatToAdd = std::make_unique<Abonat>(abonat);
	listaClienti.appendElement(abonatToAdd);
}

void Meniu::tasta2()const
{
	listaClienti.print();
}

void Meniu::tasta3()const
{
	listaClienti.printStandard();
}

void Meniu::tasta4()const
{
    listaClienti.printPremium();
}

void Meniu::tasta5()const
{
	std::cout << listaClienti.castigTotal() << std::endl;
}

void Meniu::tasta6()const
{
    std::cout << cate<Abonament>();
}

void Meniu::tasta7()const
{
    std::cout << cate<Abonament_premium>();
}

void Meniu::enterMenu()const
{
    std::string menuItem = "";
    while (true) {
        system("cls");
        std::cout << "Ce vrei sa faci?: \n";
        std::cout << " 1-> Adauga o persoana noua\n 2-> Afiseaza toti abonatii\n 3-> Afiseaza abonatii normali\n 4-> Afiseaza abonatii premium\n 5-> Afiseaza profitul total\n 6-> Cati abonati normali sunt\n 7-> Cati abonati premium sunt\n 8-> Iesi\n";
        std::cout << "Input: ";
        std::cin >> menuItem;

        if (menuItem == "1") {
            try {
                tasta1();
                std::cout << "Am citit abonamentul cu succes. Apasa ENTER pentru a continua\n";
            }
            catch (std::exception& err) {
                std::cout << "A APARUT O EROARE: " << err.what();
                std::cout << "Citirea abonamentului a esuat. Apasa ENTER pentru a continua\n";
            }
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "2") {
            system("cls");
            tasta2();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "3") {
            system("cls");
            tasta3();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "4") {
            system("cls");
            tasta4();
            std::cout << "ENTER pentru a continua\n";
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "5") {
            tasta5();
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "6") {
            tasta6();
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "7") {
            tasta7();
            std::cin.get();
            std::cin.get();
        }
        else if (menuItem == "8") {
            break;
        }
        else {
            std::cout << "input gresit\n";
        }
    }
}