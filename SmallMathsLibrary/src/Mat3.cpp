// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#include "Mat3.h"

namespace math
{
	Mat3::Mat3()
	{

	}

	Mat3::Mat3(const float& i)
	{
		m[0][0] = 1.0f;
		m[1][1] = 1.0f;
		m[2][2] = 1.0f;

		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[1][0] = 0.0f;
		m[1][2] = 0.0f;
		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
	}

	Mat3::Mat3(math::Vec3& x, math::Vec3& y, math::Vec3& z)
	{
		m[0][0] = x.x;
		m[0][1] = x.y;
		m[0][2] = x.z;
		m[1][0] = y.x;
		m[1][1] = y.y;
		m[1][2] = y.z;
		m[2][0] = z.x;
		m[2][1] = z.y;
		m[2][2] = z.z;
	}


	Mat3::~Mat3()
	{

	}


	float Mat3::determinant()
	{
		float a = m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]));
		float b = m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]));
		float c = m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));

		return (a - b + c);
	}

	math::Mat3 Mat3::transpose()
	{
		// swapping around the rows and columns (diagonal reflection)
		// before:
		//	|	a	b	c	|
		//	|	d	e	f	|
		//	|	g	h	i	|
		// after:
		//	|	a	d	g	|
		//	|	b	e	h	|
		//	|	c	f	i	|

		math::Mat3 t;
		t.m[0][0] = m[0][0];
		t.m[0][1] = m[1][0];
		t.m[0][2] = m[2][0];
		t.m[1][0] = m[0][1];
		t.m[1][1] = m[1][1];
		t.m[1][2] = m[2][1];
		t.m[2][0] = m[0][2];
		t.m[2][1] = m[1][2];
		t.m[2][2] = m[2][2];	
		return t;
	}

	bool Mat3::equals(const math::Mat3 compairToMatrix)
	{
		// might be a 'smarter' way of doing this with  & or | maybe.. might want to look into it
		if (m[0][0] == compairToMatrix.m[0][0]) {} else return false;
		if (m[0][1] == compairToMatrix.m[0][1]) {} else return false;
		if (m[0][2] == compairToMatrix.m[0][2]) {} else return false;
		if (m[1][0] == compairToMatrix.m[1][0]) {} else return false;
		if (m[1][1] == compairToMatrix.m[1][1]) {} else return false;
		if (m[1][2] == compairToMatrix.m[1][2]) {} else return false;
		if (m[2][0] == compairToMatrix.m[2][0]) {} else return false;
		if (m[2][1] == compairToMatrix.m[2][1]) {} else return false;
		if (m[2][2] == compairToMatrix.m[2][2]) {} else return false;

		return true;
	}

	math::Mat3 Mat3::matrixWithNoSacle()
	{
		Mat3 c;
		c.m[0][0] = this->m[0][0];
		c.m[0][1] = this->m[0][1];
		c.m[0][2] = this->m[0][2];
		c.m[1][0] = this->m[1][0];
		c.m[1][1] = this->m[1][1];
		c.m[1][2] = this->m[1][2];
		c.m[2][0] = this->m[2][0];
		c.m[2][1] = this->m[2][1];
		c.m[2][2] = this->m[2][2];
		c.resetScale();
		return c;
	}

	math::Mat3 Mat3::inverse()
	{
		// the matrix at the start
		//	|	a	b	c	|
		//	|	d	e	f	|
		//	|	g	h	i	|
		//
		// need to find the determinant
		// for each element make a MoM (Matrix of Minors)
		//	|	|e f| |d f|	|d e|	|
		//	|	|h i|	|g i|	|g h|	|
		//	|										|
		//  | |b c|	|a c|	|a b|	|
		//	|	|h i|	|g i|	|g h|	|
		//	|										|
		//	|	|b c|	|a c|	|a b|	|
		//	|	|e f|	|d f|	|d e|	|
		//
		// need to now bring this all together (cofactor matrix)
		//  |	+ - +	|
		//  | - + - |
		//	| + - + |

		float id = 1;
		math::Mat3 temp(id);

		// get the determinant
		float det = this->determinant();

		// make sure the matix can have a inverse
		if (det)
		{
			// the results from the MoM
			float MoM[9];
			MoM[0] = (m[1][1] * m[2][2]) - (m[1][2] * m[2][1]); ///< a
			MoM[1] = (m[1][0] * m[2][2]) - (m[1][2] * m[2][0]); ///< b
			MoM[2] = (m[1][0] * m[2][1]) - (m[1][1] * m[2][0]); ///< c
			MoM[3] = (m[0][1] * m[2][2]) - (m[0][2] * m[2][1]); ///< d
			MoM[4] = (m[0][0] * m[2][2]) - (m[0][2] * m[2][0]); ///< e
			MoM[5] = (m[0][0] * m[2][1]) - (m[0][1] * m[2][0]); ///< f
			MoM[6] = (m[0][1] * m[1][2]) - (m[0][2] * m[1][1]); ///< g
			MoM[7] = (m[0][0] * m[1][2]) - (m[0][2] * m[1][0]); ///< h
			MoM[8] = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]); ///< i

			// make values match the checkerboard pattern
			MoM[0] = MoM[0];
			MoM[1] = -1 * MoM[1];
			MoM[2] = MoM[2];
			MoM[3] = -1 * MoM[3];
			MoM[4] = MoM[4];
			MoM[5] = -1 * MoM[5];
			MoM[6] = MoM[6];
			MoM[7] = -1 * MoM[7];
			MoM[8] = MoM[8];

			// divide by the determinant (also why needed to check it was not zero)
			MoM[0] = MoM[0] / det;
			MoM[1] = MoM[1] / det;
			MoM[2] = MoM[2] / det;
			MoM[3] = MoM[3] / det;
			MoM[4] = MoM[4] / det;
			MoM[5] = MoM[5] / det;
			MoM[6] = MoM[6] / det;
			MoM[7] = MoM[7] / det;
			MoM[8] = MoM[8] / det;

			// assign to the matrix
			temp.m[0][0] = MoM[0]; // 0
			temp.m[0][1] = MoM[3]; // 3
			temp.m[0][2] = MoM[6]; // 6
			temp.m[1][0] = MoM[1]; // 1
			temp.m[1][1] = MoM[4]; // 4
			temp.m[1][2] = MoM[7]; // 7
			temp.m[2][0] = MoM[2]; // 2
			temp.m[2][1] = MoM[5]; // 5
			temp.m[2][2] = MoM[8]; // 8
		}
		
		return temp;
	}
	
	void Mat3::rotateX(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[1][1] = std::cosf(rot);
		m[1][2] = std::sinf(rot);
		m[2][1] = -std::sinf(rot);
		m[2][2] = std::cosf(rot);
	}

	void Mat3::rotateY(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[0][0] = std::cosf(rot);
		m[0][2] = -std::sinf(rot);
		m[2][0] = std::sinf(rot);
		m[2][2] = std::cosf(rot);
	}

	void Mat3::rotateZ(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[0][0] = std::cosf(rot);
		m[0][1] = std::sinf(rot);
		m[1][0] = -std::sinf(rot);
		m[1][1] = std::cosf(rot);
	}


	math::Mat3 add(const math::Mat3& a, const math::Mat3& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] + b.m[0][0];
		t.m[0][1] = a.m[0][1] + b.m[0][1];
		t.m[0][2] = a.m[0][2] + b.m[0][2];
		t.m[1][0] = a.m[1][0] + b.m[1][0];
		t.m[1][1] = a.m[1][1] + b.m[1][1];
		t.m[1][2] = a.m[1][2] + b.m[1][2];
		t.m[2][0] = a.m[2][0] + b.m[2][0];
		t.m[2][1] = a.m[2][1] + b.m[2][1];
		t.m[2][2] = a.m[2][2] + b.m[2][2];
		return t;
	}

	math::Mat3 add(const math::Mat3& a, const float& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] + b;
		t.m[0][1] = a.m[0][1] + b;
		t.m[0][2] = a.m[0][2] + b;
		t.m[1][0] = a.m[1][0] + b;
		t.m[1][1] = a.m[1][1] + b;
		t.m[1][2] = a.m[1][2] + b;
		t.m[2][0] = a.m[2][0] + b;
		t.m[2][1] = a.m[2][1] + b;
		t.m[2][2] = a.m[2][2] + b;
		return t;
	}

	math::Mat3 sub(const math::Mat3& a, const math::Mat3& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] - b.m[0][0];
		t.m[0][1] = a.m[0][1] - b.m[0][1];
		t.m[0][2] = a.m[0][2] - b.m[0][2];
		t.m[1][0] = a.m[1][0] - b.m[1][0];
		t.m[1][1] = a.m[1][1] - b.m[1][1];
		t.m[1][2] = a.m[1][2] - b.m[1][2];
		t.m[2][0] = a.m[2][0] - b.m[2][0];
		t.m[2][1] = a.m[2][1] - b.m[2][1];
		t.m[2][2] = a.m[2][2] - b.m[2][2];
		return t;
	}

	math::Mat3 sub(const math::Mat3& a, const float& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] - b;
		t.m[0][1] = a.m[0][1] - b;
		t.m[0][2] = a.m[0][2] - b;
		t.m[1][0] = a.m[1][0] - b;
		t.m[1][1] = a.m[1][1] - b;
		t.m[1][2] = a.m[1][2] - b;
		t.m[2][0] = a.m[2][0] - b;
		t.m[2][1] = a.m[2][1] - b;
		t.m[2][2] = a.m[2][2] - b;
		return t;
	}

	math::Mat3 mul(const math::Mat3& a, const math::Mat3& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0];
		t.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1];
		t.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2];
		t.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0];
		t.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1];
		t.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2];
		t.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0];
		t.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1];
		t.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2];
		return t;
	}

	math::Mat3 mul(const math::Mat3& a, const float& b)
	{
		math::Mat3 t;
		t.m[0][0] = a.m[0][0] * b;
		t.m[0][1] = a.m[0][1] * b;
		t.m[0][2] = a.m[0][2] * b;
		t.m[1][0] = a.m[1][0] * b;
		t.m[1][1] = a.m[1][1] * b;
		t.m[1][2] = a.m[1][2] * b;
		t.m[2][0] = a.m[2][0] * b;
		t.m[2][1] = a.m[2][1] * b;
		t.m[2][2] = a.m[2][2] * b;
		return t;
	}


}; /// end of namespace
