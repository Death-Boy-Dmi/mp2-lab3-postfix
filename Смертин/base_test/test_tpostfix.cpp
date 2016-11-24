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

TEST(TPostfix, throw_when_incorrect_number_of_brackets) // FAILED???
{
	string inf = "((a+b)))";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_first_character_is_operations)
{
	string inf = "+a+b";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, throw_when_last_character_is_operations) // FAILED???
{
	string inf = "a+b-";

	ASSERT_ANY_THROW(TPostfix p(inf));
}

TEST(TPostfix, can_use_ArrVarible)
{
	string inf = "a+b+c";
	TPostfix p(inf);

	ASSERT_NO_THROW(p.ArrVarible());
}

TEST(TPostfix, can_use_ArrVarible_2) // FAILED???
{
	string inf = "a+b+c";
	string arrVar[3];
	arrVar[0] = "a ";
	arrVar[1] = "b ";
	arrVar[2] = "c ";
	TPostfix p(inf);

	for (int i = 0; i < 3; i++)
		EXPECT_EQ(arrVar[i] == p.GetArrVar()[i], true);
}

TEST(TPostfix, can_use_ToPostfix)
{
	string inf = "a+b+c";
	TPostfix p(inf);

	ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TPostfix, can_use_ToPostfix_2) // FAILED???
{
	string inf = "a+b+c";
	string post = "ab+c+";
	TPostfix p(inf);

	EXPECT_EQ(p.ToPostfix() == post, true);
}

TEST(TPostfix, can_use_Calculate) // FAILED???
{
	string inf = "a+b+c";
	TPostfix p(inf);

	ASSERT_NO_THROW(p.Calculate());
}
/*
TEST(TPostfix, can_use_Calculate_2)
{
	string inf = "a+b";
	string post = "ab+c+";
	TPostfix p(inf);

	EXPECT_EQ(p.ToPostfix() == post, true);
}
*/