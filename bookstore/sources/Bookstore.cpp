#include <bookstore/Bookstore.h>
#include <iostream>
#include <fstream>

void Bookstore::addBook(Book book) {
    inventory.push_back(book);
}

void Bookstore::sellBook(std::string title) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getTitle() == title) {
            inventory.erase(it);
            std::cout << "Book \"" << title << "\" sold\n";
            return;
        }
    }

    std::cout << "Book not found in inventory\n";
}

void Bookstore::displayInventory() {
    std::cout << "Inventory:\n";
    for (const auto& book : inventory) {
        std::cout << book.getTitle() << " by " << book.getAuthor() << " - " << book.getQuantity() << " in stock, price: $" << book.getPrice() << std::endl;
    }
}

void Bookstore::saveInventoryToFile() {
    std::ofstream file("data/inventory.dat", std::ios::binary);
    for (const auto& book : inventory) {
        file.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    file.close();
}

void Bookstore::loadInventoryFromFile() {
    inventory.clear();
    std::ifstream file("data/inventory.dat", std::ios::binary);
    while (!file.eof()) {
        Book book("", "", 0, 0.0);
        if (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            inventory.push_back(book);
        }
    }
    file.close();
}