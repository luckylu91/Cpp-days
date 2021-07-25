#pragma once

template <typename T>
bool easyfind(T & cont, int val)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
	{
		if (*it == val)
			return true;
	}
	return false;
}
