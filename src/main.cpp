//Mark Goulet
//CIS-17B
#include <iostream>
#include <limits>
#include "Library.h"
#include "Factory.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addBookMenu() {
    string title, author, isbn;

    cout << ">> Add a Book:\n";
    cout << ">> Enter the Title (0 to cancel): ";
    getline(cin, title);
    if (title == "0") return;

    cout << ">> Enter the Author (0 to cancel): ";
    getline(cin, author);
    if (author == "0") return;

    cout << ">> Enter the ISBN (0 to cancel): ";
    getline(cin, isbn);
    if (isbn == "0") return;

    Book newBook(title, author, isbn);
    Library::getInstance()->addBook(newBook);
}

void addUserMenu() {
    int type;
    string name;

    while (true) {
        cout << ">> Enter 1 for student or 2 for faculty (0 to cancel): ";
        cin >> type;
        clearInput();
        if (type == 0) return;
        if (type == 1 || type == 2) break;
        cout << "!! ERROR: Only valid options are 1 or 2\n";
    }

    cout << ">> Enter name (0 to cancel): ";
    getline(cin, name);
    if (name == "0") return;

    User* user = Factory::createUser(type, name);
    Library::getInstance()->addUser(user);
}

void manageBooksMenu() {
    int choice;
    while (true) {
        cout << "\n> Manage Books:\n";
        cout << "1. Add a Book"
              "\n2. View All Books"
              "\n3. Go Back\n";
        cout << "\n> Enter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: addBookMenu(); break;
            case 2: Library::getInstance()->listAllBooks(); break;
            case 4: return;
            default: cout << "Option not implemented or invalid.\n";
        }
    }
}

void manageUsersMenu() {
    int choice;
    while (true) {
        cout << "\n> Manage Users:\n";
        cout << "1. Add a User"
              "\n2. View All Users"
              "\n3. Go Back\n";
        cout << "\n> Enter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: addUserMenu(); break;
            case 2: Library::getInstance()->listAllUsers(); break;
            case 4: return;
            default: cout << "Option not implemented or invalid.\n";
        }
    }
}

void manageTransactionsMenu() {
    string userName, isbn;
    int choice;

    while (true) {
        cout << "\n> Manage Transactions:\n";
        cout << "1. Borrow Book"
              "\n2. Return Book"
              "\n3. Go Back\n";
        cout << "\n> Enter your choice: ";
        cin >> choice;
        clearInput();

        if (choice == 3) return;

        cout << ">> Enter User Name: ";
        getline(cin, userName);
        if (userName == "0") return;
        Library::getInstance()->listAllBooks();
        cout << ">> Enter ISBN: ";
        getline(cin, isbn);
        if (isbn == "0") return;

        if (choice == 1)
            Library::getInstance()->borrowBook(userName, isbn);
        else if (choice == 2)
            Library::getInstance()->returnBook(userName, isbn);
        else
            cout << "Invalid option.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nWelcome to the Library:\n";
        cout << "1. Manage Books"
              "\n2. Manage Users"
              "\n3. Manage Transactions"
              "\n4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: manageBooksMenu(); break;
            case 2: manageUsersMenu(); break;
            case 3: manageTransactionsMenu(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
