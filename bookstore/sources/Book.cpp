





#include <bookstore/Book.h>


Book::Book(std::string title, std::string author, int quantity, double price)
    : title(title), author(author), quantity(quantity), price(price) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getQuantity() const {
    return quantity;
}

double Book::getPrice() const {
    return price;
}