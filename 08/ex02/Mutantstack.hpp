#pragma once
#include <stack>
#include <deque>
#include <iterator>
//
#include <iostream>
#include <typeinfo>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:
	MutantStack & operator=(MutantStack const &) {}

public:
	typedef T value_type;
	typedef Container container_type;
	typedef typename Container::reverse_iterator iterator;
	typedef typename Container::const_reverse_iterator const_iterator;

	MutantStack(const container_type& ctnr = container_type()) : std::stack<value_type, container_type>(ctnr) {}
	MutantStack(MutantStack const & other) : std::stack<value_type, container_type>(other.c) {}
	~MutantStack() {}

	iterator begin() { return this->c.rbegin(); }
	const_iterator begin() const { return this->c.rbegin(); }
	iterator end() { return this->c.rend(); }
	const_iterator end() const { return this->c.rend(); }
};
