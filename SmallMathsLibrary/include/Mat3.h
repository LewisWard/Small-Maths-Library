// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#pragma once
#include "Vec3.h"

//----------------------------------------------------------------------------------------------------------------------
/// \brief  maths namespace
//----------------------------------------------------------------------------------------------------------------------
namespace math
{
	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  Matrix 3x3, I could of used and thought about using 
	//----------------------------------------------------------------------------------------------------------------------
	class Mat3
	{
	public:

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \note		Matrix will be created uninitialized
		//----------------------------------------------------------------------------------------------------------------------
		Mat3();

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \prama	float 
		/// \note		Always set the matrix to an identity matrix, regardless of the prama
		//----------------------------------------------------------------------------------------------------------------------
		Mat3(const float& i);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Construtor
		/// \prama	math::Vec3 assign all the X elements
		/// \prama	math::Vec3 assign all the Y elements
		/// \prama	math::Vec3 assign all the Z elements
		//----------------------------------------------------------------------------------------------------------------------
		Mat3(math::Vec3& x, math::Vec3& y, math::Vec3& z);
		
		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Destrutor
		//----------------------------------------------------------------------------------------------------------------------
		~Mat3();

		
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
		/// \brief  Find if the martix has a determinant
		/// \note		float the determinant
		//----------------------------------------------------------------------------------------------------------------------
		float determinant();

		
		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Transpose the matrix
		/// \return	math::Mat3 the transposed martix
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat3 transpose();

		
		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Check a matrix with this matrix
		/// \prama  math::Mat3 matrix to compair with
		/// \return	bool true if equal
		//----------------------------------------------------------------------------------------------------------------------
		bool equals(const math::Mat3 compairToMatrix);

		
		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  Returns this matrix without any scale applied
		/// \return	math::Mat3
		/// \note		The scale will be equal to 1.0
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat3 matrixWithNoSacle();

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  inverse the matrix
		/// \return	math::Mat3 matrix that the inverse was applied to
		//----------------------------------------------------------------------------------------------------------------------
		math::Mat3 inverse(); 		// might also want to see if I can also make a fast inverse method

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the X axis
		//----------------------------------------------------------------------------------------------------------------------
		void rotateX(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the Y axis
		//----------------------------------------------------------------------------------------------------------------------
		void rotateY(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief  rotate matrix on the Z axis
		//----------------------------------------------------------------------------------------------------------------------
		void rotateZ(float& rotation);

		//----------------------------------------------------------------------------------------------------------------------
		/// Swizzles
		/// \brief return x swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 x()
		{ return Vec3(m[0][0], m[0][1], m[0][2]); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return y swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 y()
		{ return Vec3(m[1][0], m[1][1], m[1][2]); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return z swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 z()
		{ return Vec3(m[2][0], m[2][1], m[2][2]); }

		
		float m[3][3]; ///< 3x3 floats to form the matrix
	};

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	add
	/// \prama  math::Mat3
	/// \prama  math::Mat3
	/// \return math::Mat3
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 add(const math::Mat3& a, const math::Mat3& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	add
	/// \prama  math::Mat3 
	/// \prama  float
	/// \return math::Mat3 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 add(const math::Mat3& a, const float& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	subtract
	/// \prama  math::Mat3 
	/// \prama  math::Mat3 
	/// \return math::Mat3 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 sub(const math::Mat3& a, const math::Mat3& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	subtract
	/// \prama  math::Mat3 
	/// \prama  float 
	/// \return math::Mat3 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 sub(const math::Mat3& a, const float& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	multiply together
	/// \prama  math::Mat3 
	/// \prama  math::Mat3 
	/// \return math::Mat3 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 mul(const math::Mat3& a, const math::Mat3& b);

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief	multiply together
	/// \prama  math::Mat3 
	/// \prama  float 
	/// \return math::Mat3 
	//----------------------------------------------------------------------------------------------------------------------
	math::Mat3 mul(const math::Mat3& a, const float& b);


	// operator overloading
	inline const math::Mat3 operator + (math::Mat3& a, math::Mat3& b) { math::Mat3 r; r = add(a, b); return r; }
	inline const math::Mat3 operator + (math::Mat3& a, float& b) { math::Mat3 r; r = add(a, b); return r; }
	inline const math::Mat3 operator - (math::Mat3& a, math::Mat3& b) { math::Mat3 r; r = sub(a, b); return r; }
	inline const math::Mat3 operator - (math::Mat3& a, float& b) { math::Mat3 r; r = sub(a, b); return r; }
	inline const math::Mat3 operator * (math::Mat3& a, math::Mat3& b) { math::Mat3 r; r = mul(a, b); return r; }
	inline const math::Mat3 operator * (math::Mat3& a, float& b) { math::Mat3 r; r = mul(a, b); return r; }

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  makes matrix into an identity matrix
	//----------------------------------------------------------------------------------------------------------------------
	inline void makeIdentity(math::Mat3& a)
	{
		a.m[0][0] = 1.0f; a.m[0][1] = 0.0f; a.m[0][2] = 0.0f;
		a.m[1][0] = 0.0f; a.m[1][1] = 1.0f; a.m[1][2] = 0.0f;
		a.m[2][0] = 0.0f; a.m[2][1] = 0.0f; a.m[2][2] = 1.0f;
	}

}; // end of math namespace
