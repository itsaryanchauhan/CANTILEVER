#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProduct(int id);
    Product* findProduct(int id);
    void displayInventory() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
