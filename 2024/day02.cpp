#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

bool check_safety(const std::vector<int>& report) {
    bool asc, desc;
    int diff;

    asc = std::is_sorted(report.begin(), report.end());
    desc = std::is_sorted(report.rbegin(), report.rend());
    if (!asc && !desc) return false;
    else {
        for (int i = 1; i < report.size(); i++) {
            diff = std::abs(report.at(i) - report.at(i - 1));
            if (diff == 0 || diff > 3)
                return false;
        }
    }
    
    return true;
}

int main() {
    std::string report_string;
    std::vector<int> report, new_report;
    bool safe;

    int level;
    int safe_count = 0;
    
    // One line at a time
    while (std::getline(std::cin, report_string)) {
        std::istringstream iss(report_string);

        // One number at a time
        report.clear();
        while (iss >> level) {
            report.push_back(level);
        }

        // Part 1
        // safe_count += check_safety(report);

        // Part 2
        safe = check_safety(report);
        if (safe) safe_count += 1;
        else {
            for (int i = 0; i < report.size(); i++) {
                new_report = report;
                new_report.erase(new_report.begin() + i);
                if (check_safety(new_report)) { safe_count += 1; break; }
            }
        }
    }
    std::cout << safe_count << std::endl;
}
