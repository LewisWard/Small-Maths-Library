// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#include "Vec3.h"

namespace math
{
	Vec3::Vec3()
	{

	}

	Vec3::Vec3(float scalar)
	{
		x = scalar;
		y = scalar;
		z = scalar;
		w = 0.0f;
	}

	Vec3::Vec3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
		w = 0.0f;
	}

	Vec3::~Vec3()
	{

	}


	const Vec3 Vec3::kONE(1.0f, 1.0f, 1.0f);
	const Vec3 Vec3::kONEX(1.0f, 0.0f, 0.0f);
	const Vec3 Vec3::kONEY(0.0f, 1.0f, 0.0f);
	const Vec3 Vec3::kONEZ(0.0f, 0.0f, 1.0f);
	const Vec3 Vec3::kZERO(0.0f, 0.0f, 0.0f);
	const Vec3 Vec3::kHALF(0.5f, 0.5f, 0.5f);
	const Vec3 Vec3::kTWO(2.0f, 2.0f, 2.0f);

}; // end of math namespace

