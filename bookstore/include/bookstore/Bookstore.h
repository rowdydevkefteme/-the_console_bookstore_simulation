#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <bookstore/Book.h>
#include <vector>

class Bookstore {
public:
    void addBook(Book book);
    void sellBook(std::string title);
    void displayInventory();
    void saveInventoryToFile();
    void loadInventoryFromFile();

private:
    std::vector<Book> inventory;
};

#endif