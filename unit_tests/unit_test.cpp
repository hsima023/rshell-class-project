#include <gtest/gtest.h>

#include "token_test.hpp"
#include "../integration_tests/shell_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
