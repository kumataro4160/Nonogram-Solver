#pragma once

#include "solver_2d.hpp"


namespace nonogram_solver
{
	class Puzzle2DSolver
	{
		Solver2D solver;
		const unsigned width;
		const unsigned height;

	public:
		Puzzle2DSolver(unsigned width, unsigned height, const NumberSet2D &numberSet);
		void solve();
		PanelSet2D getResult()const;
	};
}