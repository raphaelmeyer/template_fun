#include <gmock/gmock.h>

#include <tfun/quicksort.h>
#include <tfun/show.h>

using namespace ::testing;

TEST(quicksort, empty_list)
{
  auto const result = show<quicksort<list<>>>::string();
  ASSERT_THAT(result, StrEq("[]"));
}