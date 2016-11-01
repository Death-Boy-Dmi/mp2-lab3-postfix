#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}
// Проверка конструктора на исключения
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
	TStack<int> st(5);

	ASSERT_NO_THROW(st.IsEmpty());
}
// Проверка Put() на исключения
TEST(TStack, throw_when_use_Put_when_stack_is_full)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
	{
		st.Put(i);
	}

	ASSERT_ANY_THROW(st.Put(5););
}
// Проверка Get() на исключения
TEST(TStack, throw_when_use_Get_when_stack_is_empty)
{
	TStack<int> st(5);

	ASSERT_ANY_THROW(st.Get());
}
TEST(TStack, can_Put_and_Get)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
	{
		st.Put(i);
	}
	for (int i = 0; i < 5; i++)
	{
		st.Get();
	}

	ASSERT_NO_THROW(st.IsEmpty());
}
TEST(TStack, can_check_on_the_stack_full)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
		st.Put(i);

	ASSERT_NO_THROW(st.IsFull());
}