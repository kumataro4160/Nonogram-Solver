#pragma once

#include "panel_set_1d.hpp"
#include <vector>


namespace nonogram_solver
{
	class NumberSet1D
	{
		const unsigned length;
		std::vector<unsigned> numbers;

	public:
		NumberSet1D(unsigned length);
		NumberSet1D(unsigned length, const std::vector<unsigned> &numbers);
		void set(const std::vector<unsigned> &numbers);
		void set(const PanelSet1D &panelSet);
		const std::vector<unsigned> &getNumbers()const;
	};
}