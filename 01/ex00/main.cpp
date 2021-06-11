#include "Pony.hpp"

void ponyOnTheStack(void)
{
	Pony p("Pony Stark");
	p.doThings();
}

void ponyOnTheHeap(void)
{
	Pony *p = new Pony("Pon-Heap");
	p->doThings();
	delete p;
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
}
