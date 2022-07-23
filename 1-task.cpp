#include <iostream>
#include <exception>
#include <string>
#include <map>

class Store {
    std::map<std::string, int> storage;

public:
    void fillingStorage(std::string& key_item, int& value_itemCount) {
        if (storage.find(key_item) != storage.end()) 
            throw std::invalid_argument("such a key already exists");

        if (value_itemCount < 0) 
            throw std::invalid_argument("negative count");

        storage[key_item] = value_itemCount;
    }
    void addItem(std::string& key_item, int& value_itemCountAdd) {
        if (storage.find(key_item) == storage.end()) 
            throw std::invalid_argument("such a key doesn't exist");

        if (value_itemCountAdd < 0)
            throw std::invalid_argument("negative count");

        storage[key_item] += value_itemCountAdd;
    }
    void removeItem(std::string& key_item, int& value_itemCountRemove) {
        if (storage.find(key_item) == storage.end()) 
            throw std::invalid_argument("such a key doesn't exist");

        if (value_itemCountRemove < 0) 
            throw std::invalid_argument("negative count");

        if (value_itemCountRemove > storage[key_item]) 
            throw std::invalid_argument("the count to be removed cannot exceed the count in storage");

        storage[key_item] -= value_itemCountRemove;
    }
};

int main() {
    Store store;

    std::string key_item;
    while (key_item != "end") {
        std::cout << "Input item number: ";
        std::cin >> key_item;
        if (key_item == "end")
            continue;
        int value_itemCount;
        std::cout << "Input count of item: ";
        std::cin >> value_itemCount;
        try {
            store.fillingStorage(key_item, value_itemCount);
        }
        catch (const std::invalid_argument& x) {
            std::cerr << x.what() << std::endl;
        }
    }
    while (key_item != "exit") {
        std::cout << "Input item number: ";
        std::cin >> key_item;
        if (key_item == "exit")
            continue;
        std::string answer;
        std::cout << "Input add or remove: ";
        std::cin >> answer;
        if (answer == "add") {
            int value_itemCountAdd;
            std::cout << "Input count to add: ";
            std::cin >> value_itemCountAdd;
            try {
                store.addItem(key_item, value_itemCountAdd);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << x.what() << std::endl;
            }
        }
        else if (answer == "remove") {
            int value_itemCountRemove;
            std::cout << "Input count to remove: ";
            std::cin >> value_itemCountRemove;
            try {
                store.removeItem(key_item, value_itemCountRemove);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << x.what() << std::endl;
            }
        }
    }
}

/*
В начале программы вы заполняете базу данных самого магазина через стандартную консоль. 
Каждый элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
Корзина должна поддерживать следующие операции: добавление товара с указанным его 
количеством — add, удаление товара с указанным количеством — remove. Обе операции 
принимают артикул товара в виде строки и количество в виде целого числа.
При вводе аргументов к операциям должна осуществляться их валидация. 
Артикул должен быть в базе данных магазина, количество не должно 
превышать количество доступного продукта на складе (при удалении — в корзине).
*/