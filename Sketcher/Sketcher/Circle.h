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
		Circle(Color color, Point center, Point circum)
		{
			pen = gcnew Pen(color);
			this->color = color;
			int radius = safe_cast<int>(Math::Sqrt(
				(center.X - circum.X)*(center.X - circum.X) +
				(center.Y - circum.Y)*(center.Y - circum.Y)));
			position = Point(center.X - radius, center.Y - radius);
			width = height = 2 * radius;
			boundRect = System::Drawing::Rectangle(position, Size(width, height));
		}

		virtual void Draw(Graphics^ g) override
		{
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			g->DrawEllipse(pen, 0, 0, width, height);
			g->ResetTransform();
		}
	};
}