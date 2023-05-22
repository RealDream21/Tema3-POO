#pragma once
#include "abonament.h"
#include "persoana.h"
#include "container.h"
#include <vector>
/*
class specifics 
{
	specifics() = default;
public:
	virtual void print();
	virtual void printStandard()const;
	virtual void printPremium()const;
	virtual float castigTotal()const;
};
*/

class Clienti
{
	std::vector<std::unique_ptr<Abonat>> lista;
public:
	Clienti() = default;
	void appendClient(std::unique_ptr<Abonat>& ptr_abonat);
	std::unique_ptr<Abonat>& removeLastClient();
	std::unique_ptr<Abonat>& operator[](int index);
	void print();
	void printStandard()const;
	void printPremium()const;
	float castigTotal()const;
};

class ClientiContainer : public Container<Abonat>
{

public:
	void print();
	void printStandard()const;
	void printPremium()const;
	template<typename Baza, typename Derivata>
	void printType()const
	{
		//T* newObj = new T(); //t este tipul abonamentului
		std::unique_ptr<Baza> b = std::make_unique<Baza>();
		std::unique_ptr<Derivata> d = std::make_unique<Derivata>();
		//Abonat* newObj = new Abonat();
		for (int i = 0; i < lista.size(); i++) {
			if (typeid(lista[i]->abonament) == typeid(b) && (typeid(b) == typeid(d))) {
				lista[i]->showInfo();
				std::cout << std::endl;
			}
			else if (typeid(lista[i]->abonament) == typeid(d) && (typeid(b) != typeid(d))) {
				lista[i]->showInfo();
				std::cout << std::endl;
			}
		}
		//delete newObj;
	}
	float castigTotal()const;
};