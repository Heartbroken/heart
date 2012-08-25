#include "header.hpp"

// heart::real3x3

TEST(heart_real3x3, constructors_work)
{
	// Type size is correct
	{
		EXPECT_EQ(sizeof(heart::real3x3), sizeof(heart::real) * 3 * 3);
	}
	// Default constructor exists
	{
		heart::real3x3 l_m;
	}
	// Assignment constructor works
	{
		{
			heart::real3 l_x(1.0f, 2.0f, 3.0f), l_y(4.0f, 5.0f, 6.0f), l_z(7.0f, 8.0f, 9.0f);
			heart::real3x3 l_m(l_x, l_y, l_z);
			EXPECT_EQ(l_m.x, l_x); EXPECT_EQ(l_m.y, l_y); EXPECT_EQ(l_m.z, l_z);
		}
		{
			heart::real3x3 l_m(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			EXPECT_EQ(l_m.x.x, 1.0f); EXPECT_EQ(l_m.x.y, 2.0f); EXPECT_EQ(l_m.x.z, 3.0f);
			EXPECT_EQ(l_m.y.x, 4.0f); EXPECT_EQ(l_m.y.y, 5.0f); EXPECT_EQ(l_m.y.z, 6.0f);
			EXPECT_EQ(l_m.z.x, 7.0f); EXPECT_EQ(l_m.z.y, 8.0f); EXPECT_EQ(l_m.z.z, 9.0f);
		}
	}
	// Copy constructor works
	{
		heart::real3 l_x(1.0f, 2.0f, 3.0f), l_y(4.0f, 5.0f, 6.0f), l_z(7.0f, 8.0f, 9.0f);
		heart::real3x3 l_m0(l_x, l_y, l_z), l_m1(l_m0);
		EXPECT_EQ(l_m0.x, l_m1.x); EXPECT_EQ(l_m0.y, l_m1.y); EXPECT_EQ(l_m0.z, l_m1.z);
	}
}
