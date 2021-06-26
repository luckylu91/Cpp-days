#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karen;

	if (argc == 1)
		return 1;
	karen.complain_starting_at(argv[1]);
	return 0;
}