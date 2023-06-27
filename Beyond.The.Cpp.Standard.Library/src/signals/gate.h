#ifndef GATE_INC
#define GATE_INC

#include <string>
#include "boost/signals.hpp"

class gate {
  typedef
    boost::signal<void (bool,const std::string&)> signal_type;
  typedef signal_type::slot_type slot_type;

  signal_type enter_or_leave_;
public:
  boost::signals::connection
    connect_to_gate(const slot_type& s) {
    return enter_or_leave_.connect(s);
  }

  void enter(const std::string& car_id) {
    enter_or_leave_(true,car_id);
  }

  void leave(const std::string& car_id) {
    enter_or_leave_(false,car_id);
  }
};

#endif
