#pragma once
#include <stack>
#include <deque>
#include <iterator>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	MutantStack(MutantStack const & other);
	MutantStack & operator=(MutantStack const & other);

public:
	MutantStack();
	~MutantStack();

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
};

template < typename T, typename Container >
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template < typename T, typename Container >
MutantStack<T, Container>::~MutantStack() {};

template < typename T, typename Container >
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & other) { (void)other; };

template < typename T, typename Container >
MutantStack<T, Container> & MutantStack<T, Container>::operator=(MutantStack<T, Container> const & other) { (void)other; };

template < typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() { return this->c.begin(); }

template < typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const { return this->c.begin(); }

template < typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end() { return this->c.end(); }

template < typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const { return this->c.end(); }
