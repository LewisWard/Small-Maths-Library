// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#include "Vec2.h"

namespace math
{
	Vec2::Vec2()
	{

	}

	Vec2::Vec2(const float& scalar)
	{
		x = scalar;
		y = scalar;
	}

	Vec2::Vec2(const float& X, const float& Y)
	{
		x = X;
		y = Y;
	}

	Vec2::~Vec2()
	{

	}

	const Vec2 Vec2::kONE(1.0f, 1.0f);
	const Vec2 Vec2::kONEX(1.0f, 0.0f);
	const Vec2 Vec2::kONEY(0.0f, 1.0f);
	const Vec2 Vec2::kZERO(0.0f, 0.0f);
	const Vec2 Vec2::kHALF(0.5f, 0.5f);
	const Vec2 Vec2::kTWO(2.0f, 2.0f);

}; // end of math namespace
