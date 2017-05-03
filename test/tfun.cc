#include <gmock/gmock.h>

#include <tfun/tfun.h>

#include <iostream>

using namespace ::testing;

TEST(dummy, test)
{
  auto const result = show<0, 2, 4, 5>::string();
  ASSERT_THAT(result, StrEq("0 2 4 5"));

  //ASSERT_THAT(show<quicksort<5,1,9,4,6,7,3,2,8>>::string(), StrEq("1 2 3 4 5 6 7 8 9"));
}
