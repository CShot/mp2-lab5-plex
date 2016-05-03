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
	private:
		vector<Point>^ points;

	public:
		Curve(Color color, Point p1, Point p2)
		{
			pen = gcnew Pen(color);
			this->color = color;
			points = gcnew vector<Point>();
			position = p1;
			points->push_back(p2 - Size(position));
			int minX = p1.X < p2.X ? p1.X : p2.X;
			int minY = p1.Y < p2.Y ? p1.Y : p2.Y;
			int maxX = p1.X > p2.X ? p1.X : p2.X;
			int maxY = p1.Y > p2.Y ? p1.Y : p2.Y;
			int width = Math::Max(2, maxX - minX);
			int height = Math::Max(2, maxY - minY);
			boundRect = System::Drawing::Rectangle(minX, minY, width, height);
		}

		void Add(Point p)
		{
			points->push_back(p - Size(position));
			if (p.X < boundRect.X)
			{
				boundRect.Width = boundRect.Right - p.X;
				boundRect.X = p.X;
			}
			else if (p.X > boundRect.Right)
				boundRect.Width = p.X - boundRect.Left;
			if (p.Y < boundRect.Y)
			{
				boundRect.Height = boundRect.Bottom - p.Y;
				boundRect.Y = p.Y;
			}
			else if (p.Y > boundRect.Bottom)
				boundRect.Height = p.Y - boundRect.Top;
		}
		virtual void Draw(Graphics^ g) override
		{
			g->TranslateTransform(safe_cast<float>(position.X), safe_cast<float>(position.Y));
			Point previous(0, 0);
			for each(Point p in *points)
			{
				g->DrawLine(pen, previous, p);
				previous = p;
			}
			g->ResetTransform();
		}
	};
}