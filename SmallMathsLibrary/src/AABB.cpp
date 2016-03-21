// Author  : Lewis Ward
// Program : Small Maths Library
// Date    : 20/03/2016
#pragma once
#include "AABB.h"

namespace math
{
	AABB::AABB()
	{

	}

	AABB::AABB(math::Vec3& min, math::Vec3& max)
	{
		m_min = min;
		m_max = max;
		m_half.x = max.x - min.x;
		m_half.y = max.y - min.y;
		m_half.z = max.z - min.z;
		updateCenter();
	}

	AABB::~AABB()
	{

	}

	bool AABB::contains(math::Vec3& point)
	{
		if (point.x > m_min.x && point.x < m_max.x && point.y > m_min.y && point.y < m_max.y && point.z > m_min.z && point.z < m_max.z)
		{
			return true;
		}

		return false;
	}

	bool AABB::intersect(const AABB& aabb)
	{
		if (std::abs(m_center.x - aabb.m_center.x) > (m_half.x + aabb.m_half.x)) return false;
		if (std::abs(m_center.y - aabb.m_center.y) > (m_half.y + aabb.m_half.y)) return false;
		if (std::abs(m_center.z - aabb.m_center.z) > (m_half.z + aabb.m_half.z)) return false;

		return true;
	}

	inline math::Vec3 AABB::getCenter()
	{
		return m_center;
	}

	void AABB::updateCenter()
	{
		m_center.x = (m_max.x - m_min.x) / 2.0f;
		m_center.y = (m_max.y - m_min.y) / 2.0f;
		m_center.z = (m_max.z - m_min.z) / 2.0f;
	}

}; // end of math namespace
