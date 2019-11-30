#include "solver_1d.hpp"


namespace nonogram_solver
{
	Solver1D::Solver1D(unsigned length, const NumberSet1D &numberSet)
		: numberSet(numberSet), panelSet(length), isPuzzleCompleted(false)
	{

	}

	void Solver1D::solve(const PanelSet1D &panelSet)
	{
		if(isPuzzleCompleted || panelSet.getLength() != panelSet.getLength())
		{
			return;
		}
		this->panelSet = panelSet;

	}

	PanelSet1D Solver1D::getResult()const
	{
		return panelSet;
	}

	bool Solver1D::isCompleted()const
	{
		return isPuzzleCompleted;
	}
}