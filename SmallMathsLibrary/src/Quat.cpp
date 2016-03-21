// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#include "Quat.h"

namespace math
{
Quat::Quat()
{

}

Quat::Quat(const Quat& quat)
{
	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;
}

Quat::Quat(const math::Mat4& matrix)
{
	// compute the trace
	float t = 1.0f + matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2];
	float s;

	// if greater then unit length
	if (t > 1.0f)
	{
		s = std::sqrt(t) * 2.0f;
		x = (matrix.m[6] - matrix.m[9]) / s;
		y = (matrix.m[8] - matrix.m[2]) / s;
		z = (matrix.m[1] - matrix.m[4]) / s;
		w = 0.25 * s;
	}
	else // need to check the diagonals to find greatest value
	{
		if (matrix.m[0][0] > matrix.m[1][1] && matrix.m[0][0] > matrix.m[2][2])
		{	
			// Column 0: 
			s = sqrt(1.0f + matrix.m[0][0] - matrix.m[1][1] - matrix.m[2][2]) * 2.0f;
			x = 0.25f * s;
			y = (matrix.m[1][0] + matrix.m[0][1]) / s;
			z = (matrix.m[0][2] + matrix.m[2][0]) / s;
			w = (matrix.m[2][1] - matrix.m[1][2]) / s;
		}
		else if (matrix.m[1][1] > matrix.m[2][2])
		{	
			// Column 1: 
			s = sqrt(1.0f + matrix.m[1][1] - matrix.m[0][0] - matrix.m[2][2]) * 2.0f;
			x = (matrix.m[0][1] + matrix.m[1][0]) / s;
			y = 0.25f * s;
			z = (matrix.m[1][2] + matrix.m[2][1]) / s;
			w = (matrix.m[2][0] - matrix.m[0][2]) / s;
		}
		else 
		{			
			// Column 2:
			s = sqrt(1.0f + matrix.m[2][2] - matrix.m[0][0] - matrix.m[1][1]) * 2.0f;
			x = (matrix.m[2][0] + matrix.m[0][2]) / s;
			y = (matrix.m[1][2] + matrix.m[2][1]) / s;
			z = 0.25f * s;
			w = (matrix.m[0][1] - matrix.m[1][0]) / s;
		}
	}
}

Quat::~Quat()
{

}

Quat::Quat(const float& X, const float& Y, const float& Z, const float& W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

bool Quat::equals(Quat& q)
{
	return (x == q.x) && (y == q.y) && (z == q.z) && (w == q.w);
}

math::Mat4 Quat::toMatrix()
{
	// w2+x2-y2-z2			2xy-2wz			2xz+2wy			0
	// 	 2xy+2wz			w2-x2+y2-z2		2yz+2wx			0
	// 	 2xz-2wy				2yz-2wx		w2-x2-y2+z2		0
	//      0							0						0					1
	
	math::Vec3 X(1.0f - 2.0f * (y * y) - 2.0f * (z * z), 2.0f * x * y + 2.0f * z * w, 2.0f * x * z - 2.0f * y * w);
	math::Vec3 Y(2.0f * x * y - 2.0f * z * w, 1.0f - 2.0f * (x * x) - 2.0f * (z * z), 2.0f * z * y + 2.0f * x * w);
	math::Vec3 Z(2.0f * x * z + 2.0f * y * w, 2.0f * z * y - 2.0f * x * w, 1.0f - 2.0f * (x * x) - 2.0f * (y * y));
	math::Vec3 W(0.0f, 0.0f, 0.0f);

	// need to make the w.w compent 1
	W.w = 1.0f;

	return math::Mat4(X, Y, Z, W);
}

math::Quat Quat::lerp(const Quat& a, const Quat& b, float& s)
{
	// lerp: (1.0f - s) * a + s * b
	return math::Quat(a + s) * (b - a);
}

math::Vec3 Quat::getXAxis()
{
	return rotateVector(math::Vec3(1.0f, 0.0f, 0.0f));
}

math::Vec3 Quat::getYAxis()
{
	return rotateVector(math::Vec3(0.0f, 1.0f, 0.0f));
}

math::Vec3 Quat::getZAxis()
{
	return rotateVector(math::Vec3(0.0f, 0.0f, 1.0f));
}

void Quat::normalise(const math::Quat& q)
{
	// get the magnitude
	float l = magnitudeDot(q);

	// almost zero
	if (std::fabs(l) > 0.0000001f)
	{
		this->x = this->x * (1.0f / std::sqrtf(l));
		this->y = this->y * (1.0f / std::sqrtf(l));
		this->z = this->z * (1.0f / std::sqrtf(l));
		this->w = this->w * (1.0f / std::sqrtf(l));
	}
	else
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}
}

inline Quat Quat::inverse()
{
	math::Quat temp(-x, -y, -z, w);
	return temp;
}

bool Quat::isNormalise()
{
	return ((magnitudeDot(*this) <= 1) ? true : false);
}

math::Vec3 Quat::rotateVector(math::Vec3& v)
{
	const math::Vec3 quatE(this->x, this->y, this->z);
	const math::Quat quatInv(this->inverse());
	math::Quat qout;
	qout.mul((*this), v);
	qout.mul(qout, quatInv);
	return math::Vec3(qout.x, qout.y, qout.z);
}

math::Vec3 Quat::inverseVector(math::Vec3& v)
{
	return inverse().rotateVector(v);
}

}; ///< end of namespace
