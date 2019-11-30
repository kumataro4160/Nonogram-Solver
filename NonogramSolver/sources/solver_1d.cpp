#include "solver_1d.hpp"
#include <numeric>


namespace nonogram_solver
{
	bool Solver1D::isCorrect(const std::vector<unsigned> &spaceSet)const
	{
		unsigned minLength = std::reduce(numberSet.getNumbers().begin(), numberSet.getNumbers().end()) + std::reduce(spaceSet.begin(), spaceSet.end());
		return minLength <= panelSet.getLength();
	}

	PanelSet1D Solver1D::makeLine(const std::vector<unsigned> &spaceSet)
	{
		PanelSet1D panelLine(panelSet.getLength());
		unsigned n = 0;
		for(unsigned i = 0; i < spaceSet.size(); ++i)
		{
			for(unsigned j = 0; j < spaceSet[i]; ++j)
			{
				Position1D position;
				position.x = n + j;
				panelLine[position].setStatus(PanelState::guarded);
			}
			n += spaceSet[i];
			for(unsigned j = 0; j < numberSet.getNumbers()[i]; ++j)
			{
				Position1D position;
				position.x = n + j;
				panelLine[position].setStatus(PanelState::filled);
			}
			n += numberSet.getNumbers()[i];
		}
		for(; n < panelLine.getLength(); ++n)
		{
			Position1D position;
			position.x = n;
			panelLine[position].setStatus(PanelState::guarded);
		}
		return panelLine;
	}

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
		std::vector<unsigned> spaceSet(numberSet.getNumbers().size() + 1);
		std::fill(spaceSet.begin() + 1, spaceSet.end(), 1);
		spaceSet[0] = 0;
		unsigned countingDigit = spaceSet.size() - 1;
		while(true)
		{
			if(!isCorrect(spaceSet))
			{
				if(countingDigit == 0)
				{
					break;
				}
				--countingDigit;
				spaceSet[countingDigit]++;
				std::fill(spaceSet.begin() + countingDigit + 1, spaceSet.end(), 1);
				continue;
			}
			countingDigit = spaceSet.size() - 1;
			PanelSet1D madeLine = makeLine(spaceSet);
			if(fits(panelSet, madeLine))
			{
				this->panelSet = this->panelSet && madeLine;
			}
			(*spaceSet.end())++;
		}
		isPuzzleCompleted = this->panelSet.isCompleted();
	}

	PanelSet1D Solver1D::getResult()const
	{
		return panelSet;
	}

	bool Solver1D::isCompleted()const
	{
		return isPuzzleCompleted;
	}

	std::vector<bool> Solver1D::getUpdated()const
	{
		return isUpdated;
	}

	PanelSet1D operator&&(const PanelSet1D &panelSet1, const PanelSet1D &panelSet2)
	{
		PanelSet1D ret(panelSet1.getLength());
		for(unsigned i = 0; i < panelSet1.getLength(); ++i)
		{
			const Position1D position = {i};
			PanelState panelState1 = panelSet1[position].getStatus();
			PanelState panelState2 = panelSet2[position].getStatus();
			PanelState status = panelState1 == panelState2 ? panelState1 : PanelState::none;
			ret[position].setStatus(status);
		}
		return ret;
	}

	bool fits(const PanelSet1D &panelSet1, const PanelSet1D &panelSet2)
	{
		for(unsigned i = 0; i < panelSet1.getLength(); ++i)
		{
			const Position1D position = {i};
			const PanelState panelState1 = panelSet1[position].getStatus();
			const PanelState panelState2 = panelSet2[position].getStatus();
			if(panelState1 == PanelState::filled && panelState2 == PanelState::guarded || panelState1 == PanelState::guarded && panelState2 == PanelState::filled)
			{
				return false;
			}
		}
		return true;
	}
}