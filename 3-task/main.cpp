#include <iostream>
#include <vector>
#include <string>

template <typename K, typename V>
struct MyPair {
    K key;
    V value;
    MyPair(K inKey, V inValue): key(inKey), value(inValue) {} 
};

template <typename T1, typename T2>
class MyMap {
    std::vector<MyPair<T1, T2>> myMultiMap;
public:
    void add(T1 inKey, T2 inValue) {
        MyPair<T1, T2> myPair(inKey, inValue);
        myMultiMap.push_back(myPair);
    }
    void remove(T1 inKey) {
        for (auto it = myMultiMap.begin(); it < myMultiMap.end(); it++) {
            if (it->key == inKey) {
                myMultiMap.erase(it);
            }
        }
    }
    void print() const {
        for (auto mm: myMultiMap) {
            std::cout << mm.key << ": " << mm.value << std::endl;
        }
    }
    void find(T1 inKey) const {
        for (auto mm: myMultiMap) {
            if (mm.key == inKey) {
                std::cout << mm.value << std::endl;
            }
        }
    }
};

int main() {
    MyMap<double, std::string> myMap;
    myMap.add(0.0f, "somevalue");
    myMap.add(1.0f, "somedifferentvalue");

    myMap.print();
    myMap.remove(1.0f);
    myMap.print();

    myMap.find(0.0f);
}

/*
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные 
типы значений по ключам произвольного типа. Ключи при этом могут повторяться.
Реестр должен поддерживать следующие операции: добавление элемента с ключом, 
удаление элементов с заданным ключом, вывод всех значений с ключами в консоль, поиск элементов по ключу.
Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли: 
add — добавить элемент с ключом;
remove — удалить все элементы с заданным ключом;
print — напечатать на экране все элементы с их ключами;
find — найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.
*/