// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016
#include "Mat4.h"

namespace math
{
	Mat4::Mat4()
	{

	}

	Mat4::Mat4(const float& i)
	{
		m[0][0] = 1.0f;
		m[1][1] = 1.0f;
		m[2][2] = 1.0f;
		m[3][3] = 1.0f;

		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = 0.0f;
		m[1][0] = 0.0f;
		m[1][2] = 0.0f;
		m[1][3] = 0.0f;
		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
		m[2][3] = 0.0f;
		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
	}

	Mat4::Mat4(math::Mat3& mat33)
	{
		m[0][0] = mat33.m[0][0]; 
		m[0][1] = mat33.m[0][1]; 
		m[0][2] = mat33.m[0][2]; 
		m[0][3] = mat33.m[0][3];
		m[1][0] = mat33.m[1][0]; 
		m[1][1] = mat33.m[1][1]; 
		m[1][2] = mat33.m[1][2]; 
		m[1][3] = mat33.m[1][3];
		m[2][0] = mat33.m[2][0];
		m[2][1] = mat33.m[2][1]; 
		m[2][2] = mat33.m[2][2]; 
		m[2][3] = mat33.m[2][3];
		m[3][0] = 0.0f; 
		m[3][1] = 0.0f; 
		m[3][2] = 0.0f; 
		m[3][3] = 1.0f;
	}

	Mat4::Mat4(math::Vec3& x, math::Vec3& y, math::Vec3& z, math::Vec3& w)
	{
		m[0][0] = x.x;
		m[0][1] = x.y;
		m[0][2] = x.z;
		m[0][3] = x.w;
		m[1][0] = y.x;
		m[1][1] = y.y;
		m[1][2] = y.z;
		m[1][3] = y.w;
		m[2][0] = z.x;
		m[2][1] = z.y;
		m[2][2] = z.z;
		m[2][3] = z.w;
		m[3][0] = w.x;
		m[3][1] = w.y;
		m[3][2] = w.z;
		m[3][3] = w.w;
	}

	Mat4::~Mat4()
	{

	}

	float Mat4::determinant()
	{
		float X = m[0][0] * (m[1][1] * ((m[2][2] * m[3][3]) - (m[2][3] * m[3][2])) 
			                 - m[1][2] * ((m[2][1] * m[3][3]) - (m[2][3] * m[3][1])) 
											 + m[1][3] * ((m[2][1] * m[3][2]) - (m[2][2] * m[3][1])));
		
		float Y = m[0][1] * (m[1][0] * ((m[2][2] * m[3][3]) - (m[2][3] * m[3][2]))
			                 - m[1][2] * ((m[2][0] * m[3][3]) - (m[2][3] * m[3][0]))
											 + m[1][3] * ((m[2][0] * m[3][2]) - (m[2][2] * m[3][0])));

		float Z = m[0][2] * (m[1][0] * ((m[2][1] * m[3][3]) - (m[2][3] * m[3][1]))
											 - m[1][1] * ((m[2][0] * m[3][3]) - (m[2][3] * m[3][0]))
											 + m[1][3] * ((m[2][0] * m[3][1]) - (m[2][1] * m[3][0])));

		float W = m[0][3] * (m[1][0] * ((m[2][1] * m[3][2]) - (m[2][2] * m[3][1]))
											 - m[1][1] * ((m[2][0] * m[3][2]) - (m[2][2] * m[3][0]))
										   + m[1][2] * ((m[2][0] * m[3][1]) - (m[2][1] * m[3][0])));

		return X - Y + Z - W;
	}

	math::Mat4 Mat4::transpose()
	{
		math::Mat4 mat;
		mat.m[0][0] = m[0][0];
		mat.m[0][1] = m[1][0];
		mat.m[0][2] = m[2][0];
		mat.m[0][3] = m[3][0];
		mat.m[1][0] = m[0][1];
		mat.m[1][1] = m[1][1];
		mat.m[1][2] = m[2][1];
		mat.m[1][3] = m[3][1];
		mat.m[2][0] = m[0][2];
		mat.m[2][1] = m[1][2];
		mat.m[2][2] = m[2][2];
		mat.m[2][3] = m[3][2];
		mat.m[3][0] = m[0][3];
		mat.m[3][1] = m[1][3];
		mat.m[3][2] = m[2][3];
		mat.m[3][3] = m[3][3];
		return mat;
	}

	bool Mat4::equals(const math::Mat4 compairToMatrix)
	{
		// cycle all the elements
		for (size_t i = 0; i < 4; ++i)
		{
			for (size_t ii = 0; ii < 4; ++ii)
			{
				// if these two elements do not match, quit now and return false
				if (m[i][ii] != compairToMatrix.m[i][ii])
				{
					return false;
				}
			}
		}
		return true;
	}

	math::Mat4 Mat4::matrixWithNoSacle()
	{
		math::Mat4 mat;
		mat.m[0][0] = 1.0f;
		mat.m[0][1] = m[0][1];
		mat.m[0][2] = m[0][2];
		mat.m[0][3] = m[0][3];
		mat.m[1][0] = m[1][0];
		mat.m[1][1] = 1.0f;
		mat.m[1][2] = m[1][2];
		mat.m[1][3] = m[1][3];
		mat.m[2][0] = m[2][0];
		mat.m[2][1] = m[2][1];
		mat.m[2][2] = 1.0f;
		mat.m[2][3] = m[2][3];
		mat.m[3][0] = m[3][0];
		mat.m[3][1] = m[3][1];
		mat.m[3][2] = m[3][2];
		mat.m[3][3] = 1.0f;
		return mat;
	}

	math::Mat4 Mat4::inverse()
	{
		math::Mat4 mat;
		// can remove this and just a empty matrix if it failed
		mat.m[0][0] = m[0][0];
		mat.m[0][1] = m[0][1];
		mat.m[0][2] = m[0][2];
		mat.m[0][3] = m[0][3];
		mat.m[1][0] = m[1][0];
		mat.m[1][1] = m[1][1];
		mat.m[1][2] = m[1][2];
		mat.m[1][3] = m[1][3];
		mat.m[2][0] = m[2][0];
		mat.m[2][1] = m[2][1];
		mat.m[2][2] = m[2][2];
		mat.m[2][3] = m[2][3];
		mat.m[3][0] = m[3][0];
		mat.m[3][1] = m[3][1];
		mat.m[3][2] = m[3][2];
		mat.m[3][3] = m[3][3];

		float det = this->determinant();

		if (det)
		{
			float MoM[16];
			MoM[0] = m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2]
				     - m[1][3] * m[2][2] * m[3][1] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3];
			MoM[1] = m[1][0] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][2]
						 - m[1][3] * m[2][2] * m[3][0] - m[1][0] * m[2][3] * m[3][2] - m[1][2] * m[2][0] * m[3][3];
			MoM[2] = m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1]
      			 - m[1][3] * m[2][1] * m[3][0] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3];
			MoM[3] = m[1][0] * m[2][1] * m[3][2] + m[1][1] * m[2][2] * m[3][0] + m[1][2] * m[2][0] * m[3][1]
						 - m[1][2] * m[2][1] * m[3][0] - m[1][0] * m[2][2] * m[3][1] - m[1][1] * m[2][0] * m[3][2];
			MoM[4] = m[0][1] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][1] + m[0][3] * m[2][1] * m[3][2]
					   - m[0][3] * m[2][2] * m[3][1] - m[0][1] * m[2][3] * m[3][2] - m[0][2] * m[2][1] * m[3][3];
			MoM[5] = m[0][0] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][2]
						 - m[0][3] * m[2][2] * m[3][0] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3];
			MoM[6] = m[0][0] * m[2][1] * m[3][3] + m[0][1] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][1]
						 - m[0][3] * m[2][1] * m[3][0] - m[0][0] * m[2][3] * m[3][1] - m[0][1] * m[2][0] * m[3][3];
			MoM[7] = m[0][0] * m[2][1] * m[3][2] + m[0][1] * m[2][2] * m[3][0] + m[0][2] * m[2][0] * m[3][1]
						 - m[0][2] * m[2][1] * m[3][0] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2];
			MoM[8] = m[0][1] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][1] + m[0][3] * m[1][1] * m[3][2]
						 - m[0][3] * m[1][2] * m[3][1] - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3];
			MoM[9] = m[0][0] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][2]
						 - m[0][3] * m[1][2] * m[3][0] - m[0][0] * m[1][3] * m[3][2] - m[0][2] * m[1][0] * m[3][3];
			MoM[10] = m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][1]
							- m[0][3] * m[1][1] * m[3][0] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3];
			MoM[11] = m[0][0] * m[1][1] * m[3][2] + m[0][1] * m[1][2] * m[3][0] + m[0][2] * m[1][0] * m[3][1]
							- m[0][2] * m[1][1] * m[3][0] - m[0][0] * m[1][2] * m[3][1] - m[0][1] * m[1][0] * m[3][2];
			MoM[12] = m[0][1] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][1] + m[0][3] * m[1][1] * m[2][2] 
							- m[0][3] * m[1][2] * m[2][1] - m[0][1] * m[1][3] * m[2][2] - m[0][2] * m[1][1] * m[2][3];
			MoM[13] = m[0][0] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][2]
							- m[0][3] * m[1][2] * m[2][0] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3];
			MoM[14] = m[0][0] * m[1][1] * m[2][3] + m[0][1] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][1] 
							- m[0][3] * m[1][1] * m[2][0] - m[0][0] * m[3][3] * m[2][1] - m[0][1] * m[1][0] * m[2][3];
			MoM[15] = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] 
							- m[0][2] * m[1][1] * m[2][0] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2];

			// make values match the checkerboard pattern
			mat.m[0][0] = MoM[0];
			mat.m[0][1] = MoM[4] * -1.0f;
			mat.m[0][2] = MoM[8];
			mat.m[0][3] = MoM[12] * -1.0f;
			mat.m[1][0] = MoM[1] * -1.0f;
			mat.m[1][1] = MoM[5];
			mat.m[1][2] = MoM[9] * -1.0f;
			mat.m[1][3] = MoM[13];
			mat.m[2][0] = MoM[2];
			mat.m[2][1] = MoM[6] * -1.0f;
			mat.m[2][2] = MoM[10];
			mat.m[2][3] = MoM[14] * -1.0f;
			mat.m[3][0] = MoM[3] * -1.0f;
			mat.m[3][1] = MoM[7];
			mat.m[3][2] = MoM[11] * -1.0f;
			mat.m[3][3] = MoM[15];

			// divide by the determinant (also why needed to check it was not zero)
			mat.m[0][0] /= det;
			mat.m[0][1] /= det;
			mat.m[0][2] /= det;
			mat.m[0][3] /= det;
			mat.m[1][0] /= det;
			mat.m[1][1] /= det;
			mat.m[1][2] /= det;
			mat.m[1][3] /= det;
			mat.m[2][0] /= det;
			mat.m[2][1] /= det;
			mat.m[2][2] /= det;
			mat.m[2][3] /= det;
			mat.m[3][0] /= det;
			mat.m[3][1] /= det;
			mat.m[3][2] /= det;
			mat.m[3][3] /= det;

		}

		return mat;
	}

	void Mat4::rotateX(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[1][1] = std::cosf(rot);
		m[1][2] = std::sinf(rot);
		m[2][1] = -std::sinf(rot);
		m[2][2] = std::cosf(rot);
	}

	void Mat4::rotateY(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[0][0] = std::cosf(rot);
		m[0][2] = -std::sinf(rot);
		m[2][0] = std::sinf(rot);
		m[2][2] = std::cosf(rot);
	}

	void Mat4::rotateZ(float& rotation)
	{
		// get the number of radians
		float rot = rotation * PI / 180.0f;

		m[0][0] = std::cosf(rot);
		m[0][1] = std::sinf(rot);
		m[1][0] = -std::sinf(rot);
		m[1][1] = std::cosf(rot);
	}

	math::Mat4 add(const math::Mat4& a, const math::Mat4& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] + b.m[0][0];
		t.m[0][1] = a.m[0][1] + b.m[0][1];
		t.m[0][2] = a.m[0][2] + b.m[0][2];
		t.m[0][3] = a.m[0][3] + b.m[0][3];
		t.m[1][0] = a.m[1][0] + b.m[1][0];
		t.m[1][1] = a.m[1][1] + b.m[1][1];
		t.m[1][2] = a.m[1][2] + b.m[1][2];
		t.m[1][3] = a.m[1][3] + b.m[1][3];
		t.m[2][0] = a.m[2][0] + b.m[2][0];
		t.m[2][1] = a.m[2][1] + b.m[2][1];
		t.m[2][2] = a.m[2][2] + b.m[2][2];
		t.m[2][3] = a.m[2][3] + b.m[2][3];
		t.m[3][0] = a.m[3][0] + b.m[3][0];
		t.m[3][1] = a.m[3][1] + b.m[3][1];
		t.m[3][2] = a.m[3][2] + b.m[3][2];
		t.m[3][3] = a.m[3][3] + b.m[3][3];
		return t;
	}

	math::Mat4 add(const math::Mat4& a, const float& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] + b;
		t.m[0][1] = a.m[0][1] + b;
		t.m[0][2] = a.m[0][2] + b;
		t.m[0][3] = a.m[0][3] + b;
		t.m[1][0] = a.m[1][0] + b;
		t.m[1][1] = a.m[1][1] + b;
		t.m[1][2] = a.m[1][2] + b;
		t.m[1][3] = a.m[1][3] + b;
		t.m[2][0] = a.m[2][0] + b;
		t.m[2][1] = a.m[2][1] + b;
		t.m[2][2] = a.m[2][2] + b;
		t.m[2][3] = a.m[2][3] + b;
		t.m[3][0] = a.m[3][0] + b;
		t.m[3][1] = a.m[3][1] + b;
		t.m[3][2] = a.m[3][2] + b;
		t.m[3][3] = a.m[3][3] + b;
		return t;
	}

	math::Mat4 sub(const math::Mat4& a, const math::Mat4& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] - b.m[0][0];
		t.m[0][1] = a.m[0][1] - b.m[0][1];
		t.m[0][2] = a.m[0][2] - b.m[0][2];
		t.m[0][3] = a.m[0][3] - b.m[0][3];
		t.m[1][0] = a.m[1][0] - b.m[1][0];
		t.m[1][1] = a.m[1][1] - b.m[1][1];
		t.m[1][2] = a.m[1][2] - b.m[1][2];
		t.m[1][3] = a.m[1][3] - b.m[1][3];
		t.m[2][0] = a.m[2][0] - b.m[2][0];
		t.m[2][1] = a.m[2][1] - b.m[2][1];
		t.m[2][2] = a.m[2][2] - b.m[2][2];
		t.m[2][3] = a.m[2][3] - b.m[2][3];
		t.m[3][0] = a.m[3][0] - b.m[3][0];
		t.m[3][1] = a.m[3][1] - b.m[3][1];
		t.m[3][2] = a.m[3][2] - b.m[3][2];
		t.m[3][3] = a.m[3][3] - b.m[3][3];
		return t;
	}

	math::Mat4 sub(const math::Mat4& a, const float& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] - b;
		t.m[0][1] = a.m[0][1] - b;
		t.m[0][2] = a.m[0][2] - b;
		t.m[0][3] = a.m[0][3] - b;
		t.m[1][0] = a.m[1][0] - b;
		t.m[1][1] = a.m[1][1] - b;
		t.m[1][2] = a.m[1][2] - b;
		t.m[1][3] = a.m[1][3] - b;
		t.m[2][0] = a.m[2][0] - b;
		t.m[2][1] = a.m[2][1] - b;
		t.m[2][2] = a.m[2][2] - b;
		t.m[2][3] = a.m[2][3] - b;
		t.m[3][0] = a.m[3][0] - b;
		t.m[3][1] = a.m[3][1] - b;
		t.m[3][2] = a.m[3][2] - b;
		t.m[3][3] = a.m[3][3] - b;
		return t;
	}

	math::Mat4 mul(const math::Mat4& a, const math::Mat4& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0];
		t.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1];
		t.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2];
		t.m[0][3] = a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] + a.m[0][3] * b.m[3][3];
		t.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0];
		t.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1];
		t.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2];
		t.m[1][3] = a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3];
		t.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0];
		t.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1];
		t.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2];
		t.m[2][3] = a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3];
		t.m[3][0] = a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] + a.m[3][3] * b.m[3][0];
		t.m[3][1] = a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1];
		t.m[3][2] = a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2];
		t.m[3][3] = a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3];
		return t;
	}

	math::Mat4 mul(const math::Mat4& a, const float& b)
	{
		math::Mat4 t;
		t.m[0][0] = a.m[0][0] * b;
		t.m[0][1] = a.m[0][1] * b;
		t.m[0][2] = a.m[0][2] * b;
		t.m[0][3] = a.m[0][3] * b;
		t.m[1][0] = a.m[1][0] * b;
		t.m[1][1] = a.m[1][1] * b;
		t.m[1][2] = a.m[1][2] * b;
		t.m[1][3] = a.m[1][3] * b;
		t.m[2][0] = a.m[2][0] * b;
		t.m[2][1] = a.m[2][1] * b;
		t.m[2][2] = a.m[2][2] * b;
		t.m[2][3] = a.m[2][3] * b;
		t.m[3][0] = a.m[3][0] * b;
		t.m[3][1] = a.m[3][1] * b;
		t.m[3][2] = a.m[3][2] * b;
		t.m[3][3] = a.m[3][3] * b;
		return t;
	}

	math::Mat4 frustum(const float& left, const float& right, const float& bottom,
		                 const float& top, const float& nearPlane, const float& farPlane)
	{
		math::Mat4 frustum;
		math::makeIdentity(frustum);
		frustum.m[0][0] = 2.0f * (nearPlane / (right - left));
		frustum.m[1][1] = 2.0f * (nearPlane / (top - bottom));
		frustum.m[2][2] = -((farPlane + nearPlane) / (farPlane - nearPlane));
		frustum.m[2][0] = (left + right) / (right - left);
		frustum.m[2][1] = (top + bottom) / (top - bottom);
		frustum.m[2][3] = -1.0f;
		frustum.m[3][2] = 2.0f * farPlane * nearPlane / (nearPlane - farPlane);
		return frustum;
	}

	math::Mat4 perspective(const float& angle, const float& aspect, const float& nearPlane, const float& farPlane)
	{
		const float halfTan = std::tanf(angle * 0.5f) * nearPlane;
		const float right = aspect * halfTan;
		const float left = -right;
		const float top = halfTan;
		const float bottom = -top;
		return frustum(left, right, bottom, top, nearPlane, farPlane);
	}

	math::Mat4 ortho(const float& left, const float& right, const float& bottom,
									 const float& top, const float& nearPlane, const float& farPlane)
	{
		math::Mat4 ortho;
		math::makeIdentity(ortho);
		ortho.m[0][0] = 2.0f * (1.0f / (right - left));
		ortho.m[1][1] = 2.0f * (1.0f / (top - bottom));
		ortho.m[2][2] = -2.0f * (1.0f / (farPlane - nearPlane));
		ortho.m[3][0] = -(left + right) * (1.0f / (right - left));
		ortho.m[3][1] = -(top + bottom) * (1.0f / (top - bottom));
		ortho.m[3][2] = -(farPlane + nearPlane) * (1.0f / (farPlane - nearPlane));
		ortho.m[3][3] = 1.0f;
		return ortho;
	}

}; // end of math namespace
