#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Ellipse : Element
	{
	protected:
		int width;
		int height;

	public:
		Ellipse(Color color, Point start, Point end)
		{
			pen = gcnew Pen(color);
			this->color = color;
			position = Point(Math::Min(start.X, end.X), Math::Min(start.Y, end.Y));
			width = Math::Abs(end.X - start.X);
			height = Math::Abs(end.Y - start.Y);
			boundRect = System::Drawing::Rectangle(start, Size(width, height));
		}

		virtual void Draw(Graphics^ g) override
		{
			g->DrawEllipse(pen, position.X, position.Y, width, height);
		}
	};
}