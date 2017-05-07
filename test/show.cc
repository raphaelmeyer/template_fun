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
