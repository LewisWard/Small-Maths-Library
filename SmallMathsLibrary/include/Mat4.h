// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#pragma once
#include "Mat3.h"

//----------------------------------------------------------------------------------------------------------------------
/// \brief  maths namespace
//----------------------------------------------------------------------------------------------------------------------
namespace math
{
	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  Matrix 4x4
	//----------------------------------------------------------------------------------------------------------------------
	class Mat4
	{
	public:

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \note		Matrix will be created uninitialized
		//----------------------------------------------------------------------------------------------------------------------
		Mat4();

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \prama	float 
		/// \note		Always set the matrix to an identity matrix, regardless of the prama
		//----------------------------------------------------------------------------------------------------------------------
		Mat4(const float& i);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor, creates 4x4 from 3x3 matrix
		/// \prama	math::Mat3
		//----------------------------------------------------------------------------------------------------------------------
		Mat4(math::Mat3& mat33);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \prama	math::Vec3 assign all the X elements
		/// \prama	math::Vec3 assign all the Y elements
		/// \prama	math::Vec3 assign all the Z elements
		/// \prama	math::Vec3 assign all the W elements
		//----------------------------------------------------------------------------------------------------------------------
		Mat4(math::Vec3& x, math::Vec3& y, math::Vec3& z, math::Vec3& w);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Destrutor
		//----------------------------------------------------------------------------------------------------------------------
		~Mat4();


		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Apply the scale of the matrix
		/// \prama	float scalar to set the scale to
		//----------------------------------------------------------------------------------------------------------------------
		inline void applyScale(float scalar)
		{
			m[0][0] = scalar;
			m[1][1] = scalar;
			m[2][2] = scalar;
		}


		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Reset the scale
		//----------------------------------------------------------------------------------------------------------------------
		inline void resetScale()
		{
			m[0][0] = 1.0f;
			m[1][1] = 1.0f;
			m[2][2] = 1.0f;
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Translate the matrix
		/// \prama	math::Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline void translation(math::Vec3 t)
		{
			m[0][3] += t.x;
			m[1][3] += t.y;
			m[2][3] += t.z;
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Find if the martix has a determinant
		/// \note		float the determinant
		//----------------------------------------------------------------------------------------------------------------------
		float determinant();


		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Transpose the matrix
		/// \return	math::Mat3 the transposed martix
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat4 transpose();


		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Check a matrix with this matrix
		/// \prama  math::Mat3 matrix to compair with
		/// \return	bool true if equal
		//----------------------------------------------------------------------------------------------------------------------
		bool equals(const math::Mat4 compairToMatrix);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Returns the origin 
		/// \return	math::Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline math::Vec3 origin()
		{
			return math::Vec3(m[0][3], m[1][3], m[2][3]);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Returns this matrix without any scale applied
		/// \return	math::Mat3
		/// \note		The scale will be equal to 1.0
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat4 matrixWithNoSacle();

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  inverse the matrix
		/// \return	math::Mat3 matrix that the inverse was applied to
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat4 inverse();

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the X axis
		/// \prama	float degrees
		//----------------------------------------------------------------------------------------------------------------------
		void rotateX(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the Y axis
		/// \prama	float degrees
		//----------------------------------------------------------------------------------------------------------------------
		void rotateY(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the Z axis
		/// \prama	float degrees
		//----------------------------------------------------------------------------------------------------------------------
		void rotateZ(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// Swizzles
		/// \brief return x swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 x()
		{
			return Vec3(m[0][0], m[0][1], m[0][2]);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return y swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 y()
		{
			return Vec3(m[1][0], m[1][1], m[1][2]);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return z swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 z()
		{
			return Vec3(m[2][0], m[2][1], m[2][2]);
		}

		float m[4][4]; ///< 4x4 floats to form the matrix
	};


	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	add
	/// \prama  math::Mat4 
	/// \prama  math::Mat4 
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 add(const math::Mat4& a, const math::Mat4& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	add
	/// \prama  math::Mat4 
	/// \prama  float
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 add(const math::Mat4& a, const float& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	subtract
	/// \prama  math::Mat4 
	/// \prama  math::Mat4 
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 sub(const math::Mat4& a, const math::Mat4& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	subtract
	/// \prama  math::Mat4 
	/// \prama  float 
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 sub(const math::Mat4& a, const float& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	multiply together
	/// \prama  math::Mat4 
	/// \prama  math::Mat4 
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 mul(const math::Mat4& a, const math::Mat4& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	multiply together
	/// \prama  math::Mat4 
	/// \prama  float 
	/// \return math::Mat4 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 mul(const math::Mat4& a, const float& b);

	// operator overloading
	inline const math::Mat4 operator + (math::Mat4& a, math::Mat4& b) { math::Mat4 r; r = add(a, b); return r; }
	inline const math::Mat4 operator + (math::Mat4& a, float& b) { math::Mat4 r; r = add(a, b); return r; }
	inline const math::Mat4 operator - (math::Mat4& a, math::Mat4& b) { math::Mat4 r; r = sub(a, b); return r; }
	inline const math::Mat4 operator - (math::Mat4& a, float& b) { math::Mat4 r; r = sub(a, b); return r; }
	inline const math::Mat4 operator * (math::Mat4& a, math::Mat4& b) { math::Mat4 r; r = mul(a, b); return r; }
	inline const math::Mat4 operator * (math::Mat4& a, float& b) { math::Mat4 r; r = mul(a, b); return r; }


	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  makes matrix into an identity matrix
	//----------------------------------------------------------------------------------------------------------------------
	inline void makeIdentity(math::Mat4& a)
	{
		a.m[0][0] = 1.0f; a.m[0][1] = 0.0f; a.m[0][2] = 0.0f; a.m[0][3] = 0.0f;
		a.m[1][0] = 0.0f; a.m[1][1] = 1.0f; a.m[1][2] = 0.0f; a.m[1][3] = 0.0f;
		a.m[2][0] = 0.0f; a.m[2][1] = 0.0f; a.m[2][2] = 1.0f; a.m[2][3] = 0.0f;
		a.m[3][0] = 0.0f; a.m[3][1] = 0.0f; a.m[3][2] = 0.0f; a.m[3][3] = 1.0f;
	}

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  creates a frustum matrix
	/// \prama	float left plane
	/// \prama	float right plane
	/// \prama	float top plane
	/// \prama	float bottom plane
	/// \prama	float near plane
	/// \prama	float far plane
	/// \return math::Mat4
	/// \note		Right hand
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 frustum(const float& left, const float& right,
										 const float& bottom, const float& top,
										 const float& nearPlane, const float& farPlane);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  creates a projection matrix
	/// \prama	float angle (FOV)
	/// \prama	float aspect ratio
	/// \prama	float near plane
	/// \prama	float far plane
	/// \return math::Mat4
	/// \note		Right hand
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 perspective(const float& angle, const float& aspect, const float& nearPlane, const float& farPlane);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  creates a orthographic frustum
	/// \prama	float left plane
	/// \prama	float right plane
	/// \prama	float top plane
	/// \prama	float bottom plane
	/// \prama	float near plane
	/// \prama	float far plane
	/// \return math::Mat4
	/// \note		Right hand
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat4 ortho(const float& left, const float& right,
									 const float& bottom, const float& top,
									 const float& nearPlane, const float& farPlane);

}; // end of SML namespace
