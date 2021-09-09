#include "Mutantstack.hpp"
#include <iostream>
#include <list>

// push
template <class T>
void push(MutantStack<T> & mStack, T element) {
	std::cout << "Pushing " << element << std::endl;
	mStack.push(element);
}
template <class T>
void push(std::list<T> & list, T element) {
	std::cout << "Pushing " << element << std::endl;
	list.push_front(element);
}

// pop
template <class T>
void pop(MutantStack<T> & mStack) {
	std::cout << "Poping" << std::endl;
	mStack.pop();
}
template <class T>
void pop(std::list<T> & list) {
	std::cout << "Poping" << std::endl;
	list.pop_front();
}

// top
template <class T>
T & top(MutantStack<T> & mStack) {
	return mStack.top();
}
template <class T>
T & top(std::list<T> & list) {
	return list.front();
}

template <class ContainerType>
void makeTests() {
	ContainerType container;
	push(container, 5);
	push(container, 17);
	std::cout << "First element : " << top(container) << std::endl;
	pop(container);
	std::cout << "Size : " << container.size() << std::endl;
	push(container, 3);
	push(container, 5);
	push(container, 737);
	push(container, 0);
	typename ContainerType::iterator it = container.begin();
	typename ContainerType::iterator ite = container.end();
	++it;
	--it;
	std::cout << "Container's content : ";
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Converting to std::stack" << std::endl;
	std::stack<typename ContainerType::value_type, ContainerType> s(container);
}

int main()
{
	std::cout << "--- Tests on Mutantstack ---" << std::endl;
	makeTests< MutantStack<int> >();
	std::cout << std::endl;
	std::cout << "--- Tests on std::list ---" << std::endl;
	makeTests< std::list<int> >();
}
