#include "solver_2d.hpp"


namespace nonogram_solver
{
	void Solver2D::solveRow(unsigned rowNo)
	{
		row[rowNo].solve(panelSet.getRow(rowNo));
		panelSet.updateRow(rowNo, row[rowNo].getResult());
		const std::vector<bool> isUpdated = row[rowNo].getUpdated();
		for(unsigned i = 0; i < isUpdated.size(); ++i)
		{
			if(isUpdated[i])
			{
				solveColumn(i);
			}
		}
	}
	
	void Solver2D::solveColumn(unsigned columnNo)
	{
		column[columnNo].solve(panelSet.getColumn(columnNo));
		panelSet.updateColumn(columnNo, column[columnNo].getResult());
		const std::vector<bool> isUpdated = column[columnNo].getUpdated();
		for(unsigned i = 0; i < isUpdated.size(); ++i)
		{
			if(isUpdated[i])
			{
				solveRow(i);
			}
		}
	}

	Solver2D::Solver2D(unsigned width, unsigned height, const NumberSet2D &numberSet)
		: panelSet(width, height), isPuzzleCompleted(false)
	{
		row.reserve(height);
		for(unsigned i = 0; i < height; ++i)
		{
			row.emplace_back(Solver1D(width, numberSet.getRow(i)));
		}
		column.reserve(width);
		for(unsigned i = 0; i < width; ++i)
		{
			column.emplace_back(Solver1D(height, numberSet.getColumn(i)));
		}
	}

	void Solver2D::solve(const PanelSet2D &panelSet)
	{
		for(unsigned i = 0; i < panelSet.getHeight(); ++i)
		{
			solveRow(i);
		}
		for(unsigned i = 0; i < panelSet.getWidth(); ++i)
		{
			solveColumn(i);
		}
	}

	PanelSet2D Solver2D::getResult()const
	{
		return panelSet;
	}

	bool Solver2D::isCompleted()const
	{
		return isPuzzleCompleted;
	}
}