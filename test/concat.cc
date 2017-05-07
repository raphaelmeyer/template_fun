#include <gmock/gmock.h>

#include <tfun/concat.h>
#include <tfun/show.h>

using namespace ::testing;

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
