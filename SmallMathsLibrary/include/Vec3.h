// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#pragma once
#include "Vec2.h"

//----------------------------------------------------------------------------------------------------------------------
/// \brief  maths namespace
//----------------------------------------------------------------------------------------------------------------------
namespace math
{

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  3D Vector type (although it actually a 4D but the 'w' term will always be zero)
	//----------------------------------------------------------------------------------------------------------------------
	class Vec3
	{
	public:

		Vec3();
		Vec3(float scalar);
		Vec3(float X, float Y, float Z);
		~Vec3();

		// methods might want to add at a later date
		// copy constructor
		// debugging utilities (i.e. check w term to be 0) etc.
		// lerp function ((b-a) * scalar + a)

		//----------------------------------------------------------------------------------------------------------------------
		/// Standard Vector Arithmetic
		/// \note		Dividion methods do not take into account of division by zero in release modes!
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 add(Vec3& a, Vec3& b)
		{ return Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }

		inline void add(Vec3& b)
		{ this->x = this->x + b.x, this->y = this->y + b.y, this->z = this->z + b.z; }

		inline Vec3 sub(Vec3& a, Vec3& b)
		{ return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }

		inline void sub(Vec3& b)
		{ this->x = this->x - b.x, this->y = this->y - b.y, this->z = this->z - b.z; }

		inline Vec3 mul(Vec3& a, Vec3& b)
		{ return Vec3(a.x * b.x, a.y * b.y, a.z * b.z); }

		inline Vec3 mul(Vec3& a, float& scalar)
		{ return Vec3(a.x * scalar, a.y * scalar, a.z * scalar); }

		inline void mul(Vec3& b)
		{ this->x = this->x * b.x, this->y = this->y * b.y, this->z = this->z * b.z; }

		// if in debug performs extra checks to prevent divion by zero
#ifdef _DEBUG

		Vec3 div(Vec3& a, Vec3& b)
		{
			// make sure there are not any zeros in the vector
			if(abs(b.x) == 0.000000f || abs(b.y) == 0.000000f || abs(b.z) == 0.000000f)
			{
				return Vec3(0.0f, 0.0f, 0.0f);
			}

			return Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
		}

		Vec3 div(Vec3& a, float& scalar)
		{
			// make sure the scalar is not zero
			if(abs(scalar) == 0.000000f)
			{
				return Vec3(0.0f, 0.0f, 0.0f);
			}

			return Vec3(a.x / scalar, a.y / scalar, a.z / scalar);
		}

		void div(Vec3& b)
		{
			// make sure there are not any zeros in the vector
			if(abs(b.x) == 0.000000f || abs(b.y) == 0.000000f || abs(b.z) == 0.000000f)
			{
				this->x = 0.0f; this->y = 0.0f; this->z = 0.0f;
			}

			this->x = this->x / b.x, this->y =  this->y / b.y, this->z = this->z / b.z;
		}
#else
		inline Vec3 div(Vec3& a, Vec3& b)
		{ return Vec3(a.x / b.x, a.y / b.y, a.z / b.z); }

		inline Vec3 div(Vec3& a, float& scalar)
		{ return Vec3(a.x / scalar, a.y / scalar, a.z / scalar); }

		inline void div(Vec3& b)
		{ this->x = this->x / b.x, this->y = this->y / b.y, this->z = this->z / b.z; }
#endif

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Dot Product
		/// \prama Vec3
		/// \prama Vec3
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------
		inline float dot(Vec3& a, Vec3& b)
		{ return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Cross Product
		/// \prama Vec3
		/// \prama Vec3
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 cross(Vec3& a, Vec3& b)
		{
			Vec3 c;
			c.x = a.y * b.z - a.z * b.y;
			c.y = a.z * b.x - a.x * b.z;
			c.z = a.x * b.y - a.y * b.x;
			return c;
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Magnitude of a vector from a dot product of it's self. You should call magnitude(Vec3& a) function as
		///				 this function does not perform the square root
		/// \prama Vec3
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------
		inline float magnitudeDot(Vec3& a)
		{ return dot(a, a); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Magnitude of the vector
		/// \prama Vec3
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------


		inline float magnitude(Vec3& a)
		{ return std::sqrt(magnitudeDot(a)); }


		//----------------------------------------------------------------------------------------------------------------------
		/// \breif normalize
		//----------------------------------------------------------------------------------------------------------------------
		inline void normalise()
		{ 
			// get the vectors magitude
			float l = magnitude((*this));
		
			// make sure its magitude is not 0 or less and normalise
			if (std::fabs(l) > 0.000001f)
			{
				this->x = this->x / l;
				this->y = this->y / l;
				this->z = this->z / l;
			}
			else
			{
				this->x = this->x * 0.0f;
				this->y = this->y * 0.0f;
				this->z = this->z * 0.0f;
			}
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// Swizzles
		/// \note	can be used for single SHUFPS (Shuffle Packed Single-Precision Floating-Point Values) instruction
		/// An example where is can become helpful if when you are storing a RGB color and only want to extract certain values
		/// \brief return xxx swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xxx()
		{ return Vec3(this->x, this->x, this->x); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xxy swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xxy()
		{ return Vec3(this->x, this->x, this->y); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xyy swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xyy()
		{ return Vec3(this->x, this->y, this->y); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xyz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xyz()
		{ return Vec3(this->x, this->y, this->z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xxz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xxz()
		{ return Vec3(this->x, this->x, this->z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xzz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 xzz()
		{ return Vec3(this->x, this->z, this->z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return yyy swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 yyy()
		{ return Vec3(this->y, this->y, this->y); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return yyz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 yyz()
		{ return Vec3(this->y, this->y, this->z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return yzz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 yzz()
		{ return Vec3(this->y, this->z, this->z); }

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return zzz swizzle
		/// \return Vec3
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec3 zzz()
		{ return Vec3(this->z, this->z, this->z); }


		
		//----------------------------------------------------------------------------------------------------------------------
		/// constant values for initialisation by assignment
		/// \note	mostly useful for SIMD
		//----------------------------------------------------------------------------------------------------------------------
		static const Vec3 kONE;
		static const Vec3 kONEX;
		static const Vec3 kONEY;
		static const Vec3 kONEZ;
		static const Vec3 kZERO;
		static const Vec3 kHALF;
		static const Vec3 kTWO;

		float x; ///< X term
		float y; ///< Y term
		float z; ///< Z term
		float w; ///< W terms
	};

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Operator Overloading
	//----------------------------------------------------------------------------------------------------------------------
	inline const math::Vec3& operator += (math::Vec3& a, math::Vec3& b)
	{
		a.add(a, b);
		return a;
	}

	inline const math::Vec3& operator += (math::Vec3& a, const math::Vec3& b)
	{
		math::Vec3 t(a.x + b.x, a.y + b.y, a.z + b.z);
		return t;
	}

	inline const math::Vec3& operator += (math::Vec3& a, float& b)
	{
		math::Vec3 t(a.x + b, a.y + b, a.z + b);
		return t;
	}

	inline const math::Vec3& operator += (float& b, math::Vec3& a)
	{
		math::Vec3 t(a.x + b, a.y + b, a.z + b);
		return t;
	}

	inline const math::Vec3& operator -= (math::Vec3& a, math::Vec3& b)
	{
		a.sub(a, b);
		return a;
	}

	inline const math::Vec3& operator *= (math::Vec3& a, math::Vec3& b)
	{
		a.mul(a, b);
		return a;
	}

	inline const math::Vec3& operator * (math::Vec3& a, math::Vec3& b)
	{
		math::Vec3 t(a.x * b.x, a.y * b.y, a.z * b.z);
		return t;
	}

	inline const math::Vec3& operator * (math::Vec3& v, float& f)
	{
		math::Vec3 t(v.x * f, v.y * f, v.x * f);
		return t;
	}

	inline const math::Vec3& operator * (float& f, math::Vec3& v)
	{
		math::Vec3 t(v.x * f, v.y * f, v.x * f);
		return t;
	}

	inline const math::Vec3& operator * (const float& f, math::Vec3& v)
	{
		math::Vec3 t(v.x * f, v.y * f, v.x * f);
		return t;
	}

	inline const math::Vec3& operator * (const float& f, const math::Vec3& v)
	{
		math::Vec3 t(v.x * f, v.y * f, v.x * f);
		return t;
	}

	inline const math::Vec3& operator + (math::Vec3& a, math::Vec3& b)
	{
		math::Vec3 t(a.x * a.x, a.y * b.y, a.z * b.z); 
		return t;
	}

	inline const math::Vec3& operator - (math::Vec3& a, math::Vec3& b)
	{
		math::Vec3 t(a.x - a.x, a.y - b.y, a.z - b.z);
		return t;
	}

	inline const math::Vec3& operator - (const float& f, const math::Vec3& v)
	{
		math::Vec3 t(v.x - f, v.y - f, v.z - f);
		return t;
	}


	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Cross Product
	/// \prama Vec3
	/// \prama Vec3
	/// \return Vec3
	//----------------------------------------------------------------------------------------------------------------------
	inline math::Vec3 cross(const math::Vec3& a, const math::Vec3& b)
	{
		math::Vec3 c;
		c.x = a.y * b.z - a.z * b.y;
		c.y = a.z * b.x - a.x * b.z;
		c.z = a.x * b.y - a.y * b.x;
		return c;
	}

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Dot Product
	/// \prama Vec3
	/// \prama Vec3
	/// \return float
	//----------------------------------------------------------------------------------------------------------------------
	inline float dot(const math::Vec3& a, const math::Vec3& b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Multiply
	/// \prama Vec3
	/// \prama float
	/// \return Vec3
	//----------------------------------------------------------------------------------------------------------------------
	inline math::Vec3 multiply(const math::Vec3& a, const math::Vec3& b)
	{
		math::Vec3 c(a.x * b.x, a.y * b.y, a.z * b.z);
		return c;
	}

	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Multiply
	/// \prama Vec3
	/// \prama float
	/// \return Vec3
	//----------------------------------------------------------------------------------------------------------------------
	inline math::Vec3 multiply(const math::Vec3& a, const float& b)
	{
		math::Vec3 c(a.x * b, a.y * b, a.z * b);
		return c;
	}

}; // end of math namespace
