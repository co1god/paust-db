#ifndef QUERY_DATA_GROUP_CONTAINER_H
#define QUERY_DATA_GROUP_CONTAINER_H

#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>

namespace paust::query {
struct Data : public std::tuple<uint64_t, std::string> {
  using std::tuple<uint64_t, std::string>::tuple;

  uint64_t timestamp() const { return std::get<0>(*this); }
  const std::string &id() const { return std::get<1>(*this); }
};

struct DataGroup : public std::tuple<int, std::vector<std::shared_ptr<Data>>> {
  using std::tuple<int, std::vector<std::shared_ptr<Data>>>::tuple;

  int label() const { return std::get<0>(*this); }
  const std::vector<std::shared_ptr<Data>> &datas() const { return std::get<1>(*this); }
};
}

#endif //QUERY_DATAGROUPCONTAINER_H
