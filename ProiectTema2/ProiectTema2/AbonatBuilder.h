#pragma once
#include "persoana.h"

class Builder 
{
public:
	virtual ~Builder() = default;
	virtual void setAttribute1()const = 0; //id
	virtual void setAttribute2()const = 0; //nume
	virtual void setAttribute3()const = 0; //cnp
	virtual void setAttribute4()const = 0; // nr_telefon
	virtual void setAttribute5()const = 0; //abonament
};

class AbonatBuilder : public Builder
{
	Abonat* ab;
public:
	AbonatBuilder();
	~AbonatBuilder();
	virtual void setAttribute1()const override;
	virtual void setAttribute2()const override;
	virtual void setAttribute3()const override;
	virtual void setAttribute4()const override;
	virtual void setAttribute5()const override;
	Abonat* buildProduct();
};

class BuilderManager
{
	Builder* build;
public:
	void set_builder(Builder* aux);
	void buildItem()const;
};