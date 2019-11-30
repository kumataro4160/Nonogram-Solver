#pragma once

#include <vector>


namespace nonogram_solver
{
	class NumberSet1D
	{
		const std::vector<unsigned> numberSet;

	public:
		NumberSet1D(const std::vector<unsigned> &numberSet);
	};
}