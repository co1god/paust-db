#ifndef QUERY_QUERY_H
#define QUERY_QUERY_H

#include <string>
#include <memory>

#include <fst/fst-decl.h>

#include "data_group_container.h"

namespace paust::query {
class QueryContext {
public:
  ~QueryContext();
  QueryContext(uint64_t startTime, uint64_t delta);
  QueryContext(const QueryContext &) = default;
  QueryContext(QueryContext &&) = default;

  void add(std::vector<Data> datas);

  fst::StdVectorFst &fst();

private:
  void addNewState();

  uint64_t start_, delta_;
  std::unordered_map<int, DataGroup> dataGroups_;
  std::unique_ptr<fst::StdVectorFst> fst_;
  std::atomic<int> counter_ = 0;
};
}

#endif //QUERY_QUERY_H
