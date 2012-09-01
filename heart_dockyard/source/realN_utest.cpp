#include "header.hpp"

using namespace heart;

// real2

TEST(heart_real2, constructors_work)
{
	// Type size is correct
	{
		EXPECT_EQ(sizeof(real2), sizeof(real) * 2);
	}
	// Default constructor exists
	{
		real2 l_v;
	}
	// Assignment constructor works
	{
		real2 l_v(1.0f, 2.0f);
		EXPECT_EQ(l_v.x, 1.0f); EXPECT_EQ(l_v.y, 2.0f);
	}
	// Copy constructor works
	{
		real2 l_v0(3.0f, 4.0f), l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
}

TEST(heart_real2, functions_work)
{
	// Negation function works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(neg(l_v0));
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y);
	}
	// Addition function works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(add(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y);
	}
	// Subtraction function works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(sub(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y);
	}
	// Multiplication function works
	{
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(mul(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(mul(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			real l_s(3.0f); real2 l_v0(1.0f, 2.0f), l_v1(mul(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y);
		}
	}
	// Division function works
	{
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(div(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(div(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			real l_s(3.0f); real2 l_v0(1.0f, 2.0f), l_v1(div(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y);
		}
	}
	// Dot product function works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f); real l_dot(dot(l_v0, l_v1));
		EXPECT_EQ(l_dot, l_v0.x * l_v1.x + l_v0.y * l_v1.y);
	}
	// Cross product function works
	{
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f); real l_cross(cross(l_v0, l_v1));
			EXPECT_EQ(l_cross, l_v0.x * l_v1.y - l_v0.y * l_v1.x);
		}
		{
			real2 l_v0(1.0f, 2.0f), l_v1(cross(l_v0));
			EXPECT_EQ(l_v1.x, -l_v0.y); EXPECT_EQ(l_v1.y, l_v0.x);
		}
	}
	// Length function works
	{
		{
			real2 l_v0(1.0f, 2.0f); real l_len2(length2(l_v0));
			EXPECT_EQ(l_len2, l_v0.x * l_v0.x + l_v0.y * l_v0.y);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_len(length(l_v0));
			EXPECT_EQ(l_len, sqrtf(l_v0.x * l_v0.x + l_v0.y * l_v0.y));
		}
	}
	// Normalization function works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(normal(l_v0));
		EXPECT_FLOAT_EQ(length(l_v1), 1.0f);
	}
}

TEST(heart_real2, operators_work)
{
	// Assignment operator works
	{
		real2 l_v0(1.0f, 2.0f), l_v1; l_v1 = l_v0;
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
	// Negation operator works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(-l_v0);
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y);
	}
	// Addition operator works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 + l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y);
	}
	// Subtraction operator works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 - l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y);
	}
	// Multiplication operator works
	{
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 * l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0); l_v2 *= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(l_v0 * l_s);
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(l_v0); l_v1 *= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			real l_s(3.0f); real2 l_v0(1.0f, 2.0f), l_v1(l_s * l_v0);
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y);
		}
	}
	// Division operator works
	{
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 / l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0); l_v2 /= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(l_v0 / l_s);
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			real2 l_v0(1.0f, 2.0f); real l_s(3.0f); real2 l_v1(l_v0); l_v1 /= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			real l_s(3.0f); real2 l_v0(1.0f, 2.0f), l_v1(l_s / l_v0);
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y);
		}
	}
	// Array subscript operator works
	{
		real2 l_v0(1.0f, 2.0f);
		EXPECT_EQ(l_v0[0], 1.0f); EXPECT_EQ(l_v0[1], 2.0f);
		l_v0[0] = 2.0f; l_v0[1] = 1.0f;
		EXPECT_EQ(l_v0[0], 2.0f); EXPECT_EQ(l_v0[1], 1.0f);
	}
	// Equality operator works
	{
		real2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0);
		EXPECT_TRUE(l_v0 != l_v1); EXPECT_TRUE(l_v0 == l_v2);
	}
}

TEST(heart_real2, constants_valid)
{
	EXPECT_EQ(r2_0, real2(0.0f, 0.0f));
	EXPECT_EQ(r2_1, real2(1.0f, 1.0f));
	EXPECT_EQ(r2_x, real2(1.0f, 0.0f));
	EXPECT_EQ(r2_y, real2(0.0f, 1.0f));
}

// real3

TEST(heart_real3, constructors_work)
{
	// Type size is correct
	{
		EXPECT_EQ(sizeof(real3), sizeof(real) * 3);
	}
	// Default constructor exists
	{
		real3 l_v;
	}
	// Assignment constructor works
	{
		real3 l_v(1.0f, 2.0f, 3.0f);
		EXPECT_EQ(l_v.x, 1.0f); EXPECT_EQ(l_v.y, 2.0f); EXPECT_EQ(l_v.z, 3.0f);
	}
	// Copy constructor works
	{
		real3 l_v0(4.0f, 5.0f, 6.0f), l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z);
	}
}

TEST(heart_real3, functions_work)
{
	// Negation function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(neg(l_v0));
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z);
	}
	// Addition function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(add(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z);
	}
	// Subtraction function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(sub(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z);
	}
	// Multiplication function works
	{
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(mul(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(3.0f); real3 l_v1(mul(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			real l_s(1.0f); real3 l_v0(2.0f, 3.0f, 4.0f), l_v1(mul(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z);
		}
	}
	// Division function works
	{
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(div(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(4.0f); real3 l_v1(div(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			real l_s(1.0f); real3 l_v0(2.0f, 3.0f, 4.0f), l_v1(div(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z);
		}
	}
	// Dot product function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f); real l_dot(dot(l_v0, l_v1));
		EXPECT_EQ(l_dot, l_v0.x * l_v1.x + l_v0.y * l_v1.y + l_v0.z * l_v1.z);
	}
	// Cross product function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_cross(cross(l_v0, l_v1));
		EXPECT_EQ(l_cross.x, l_v0.y * l_v1.z - l_v0.z * l_v1.y); EXPECT_EQ(l_cross.y, l_v0.x * l_v1.z - l_v0.z * l_v1.x); EXPECT_EQ(l_cross.z, l_v0.x * l_v1.y - l_v0.y * l_v1.x);
	}
	// Length function works
	{
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_len2(length2(l_v0));
			EXPECT_EQ(l_len2, l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_len(length(l_v0));
			EXPECT_EQ(l_len, sqrtf(l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z));
		}
	}
	// Normalization function works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(normal(l_v0));
		EXPECT_FLOAT_EQ(length(l_v1), 1.0f);
	}
}

TEST(heart_real3, operators_work)
{
	// Assignment operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1; l_v1 = l_v0;
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z);
	}
	// Negation operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(-l_v0);
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z);
	}
	// Addition operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 + l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z);
	}
	// Subtraction operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 - l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z);
	}
	// Multiplication operator works
	{
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 * l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0); l_v2 *= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(4.0f); real3 l_v1(l_v0 * l_s);
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(3.0f); real3 l_v1(l_v0); l_v1 *= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			real l_s(3.0f); real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(l_s * l_v0);
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z);
		}
	}
	// Division operator works
	{
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 / l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0); l_v2 /= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(4.0f); real3 l_v1(l_v0 / l_s);
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			real3 l_v0(1.0f, 2.0f, 3.0f); real l_s(4.0f); real3 l_v1(l_v0); l_v1 /= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			real l_s(1.0f); real3 l_v0(2.0f, 3.0f, 4.0f), l_v1(l_s / l_v0);
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z);
		}
	}
	// Cast operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f); real2 l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
	// Array subscript operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f);
		EXPECT_EQ(l_v0[0], 1.0f); EXPECT_EQ(l_v0[1], 2.0f); EXPECT_EQ(l_v0[2], 3.0f);
		l_v0[0] = 3.0f; l_v0[1] = 2.0f; l_v0[2] = 1.0f;
		EXPECT_EQ(l_v0[0], 3.0f); EXPECT_EQ(l_v0[1], 2.0f); EXPECT_EQ(l_v0[2], 1.0f);
	}
	// Equality operator works
	{
		real3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0);
		EXPECT_TRUE(l_v0 != l_v1); EXPECT_TRUE(l_v0 == l_v2);
	}
}

TEST(heart_real3, constants_valid)
{
	EXPECT_EQ(r3_0, real3(0.0f, 0.0f, 0.0f));
	EXPECT_EQ(r3_1, real3(1.0f, 1.0f, 1.0f));
	EXPECT_EQ(r3_x, real3(1.0f, 0.0f, 0.0f));
	EXPECT_EQ(r3_y, real3(0.0f, 1.0f, 0.0f));
	EXPECT_EQ(r3_z, real3(0.0f, 0.0f, 1.0f));
}

// real4

TEST(heart_real4, constructors_work)
{
	// Type size is correct
	{
		EXPECT_EQ(sizeof(real4), sizeof(real) * 4);
	}
	// Default constructor exists
	{
		real4 l_v;
	}
	// Assignment constructor works
	{
		real4 l_v(1.0f, 2.0f, 3.0f, 4.0f);
		EXPECT_EQ(l_v.x, 1.0f); EXPECT_EQ(l_v.y, 2.0f); EXPECT_EQ(l_v.z, 3.0f); EXPECT_EQ(l_v.w, 4.0f);
	}
	// Copy constructor works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z); EXPECT_EQ(l_v0.w, l_v1.w);
	}
}

TEST(heart_real4, functions_work)
{
	// Negation function works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(neg(l_v0));
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z); EXPECT_EQ(l_v0.w, -l_v1.w);
	}
	// Addition function works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(add(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w + l_v1.w);
	}
	// Subtraction function works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(sub(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w - l_v1.w);
	}
	// Multiplication function works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(mul(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w * l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(mul(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s); EXPECT_EQ(l_v1.w, l_v0.w * l_s);
		}
		{
			real l_s(1.0f); real4 l_v0(2.0f, 3.0f, 4.0f, 5.0f), l_v1(mul(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z); EXPECT_EQ(l_v1.w, l_s * l_v0.w);
		}
	}
	// Division function works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(div(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w / l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(div(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s); EXPECT_EQ(l_v1.w, l_v0.w / l_s);
		}
		{
			real l_s(1.0f); real4 l_v0(2.0f, 3.0f, 4.0f, 5.0f), l_v1(div(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z); EXPECT_EQ(l_v1.w, l_s / l_v0.w);
		}
	}
	// Dot product function works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f); real l_dot(dot(l_v0, l_v1));
		EXPECT_EQ(l_dot, l_v0.x * l_v1.x + l_v0.y * l_v1.y + l_v0.z * l_v1.z + l_v0.w * l_v1.w);
	}
	// Length function works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_len2(length2(l_v0));
			EXPECT_EQ(l_len2, l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z + l_v0.w * l_v0.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_len(length(l_v0));
			EXPECT_EQ(l_len, sqrtf(l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z + l_v0.w * l_v0.w));
		}
	}
	// Normalization function works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(normal(l_v0));
		EXPECT_FLOAT_EQ(length(l_v1), 1.0f);
	}
}

TEST(heart_real4, operators_work)
{
	// Assignment operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1; l_v1 = l_v0;
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z); EXPECT_EQ(l_v0.w, l_v1.w);
	}
	// Negation operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(-l_v0);
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z); EXPECT_EQ(l_v0.w, -l_v1.w);
	}
	// Addition operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0 + l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w + l_v1.w);
	}
	// Subtraction operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0 - l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w - l_v1.w);
	}
	// Multiplication operator works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0 * l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w * l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0); l_v2 *= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w * l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(l_v0 * l_s);
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s); EXPECT_EQ(l_v1.w, l_v0.w * l_s);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(l_v0); l_v1 *= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s); EXPECT_EQ(l_v1.w, l_v0.w * l_s);
		}
		{
			real l_s(1.0f); real4 l_v0(2.0f, 3.0f, 4.0f, 5.0f), l_v1(l_s * l_v0);
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z); EXPECT_EQ(l_v1.w, l_s * l_v0.w);
		}
	}
	// Division operator works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0 / l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w / l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0); l_v2 /= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z); EXPECT_EQ(l_v2.w, l_v0.w / l_v1.w);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(l_v0 / l_s);
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s); EXPECT_EQ(l_v1.w, l_v0.w / l_s);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real l_s(5.0f); real4 l_v1(l_v0); l_v1 /= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s); EXPECT_EQ(l_v1.w, l_v0.w / l_s);
		}
		{
			real l_s(1.0f); real4 l_v0(2.0f, 3.0f, 4.0f, 5.0f), l_v1(l_s / l_v0);
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z); EXPECT_EQ(l_v1.w, l_s / l_v0.w);
		}
	}
	// Cast operator works
	{
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real2 l_v1(l_v0);
			EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
		}
		{
			real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f); real3 l_v1(l_v0);
			EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z);
		}
	}
	// Array subscript operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f);
		EXPECT_EQ(l_v0[0], 1.0f); EXPECT_EQ(l_v0[1], 2.0f); EXPECT_EQ(l_v0[2], 3.0f); EXPECT_EQ(l_v0[3], 4.0f);
		l_v0[0] = 4.0f; l_v0[1] = 3.0f; l_v0[2] = 2.0f; l_v0[3] = 1.0f;
		EXPECT_EQ(l_v0[0], 4.0f); EXPECT_EQ(l_v0[1], 3.0f); EXPECT_EQ(l_v0[2], 2.0f); EXPECT_EQ(l_v0[3], 1.0f);
	}
	// Equality operator works
	{
		real4 l_v0(1.0f, 2.0f, 3.0f, 4.0f), l_v1(5.0f, 6.0f, 7.0f, 8.0f), l_v2(l_v0);
		EXPECT_TRUE(l_v0 != l_v1); EXPECT_TRUE(l_v0 == l_v2);
	}
}

TEST(heart_real4, constants_valid)
{
	EXPECT_EQ(r4_0, real4(0.0f, 0.0f, 0.0f, 0.0f));
	EXPECT_EQ(r4_1, real4(1.0f, 1.0f, 1.0f, 1.0f));
	EXPECT_EQ(r4_x, real4(1.0f, 0.0f, 0.0f, 0.0f));
	EXPECT_EQ(r4_y, real4(0.0f, 1.0f, 0.0f, 0.0f));
	EXPECT_EQ(r4_z, real4(0.0f, 0.0f, 1.0f, 0.0f));
	EXPECT_EQ(r4_w, real4(0.0f, 0.0f, 0.0f, 1.0f));
}
