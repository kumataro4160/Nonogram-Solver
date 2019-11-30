#include "panel_set_2d.hpp"


namespace nonogram_solver
{
	PanelSet2D::PanelSet2D(unsigned width, unsigned height)
		: panels(height)
	{
		for(unsigned i = 0; i < height; ++i)
		{
			panels[i].resize(width);
		}
	}

	PanelSet2D::PanelSet2D(const std::vector<std::vector<Panel>> &panels)
		: panels(panels)
	{

	}

	unsigned PanelSet2D::getWidth()const
	{
		if(panels.size() == 0)
		{
			return 0;
		}
		return static_cast<unsigned>(panels[0].size());
	}

	unsigned PanelSet2D::getHeight()const
	{
		return static_cast<unsigned>(panels.size());
	}

	PanelSet1D PanelSet2D::getRow(unsigned rowNo)const
	{
		return PanelSet1D(panels[rowNo]);
	}

	PanelSet1D PanelSet2D::getColumn(unsigned columnNo)const
	{
		std::vector<Panel> panels(getHeight());
		for(unsigned i = 0; i < getHeight(); ++i)
		{
			panels[i] = this->panels[i][columnNo];
		}
		return PanelSet1D(panels);
	}

	void PanelSet2D::updateRow(unsigned rowNo, const PanelSet1D &panelSet)
	{
		panels[rowNo] = panelSet.getLine();
	}

	void PanelSet2D::updateColumn(unsigned columnNo, const PanelSet1D &panelSet)
	{
		for(unsigned i = 0; i < getHeight(); ++i)
		{
			Position1D position;
			position.x = i;
			panels[i][columnNo] = panelSet[position];
		}
	}

	Panel &PanelSet2D::operator[](Position2D position)
	{
		return panels[position.y][position.x];
	}

	const Panel &PanelSet2D::operator[](Position2D position)const
	{
		return panels[position.y][position.x];
	}

	bool PanelSet2D::isCompleted()const
	{
		for(const auto &row : panels)
		{
			for(const Panel &panel : row)
			{
				if(panel.getStatus() == PanelState::none)
				{
					return false;
				}
			}
		}
		return true;
	}
}