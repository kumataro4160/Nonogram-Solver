#include "panel.hpp"


namespace nonogram_solver
{
	Panel::Panel()noexcept
	{
		status = PanelState::none;
	}

	void Panel::fill()noexcept
	{
		status = PanelState::filled;
	}

	void Panel::clear()noexcept
	{
		status = PanelState::none;
	}

	void Panel::guard()noexcept
	{
		status = PanelState::guarded;
	}

	void Panel::setStatus(PanelState status) noexcept
	{
		this->status = status;
	}

	PanelState Panel::getStatus()const noexcept
	{
		return status;
	}
}