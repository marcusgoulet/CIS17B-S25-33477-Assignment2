#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"

class Library {
private:
  static Library* instance;

  Book books[50];
  User* users[20];
  int bookCount;
  int userCount;

  Library();  // private constructor (Singleton)

public:
  static Library* getInstance();

  void addBook(const Book& book);
  void addUser(User* user);

  void borrowBook(const std::string& userID, const std::string& isbn);
  void returnBook(const std::string& userID, const std::string& isbn);

  void listAllBooks() const;
  void listAllUsers() const;
};

#endif //LIBRARY_H
