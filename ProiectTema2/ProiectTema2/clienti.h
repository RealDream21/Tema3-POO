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
	float castigTotal()const;
};