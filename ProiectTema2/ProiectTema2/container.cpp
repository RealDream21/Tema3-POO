#pragma once
#include "container.h"

template<typename T>
void Container<T>::appendElement(std::unique_ptr<T>& ptr_element)
{
	lista.push_back(std::move(ptr_element));
	return;
}

template<typename T>
std::unique_ptr<T>& Container<T>::removeLastElement()
{
	std::unique_ptr<T> last = std::move(lista.back());
	lista.pop_back();
	return last;
}

template<typename T>
std::unique_ptr<T>& Container<T>::operator[](int i)
{
	if (i >= lista.size())
		throw std::out_of_range("Elementul nu exista in lista\n");
	else
		return lista[i];
}