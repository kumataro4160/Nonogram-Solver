#pragma once

#include "number_set_1d.hpp"
#include "panel_set_1d.hpp"


namespace nonogram_solver
{
	PanelSet1D operator&&(const PanelSet1D &panelSet1, const PanelSet1D &panelSet2);
	bool fits(const PanelSet1D &panelSet1, const PanelSet1D &panelSet2);

	class Solver1D
	{
		const NumberSet1D numberSet;
		PanelSet1D panelSet;
		std::vector<bool> isUpdated;
		bool isPuzzleCompleted;

		bool isCorrect(const std::vector<unsigned> &spaceSet)const;
		PanelSet1D makeLine(const std::vector<unsigned> &spaceSet);

	public:
		Solver1D(unsigned length, const NumberSet1D &numberSet);
		void solve(const PanelSet1D &panelSet);
		PanelSet1D getResult()const;
		bool isCompleted()const;
		std::vector<bool> getUpdated()const;
	};
}