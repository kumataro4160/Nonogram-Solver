#pragma once

#include "number_set_2d.hpp"
#include "panel_set_2d.hpp"
#include "solver_1d.hpp"


namespace nonogram_solver
{
	class Solver2D
	{
		std::vector<Solver1D> row;
		std::vector<Solver1D> column;
		PanelSet2D panelSet;
		bool isPuzzleCompleted;

		void solveRow(unsigned rowNo);
		void solveColumn(unsigned columnNo);

	public:
		Solver2D(unsigned width, unsigned height, const NumberSet2D &numberSet);
		void solve(const PanelSet2D &panelSet);
		PanelSet2D getResult()const;
		bool isCompleted()const;
	};
}