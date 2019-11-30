#pragma once

#include "number_set_1d.hpp"
#include "panel_set_2d.hpp"
#include <vector>


namespace nonogram_solver
{
	class NumberSet2D
	{
		const unsigned width;
		const unsigned height;
		std::vector<std::vector<unsigned>> rowNumbers;
		std::vector<std::vector<unsigned>> columnNumbers;

	public:
		NumberSet2D(unsigned width, unsigned height);
		void set(const PanelSet2D &panelSet);
		NumberSet1D getRow(unsigned rowNo)const;
		NumberSet1D getColumn(unsigned columnNo)const;
	};
}