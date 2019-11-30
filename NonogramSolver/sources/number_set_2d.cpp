#include "number_set_2d.hpp"


namespace nonogram_solver
{
	NumberSet2D::NumberSet2D(unsigned width, unsigned height)
		:width(width), height(height)
	{

	}

	NumberSet1D NumberSet2D::getRow(unsigned rowNo)const
	{
		NumberSet1D ret(width);
		ret.set(rowNumbers[rowNo]);
		return ret;
	}

	NumberSet1D NumberSet2D::getColumn(unsigned columnNo)const
	{
		NumberSet1D ret(height);
		ret.set(columnNumbers[columnNo]);
		return ret;
	}
}