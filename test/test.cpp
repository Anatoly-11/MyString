#include "pch.h"
#include "MyString.h"
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringCreateEmpty, Test1) {
  MyString::MyString m;
  EXPECT_TRUE(m.emptó());
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringCreateFillEquql, Test2) {
  const char *val = "123456";
  MyString::MyString p = val;
  EXPECT_TRUE(p == val);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringGtZterm, Test3) {
  MyString::MyString p("123456");
  EXPECT_TRUE(p > "023456");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringLtZterm, Test4) {
  MyString::MyString p("123456");
  EXPECT_TRUE(p < "723456");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(ZtermEqMyString, Test5) {
  MyString::MyString p("123456");
  EXPECT_TRUE("7123456" > p);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(ZtermLtMyString, Test6) {
  MyString::MyString p("123456");
  EXPECT_TRUE("023456" < p);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringReverse, Test7) {
  MyString::MyString p("1234567");
  p.reverse();
  EXPECT_TRUE("7654321"  == p);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringSize, Test8) {
  MyString::MyString p("1234567");
  EXPECT_EQ(p.size(),  7);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringReserve, Test9) {
  MyString::MyString p("1234567890");
  p.reserve(5);
  EXPECT_LT(p.size(),  10);
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringTruncate, Test10) {
  MyString::MyString p("1234567890");
  p.truncate(5);
  EXPECT_EQ(p.size(),  5);
  EXPECT_TRUE(p == "12345");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringPlusMyString, Test11) {
  MyString::MyString s1("1234567890"), s2("InavPetrov ") ;
  MyString::MyString s3 = s2 + s1;
  EXPECT_TRUE(s3 == "InavPetrov 1234567890");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringPlusZTermg, Test12) {
  MyString::MyString s1("InavPetrov ") ;
  MyString::MyString s3 = s1 + "1234567890";
  EXPECT_TRUE(s3 == "InavPetrov 1234567890");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringPlusChar, Test13) {
  MyString::MyString s1("InavPetrov ") ;
  MyString::MyString s3 = s1 + 'A';
  EXPECT_TRUE(s3 == "InavPetrov A");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(ZTermgPlusMyString, Test12) {
  MyString::MyString s2("1234567890") ;
  MyString::MyString s3 = "InavPetrov " + s2;
  EXPECT_TRUE(s3 == "InavPetrov 1234567890");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(CharPlusMyString, Test13) {
  char chr = 'A';
  MyString::MyString s1(" InavPetrov") ;
  MyString::MyString s3 = chr + s1;
  EXPECT_TRUE(s3 == "A InavPetrov");
}
//---------------------------------------------------------------------------------------------------------------------------------
TEST(MyStringCreateMovePtr, Test14) {
  constexpr size_t SZ = 24;
  char *val = new char[SZ]{"Piter Ivanov"};
  MyString::MyString p(std::move(val), SZ);
  EXPECT_STREQ(p.c_str(), "Piter Ivanov");
  EXPECT_TRUE(val == nullptr);
}
//---------------------------------------------------------------------------------------------------------------------------------