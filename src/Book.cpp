#include <iostream>
#include "Book.h"

using namespace std;

Book::Book() : title(""), author(""), ISBN("") {}

Book::Book(string title, string author, string ISBN) : title(title), author(author), ISBN(ISBN) {}

string Book::getTitle() const { return title; }

string Book::getAuthor() const { return author; }

string Book::getISBN() const { return ISBN; }