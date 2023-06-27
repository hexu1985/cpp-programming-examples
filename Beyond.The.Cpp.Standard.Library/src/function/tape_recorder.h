#ifndef TAPE_RECORDER_INC
#define TAPE_RECORDER_INC

#include <string>
#include <iostream>

class tape_recorder {
public:
  void play() {
    std::cout << "Since my baby left me...\n";
  }

  void stop() {
    std::cout << "OK, taking a break\n";
  }

  void forward() {
    std::cout << "whizzz\n";
  }

  void rewind() {
    std::cout << "zzzihw\n";
  }

  void record(const std::string& sound) {
    std::cout << "Recorded: " << sound << '\n';
  }
};

#endif
