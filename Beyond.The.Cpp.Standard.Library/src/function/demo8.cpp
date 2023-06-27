#include "tape_recorder.h"

class command_base {
public:
  virtual bool enabled() const=0;
  virtual void execute()=0;

  virtual ~command_base() {}
};

class tape_recorder_command : public command_base {
  void (tape_recorder::*func_)();
  tape_recorder* p_;
public:

  tape_recorder_command(
    tape_recorder* p,
    void (tape_recorder::*func)()) : p_(p),func_(func) {}

  bool enabled() const {
    return true;
  }

  void execute() {
    (p_->*func_)();
  }
};

int main() {
  tape_recorder tr;

  // 使用改进的命令模式
  command_base* pPlay=
    new tape_recorder_command(&tr,&tape_recorder::play);
  command_base* pStop=
    new tape_recorder_command(&tr,&tape_recorder::stop);

  // 从一个GUI或一个脚本客户端进行调用
  pPlay->execute();
  pStop->execute();

  delete pPlay;
  delete pStop;
}

