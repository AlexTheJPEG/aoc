#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string line, memory;
    std::regex mul_exp ("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::regex dont_do ("don't\\(\\).*?do\\(\\)");
    std::regex_token_iterator<std::string::iterator> rend;
    int submatches[] = {1, 2};
    int x, y;
    int result = 0;

    while (std::getline(std::cin, line)) {
        memory += line;
    }

    // Comment line below for part 1, uncomment for part 2
    memory = std::regex_replace(memory, dont_do, "");

    std::regex_token_iterator<std::string::iterator> matches (memory.begin(), memory.end(), mul_exp, submatches);
    //std::cout << memory << "\n";
    while (matches != rend) {
        x = std::stoi(*matches++);
        y = std::stoi(*matches++);
        result += x * y;
        //std::cout << "mul(" << x << ", " << y << ") = " << x * y << "\n";
    }
    //std::cout << "\n";
    std::cout << result << "\n";
}
