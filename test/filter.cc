#include <gmock/gmock.h>

#include <tfun/filter.h>
#include <tfun/show.h>

using namespace ::testing;

template<int A, int B>
struct lt
{
  static constexpr bool result = A < B;
};

template <int X>
using lt_3 = lt<X, 3>;

TEST(filter, elements_smaller_than)
{
  using filtered = filter<lt_3, list<1, 2, 3, 4>>;
  auto const result = show<filtered>::string();
  ASSERT_THAT(result, StrEq("[1, 2]"));
}