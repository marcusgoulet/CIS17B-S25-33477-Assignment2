#ifndef BOOK_H
#define BOOK_H


#include <string>

class Book {
  private:
    std::string title;
    std::string author;
    std::string ISBN;

  public:
    Book();
    Book(std::string title, std::string author, std::string ISBN);

    // get methods
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;

};

#endif //BOOK_H
