#pragma once

#include "panel_set_1d.hpp"


namespace nonogram_solver
{
	class PanelSet2D
	{
		std::vector<std::vector<Panel>> panels;

	public:
		PanelSet2D(unsigned width, unsigned height);
		PanelSet2D(const std::vector<std::vector<Panel>> &panels);
		unsigned getWidth()const;
		unsigned getHeight()const;
		PanelSet1D getRow(unsigned rowNo)const;
		PanelSet1D getColumn(unsigned columnNo)const;
		void updateRow(unsigned rowNo, const PanelSet1D &panelSet);
		void updateColumn(unsigned columnNo, const PanelSet1D &panelSet);
		Panel &operator[](Position2D position);
		const Panel &operator[](Position2D position)const;
	};
}