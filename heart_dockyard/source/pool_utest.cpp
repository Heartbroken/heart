#include "header.hpp"

using namespace heart;

TEST(heart_pool, constructors_work)
{
	pool_<uint> l_uint_pool;
	pool_<real2> l_real2_pool;
	pool_<real3x3> l_real3x3_pool;
}

TEST(heart_pool, functions_work)
{
	// add, remove, exists
	{
		uint l_count = 1000;
		pool_<uint> l_pool; std::vector<uint> l_IDs;
		for (uint i = 0; i < l_count; ++i)
		{
			l_IDs.push_back(l_pool.add(i));
		}
		for (uint i = 0; i < l_count; ++i)
		{
			EXPECT_TRUE(l_pool.exists(l_IDs[i]));
		}
		for (uint i = 0; i < l_count; ++i)
		{
			l_pool.remove(l_IDs[i]);
		}
		for (uint i = 0; i < l_count; ++i)
		{
			EXPECT_FALSE(l_pool.exists(l_IDs[i]));
		}
		for (uint i = 0; i < l_count; ++i)
		{
			l_pool.add(i);
		}
		for (uint i = 0; i < l_count; ++i)
		{
			EXPECT_FALSE(l_pool.exists(l_IDs[i]));
		}
	}
	// Array subscript
	{
		uint l_count = 1000;
		pool_<uint> l_pool; std::vector<uint> l_vals, l_IDs;
		for (uint i = 0; i < l_count; ++i)
		{
			l_vals.push_back(i);
			l_IDs.push_back(l_pool.add(i));
		}
		for (uint i = 0; i < l_count; ++i)
		{
			EXPECT_EQ(l_vals[i], l_pool[l_IDs[i]]);
		}
	}
	// Iterating
	{
		uint l_count = 1000;
		pool_<uint> l_pool; std::vector<uint> l_vals, l_IDs;
		for (uint i = 0; i < l_count; ++i)
		{
			l_vals.push_back(i);
			l_IDs.push_back(l_pool.add(i));
		}
		EXPECT_NE(l_pool.first_ID(), BAD_ID);
		for (uint ID = l_pool.first_ID(); ID != BAD_ID; ID = l_pool.next_ID(ID))
		{
			EXPECT_TRUE(l_pool.exists(ID));
		}
		l_pool.clear();
		EXPECT_EQ(l_pool.first_ID(), BAD_ID);
	}
	// Havy type
	{
		uint l_count = 100;
		pool_<std::vector<uint> > l_pool; std::vector<uint> l_val, l_IDs;
		for (uint i = 0; i < l_count; ++i)
		{
			l_val.push_back(i);
			l_IDs.push_back(l_pool.add(l_val));
		}
	}
}