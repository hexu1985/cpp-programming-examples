#include "tape_recorder.h"
#include "boost/function.hpp"
#include "boost/bind.hpp"

class command {
  boost::function<void()> f_;
public:
  command() {}
  command(boost::function<void()> f):f_(f) {}

  void execute() {
    if (f_) {
      f_();
    }
  }

  template <typename Func> void set_function(Func f) {
    f_=f;
  }

  bool enabled() const {
    return f_;
  }
};

int main() {
  tape_recorder tr;

  command play(boost::bind(&tape_recorder::play,&tr));
  command stop(boost::bind(&tape_recorder::stop,&tr));
  command forward(boost::bind(&tape_recorder::stop,&tr));
  command rewind(boost::bind(&tape_recorder::rewind,&tr));
  command record;

  // 从某些GUI控制中调用...
  if (play.enabled()) {
    play.execute();
  }

  // 从某些脚本客户端调用...
  stop.execute();

  // Some inspired songwriter has passed some lyrics
  std::string s="What a beautiful morning...";
  record.set_function(
    boost::bind(&tape_recorder::record,&tr,s));
  record.execute();
}

