#include <gmock/gmock.h>

#include <tfun/tfun.h>

using namespace ::testing;

TEST(show, empty_list)
{
  auto const result = show<list<>>::string();
  ASSERT_THAT(result, StrEq("[]"));
}

TEST(show, one_element)
{
  auto const result = show<list<23>>::string();
  ASSERT_THAT(result, StrEq("[23]"));
}

TEST(show, a_list)
{
  auto const result = show<list<11, 13, 17>>::string();
  ASSERT_THAT(result, StrEq("[11, 13, 17]"));
}

TEST(concat, empty_list)
{
  auto const result = show<concat<list<>, list<>>>::string();
  ASSERT_THAT(result, StrEq("[]"));
}

TEST(concat, empty_list_with_list)
{
  auto const result = show<concat<list<11, 22>, list<>>>::string();
  ASSERT_THAT(result, StrEq("[11, 22]"));
}

TEST(concat, list_with_empty_list)
{
  auto const result = show<concat<list<>, list<33, 44>>>::string();
  ASSERT_THAT(result, StrEq("[33, 44]"));
}

TEST(concat, two_lists)
{
  auto const result = show<concat<list<1, 2>, list<4, 8, 16>>>::string();
  ASSERT_THAT(result, StrEq("[1, 2, 4, 8, 16]"));
}

template <int X>
using lt_3 = lt<X, 3>;

TEST(filter, elements_smaller_than)
{
  using filtered = filter<lt_3, list<1, 2, 3, 4>>;
  //auto const result = show<filtered>::string();
  //ASSERT_THAT(result, StrEq("[1, 2]"));
}

/*

TEST(quicksort, a_list_of_int)
{
  //ASSERT_THAT(show<quicksort<5,1,9,4,6,7,3,2,8>>::string(), StrEq("1 2 3 4 5 6 7 8 9"));
  FAIL();
}
*/