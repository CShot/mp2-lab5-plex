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
			position = start;
			height = Math::Abs(end.Y - start.Y);
			width = Math::Abs(end.X - start.X);
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
		}

		virtual void Draw(Graphics^ g) override
		{
			pen->Color = highlighted ? highlightColor : color;
			g->DrawEllipse(pen, position.X, position.Y, width, height);
		}
	};
}