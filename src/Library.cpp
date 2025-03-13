#include "Library.h"

#include <iostream>
using namespace std;

Library* Library::instance = nullptr;

Library::Library() : bookCount(0), userCount(0) {}

Library* Library::getInstance() {
    if (instance == nullptr) {
        instance = new Library();
    }
    return instance;
}

void Library::addBook(const Book& book) {
    if (bookCount < 50) {
        books[bookCount++] = book;
        cout << "Book added: " << book.getTitle() << endl;
    } else {
        cout << "Library is full. Cannot add more books." << endl;
    }
}

void Library::addUser(User* user) {
    if (userCount < 20) {
        users[userCount++] = user;
        cout << "User added: " << user->getName() << endl;
    } else {
        cout << "Too many users registered." << endl;
    }
}

void Library::borrowBook(const std::string& userName, const std::string& isbn) {

    for (int i = 0; i < userCount; ++i) {
        if (users[i]->getName() == userName) {
            for (int j = 0; j < bookCount; ++j) {
                if (books[j].getISBN() == isbn) {
                    users[i]->borrowBook(books[j]);
                    return;
                }
            }
            cout << "Book with ISBN " << isbn << " not found." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

void Library::returnBook(const std::string& userName, const std::string& isbn) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i]->getName() == userName) {
            users[i]->returnBook(isbn);
            return;
        }
    }
    cout << "User not found." << endl;
}

void Library::listAllBooks() const {
    cout << "--- Books in Library ---" << endl;
    for (int i = 0; i < bookCount; ++i) {
        cout << books[i].getTitle() << " by " << books[i].getAuthor() << "- ISBN: " << books[i].getISBN() << endl;
    }
}

void Library::listAllUsers() const {
    cout << "--- Registered Users ---" << endl;
    for (int i = 0; i < userCount; ++i) {
        cout << users[i]->getName() << " (ID: " << users[i]->getUserID() << ")" << endl;
    }
}