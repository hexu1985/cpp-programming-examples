#ifndef PARKING_LOT_GUARD_INC
#define PARKING_LOT_GUARD_INC

#include <string>
#include <vector>
#include <iostream>
#include "boost/shared_ptr.hpp"
#include "boost/signals.hpp"

class parking_lot_guard {
  typedef
    boost::signal<void (const std::string&)> alarm_type;
  typedef alarm_type::slot_type slot_type;

  boost::shared_ptr<alarm_type> alarm_;

  typedef std::vector<std::string> cars;
  typedef cars::iterator iterator;

  boost::shared_ptr<cars> cars_;
public:

  parking_lot_guard()
    : alarm_(new alarm_type), cars_(new cars) {}

  boost::signals::connection
    connect_to_alarm(const slot_type& a) {
    return alarm_->connect(a);
  }

  void operator()
    (bool is_entering,const std::string& car_id) {
    if (is_entering)
      enter(car_id);
    else
      leave(car_id);
  }

private:
  void enter(const std::string& car_id) {
    std::cout <<
      "parking_lot_guard::enter(" << car_id << ")\n";

    // 如果车辆已经在这，就触发警报
    if (std::binary_search(cars_->begin(),cars_->end(),car_id))
      (*alarm_)(car_id);
    else // Insert the car_id
      cars_->insert(
        std::lower_bound(
          cars_->begin(),
          cars_->end(),car_id),car_id);
  }

  void leave(const std::string& car_id) {
    std::cout <<
      "parking_lot_guard::leave(" << car_id << ")\n";

    // 如果是未登记的车辆，就触发警报
    std::pair<iterator,iterator> p=
      std::equal_range(cars_->begin(),cars_->end(),car_id);
    if (p.first==cars_->end() || *(p.first)!=car_id)
      (*alarm_)(car_id);
    else
      cars_->erase(p.first);
  }
};

#endif
