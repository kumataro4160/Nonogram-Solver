#pragma once

#include "panel.hpp"
#include <vector>


namespace nonogram_solver
{
	class PanelSet1D
	{
		std::vector<Panel> panels;

	public:
		PanelSet1D(unsigned length);
		PanelSet1D(const std::vector<Panel> &panels); 
	};
}