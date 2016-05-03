
#pragma once
#include <cliext/vector>
#include <cliext/list>

using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Element abstract
	{
	protected:
		Point position;
		Color color;
		System::Drawing::Rectangle boundRect;
		Pen^ pen;
	public:
		virtual void Draw(Graphics^ g) abstract;
	};
	
}
