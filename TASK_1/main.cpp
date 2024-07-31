#include <iostream>
#include "Inventory.h"

void showMenu() {
    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Remove Product\n";
    std::cout << "3. Display Inventory\n";
    std::cout << "4. Save Inventory to File\n";
    std::cout << "5. Load Inventory from File\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Inventory inventory;
    int choice;
    std::string filename;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int id, quantity;
                double price;
                std::cout << "Enter Product ID: ";
                std::cin >> id;
                std::cout << "Enter Product Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cout << "Enter Price: ";
                std::cin >> price;
                inventory.addProduct(Product(name, id, quantity, price));
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Product ID to Remove: ";
                std::cin >> id;
                inventory.removeProduct(id);
                break;
            }
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                inventory.saveToFile(filename);
                break;
            case 5:
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                inventory.loadFromFile(filename);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
