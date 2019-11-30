#include "number_set_1d.hpp"
#include <numeric>


namespace nonogram_solver
{
	NumberSet1D::NumberSet1D(unsigned length)
		: length(length)
	{

	}

	void NumberSet1D::set(const std::vector<unsigned> &numbers)
	{
		unsigned minLength = std::reduce(numbers.begin(), numbers.end()) + static_cast<unsigned>(numbers.size() - 1);
		if(minLength > length)
		{
			return;
		}
		this->numbers = numbers;
	}

	void NumberSet1D::set(const PanelSet1D &panelSet)
	{

	}

	std::vector<unsigned> NumberSet1D::getNumbers()const
	{
		return numbers;
	}
}