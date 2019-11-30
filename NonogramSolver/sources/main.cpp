#include "puzzle_2d_solver.hpp"
#include <iostream>


namespace nonogram_solver
{
	using namespace std;

	void displayPanel(const Panel &panel)
	{
		cout << (panel.getStatus() == PanelState::filled ? "¡" : "  ");
	}

	void display(const PanelSet2D &field)
	{
		const unsigned width = field.getWidth();
		const unsigned height = field.getHeight();
		Position2D position;
		cout << "    ";
		for(unsigned i = 0; i < width; ++i)
		{
			printf("%2d", i + 1);
		}
		cout << endl;
		for(position.y = 0; position.y < height; ++position.y)
		{
			printf("%3d ", position.y + 1);
			for(position.x = 0; position.x < width; ++position.x)
			{
				displayPanel(field[position]);
			}
			cout << endl;
		}
	}

	unsigned inputWidth()
	{
		unsigned ret;
		cout << "Input width >";
		cin >> ret;
		return ret;
	}

	unsigned inputHeight()
	{
		unsigned ret;
		cout << "Input height >";
		cin >> ret;
		return ret;
	}

	NumberSet1D inputNumberSetRow(unsigned width)
	{
		cout << "Input number set of row >";
		unsigned N;
		cin >> N;
		std::vector<unsigned> numbers(N);
		for(unsigned i = 0; i < N; ++i)
		{
			unsigned number;
			cin >> number;
			numbers[i] = number;
		}
		return NumberSet1D(width, numbers);
	}

	NumberSet1D inputNumberSetColumn(unsigned height)
	{
		cout << "Input number set of column >";
		unsigned N;
		cin >> N;
		std::vector<unsigned> numbers(N);
		for(unsigned i = 0; i < N; ++i)
		{
			unsigned number;
			cin >> number;
			numbers[i] = number;
		}
		return NumberSet1D(height, numbers);
	}

	NumberSet2D inputNumberSet(unsigned width, unsigned height)
	{
		NumberSet2D ret(width, height);
		for(unsigned i = 0; i < height; ++i)
		{
			ret.setRow(i, inputNumberSetRow(width));
		}
		for(unsigned i = 0; i < width; ++i)
		{
			ret.setColumn(i, inputNumberSetColumn(height));
		}
		return ret;
	}
}

int main()
{
	using namespace nonogram_solver;
	const unsigned width = inputWidth();
	const unsigned height = inputHeight();
	const NumberSet2D &numberSet = inputNumberSet(width, height);
	Puzzle2DSolver solver(width, height, numberSet);
	solver.solve();
	display(solver.getResult());
	return 0;
}