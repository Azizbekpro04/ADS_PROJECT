#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::pair<std::string, int>> MapReduce(const std::vector<std::string>& input) {
    std::map<std::string, int> intermediate;

    for (const std::string& word : input) {
        intermediate[word]++;
    }

    std::vector<std::pair<std::string, int>> result;
    std::copy(intermediate.begin(), intermediate.end(), std::back_inserter(result));

    return result;
}

int main() {
    std::vector<std::string> input = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    std::vector<std::pair<std::string, int>> output = MapReduce(input);

    for (const auto& pair : output) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
