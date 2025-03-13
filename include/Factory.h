#ifndef FACTORY_H
#define FACTORY_H

#include "User.h"

class Factory {
public:
  static User* createUser(int type, const std::string& name);  // 1 = Student, 2 = Faculty
};

#endif //FACTORY_H
