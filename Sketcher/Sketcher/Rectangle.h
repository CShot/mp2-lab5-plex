#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Rectangle : Element
	{
	protected:
		int width;
		int height;
	public:
		Rectangle(Color color, Point p1, Point p2)
		{
			pen = gcnew Pen(color);
			this->color = color;
			position = Point(Math::Min(p1.X, p2.X), Math::Min(p1.Y, p2.Y));
			width = Math::Abs(p1.X - p2.X);
			height = Math::Abs(p1.Y - p2.Y);
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
			int penWidth(safe_cast<int>(pen->Width));
			boundRect.Inflate(penWidth, penWidth);
		}

		virtual void Draw(Graphics^ g) override
		{
			pen->Color=highlighted?highlightColor:color;
			g->DrawRectangle(pen, position.X, position.Y, width, height);
		}
	};
}