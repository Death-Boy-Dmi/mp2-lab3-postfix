#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	string inf = "a+b";

	ASSERT_NO_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_entered_invalid_characters_in_expression)
{
	string inf = "a+b#@";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_number_of_variables_does_not_correspond_to_the_numbers_of_operations)
{
	string inf = "a++b";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_incorrect_number_of_brackets)
{
	string inf = "((a+b)))";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_first_character_is_operations)
{
	string inf = "+a+b";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_last_character_is_operations)
{
	string inf = "a+b+";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, can_use_ArrVarible)
{
	string inf = "a+b+c";
	TPostfix p(inf);

	ASSERT_NO_THROW(p.ArrVarible());
}

TEST(TPostfix, can_use_ToPostfix)
{
	string inf = "a+b+c";
	TPostfix p(inf);

	ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TPostfix, can_use_ToPostfix_2)
{
	string inf = "a+b+c";
	TPostfix p(inf);
	string post = "a b +c +";

	EXPECT_EQ(p.ToPostfix(), post);
}
TEST(TPostfix, can_use_ToPostfix_3)
{
	string inf = "(a+b*c/d-c)*(f-c/e)";
	TPostfix p(inf);
	string post = "a b c *d /+c -f c e /-*";

	EXPECT_EQ(p.ToPostfix(), post);
}

TEST(TPostfix, can_use_Calculate)
{
	string inf = "1+2+3";
	TPostfix p(inf);
	p.ToPostfix();

	ASSERT_NO_THROW(p.Calculate());
}

TEST(TPostfix, can_use_Calculate_2)
{
	string inf = "2+3+4";
	TPostfix p(inf);
	p.ToPostfix();

	EXPECT_EQ(p.Calculate(), 9);
}

TEST(TPostfix, can_use_Calculate_3)
{
	string inf = "(2+3*2/3-2)*(8-2)";
	TPostfix p(inf);
	p.ToPostfix();

	EXPECT_EQ(p.Calculate(), 12);
}