#include <fst/fstlib.h>

#include "query.h"

namespace paust::query {
QueryContext::~QueryContext() = default;

QueryContext::QueryContext(uint64_t startTime, uint64_t delta)
: start_(startTime), delta_(delta), fst_(std::make_unique<fst::StdVectorFst>()) {
  auto startId = fst_->AddState();
  fst_->SetStart(startId);
}

fst::StdVectorFst& QueryContext::fst() {
  return *fst_;
}

void QueryContext::add(std::vector<Data> datas) {
  for (auto &&data : std::move(datas)) {
    auto stateId = (int)((data.timestamp() - start_) / delta_);

    while (fst_->NumStates() < stateId + 1) {
      addNewState();
    }

    auto pData = std::make_shared<Data>(std::move(data));
    for (fst::ArcIterator ai(*fst_, stateId); !ai.Done(); ai.Next()) {
      std::get<1>(this->dataGroups_.at(ai.Value().ilabel)).emplace_back(pData);
    }
  }
}

void QueryContext::addNewState() {
  auto label = counter_.fetch_add(1);
  auto stateId = fst_->AddState();
  fst_->AddArc(stateId - 1, fst::StdArc(1, 1, 0.5, stateId));

  this->dataGroups_.emplace(label, DataGroup(label, {}));
}
}