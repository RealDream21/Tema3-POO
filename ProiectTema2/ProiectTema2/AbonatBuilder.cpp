#include "AbonatBuilder.h"

AbonatBuilder::AbonatBuilder()
{
	ab = new Abonat();
}

AbonatBuilder::~AbonatBuilder()
{
	delete ab;
}

void AbonatBuilder::setAttribute1() const
{
	std::cout << "Dati id-ul abonatului: " << std::endl;
	std::cin >> ab->id;
}

void AbonatBuilder::setAttribute2()const
{
	std::cout << "Dati numele abonatului: " << std::endl;
	std::cin >> ab->nume;
}

void AbonatBuilder::setAttribute3()const
{
	std::cout << "Dati cnp-ul abonatului: " << std::endl;
	std::cin >> ab->cnp;
}

void AbonatBuilder::setAttribute4()const
{
	std::cout << "Dati numarul de telefon al abonatului " << std::endl;
	std::cin >> ab->nr_telefon;
}

void AbonatBuilder::setAttribute5()const
{
	std::string tip;
	std::cout << "De ce tip este abonamentul? 1 pentru normal, 2 pentru premium: \n";
	while (true)
	{
		std::cin.get();
		std::cin >> tip;
		if (!(tip == "1" || tip == "2")) {
			std::cout << "numar gresit\n";
		}
		if (tip == "1") {
			std::cout << "ati selectat abonamentul normal\n";
			ab->abonament = std::move(std::make_unique<Abonament>());
			ab->abonament->setInfo();
			break;
		}
		else if (tip == "2") {
			std::cout << "ati selectat abonamentul premium\n";
			ab->abonament = std::move(std::make_unique<Abonament_premium>());
			ab->abonament->setInfo();
			break;
		}
	}
}

Abonat* AbonatBuilder::buildProduct()
{
	Abonat* aux = this->ab;
	this->ab = new Abonat();
	return aux;
}

void BuilderManager::set_builder(Builder* aux)
{
	build = aux;
}

void BuilderManager::buildItem()const
{
	build->setAttribute1();
	build->setAttribute2();
	build->setAttribute3();
	build->setAttribute4();
	build->setAttribute5();
}