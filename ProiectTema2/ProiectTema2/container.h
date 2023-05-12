#pragma once
#include <memory>
#include <vector>
#include <exception>
#include <iostream>

template<typename T>
class Container
{
protected:
	std::vector<std::unique_ptr<T>> lista;
public:
	Container() = default;
	void appendElement(std::unique_ptr<T>& ptr_element);
	std::unique_ptr<T>& removeLastElement();
	std::unique_ptr<T>& operator[](int index);
};

//#include "container.cpp"