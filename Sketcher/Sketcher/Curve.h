#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Curve : Element
	{
	protected:
		int width;
		int height;

	public:
		Curve(Color color, Point start, Point end)
		{
			pen = gcnew Pen(color);
			this->color = color;
			position = Point(Math::Min(start.X, end.X), Math::Min(start.Y, end.Y));
			width = 3;
			height = 3;
			boundRect = System::Drawing::Rectangle(position, Size(width + 1, height + 1));
		}
		virtual void Draw(Graphics^ g) override
		{
			pen->Color = highlighted ? highlightColor : color;
			g->DrawEllipse(pen, position.X, position.Y, width, height);
		}
	};
}