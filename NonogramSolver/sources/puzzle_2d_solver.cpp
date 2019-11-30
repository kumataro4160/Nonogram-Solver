#include "puzzle_2d_solver.hpp"


namespace nonogram_solver
{
	Puzzle2DSolver::Puzzle2DSolver(unsigned width, unsigned height, const NumberSet2D &numberSet)
		: solver(width, height, numberSet), width(width), height(height)
	{

	}

	void Puzzle2DSolver::solve()
	{
		PanelSet2D dummy(width, height);
		solver.solve(dummy);
	}

	PanelSet2D Puzzle2DSolver::getResult()const
	{
		return solver.getResult();
	}
}