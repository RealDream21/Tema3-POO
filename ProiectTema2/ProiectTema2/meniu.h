#pragma once
#include "clienti.h"
#include "AbonatBuilder.h"
#include "container.cpp"
class Meniu
{
	static Meniu* meniu_;
	static ClientiContainer listaClienti;
	static AbonatBuilder* ab_builder;
	static BuilderManager build_manager;
	Meniu();
public:
	void operator=(const Meniu&) = delete;
	static Meniu* getInstance();
	void tasta1() const;
	void tasta2() const;
	void tasta3() const;
	void tasta4() const;
	void tasta5() const;
	void enterMenu() const;
};

