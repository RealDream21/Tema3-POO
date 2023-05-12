#include "persoana.h"

int Persoana::nr_persoane = 0;
int Abonat::nr_persoane_abonate = 0;

Persoana::Persoana(const std::string& numeInit, const std::string& cnpInit, const int idInit) : id(idInit), nume(numeInit), cnp(cnpInit) { nr_persoane++; std::cout << "Constructor persoana cu dublu referinta\n"; }

Persoana::Persoana(const std::string&& numeInit, const std::string& cnpInit, const int idInit) : id(idInit), nume(numeInit), cnp(cnpInit) { nr_persoane++; std::cout << "Constructor persoana primul cu move al doilea referinta\n "; }

Persoana::Persoana(const std::string& numeInit, const std::string&& cnpInit, const int idInit) : id(idInit), nume(numeInit), cnp(cnpInit) { nr_persoane++; std::cout << "Constructor persoana primul cu referinta al doilea cu move\n"; }

Persoana::Persoana(const std::string&& numeInit, const std::string&& cnpInit, const int idInit) : id(idInit), nume(numeInit), cnp(cnpInit) { nr_persoane++; std::cout << "Constructor persoana ambele cu move\n"; }

Persoana::Persoana(const Persoana& other) : id(other.id), nume(other.nume), cnp(other.cnp) { nr_persoane++; std::cout << "Constructor de copiere la persoana\n"; }

Persoana::Persoana()
{
	nr_persoane++;
	id = -1;
	nume = "Neinitializat";
	cnp = "Neinitializat";
	std::cout << "Constructor default de la persoana\n";
}

Persoana::~Persoana()
{
	nr_persoane--;
}

Persoana& Persoana::operator=(const Persoana& other)
{
	id = other.id;
	nume = other.nume;
	cnp = other.cnp;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Persoana& persoana)
{
	os << "id-ul persoanei: " << persoana.id << std::endl;
	os << "numele persoanei: " << persoana.nume << std::endl;
	os << "cnp-ul persoanei: " << persoana.cnp << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Persoana& persoana)
{
	std::cout << "Dati id-ul persoanei: \n";
	is >> persoana.id;
	std::cout << "Dati numele persoanei: \n";
	is >> persoana.nume;
	std::cout << "Dati cnp-ul persoanei: \n";
	is >> persoana.cnp;
	return is;
}

void Persoana::showInfo()const
{
	std::cout << "Persoana nu este un abonat\n";
	std::cout << "Nume: " << nume << std::endl;
	std::cout << "CNP: " << cnp << std::endl;
}

void Persoana::catePersoane()
{
	std::cout << "Exista " << nr_persoane << " persoane\n";
}


Abonat::Abonat(const std::string& nr_telefonInit, const std::string& numeInit, const std::string& cnpInit, const int idInit) : nr_telefon(nr_telefonInit), Persoana(numeInit, cnpInit, idInit), abonament(std::move(std::make_unique<Abonament>())) { nr_persoane_abonate++; std::cout << "Constructor de Abonat de la 0 cu referinta\n"; }

Abonat::Abonat(const std::string&& nr_telefonInit, const std::string&& numeInit, const std::string&& cnpInit, const int idInit) : nr_telefon(nr_telefonInit), Persoana(numeInit, cnpInit, idInit), abonament(std::move(std::make_unique<Abonament>())) { nr_persoane_abonate++; std::cout << "Constructor de Abonat plecand de la 0 cu move\n"; }

Abonat::Abonat(const std::string&& nr_telefonInit, const std::string&& numeInit, const std::string&& cnpInit, const int idInit, std::unique_ptr<Abonament>& abonamentInit) : abonament(std::move(abonamentInit)), nr_telefon(nr_telefonInit), Persoana(numeInit, cnpInit, idInit)
{
	nr_persoane_abonate++;
	std::cout << "Constructor abonat cu move\n";
}

Abonat::Abonat(const std::string& nr_telefonInit, const Persoana& persoanaInit) : nr_telefon(nr_telefonInit), Persoana(persoanaInit), abonament(std::move(std::make_unique<Abonament>())) { nr_persoane_abonate++; std::cout << "Constructor aboant plecand de la persoana cu referinta la nr_telefon\n"; }

Abonat::Abonat(const std::string&& nr_telefonInit, const Persoana& persoanaInit) : nr_telefon(nr_telefonInit), Persoana(persoanaInit), abonament(std::move(std::make_unique<Abonament>())) { nr_persoane_abonate++; std::cout << "Constructor abonat plecand de la persoana cu move la nr_telefon\n"; }

Abonat::Abonat(const std::string& nr_telefonInit, const Persoana& persoanaInit, std::unique_ptr<Abonament>& abonamentInit): abonament(std::move(abonamentInit)), nr_telefon(nr_telefonInit), Persoana(persoanaInit)
{
	nr_persoane_abonate++;
	std::cout<< "Constructor Abonat plecand de la persoana si abonament cu referinta la nr_telefonInit\n";
}
Abonat::Abonat(const std::string&& nr_telefonInit, const Persoana& persoanaInit, std::unique_ptr<Abonament>& abonamentInit): abonament(std::move(abonamentInit)), nr_telefon(nr_telefonInit), Persoana(persoanaInit)
{
	nr_persoane_abonate++;
	std::cout<< "Constructor Abonat plecand de la persoana si abonament cu move la nr_telefonInit\n";
}

Abonat::Abonat(Abonat& other): abonament(std::move(other.abonament)), nr_telefon(other.nr_telefon), Persoana(other)
{
	nr_persoane_abonate++;

	std::cout << "Constructor de copiere\n";
}


Abonat::Abonat() : Persoana()
{
	nr_persoane_abonate++;
	nr_telefon = "Neinitializat\n";
	std::cout << "Constructor default de la Abonat\n";
}

Abonat::~Abonat()
{
	nr_persoane_abonate--;
}

Abonat& Abonat::operator=(const Abonat& other)
{
	nume = other.nume;
	cnp = other.cnp;
	nr_telefon = other.nr_telefon;
	//abonament = std::move(std::make_unique<Abonament>(other.abonament));
	Abonament_premium a;
	Abonament b;
	const std::type_info& t_premium = typeid(a);
	const std::type_info& t_standard = typeid(b);
	const std::type_info& tabonament = typeid(*other.abonament);
	if (t_premium == tabonament) {
		std::unique_ptr<Abonament> ptr2 = std::move(std::make_unique<Abonament_premium>(other.abonament->getReducere(), *other.abonament));
		abonament = std::move(ptr2);
	}
	else if (t_standard == tabonament) {
		abonament = std::move(std::make_unique<Abonament>());
		*abonament = *other.abonament;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Abonat& abonat)
{
	os << "nr_telefon: " << abonat.nr_telefon << std::endl;
	os << "nume: " << abonat.nume << std::endl;
	os << "cnp: " << abonat.cnp << std::endl;
	os << "informatii despre abonament: \n";
	if (abonat.abonament != nullptr)
		abonat.abonament->showInfo();
	else
		os << "persoana nu are abonament\n";
	return os;
}

std::istream& operator>>(std::istream& is, Abonat& abonat)
{
	std::cout << "Dati id-ul abonatului: \n";
	is >> abonat.id;

	std::cout << "Dati numele abonatului: \n";
	is.get();
	std::getline(is, abonat.nume);
	std::cout << "Dati cnp-ul abonatului: \n";
	is >> abonat.cnp;
	std::cout << "Dati numarul de telefon: \n";
	is >> abonat.nr_telefon;
	std::string tip;
	std::cout << "De ce tip este abonamentul? 1 pentru normal, 2 pentru premium: \n";
	while (true) 
	{
		is.get();
		is >> tip;
		if (!(tip == "1" || tip == "2")) {
			std::cout << "numar gresit\n";
		}
		if (tip == "1") {
			std::cout << "ati selectat abonamentul normal\n";
			abonat.abonament = std::move(std::make_unique<Abonament>());
			abonat.abonament->setInfo();
			break;
		}
		else if (tip == "2") {
			std::cout << "ati selectat abonamentul premium\n";
			abonat.abonament = std::move(std::make_unique<Abonament_premium>());
			abonat.abonament->setInfo();
			break;
		}
	}
	return is;
}

void Abonat::setInfo()
{
	Abonat* ptr = new Abonat();
	std::cin >> *ptr;
	id = ptr->id;
	nume = ptr->nume;
	cnp = ptr->cnp;
	nr_telefon = ptr->nr_telefon;
	delete ptr;
}

void Abonat::setAbonament(std::unique_ptr<Abonament>& newAbonament)
{
	abonament = std::move(newAbonament);
	return;
}


void Abonat::showInfo()const
{
	std::cout << "Persoana este un abonat\n";
	std::cout << "Numar de telefon: " << nr_telefon << std::endl;
	std::cout << "Nume: " << nume << std::endl;
	std::cout << "CNP: " << cnp << std::endl;
	std::cout << "Informatii despre abonament: \n";
	//abonament.showInfo();//poate un cout << abonament;
	if (abonament != nullptr)
		std::cout << abonament;
	else
		std::cout << "Persoana nu are abonament\n";
}

float Abonat::castig() const
{
	return abonament->castig();
}

std::string Abonat::tip()
{
	Abonament a;
	Abonament_premium b;
	const std::type_info& tip_standard = typeid(a);
	const std::type_info& tip_premium = typeid(b);
	if (typeid(*abonament) == typeid(a)) {
		return std::string("standard");
	}
	else if (typeid(*abonament) == typeid(b)) {
		return std::string("premium");
	}
}

void Abonat::catePersoane()
{
	std::cout << "Exista " << nr_persoane << " persoane si " << nr_persoane_abonate << " abonati\n";
}
