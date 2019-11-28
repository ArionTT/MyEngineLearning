#include "Rect.h"

namespace External
{

	Rect::Rect()
	{
		x = y = 0.0f;
		width = height = 10.0f;
	}

	Rect::Rect(float w, float h)
	{
		x = y = 0.0f;
		width = w;
		height = h;
	}

	Rect::Rect(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		width = w;
		height = h;
	}

	Rect::Rect(Vector2 pos, Vector2 size)
	{
		x = pos.x;
		y = pos.y;
		width = size.x;
		height = size.y;
	}

	Rect::Rect(const Rect & rect)
	{
		x = rect.x;
		y = rect.y;
		width = rect.width;
		height = rect.height;
	}

	Rect::~Rect()
	{
	}


}
