#include "Inventory.h"
#include <fstream>
#include <iostream>

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

void Inventory::removeProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return;
        }
    }
}

Product* Inventory::findProduct(int id) {
    for (auto& product : products) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

void Inventory::displayInventory() const {
    for (const auto& product : products) {
        product.displayProduct();
        std::cout << "----------------------" << std::endl;
    }
}

void Inventory::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& product : products) {
            outFile << product.getId() << "\n"
                    << product.getName() << "\n"
                    << product.getQuantity() << "\n"
                    << product.getPrice() << "\n";
        }
        outFile.close();
    }
}

void Inventory::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        products.clear();
        int id, quantity;
        double price;
        std::string name;
        while (inFile >> id) {
            inFile.ignore();
            std::getline(inFile, name);
            inFile >> quantity >> price;
            inFile.ignore();
            products.push_back(Product(name, id, quantity, price));
        }
        inFile.close();
    }
}
