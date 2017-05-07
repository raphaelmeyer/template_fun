#include <gmock/gmock.h>

#include <tfun/quicksort.h>
#include <tfun/show.h>

using namespace ::testing;

TEST(quicksort, empty_list)
{
  auto const result = show<quicksort<list<>>>::string();
  ASSERT_THAT(result, StrEq("[]"));
}

TEST(quicksort, one_element)
{
  auto const result = show<quicksort<list<1>>>::string();
  ASSERT_THAT(result, StrEq("[1]"));
}

TEST(quicksort, unsorted_list)
{
  auto const result = show<quicksort<list<5, 1, 9, 4, 6, 7, 3, 2, 8>>>::string();
  ASSERT_THAT(result, StrEq("[1, 2, 3, 4, 5, 6, 7, 8, 9]"));
}

