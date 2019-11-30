#include "panel_set_1d.hpp"


namespace nonogram_solver
{
	PanelSet1D::PanelSet1D(unsigned length)
		: panels(length)
	{

	}

	PanelSet1D::PanelSet1D(const std::vector<Panel> &panels)
		: panels(panels)
	{

	}

	unsigned PanelSet1D::getLength()const
	{
		return static_cast<unsigned>(panels.size());
	}

	Panel &PanelSet1D::operator[](Position1D position)
	{
		return panels[position.x];
	}

	const Panel &PanelSet1D::operator[](Position1D position)const
	{
		return panels[position.x];
	}

	const std::vector<Panel> &PanelSet1D::getLine()const
	{
		return panels;
	}

	bool PanelSet1D::isCompleted()const
	{
		for(const Panel &panel : panels)
		{
			if(panel.getStatus() == PanelState::none)
			{
				return false;
			}
		}
		return true;
	}
}