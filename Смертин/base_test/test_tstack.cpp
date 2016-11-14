#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throw_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, throw_when_create_stack_with_large_max_size_length)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, can_check_on_the_stack_empty)
{
	TStack<int> st(2);

	EXPECT_EQ(st.IsEmpty(),true);
}

TEST(TStack, can_check_on_the_stack_full)
{
	TStack<int> st(1);
	st.Put(4);
	EXPECT_EQ(st.IsFull(), true);
}

TEST(TStack, throw_when_use_Get_when_stack_is_empty)
{
	TStack<int> st(5);

	ASSERT_ANY_THROW(st.Get());	
}

TEST(TStack, can_use_Get)
{
	TStack<int> st(2);
	st.Put(4);
	ASSERT_NO_THROW(st.Get());
}

TEST(TStack, throw_when_use_Put_when_stack_is_Full)
{
	TStack<int> st(1);
	st.Put(4);

	ASSERT_ANY_THROW(st.Put(1));
}

TEST(TStack, can_use_Put)
{
	TStack<int> st(2);

	ASSERT_NO_THROW(st.Put(0));
}
Test(TStack, chek_Put_and_Get)
{
	TStack<int> st(2);
	st.Put(13);
	
	EXPECT_EQ(st.Get(), 13);
}
