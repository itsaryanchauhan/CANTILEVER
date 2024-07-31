#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int id;
    int quantity;
    double price;

public:
    Product();
    Product(std::string name, int id, int quantity, double price);
    std::string getName() const;
    int getId() const;
    int getQuantity() const;
    double getPrice() const;
    void setQuantity(int quantity);
    void setPrice(double price);
    void displayProduct() const;
};

#endif
