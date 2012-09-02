#include "header.hpp"

using namespace heart;

TEST(heart_xstr, constructors_work)
{
    xstr_<10> l_str1;
    EXPECT_STREQ("", l_str1);
    xstr_<15> l_str2("Str %d", 2);
    EXPECT_STREQ("Str 2", l_str2);
    xstr_<20> l_str3(l_str2);
    EXPECT_STREQ("Str 2", l_str3);
    xstr_<5> l_str4("1234567890");
    EXPECT_STREQ("12345", l_str4);
}

TEST(heart_xstr, operators_work)
{
    xstr_<10> l_str1;
    EXPECT_STREQ("", l_str1);
    xstr_<15> l_str2 = "Str 1";
    EXPECT_STREQ("Str 1", l_str2);
    l_str1 = l_str2;
    EXPECT_STREQ("Str 1", l_str1);
    l_str2 = "Str 2";
    EXPECT_STREQ("Str 2", l_str2);
    char* l_str = l_str1;
    EXPECT_STREQ("Str 1", l_str);
    const char* l_cstr = l_str2;
    EXPECT_STREQ("Str 2", l_cstr);
    xstr_<20> l_str3 = l_str1;
    EXPECT_TRUE(l_str1 == "Str 1");
    EXPECT_TRUE(l_str2 != "Str 1");
    EXPECT_TRUE(l_str1 == l_str3);
    EXPECT_TRUE(l_str2 != l_str1);
    EXPECT_FALSE("Str 2" == l_str1);
    EXPECT_FALSE("Str 1" != l_str1);
}
