#pragma once

#include "number_set_1d.hpp"
#include "panel_set_1d.hpp"


namespace nonogram_solver
{
	class Solver1D
	{
		const NumberSet1D numberSet;
		PanelSet1D panelSet;
		bool isPuzzleCompleted;

	public:
		Solver1D(unsigned length, const NumberSet1D &numberSet);
		void solve(const PanelSet1D &panelSet);
		PanelSet1D getResult()const;
		bool isCompleted()const;
	};
}