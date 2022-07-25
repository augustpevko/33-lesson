#include <iostream>
#include <array>

template<typename T>
void input(std::array<T, 10>& arr) {
    for (auto &a: arr) {
        std::cout << "Input digit: ";
        std::cin >> a;
    }
}

template<typename T>
T avg(std::array<T, 10>& arr) {
    T size = arr.size();
    T sum = T();
    for (auto a: arr) {
        sum += a;
    }
    return sum / size;
}

int main() {
    std::array<double, 10> arr;
    input(arr);
    std::cout << avg(arr);
}