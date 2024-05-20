#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

struct Product {
    int productID, quantity;
    string name, brand, description, size, color;
    double price;
    Product* next;
};

Product* cart = NULL;

void viewProducts();
void displayMenu();
void addProduct();
void viewCart();
void removeProduct();
void checkout();
void clearCart();

int main() {
    int option;

    while (true) {
        displayMenu();
        cout << "Option: ";
        cin >> option;

        switch (option) {
            case 1:
                viewProducts();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                checkout();
                break;
            case 6:
                clearCart();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid option. Please choose a valid option.";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nAlibaba" << endl;
    cout << "[1] View Products" << endl;
    cout << "[2] Add Product to Cart" << endl;
    cout << "[3] View Cart" << endl;
    cout << "[4] Remove Product from Cart" << endl;
    cout << "[5] Checkout" << endl;
    cout << "[6] Clear Cart" << endl;
    cout << "[7] Exit" << endl;
}

void viewProducts() {
    cout << "Alibaba" << endl;
    cout << " ID    Name                Brand           Description         Price " << endl;
    cout << " 01    Men's Shirt         Uniqlo          Crew Neck             ₱400 " << endl;
    cout << " 02    Women's Shirt       Uniqlo          Crew Neck             ₱600 " << endl;
    cout << " 03    Unisex Jacket       Levi's          Hoodie                ₱800 " << endl;
    cout << " 04    Shades              Rayban          Chromatic            ₱2500 " << endl;
    cout << " 05    Cellphone           Samsung         S20                 ₱9999 " << endl;
    cout << " 06    Cellphone           Iphone          15 Pro Max             ₱25 " << endl;
}

void addProduct() {
    Product* newProduct = new Product;

    cout << "Enter Product ID: ";
    cin >> newProduct->productID;

    while (newProduct->productID <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid product ID. Please enter a positive integer." << endl;
        cout << "Enter Product ID: ";
        cin >> newProduct->productID;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newProduct->name);

    cout << "Enter Brand: ";
    getline(cin, newProduct->brand);

    cout << "Enter Description: ";
    getline(cin, newProduct->description);
    
    cout << "Enter Size: ";
    cin >> newProduct->size;

    cout << "Enter Color: ";
    cin >> newProduct->color;

    cout << "Enter Price: ";
    cin >> newProduct->price;

    while (newProduct->price <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid price. Please enter a positive number." << endl;
        cout << "Enter Price: ";
        cin >> newProduct->price;
    }

    cout << "Enter Quantity: ";
    cin >> newProduct->quantity;

    while (newProduct->quantity <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid quantity. Please enter a positive integer." << endl;
        cout << "Enter Quantity: ";
        cin >> newProduct->quantity;
    }

    if (cart == nullptr || newProduct->productID < cart->productID) {
        newProduct->next = cart;
        cart = newProduct;
    } else {
        Product* current = cart;
        while (current->next != nullptr && newProduct->productID > current->next->productID) {
            current = current->next;
        }
        newProduct->next = current->next;
        current->next = newProduct;
    }

    cout << "Product added to the cart successfully." << endl;
}


void viewCart() {
    if (cart == nullptr) {
        cout << "Your cart is empty." << endl;
        return;
    }

    Product* current = cart;
    
    while (current != nullptr) {
    cout << "\nYour Shopping Cart: " << endl;
    cout << "ID |  " << current ->productID << endl;
    cout << "Name |  " << current->name << endl;
    cout << "Brand |  " << current->brand << endl;
    cout << "Description |  " << current->description << endl;
    cout << "Size |  " << current->size << endl;
    cout << "Color |  " << current->color << endl;
    cout << "Price |  " << current->price << endl;
    cout << "Quantity |  " << current->quantity << endl;
    
    current = current->next;
}
}

void removeProduct() {
    if (cart == NULL) {
        cout << "Cart is empty. Nothing to remove." << endl;
        return;
    }

    int productID;
    cout << "Enter Product ID to remove: ";
    cin >> productID;

    Product* current = cart;
    Product* prev = NULL;
    bool found = false;

    while (current != NULL) {
        if (current->productID == productID) {
            if (prev == NULL) {
                cart = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;
            cout << "Product removed from the cart successfully." << endl;
            found = true;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        cout << "Product not found in the cart." << endl;
    }
}

void checkout() {
    
    Product* current = cart;
    int itemCount = 0;
    double totalCost = 0.0;
    
    if (cart == nullptr) {
        cout << "Your cart is empty. Please add products before checking out." << endl;
        return;
    }

    while (current != nullptr) {
    cout << "\nYour Shopping Cart: " << endl;
    cout << "ID |  " << current ->productID << endl;
    cout << "Name |  " << current->name << endl;
    cout << "Brand |  " << current->brand << endl;
    cout << "Description |  " << current->description << endl;
    cout << "Size |  " << current->size << endl;
    cout << "Color |  " << current->color << endl;
    cout << "Price |  " << current->price << endl;
    cout << "Quantity |  " << current->quantity << endl << endl;
    
    totalCost += current->price * current->quantity;
    itemCount += current->quantity;

    current = current->next;
}

    cout << "Total Cost: " << totalCost << endl;
    cout << "Items in Cart: " << itemCount << endl;\
    clearCart();
}

void clearCart() {
    while (cart != NULL) {
        Product* temp = cart;
        cart = cart->next;
        delete temp;
    }

    cout << "Cart cleared successfully." << endl;
}