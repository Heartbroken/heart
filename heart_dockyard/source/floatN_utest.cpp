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
		EXPECT_EQ(l_v.x, 1.0f); EXPECT_EQ(l_v.y, 2.0f);
	}
	// Copy constructor works
	{
		heart::float2 l_v0(3.0f, 4.0f), l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
}

TEST(heart_float2, functions_work)
{
	// Negation function works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(neg(l_v0));
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y);
	}
	// Addition function works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(add(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y);
	}
	// Subtraction function works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(sub(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y);
	}
	// Multiplication function works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(mul(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(mul(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			float l_s(3.0f); heart::float2 l_v0(1.0f, 2.0f), l_v1(mul(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y);
		}
	}
	// Division function works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(div(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(div(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			float l_s(3.0f); heart::float2 l_v0(1.0f, 2.0f), l_v1(div(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y);
		}
	}
	// Dot product function works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f); float l_dot(dot(l_v0, l_v1));
		EXPECT_EQ(l_dot, l_v0.x * l_v1.x + l_v0.y * l_v1.y);
	}
	// Cross product function works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f); float l_cross(cross(l_v0, l_v1));
			EXPECT_EQ(l_cross, l_v0.x * l_v1.y - l_v0.y * l_v1.x);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(cross(l_v0));
			EXPECT_EQ(l_v1.x, -l_v0.y); EXPECT_EQ(l_v1.y, l_v0.x);
		}
	}
	// Length function works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_len2(length2(l_v0));
			EXPECT_EQ(l_len2, l_v0.x * l_v0.x + l_v0.y * l_v0.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_len(length(l_v0));
			EXPECT_EQ(l_len, sqrtf(l_v0.x * l_v0.x + l_v0.y * l_v0.y));
		}
	}
	// Normalization function works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(normal(l_v0));
		EXPECT_FLOAT_EQ(length(l_v1), 1.0f);
	}
}

TEST(heart_float2, operators_work)
{
	// Assignment operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1; l_v1 = l_v0;
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
	// Negation operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(-l_v0);
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y);
	}
	// Addition operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 + l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y);
	}
	// Subtraction operator works
	{
		heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 - l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y);
	}
	// Multiplication operator works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 * l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0); l_v2 *= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(l_v0 * l_s);
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(l_v0); l_v1 *= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s);
		}
		{
			float l_s(3.0f); heart::float2 l_v0(1.0f, 2.0f), l_v1(l_s * l_v0);
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y);
		}
	}
	// Division operator works
	{
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0 / l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f), l_v1(3.0f, 4.0f), l_v2(l_v0); l_v2 /= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(l_v0 / l_s);
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			heart::float2 l_v0(1.0f, 2.0f); float l_s(3.0f); heart::float2 l_v1(l_v0); l_v1 /= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s);
		}
		{
			float l_s(3.0f); heart::float2 l_v0(1.0f, 2.0f), l_v1(l_s / l_v0);
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y);
		}
	}
}

TEST(heart_float3, constructors_work)
{
	// Default constructor exists
	{
		heart::float3 l_v;
	}
	// Assignment constructor works
	{
		heart::float3 l_v(1.0f, 2.0f, 3.0f);
		EXPECT_EQ(l_v.x, 1.0f); EXPECT_EQ(l_v.y, 2.0f); EXPECT_EQ(l_v.z, 3.0f);
	}
	// Copy constructor works
	{
		heart::float3 l_v0(4.0f, 5.0f, 6.0f), l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z);
	}
}

TEST(heart_float3, functions_work)
{
	// Negation function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(neg(l_v0));
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z);
	}
	// Addition function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(add(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z);
	}
	// Subtraction function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(sub(l_v0, l_v1));
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z);
	}
	// Multiplication function works
	{
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(mul(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(3.0f); heart::float3 l_v1(mul(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			float l_s(1.0f); heart::float3 l_v0(2.0f, 3.0f, 4.0f), l_v1(mul(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z);
		}
	}
	// Division function works
	{
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(div(l_v0, l_v1));
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(4.0f); heart::float3 l_v1(div(l_v0, l_s));
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			float l_s(1.0f); heart::float3 l_v0(2.0f, 3.0f, 4.0f), l_v1(div(l_s, l_v0));
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z);
		}
	}
	// Dot product function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f); float l_dot(dot(l_v0, l_v1));
		EXPECT_EQ(l_dot, l_v0.x * l_v1.x + l_v0.y * l_v1.y + l_v0.z * l_v1.z);
	}
	// Cross product function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_cross(cross(l_v0, l_v1));
		EXPECT_EQ(l_cross.x, l_v0.y * l_v1.z - l_v0.z * l_v1.y); EXPECT_EQ(l_cross.y, l_v0.x * l_v1.z - l_v0.z * l_v1.x); EXPECT_EQ(l_cross.z, l_v0.x * l_v1.y - l_v0.y * l_v1.x);
	}
	// Length function works
	{
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_len2(length2(l_v0));
			EXPECT_EQ(l_len2, l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_len(length(l_v0));
			EXPECT_EQ(l_len, sqrtf(l_v0.x * l_v0.x + l_v0.y * l_v0.y + l_v0.z * l_v0.z));
		}
	}
	// Normalization function works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(normal(l_v0));
		EXPECT_FLOAT_EQ(length(l_v1), 1.0f);
	}
}

TEST(heart_float3, operators_work)
{
	// Assignment operator works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1; l_v1 = l_v0;
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y); EXPECT_EQ(l_v0.z, l_v1.z);
	}
	// Negation operator works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(-l_v0);
		EXPECT_EQ(l_v0.x, -l_v1.x); EXPECT_EQ(l_v0.y, -l_v1.y); EXPECT_EQ(l_v0.z, -l_v1.z);
	}
	// Addition operator works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 + l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x + l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y + l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z + l_v1.z);
	}
	// Subtraction operator works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 - l_v1);
		EXPECT_EQ(l_v2.x, l_v0.x - l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y - l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z - l_v1.z);
	}
	// Multiplication operator works
	{
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 * l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0); l_v2 *= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x * l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y * l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z * l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(4.0f); heart::float3 l_v1(l_v0 * l_s);
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(3.0f); heart::float3 l_v1(l_v0); l_v1 *= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x * l_s); EXPECT_EQ(l_v1.y, l_v0.y * l_s); EXPECT_EQ(l_v1.z, l_v0.z * l_s);
		}
		{
			float l_s(3.0f); heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(l_s * l_v0);
			EXPECT_EQ(l_v1.x, l_s * l_v0.x); EXPECT_EQ(l_v1.y, l_s * l_v0.y); EXPECT_EQ(l_v1.z, l_s * l_v0.z);
		}
	}
	// Division operator works
	{
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0 / l_v1);
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f), l_v1(4.0f, 5.0f, 6.0f), l_v2(l_v0); l_v2 /= l_v1;
			EXPECT_EQ(l_v2.x, l_v0.x / l_v1.x); EXPECT_EQ(l_v2.y, l_v0.y / l_v1.y); EXPECT_EQ(l_v2.z, l_v0.z / l_v1.z);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(4.0f); heart::float3 l_v1(l_v0 / l_s);
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			heart::float3 l_v0(1.0f, 2.0f, 3.0f); float l_s(4.0f); heart::float3 l_v1(l_v0); l_v1 /= l_s;
			EXPECT_EQ(l_v1.x, l_v0.x / l_s); EXPECT_EQ(l_v1.y, l_v0.y / l_s); EXPECT_EQ(l_v1.z, l_v0.z / l_s);
		}
		{
			float l_s(1.0f); heart::float3 l_v0(2.0f, 3.0f, 4.0f), l_v1(l_s / l_v0);
			EXPECT_EQ(l_v1.x, l_s / l_v0.x); EXPECT_EQ(l_v1.y, l_s / l_v0.y); EXPECT_EQ(l_v1.z, l_s / l_v0.z);
		}
	}
	// Cast operator works
	{
		heart::float3 l_v0(1.0f, 2.0f, 3.0f); heart::float2 l_v1(l_v0);
		EXPECT_EQ(l_v0.x, l_v1.x); EXPECT_EQ(l_v0.y, l_v1.y);
	}
}
