#ifndef USER_H
#define USER_H



#include <string>
#include "Book.h"
using namespace std;

class User {
	private:
		string name;
		int userID;
		Book borrowedBooks[5]; // max 5 books
		int borrowedCount;

        int generateUserID();

	public:
		User();
		User(string name);

    	string getName() const;
        int getUserID() const;

        void borrowBook(const Book& book);
        void returnBook(const string& ISBN);
        void listBorrowedBooks() const;
};

class Student : public User {
public:
	Student();
	Student(std::string name);
};

class Faculty : public User {
public:
	Faculty();
	Faculty(std::string name);
};
#endif //USER_H
