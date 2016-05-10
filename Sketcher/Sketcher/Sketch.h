#pragma once
#include <cliext/vector>
#include <cliext/list>
#include "Object.h"
using namespace System;
using namespace System::Drawing;
using namespace cliext;

namespace Sketcher
{
	public ref class Sketch
	{
	private:
		list<Element^>^ elements;

	public:
		Sketch()
		{
			elements = gcnew list<Element^>();
		}

		Sketch^ operator+=(Element^ element)
		{
			elements->push_back(element);
			return this;
		}

		Sketch^ operator-=(Element^ element)
		{
			elements->remove(element);
			return this;
		}

		void Draw(Graphics^ g)
		{
			for each(Element^ element in *elements)
				element->Draw(g);
		}

		Element^ HitElement(Point p)
		{
			for (auto riter = elements->rbegin();riter != elements->rend(); ++riter)
			{
				if ((*riter)->Hit(p))
					return *riter;
			}
			return nullptr;
		}

		void push_front(Element^ element)
		{
			elements->push_front(element);
		}
	};
}