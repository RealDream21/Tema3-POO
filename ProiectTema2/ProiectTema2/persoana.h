#pragma once
#include "abonament.h"

class Persoana
{
protected:
	static int nr_persoane;
	int id; //se poate schimba in const daca nu am cin
	std::string nume;
	std::string cnp;
public:
	Persoana(const std::string&nume, const std::string&cnp, const int id);
	Persoana(const std::string&&nume, const std::string&cnp, const int id);
	Persoana(const std::string&nume, const std::string&&cnp, const int id);
	Persoana(const std::string&&nume, const std::string&&cnp, const int id);
	Persoana(const Persoana& persoana);
	Persoana();
	virtual ~Persoana();
	Persoana& operator=(const Persoana& persoana);
	friend std::ostream& operator<<(std::ostream&, const Persoana& persoana);
	friend std::istream& operator>>(std::istream&, Persoana& persoana);
	virtual void showInfo()const;
	static void catePersoane();
};

class Abonat : public Persoana
{
	static int nr_persoane_abonate;
	//eventual trebuie rescrise toate functiile de constructor cu shared_ptr dar pentru ptr normal 
	std::string nr_telefon;
	std::unique_ptr<Abonament> abonament;
public:
	Abonat(const std::string&nr_telefon, const std::string&nume, const std::string&cnp, const int id);
	Abonat(const std::string&&nr_telefon, const std::string&&nume, const std::string&&cnp, const int id);
	Abonat(const std::string&&nr_telefon, const std::string&&nume, const std::string&&cnp, const int id, std::unique_ptr<Abonament>& abonament); //<----- trebuie rescrisa pentru Abonament* abonament;
	Abonat(const std::string&nr_telefon, const Persoana&persoana);
	Abonat(const std::string&&nr_telefon, const Persoana&persoana);
	Abonat(const std::string&nr_telefon, const Persoana&persoana, std::unique_ptr<Abonament>&abonament); //<----- trebuie rescrisa pentru Abonament* abonament;
	Abonat(const std::string&&nr_telefon, const Persoana&persoana, std::unique_ptr<Abonament>&abonament); //<----- trebuie rescrisa pentru Abonament* abonament;
	Abonat(Abonat&abonat); // de scris
	Abonat();
	~Abonat();
	Abonat& operator=(const Abonat& abonat);
	friend std::ostream& operator<<(std::ostream&, const Abonat& abonat);
	friend std::istream& operator>>(std::istream&, Abonat& abonat);
	void setInfo();
	void setAbonament(std::unique_ptr<Abonament>&abonament);
	void setAbonament(const Abonament otherAbonament);
	void setAbonament(const Abonament_premium otherAbonamentPremium);
	void showInfo()const override;
	float castig()const;
	std::string tip();
	static void catePersoane();
};

