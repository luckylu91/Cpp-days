#pragma once

struct Data
{
	int		n;
	char	comment[250];
	bool operator==(Data const &) const;
};
