#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Line : Element
	{
	protected:
		Point end;
	public:
		Line(Color color, Point start, Point end)
		{
			pen = gcnew Pen(color);
			this->color = color;
			position = start;
			this->end = end;
			boundRect = System::Drawing::Rectangle(
				Math::Min(position.X, end.X),
				Math::Min(position.Y, end.Y),
				Math::Abs(position.X - end.X),
				Math::Abs(position.Y - end.Y));
			int penWidth(safe_cast<int>(pen->Width));
			boundRect.Inflate(penWidth, penWidth);
		}
		virtual void Draw(Graphics^ g) override
		{
			pen->Color = highlighted ? highlightColor : color;
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			g->DrawLine(pen, 0, 0, end.X - position.X, end.Y - position.Y);
			g->ResetTransform();
		}
		
		virtual void Move(int dx, int dy) override
		{
			end.Offset(dx, dy);
			Element::Move(dx, dy);
		}
	};
}