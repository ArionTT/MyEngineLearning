#include"Color.h"

namespace External
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Color::Color()
	{
		this->r = this->g = this->b = this->a = 1.0f;
	}

	Color::Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color::Color(float Gray)
	{
		this->r = this->g = this->b = Gray;
		this->a = 1.0f;
	}

	Color::Color(const Color & color)
	{
		this->r = color.r;
		this->g = color.g;
		this->b = color.b;
		this->a = color.a;
	}

	Color::Color(const Color32 & color)
	{
		r = static_cast<float>(color.r / 255.0f);
		g = static_cast<float>(color.g / 255.0f);
		b = static_cast<float>(color.b / 255.0f);
		a = static_cast<float>(color.a / 255.0f);
	}

	Color::~Color()
	{
	}

	Color32 Color::GetColor32()
	{
		return Color32(static_cast<Uint8>(r * 255), static_cast<Uint8>(g * 255), static_cast<Uint8>(b * 255), static_cast<Uint8>(a * 255));
	}

	void Color::ToGray()
	{
		r = g = b = (r*0.333f + g * 0.333f + b * 0.333f);
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	Color32::Color32()
	{
		r = g = b = a = 255;
	}

	Color32::Color32(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color32::Color32(const Color32 & color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	Color32::Color32(const Color & color)
	{
		r = static_cast<Uint8>(color.r * 255);
		g = static_cast<Uint8>(color.g * 255);
		b = static_cast<Uint8>(color.b * 255);
		a = static_cast<Uint8>(color.a * 255);
	}

	Color32::~Color32()
	{
	}

	Color Color32::GetColor()
	{
		return Color(static_cast<float>(r / 255.0f), static_cast<float>(g / 255.0f), static_cast<float>(b / 255.0f), static_cast<float>(a / 255.0f));
	}

	void Color32::ToGray()
	{
		r = g = b = (Uint8)(r*0.333f + g * 0.333f + b * 0.333f);
	}

}