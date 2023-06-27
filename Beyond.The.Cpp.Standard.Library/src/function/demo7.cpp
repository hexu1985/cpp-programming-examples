#include "tape_recorder.h"

class command_base {
public:
  virtual bool enabled() const=0;
  virtual void execute()=0;

  virtual ~command_base() {}
};

class play_command : public command_base {
  tape_recorder* p_;
public:
  play_command(tape_recorder* p):p_(p) {}

  bool enabled() const {
    return true;
  }

  void execute() {
    p_->play();
  }
};

class stop_command : public command_base {
  tape_recorder* p_;
public:
  stop_command(tape_recorder* p):p_(p) {}

  bool enabled() const {
    return true;
  }

  void execute() {
    p_->stop();
  }
};

int main() {
  tape_recorder tr;

  // 使用命令模式
  command_base* pPlay=new play_command(&tr);
  command_base* pStop=new stop_command(&tr);

  // 在按下某个按钮时调用
  pPlay->execute();
  pStop->execute();

  delete pPlay;
  delete pStop;
}

