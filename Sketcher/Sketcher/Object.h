
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
		Color highlightColor;
		System::Drawing::Rectangle boundRect;
		Pen^ pen;
	public:
		property bool highlighted;
		virtual void Draw(Graphics^ g) abstract;
		Element():highlightColor(Color::Gold)
		{
			highlighted = false;
		}
		property System::Drawing::Rectangle bound
		{
			System::Drawing::Rectangle get()
			{ 
				return boundRect; 
			}
		}
		bool Hit(Point p)
		{
			return boundRect.Contains(p);
		}
		virtual void Move(int dx, int dy) override
		{
			position.Offset(dx, dy);
			Element::Move(dx, dy);
		}
	};
	
}
