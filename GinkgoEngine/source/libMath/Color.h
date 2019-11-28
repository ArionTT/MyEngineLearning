#ifndef COLOR_H
#define COLOR_H

#include"stdhead.h"

namespace External
{
	struct Color;
	struct Color32;

	struct Color32
	{
	public:
		Color32();
		Color32(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
		Color32(const Color32& color);
		Color32(const Color& color);
		~Color32();

	public:
		Color GetColor();
		void ToGray();

	public:
		Uint8 r, g, b, a;
	};

	struct Color
	{
	public:
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		Color(float Gray);
		Color(const Color& color);
		Color(const Color32 & color);
		~Color();

	public:
		Color32 GetColor32();
		void ToGray();

	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				float r, g, b, a;
			};
			float c[4];
		};
	};


}
#endif // !COLOR_H

