/*
 * File: exercise10.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Create a book class with the properties title, author, year of publication
 * and quantity, and methods to print book information, borrow books and
 * give book back
 */

#include<iostream>
#include<stdint.h>
#include<string>
#include<vector>

using namespace std;

/* Description: Information management of books */
class Book {
    private:
        uint16_t ID;
        string AUTHOR;
        string BOOKNAME;
        uint16_t QUANTIY;
    public:
        Book(string author = NULL, string bookName = NULL, uint16_t quantity = 0);
        uint16_t getId();
        string getAuthor();
        string getbookName();
        void setQuantity(uint16_t quantity = 0);
        uint16_t getQuantity();
};

Book::Book (string author, string bookName, uint16_t quantity) {

    /* Create id incrementing with the number of function calls */
    static uint16_t id = 100;
    this->ID = id;
    id++;

    this->AUTHOR = author;
    this->BOOKNAME = bookName;
    this->QUANTIY = quantity;
}

uint16_t Book::getId () {
    return ID;
}

string Book::getAuthor () {
    return AUTHOR;
}

string Book::getbookName() {
    return BOOKNAME;
}

/* 
 * Function: Book::setQuantity()
 * Description: Update new value for quantity
 */
void Book::setQuantity (uint16_t quantity) {
    this->QUANTIY = quantity;
}

uint16_t Book::getQuantity () {
    return QUANTIY;
}

/* Manage books in the library */
class Library {
    private:
        vector<Book> databaseBook;
    public:
        void addBook(Book book);
        void lishBook();
        void option();
        void borrowBook();
        void backBook();
};

void Library::addBook (Book book) {
    databaseBook.push_back(book);
};

/* 
 * Function: Library::lishBook()
 * Description: Print all book from databaseBook
 */
void Library::lishBook () {
    cout << "-----------------------------------------------------------------------------"
         << "--------------------------------------------\n";
    cout << "|\tID\t|\t\tAuthor\t\t\t|\t\tbookName\t\t|\tQuantity\t|\n";
    cout << "-----------------------------------------------------------------------------"
         << "--------------------------------------------\n";
    for (int i = 0; i < databaseBook.size(); i++) {

        cout << "|\t" << databaseBook[i].getId() << "\t|"
            << "\t\t" << databaseBook[i].getAuthor() << " \t\t|"
            << "\t\t" << databaseBook[i].getbookName() << "\t\t|"
            << "\t" << databaseBook[i].getQuantity() << "\t\t|";
        cout << "\n------------------------------------------------------------------"
            << "-------------------------------------------------------\n";
    }
}

/* 
 * Function: Library::option()
 * Description: Choose 2 options from the keyboard
 */
void Library::option () {

    int keyboard = 0;
    cout << "1: Borrow books\n2: Give book back\nSelect key: "; cin >> keyboard;
    if(keyboard == 1) borrowBook();
    else if(keyboard == 2) backBook();
    else {
        cout << "Error";
        return;
    }
    
}

/* 
 * Function: Library::borrowBook()
 * Description: Every time a book is successfully borrowed, 
 * the number of books in the library decreases by 1
 */
void Library::borrowBook () {

    uint16_t idBook = 0;
    cout << "ID book: "; cin >> idBook;
    for (int i = 0; i < databaseBook.size(); i++) {
        if(databaseBook[i].getId() == idBook) {

            cout << "\nBorrowing a successful book\n";
            /* reset the number of books */
            databaseBook[i].setQuantity(databaseBook[i].getQuantity() - 1);
            lishBook();

        }
    }
}

/* 
 * Function: Library::backBook()
 * Description: With each successful return, 
 * the number of books in the library increases by 1 .
 */
void Library::backBook () {

    uint16_t idBook = 0;
    cout << "ID book: "; cin >> idBook;
    for (int i = 0; i < databaseBook.size(); i++) {
        if(databaseBook[i].getId() == idBook) {

            cout << "\nSuccessful book return\n";
            /* reset the number of books */
            databaseBook[i].setQuantity(databaseBook[i].getQuantity() + 1);
            lishBook();

        }
    }

}


int main() {
    
    Book book1("Nam Cao", "Chi Pheo", 1);
    Book book2("Nguyen Du", "Truyen Kieu", 1);
    Book book3("Nam Cao", "Song Mon", 1);

    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.lishBook();
    library.option();

}

