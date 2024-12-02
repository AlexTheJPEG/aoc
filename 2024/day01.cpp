#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> first_list, second_list;
    int a, b;

    while (std::cin >> a >> b) {
        first_list.push_back(a);
        second_list.push_back(b);
    }

    std::sort(first_list.begin(), first_list.end());
    std::sort(second_list.begin(), second_list.end());

    // Part 1
    int sum = 0;
    for (int i = 0; i < first_list.size(); i++) 
        sum += std::abs(first_list.at(i) - second_list.at(i));
    std::cout << sum << std::endl;
    
    // Part 2
    sum = 0;
    int occurrences;
    for (int i = 0; i < first_list.size(); i++) {
        occurrences = std::count(second_list.begin(), second_list.end(), first_list.at(i));
        sum += first_list.at(i) * occurrences;
    }
    std::cout << sum << std::endl;
}
