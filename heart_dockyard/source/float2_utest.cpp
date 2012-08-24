#include "header.hpp"

TEST(heart_float2, constructors_work)
{
	// Default constructor exists
	{
		heart::float2 l_v;
	}
	// Assignment constructor works
	{
		heart::float2 l_v(1.0f, 2.0f);
		EXPECT_TRUE(l_v.x == 1.0f && l_v.y == 2.0f);
	}
	// Copy constructor works
	{
		heart::float2 l_v0(3.0f, 4.0f), l_v1(l_v0);
		EXPECT_TRUE(l_v0.x == l_v1.x && l_v0.y == l_v1.y);
	}
}

TEST(heart_float2, operators_work)
{
	// Assignment operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1; l_v1 = l_v0;
		EXPECT_TRUE(l_v0.x == l_v1.x && l_v0.y == l_v1.y);
	}
	// Negation operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(-l_v0);
		EXPECT_TRUE(l_v0.x == -l_v1.x && l_v0.y == -l_v1.y);
	}
	// Addition operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 + l_v1);
		EXPECT_TRUE(l_v2.x == l_v0.x + l_v1.x && l_v2.y == l_v0.y + l_v1.y);
	}
	// Subtraction operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 - l_v1);
		EXPECT_TRUE(l_v2.x == l_v0.x - l_v1.x && l_v2.y == l_v0.y - l_v1.y);
	}
	// Multiplication operator works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 * l_v1);
			EXPECT_TRUE(l_v2.x == l_v0.x * l_v1.x && l_v2.y == l_v0.y * l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(l_v0 * l_s);
			EXPECT_TRUE(l_v1.x == l_v0.x * l_s && l_v1.y == l_v0.y * l_s);
		}
		{
			float l_s(3.0f); heart::float2 l_v0(1.0f, 2.0f), l_v1(l_s * l_v0);
			EXPECT_TRUE(l_v1.x == l_s * l_v0.x && l_v1.y == l_s * l_v0.y);
		}
	}
}
