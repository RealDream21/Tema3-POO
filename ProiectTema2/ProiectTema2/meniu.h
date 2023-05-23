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
	Meniu(Meniu&) = delete;
	Meniu& operator=(const Meniu&) = delete;
	~Meniu();
	void tasta1() const;
	void tasta2() const;
	void tasta3() const;
	void tasta4() const;
	void tasta5() const;
	void tasta6() const;
	void tasta7() const;
public:
	static Meniu* getInstance();
	void enterMenu() const;
};

