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
}
