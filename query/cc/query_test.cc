#include <fst/fstlib.h>
#include <gtest/gtest.h>

#include "query.h"

namespace paust::query {
struct QueryContextTest : public ::testing::Test {
  void SetUp() override {
    qc = std::make_unique<QueryContext>(baseTime, delta);
  }

  void TearDown() override {
    qc = nullptr;
  }

  const uint64_t baseTime = 1551617018000;
  const uint64_t delta = 60 * 1000;

  std::unique_ptr<QueryContext> qc;
};

TEST_F(QueryContextTest, testAdd) {
  qc->add({
    {baseTime+1, "asd"},
    {baseTime+1+delta, "asd1"},
    {baseTime+1+delta*2, "asd2"},
    {baseTime+1+delta*3, "asd3"}
  });

  auto &fst1 = qc->fst();
  fst1.SetStart(0);

  std::cout << fst1.Start() << std::endl;

  auto fst2 = fst1;
  fst2.SetStart(1);

  std::cout << fst1.Start() << std::endl;
}
}