#include "header.hpp"

using namespace heart;

// world

TEST(heart_world, constructors_work)
{
	// Unnamed world
	{
        world l_world;
        EXPECT_STREQ("", l_world.name());
	}
	// Named world
	{
        world l_world("Test world");
        EXPECT_STREQ("Test world", l_world.name());
	}
}

TEST(heart_world, functions_work)
{
	// Rigidbody
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        EXPECT_TRUE(l_rigidbody.valid());
        l_rigidbody.destroy();
        EXPECT_FALSE(l_rigidbody.valid());
	}
	// Many rigidbodies
	{
        world l_world("Test world");
        std::vector<rigidbody> l_rigidbodies;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_rigidbodies.push_back(l_world.create_rigidbody(xname("Rigidbody %d", i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_rigidbodies[i].destroy();
        }
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_rigidbodies[i].valid()) l_rigidbodies.erase(l_rigidbodies.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_rigidbodies.push_back(l_world.create_rigidbody(xname("Rigidbody %d", l_count + i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_rigidbodies[i].valid());
        }
	}
}

TEST(heart_rigidbody, functions_work)
{
	// Rigidbody name
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        EXPECT_STREQ("Test rigidbody", l_rigidbody.name());
        l_rigidbody.destroy();
        EXPECT_STREQ("", l_rigidbody.name());
	}
	// Rigidbody shape
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        shape l_shape = l_rigidbody.create_shape("Test shape");
        EXPECT_TRUE(l_shape.valid());
        l_shape.destroy();
        EXPECT_FALSE(l_shape.valid());
        l_shape = l_rigidbody.create_shape("Test shape");
        EXPECT_TRUE(l_shape.valid());
        l_rigidbody.destroy();
        EXPECT_FALSE(l_shape.valid());
	}
	// Rigidbody many shapes
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        std::vector<shape> l_shapes;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_shapes.push_back(l_rigidbody.create_shape(xname("Shape %d", i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_shapes[i].destroy();
        }
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_shapes[i].valid()) l_shapes.erase(l_shapes.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        uint l_enum = 0;
        for (shape s = l_rigidbody.first_shape(); s.valid(); s = s.next_shape())
        {
            ++l_enum;
        }
        EXPECT_EQ(l_enum, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_shapes.push_back(l_rigidbody.create_shape(xname("Shape %d", l_count + i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_shapes[i].valid());
        }
    }
	// Rigidbody joint
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        joint l_joint = l_rigidbody.create_joint("Test joint");
        EXPECT_TRUE(l_joint.valid());
        l_joint.destroy();
        EXPECT_FALSE(l_joint.valid());
        l_joint = l_rigidbody.create_joint("Test joint");
        EXPECT_TRUE(l_joint.valid());
        l_rigidbody.destroy();
        EXPECT_FALSE(l_joint.valid());
	}
	// Rigidbody many joints
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        std::vector<joint> l_joints;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_joints.push_back(l_rigidbody.create_joint(xname("Joint %d", i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_joints[i].destroy();
        }
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_joints[i].valid()) l_joints.erase(l_joints.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        uint l_enum = 0;
        for (joint j = l_rigidbody.first_joint(); j.valid(); j = j.next_joint())
        {
            ++l_enum;
        }
        EXPECT_EQ(l_enum, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_joints.push_back(l_rigidbody.create_joint(xname("Joint %d", l_count + i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_joints[i].valid());
        }
    }
}

TEST(heart_shape, functions_work)
{
	// Rigidbody shape name
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        shape l_shape = l_rigidbody.create_shape("Test shape");
        EXPECT_STREQ("Test shape", l_shape.name());
        l_shape.destroy();
        EXPECT_STREQ("", l_shape.name());
        l_shape = l_rigidbody.create_shape("Test shape");
        EXPECT_STREQ("Test shape", l_shape.name());
        l_rigidbody.destroy();
        EXPECT_STREQ("", l_shape.name());
	}
}

TEST(heart_joint, functions_work)
{
	// Rigidbody joint name
	{
        world l_world("Test world");
        rigidbody l_rigidbody = l_world.create_rigidbody("Test rigidbody");
        joint l_joint = l_rigidbody.create_joint("Test joint");
        EXPECT_STREQ("Test joint", l_joint.name());
        l_joint.destroy();
        EXPECT_STREQ("", l_joint.name());
        l_joint = l_rigidbody.create_joint("Test joint");
        EXPECT_STREQ("Test joint", l_joint.name());
        l_rigidbody.destroy();
        EXPECT_STREQ("", l_joint.name());
	}
}
