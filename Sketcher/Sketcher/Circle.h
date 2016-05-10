#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Circle : Element
	{
	protected:
		int width;
		int height;
	public:
		Circle(Color color, Point start, Point end)
		{
			pen = gcnew Pen(color);
			this->color = color;
			int radius = safe_cast<int>(Math::Sqrt((start.X - end.X)*(start.X - end.X) + (start.Y - end.Y)*(start.Y - end.Y)));
			width = height = 2 * radius;
			position.X = start.X - radius;
			position.Y = start.Y - radius;
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
			int penWidth(safe_cast<int>(pen->Width));
			boundRect.Inflate(penWidth, penWidth);
		}

		virtual void Draw(Graphics^ g) override
		{
			pen->Color = highlighted ? highlightColor : color;
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			g->DrawEllipse(pen, 0, 0, width, height);
			g->ResetTransform();
		}
	};
}