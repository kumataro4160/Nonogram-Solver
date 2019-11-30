#include "number_set_2d.hpp"


namespace nonogram_solver
{
	NumberSet2D::NumberSet2D(unsigned width, unsigned height)
		:width(width), height(height), rowNumbers(height), columnNumbers(width)
	{

	}

	void NumberSet2D::setRow(unsigned rowNo, const NumberSet1D &numberSet)
	{
		rowNumbers[rowNo] = numberSet.getNumbers();
	}

	void NumberSet2D::setColumn(unsigned columnNo, const NumberSet1D &numberSet)
	{
		columnNumbers[columnNo] = numberSet.getNumbers();
	}

	NumberSet1D NumberSet2D::getRow(unsigned rowNo)const
	{
		return NumberSet1D(width, rowNumbers[rowNo]);
	}

	NumberSet1D NumberSet2D::getColumn(unsigned columnNo)const
	{
		return NumberSet1D(height, columnNumbers[columnNo]);
	}
}