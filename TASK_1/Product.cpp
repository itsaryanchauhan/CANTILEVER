#include "Product.h"
#include <iostream>

Product::Product() : name(""), id(0), quantity(0), price(0.0) {}

Product::Product(std::string name, int id, int quantity, double price) 
    : name(name), id(id), quantity(quantity), price(price) {}

std::string Product::getName() const {
    return name;
}

int Product::getId() const {
    return id;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::displayProduct() const {
    std::cout << "Product ID: " << id << std::endl;
    std::cout << "Product Name: " << name << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Price: " << price << std::endl;
}
