





#include <iostream>
#include <bookstore/Bookstore.h>
#include <bookstore/Book.h>

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add book to inventory\n";
    std::cout << "2. Sell book\n";
    std::cout << "3. Display inventory\n";
    std::cout << "4. Save inventory to file\n";
    std::cout << "5. Load inventory from file\n";
    std::cout << "6. Exit\n";
}

int main() {
    Bookstore store;

    store.loadInventoryFromFile();

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string title, author;
            int quantity;
            double price;

            std::cout << "Enter book title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cout << "Enter price: ";
            std::cin >> price;

            Book newBook(title, author, quantity, price);
            store.addBook(newBook);
            break;
        }
        case 2: {
            std::string title;
            std::cout << "Enter title of the book to sell: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            store.sellBook(title);
            break;
        }
        case 3:
            store.displayInventory();
            break;
        case 4:
            store.saveInventoryToFile();
            break;
        case 5:
            store.loadInventoryFromFile();
            break;
        case 6:
            std::cout << "Exiting program\n";
            break;
        default:
            std::cout << "Invalid choice, please try again\n";
        }
    } while (choice != 6);

    return 0;
}