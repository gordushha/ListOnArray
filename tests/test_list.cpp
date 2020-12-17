#include <../gtest/gtest.h>
#include "List.h"

TEST(list, default_constructor)
{
	ASSERT_NO_THROW(List<int> A);
}

TEST(list, copy_constructor)
{
	List<int> A;

	A.push_back(5);

	List<int> B(A);

	EXPECT_EQ(5, B.pop_back());
}

TEST(list, empty)
{
	List<int> A;
	EXPECT_EQ(1, A.IsEmpty());
}

TEST(list, full)
{
	List<int> A(5);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);

	EXPECT_EQ(1, A.IsFull());
}

TEST(list, getsize)
{
	List<int> A(5);

	EXPECT_EQ(5, A.GetSize());
}

TEST(list, getcount)
{
	List<int> A(5);
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);

	EXPECT_EQ(5, A.GetCount());
}

TEST(list, push_back)
{
	List<int> A(5);

	A.push_back(1);
	A.push_back(2);

	EXPECT_EQ(2, A.pop_back());
}

TEST(list, pop_back)
{
	List<int> A(5);

	A.push_back(1);
	A.push_back(2);
	A.pop_back();
	A.push_back(3);

	EXPECT_EQ(3, A.pop_back());
}

TEST(list, push_front)
{
	List<int> A(5);

	A.push_back(1);
	A.push_front(2);

	EXPECT_EQ(2, A.pop_front());
}

TEST(list, pop_front)
{
	List<int> A(5);

	A.push_back(1);
	A.push_back(2);

	EXPECT_EQ(1, A.pop_front());
}

TEST(list, pop_empty)
{
	List<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}