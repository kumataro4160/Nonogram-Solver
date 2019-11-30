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
}