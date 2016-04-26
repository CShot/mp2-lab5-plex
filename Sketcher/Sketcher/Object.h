#pragma once
#include <math.h>

namespace Sketcher
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	class Object
	{
	protected:
		bool Visible, Active;
	public:
		Object() : Visible(false), Active(false)
		{
		};
		virtual void Show(Graphics ^g) = 0;
		virtual void Hide(Graphics ^g) = 0;
		virtual void Move(Graphics ^g, int mx, int my) = 0;
		virtual int GetX(Graphics ^g) = 0;
		virtual int GetY(Graphics ^g) = 0;
	};

	class TPoint : public Object
	{
	protected:
		int x, y;
	public:
		TPoint(int _x = 0, int _y = 0)
		{
			x = _x;
			y = _y;
			Visible = false;
			Active = false;
		}
		virtual void Show(Graphics ^g)
		{
			g->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
			Visible = true;
			Active = true;
		}
		virtual void Hide(Graphics ^g)
		{
			g->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
			Visible = false;
			Active = false;
		}
		virtual void Move(Graphics ^g, int mx, int my)
		{
			Hide(g);
			x += mx;
			y += my;
			Show(g);
		}
		virtual int GetX(Graphics ^g)
		{ 
			return x; 
		}
		virtual int GetY(Graphics ^g)
		{ 
			return y; 
		}
	};
}