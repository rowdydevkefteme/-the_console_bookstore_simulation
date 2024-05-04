#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(std::string title, std::string author, int quantity, double price);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getQuantity() const;
    double getPrice() const;

private:
    std::string title;
    std::string author;
    int quantity;
    double price;
};

#endif