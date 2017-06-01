#include <gmock/gmock.h>

#include <tfun/map.h>
#include <tfun/show.h>

using namespace ::testing;

template<int A>
struct inc
{
  static constexpr int result = A + 1;
};

TEST(map, empty_list)
{
  using result = map<inc, list<>>;
  ASSERT_THAT(show<result>::string(), StrEq("[]"));
}

TEST(map, single_element_with_increment)
{
  using result = map<inc, list<41>>;
  ASSERT_THAT(show<result>::string(), StrEq("[42]"));
}

TEST(map, elements_with_increment)
{
  using result = map<inc, list<5,-3,8,2>>;
  ASSERT_THAT(show<result>::string(), StrEq("[6, -2, 9, 3]"));
}
