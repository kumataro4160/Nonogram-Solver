#pragma once


namespace nonogram_solver
{
	enum class PanelState
	{
		none,
		filled,
		guarded,
	};

	class Panel
	{
		PanelState status;

	public:
		Panel()noexcept;
		void fill()noexcept;
		void clear()noexcept;
		void guard()noexcept;
		void setStatus(PanelState status)noexcept;
		PanelState getStatus()const noexcept;
	};
}