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
			width = Math::Abs(start.X - end.X);
			height = Math::Abs(start.Y - end.Y);
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
			int penWidth(safe_cast<int>(pen->Width));
			boundRect.Inflate(penWidth, penWidth);
		}

		virtual void Draw(Graphics^ g) override
		{
			pen->Color = highlighted ? highlightColor : color;
			g->DrawEllipse(pen, position.X, position.Y, width, height);
		}
	};
}