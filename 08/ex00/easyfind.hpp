#pragma once

template <typename T>
typename T::iterator easyfind(T & container, int val)
{
	typename T::iterator it = container.begin();
	for (; it != container.end(); ++it)
	{
		if (*it == val)
			break;
	}
	return it;
}
