#include <iostream>
#include <queue>

int main() {
    std::queue<int> values;
    int count;

    std::cout << "How many elements are in the queue? ";
    if (!(std::cin >> count) || count < 0) {
        std::cerr << "Please enter a non-negative number.\n";
        return 1;
    }

    std::cout << "Enter " << count << " integer(s): ";
    for (int i = 0; i < count; ++i) {
        int value;
        if (!(std::cin >> value)) {
            std::cerr << "Invalid queue element.\n";
            return 1;
        }
        values.push(value);
    }

    int target;
    std::cout << "Enter the element to delete: ";
    if (!(std::cin >> target)) {
        std::cerr << "Invalid element to delete.\n";
        return 1;
    }

    std::queue<int> remaining;
    bool deleted = false;
    while (!values.empty()) {
        const int value = values.front();
        values.pop();

        if (value == target && !deleted) {
            deleted = true;
        } else {
            remaining.push(value);
        }
    }

    if (!deleted) {
        std::cout << target << " was not found in the queue.\n";
    } else {
        std::cout << "The first occurrence of " << target << " was deleted.\n";
    }

    std::cout << "Queue (front to back): ";
    if (remaining.empty()) {
        std::cout << "(empty)";
    } else {
        while (!remaining.empty()) {
            std::cout << remaining.front();
            remaining.pop();
            if (!remaining.empty()) {
                std::cout << ' ';
            }
        }
    }
    std::cout << '\n';

    return 0;
}