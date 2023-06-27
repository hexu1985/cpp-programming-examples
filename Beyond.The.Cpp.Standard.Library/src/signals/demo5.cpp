#include <vector>
#include <iostream>
#include "gate.h"
#include "parking_lot_guard.h"
#include "security_guard.h"

int main() {
  // 创建一些警卫
  std::vector<security_guard> security_guards;
  security_guards.push_back("Bill");
  security_guards.push_back("Bob");
  security_guards.push_back("Bull");
  // 创建两个门
  gate gate1;
  gate gate2;

  // 创建自动监视器
  parking_lot_guard plg;

  // 把自动监视器连接到门上
  gate1.connect_to_gate(plg);
  gate2.connect_to_gate(plg);

  // 把警卫连接到自动监视器上
  for (unsigned int i=0;i<security_guards.size();++i) {
    plg.connect_to_alarm(security_guards[i]);
  }

  std::cout << "A couple of cars enter...\n";
  gate1.enter("SLN 123");
  gate2.enter("RFD 444");
  gate2.enter("IUY 897");

  std::cout << "\nA couple of cars leave...\n";
  gate1.leave("IUY 897");
  gate1.leave("SLN 123");

  std::cout << "\nSomeone is entering twice - or is it a stolen license plate?\n";
  gate1.enter("RFD 444");
}

