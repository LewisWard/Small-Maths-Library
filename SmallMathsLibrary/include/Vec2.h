// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016

#pragma once
#include <cmath>
#include <stdint.h>
#define PI 3.14159265f

//----------------------------------------------------------------------------------------------------------------------
/// \brief  maths namespace
//----------------------------------------------------------------------------------------------------------------------
namespace math
{
	//----------------------------------------------------------------------------------------------------------------------
	/// \brief  2D Vector
	//----------------------------------------------------------------------------------------------------------------------
	class Vec2
	{
	public:

		Vec2();
		Vec2(const float& scalar);
		Vec2(const float& X, const float& Y);
		~Vec2();

		//----------------------------------------------------------------------------------------------------------------------
		/// Standard Vector Arithmetic
		/// \note		Dividion methods do not take into account of division by zero in release modes!
		//----------------------------------------------------------------------------------------------------------------------
		inline Vec2 add(Vec2& a, Vec2& b)
		{ return Vec2(a.x + b.x, a.y + b.y); }

		inline void add(Vec2& b)
		{ this->x = this->x + b.x, this->y = this->y + b.y; }

		inline Vec2 sub(Vec2& a, Vec2& b)
		{ return Vec2(a.x - b.x, a.y - b.y); }

		inline void sub(Vec2& b)
		{ this->x = this->x - b.x, this->y = this->y - b.y; }

		inline Vec2 mul(Vec2& a, Vec2& b)
		{ return Vec2(a.x * b.x, a.y * b.y); }

		inline Vec2 mul(Vec2& a, float& scalar)
		{ return Vec2(a.x * scalar, a.y * scalar); }

		inline void mul(Vec2& b)
		{ this->x = this->x * b.x, this->y = this->y * b.y; }

		// if in debug performs extra checks to prevent divion by zero
#ifdef _DEBUG

		Vec2 div(Vec2& a, Vec2& b)
		{
			// make sure there are not any zeros in the vector
			if (abs(b.x) == 0.000000f || abs(b.y) == 0.000000f)
			{
				return Vec2(0.0f, 0.0f);
			}

			return Vec2(a.x / b.x, a.y / b.y);
		}

		Vec2 div(Vec2& a, float& scalar)
		{
			// make sure the scalar is not zero
			if (abs(scalar) == 0.000000f)
			{
				return Vec2(0.0f, 0.0f);
			}

			return Vec2(a.x / scalar, a.y / scalar);
		}

		void div(Vec2& b)
		{
			// make sure there are not any zeros in the vector
			if (abs(b.x) == 0.000000f || abs(b.y) == 0.000000f)
			{
				this->x = this->x = 0.0f; this->y = this->y = 0.0f;
			}

			this->x = this->x / b.x; this->y = this->y / b.y;
		}
#else
		inline Vec2 div(Vec2& a, Vec2& b)
		{ return Vec2(a.x / b.x, a.y / b.y); }

		inline Vec2 div(Vec2& a, float& scalar)
		{ return Vec2(a.x / scalar, a.y / scalar); }

		inline void div(Vec2& b)
		{ this->x = this->x / b.x, this->y = this->y / b.y; }
#endif

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Dot Product
		/// \prama Vec2
		/// \prama Vec2
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------
		inline float dot(Vec2& a, Vec2& b)
		{
			return (a.x * b.x) + (a.y * b.y);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Magnitude of a vector from a dot product of it's self. You should call magnitude(Vec2& a) function as
		///				 this function does not perform the square root
		/// \prama Vec2
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------
		inline float magnitudeDot(Vec2& a)
		{
			return dot(a, a);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief Magnitude of the vector
		/// \prama Vec2
		/// \return float
		//----------------------------------------------------------------------------------------------------------------------
		inline float magnitude(Vec2& a)
		{
			return std::sqrt(magnitudeDot(a));
		}


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
			}
			else
			{
				this->x = this->x * 0.0f;
				this->y = this->y * 0.0f;
			}
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// Swizzles
		/// \note	can be used for single SHUFPS (Shuffle Packed Single-Precision Floating-Point Values) instruction
		/// An example where is can become helpful if when you are storing a RGB color and only want to extract certain values
		/// \brief return xx swizzle
		/// \return Vec2
		//----------------------------------------------------------------------------------------------------------------------
		inline math::Vec2 xx()
		{
			return Vec2(this->x, this->x);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return xy swizzle
		/// \return Vec2
		//----------------------------------------------------------------------------------------------------------------------
		inline math::Vec2 xy()
		{
			return Vec2(this->x, this->y);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return yx swizzle
		/// \return Vec2
		//----------------------------------------------------------------------------------------------------------------------
		inline math::Vec2 yx()
		{
			return Vec2(this->y, this->x);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// \brief return yy swizzle
		/// \return Vec2
		//----------------------------------------------------------------------------------------------------------------------
		inline math::Vec2 yy()
		{
			return Vec2(this->y, this->y);
		}

		//----------------------------------------------------------------------------------------------------------------------
		/// constant values for initialisation by assignment
		/// \note	mostly useful for SIMD
		//----------------------------------------------------------------------------------------------------------------------
		static const Vec2 kONE;
		static const Vec2 kONEX;
		static const Vec2 kONEY;
		static const Vec2 kZERO;
		static const Vec2 kHALF;
		static const Vec2 kTWO;

		float x; ///< X term
		float y; ///< Y term
	};


	//----------------------------------------------------------------------------------------------------------------------
	/// \brief Operator Overloading
	//----------------------------------------------------------------------------------------------------------------------
	inline const Vec2& operator += (Vec2& a, Vec2& b)
	{
		a.add(a, b);
		return a;
	}

	inline const Vec2& operator -= (Vec2& a, Vec2& b)
	{
		a.sub(a, b);
		return a;
	}

	inline const Vec2& operator *= (Vec2& a, Vec2& b)
	{
		a.mul(a, b);
		return a;
	}

}; // end of math namespace
