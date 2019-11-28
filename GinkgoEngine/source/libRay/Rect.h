#ifndef RECT_H
#define RECT_H

#include<Vector.h>

namespace External
{
	struct Rect
	{
	public:
		Rect();
		Rect(float w, float h);
		Rect(float x, float y, float w, float h);
		Rect(Vector2 pos, Vector2 size);
		Rect(const Rect& rect);
		~Rect();

	public:
		float x, y;
		float width, height;
	};

}

#endif // !RECT_H

