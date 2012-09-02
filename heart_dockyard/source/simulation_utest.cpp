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
	// rigid
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        EXPECT_TRUE(l_rigid.valid());
        l_rigid.destroy();
        EXPECT_FALSE(l_rigid.valid());
	}
	// Many rigidbodies
	{
        world l_world("Test world");
        std::vector<rigid> l_rigids;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_rigids.push_back(l_world.create_rigid(xname("rigid %d", i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_rigids[i].destroy();
        }
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_rigids[i].valid()) l_rigids.erase(l_rigids.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_rigids.push_back(l_world.create_rigid(xname("rigid %d", l_count + i)));
        }
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_rigids[i].valid());
        }
	}
    // Enumeration
    {
        world l_world;
        const uint l_rigids_count = 50;
        const uint l_shapes_count = 5;
        const uint l_joints_count = 5;
        for (uint i = 0; i < l_rigids_count; ++i)
        {
            rigid l_rigid = l_world.create_rigid();
            for (uint i = 0; i < l_shapes_count; ++i)
            {
                l_rigid.create_shape();
            }
            for (uint i = 0; i < l_joints_count; ++i)
            {
                l_rigid.create_joint();
            }
        }
        EXPECT_EQ(l_rigids_count, l_world.rigids_count());
        EXPECT_EQ(l_rigids_count * l_shapes_count, l_world.shapes_count());
        EXPECT_EQ(l_rigids_count * l_joints_count, l_world.joints_count());
        // rigids
        {
            uint l_count = 0;
            for (rigid r = l_world.first_rigid(); r.valid(); r = l_world.next_rigid(r))
            {
                ++l_count;
            }
            EXPECT_EQ(l_rigids_count, l_count);
        }
        // shapes
        {
            uint l_count = 0;
            for (shape s = l_world.first_shape(); s.valid(); s = l_world.next_shape(s))
            {
                ++l_count;
            }
            EXPECT_EQ(l_rigids_count * l_shapes_count, l_count);
        }
        // joints
        {
            uint l_count = 0;
            for (joint j = l_world.first_joint(); j.valid(); j = l_world.next_joint(j))
            {
                ++l_count;
            }
            EXPECT_EQ(l_rigids_count * l_joints_count, l_count);
        }
    }
}

TEST(heart_rigid, functions_work)
{
	// rigid name
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        EXPECT_STREQ("Test rigid", l_rigid.name());
        l_rigid.destroy();
        EXPECT_STREQ("", l_rigid.name());
	}
	// rigid shape
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        shape l_shape = l_rigid.create_shape("Test shape");
        EXPECT_TRUE(l_shape.valid());
        l_shape.destroy();
        EXPECT_FALSE(l_shape.valid());
        l_shape = l_rigid.create_shape("Test shape");
        EXPECT_TRUE(l_shape.valid());
        l_rigid.destroy();
        EXPECT_FALSE(l_shape.valid());
	}
	// rigid many shapes
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        std::vector<shape> l_shapes;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_shapes.push_back(l_rigid.create_shape(xname("Shape %d", i)));
        }
        EXPECT_EQ(l_count, l_rigid.shapes_count());
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_shapes[i].destroy();
        }
        EXPECT_EQ(l_count / 2, l_rigid.shapes_count());
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_shapes[i].valid()) l_shapes.erase(l_shapes.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        uint l_enum = 0;
        for (shape s = l_rigid.first_shape(); s.valid(); s = l_rigid.next_shape(s))
        {
            ++l_enum;
        }
        EXPECT_EQ(l_enum, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_shapes.push_back(l_rigid.create_shape(xname("Shape %d", l_count + i)));
        }
        EXPECT_EQ(l_count, l_rigid.shapes_count());
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_shapes[i].valid());
        }
    }
	// rigid joint
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        joint l_joint = l_rigid.create_joint("Test joint");
        EXPECT_TRUE(l_joint.valid());
        l_joint.destroy();
        EXPECT_FALSE(l_joint.valid());
        l_joint = l_rigid.create_joint("Test joint");
        EXPECT_TRUE(l_joint.valid());
        l_rigid.destroy();
        EXPECT_FALSE(l_joint.valid());
	}
	// rigid many joints
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        std::vector<joint> l_joints;
        const sint l_count = 1000;
        for (sint i = 0; i < l_count; ++i)
        {
            l_joints.push_back(l_rigid.create_joint(xname("Joint %d", i)));
        }
        EXPECT_EQ(l_count, l_rigid.joints_count());
        for (sint i = 0; i < l_count; ++i)
        {
            if (i % 2) l_joints[i].destroy();
        }
        EXPECT_EQ(l_count / 2, l_rigid.joints_count());
        uint l_rest = 0;
        for (sint i = l_count - 1; i >= 0; --i)
        {
            if (!l_joints[i].valid()) l_joints.erase(l_joints.begin() + i);
            else ++l_rest;
        }
        EXPECT_EQ(l_count / 2, l_rest);
        uint l_enum = 0;
        for (joint j = l_rigid.first_joint(); j.valid(); j = l_rigid.next_joint(j))
        {
            ++l_enum;
        }
        EXPECT_EQ(l_enum, l_rest);
        for (sint i = 0; i < l_count / 2; ++i)
        {
            l_joints.push_back(l_rigid.create_joint(xname("Joint %d", l_count + i)));
        }
        EXPECT_EQ(l_count, l_rigid.joints_count());
        for (sint i = 0; i < l_count; ++i)
        {
            EXPECT_TRUE(l_joints[i].valid());
        }
    }
}

TEST(heart_shape, functions_work)
{
	// rigid shape name
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        shape l_shape = l_rigid.create_shape("Test shape");
        EXPECT_STREQ("Test shape", l_shape.name());
        l_shape.destroy();
        EXPECT_STREQ("", l_shape.name());
        l_shape = l_rigid.create_shape("Test shape");
        EXPECT_STREQ("Test shape", l_shape.name());
        l_rigid.destroy();
        EXPECT_STREQ("", l_shape.name());
	}
}

TEST(heart_joint, functions_work)
{
	// rigid joint name
	{
        world l_world("Test world");
        rigid l_rigid = l_world.create_rigid("Test rigid");
        joint l_joint = l_rigid.create_joint("Test joint");
        EXPECT_STREQ("Test joint", l_joint.name());
        l_joint.destroy();
        EXPECT_STREQ("", l_joint.name());
        l_joint = l_rigid.create_joint("Test joint");
        EXPECT_STREQ("Test joint", l_joint.name());
        l_rigid.destroy();
        EXPECT_STREQ("", l_joint.name());
	}
}
