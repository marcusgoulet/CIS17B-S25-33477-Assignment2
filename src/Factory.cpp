#include "Factory.h"
#include "User.h"

User* Factory::createUser(int type, const std::string& name) {
  if (type == 1) {
    return new Student(name);
  } else if (type == 2) {
    return new Faculty(name);
  } else {
    return nullptr;
  }
}