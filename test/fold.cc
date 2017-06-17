#include <gmock/gmock.h>

#include <tfun/fold.h>

using namespace ::testing;

template<int A, int B>
struct add
{
  static constexpr int result = A + B;
};

TEST(fold, an_empty_list_results_in_zero)
{
  auto const result = fold<add, list<>>;
  ASSERT_THAT(result, Eq(0));
}

TEST(fold, a_single_element_results_in_itself)
{
  auto const result = fold<add, list<23>>;
  ASSERT_THAT(result, Eq(23));
}

TEST(fold, adding_two_elements)
{
  auto const result = fold<add, list<1, 2>>;
  ASSERT_THAT(result, Eq(3));
}

TEST(fold, adding_a_list_of_ints)
{
  auto const result = fold<add, list<1, 2, 4, 8, 16, 32>>;
  ASSERT_THAT(result, Eq(63));
}
