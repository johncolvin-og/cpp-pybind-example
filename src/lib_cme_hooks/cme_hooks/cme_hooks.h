#pragma once

#include <string>

namespace bts::cme_hooks {

class CmeHooks {
  public:
   virtual ~CmeHooks();
   virtual void on_ticker(const std::string &payload);
   virtual void on_depth(const std::string &payload);
};

//////////////////////////////////////////////////
// Definition
//////////////////////////////////////////////////

inline void CmeHooks::on_depth(const std::string &payload) { (void)(payload); }
inline void CmeHooks::on_ticker(const std::string &payload) { (void)(payload); }

}  // namespace bts::cme_hooks
