#include "User.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// create 6-digit ID between 100000 and 900000
int User::generateUserID() {
    static bool seeded = false;
    if (!seeded) {
      srand(static_cast<unsigned int>(time(0)));
      seeded = true;
    }
    return 100000 + rand() % 900000;
}

// default constructor
User::User() : name(""), userID(000000), borrowedCount(0) {}

// name constructor, generate user id
User::User(string name) : name(name), userID(generateUserID()), borrowedCount(0) {}

string User::getName() const {
  return name;
}

int User::getUserID() const {
  return userID;
}

void User::borrowBook(const Book& book) {
  if (borrowedCount < 5) {
    borrowedBooks[borrowedCount++] = book;
  } else {
    cout << "Cannot borrow more books. Limit reached." << endl;
  }
}

void User::returnBook(const string& ISBN) {
  for (int i = 0; i < borrowedCount; i++) {
    if (borrowedBooks[i].getISBN() == ISBN) {
      for (int j = i; j < borrowedCount - 1; j++) {
        borrowedBooks[j] = borrowedBooks[j + 1];
      }
      --borrowedCount;
      cout << "Book returned successfully." << endl;
    }
  }
  cout << "Book not found." << endl;
}

void User::listBorrowedBooks() const {
  cout << "Borrowed Books by " << name << ":" << endl;
  for (int i = 0; i < borrowedCount; i++) {
    cout << borrowedBooks[i].getTitle() << endl;
  }
}

Student::Student() : User() {}
Student::Student(std::string name) : User(name) {}

Faculty::Faculty() : User() {}
Faculty::Faculty(std::string name) : User(name) {}