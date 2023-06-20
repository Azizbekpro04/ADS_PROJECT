#include <iostream>
#include <vector>
#include <map>

std::map<std::string, int> mapFunction(const std::vector<std::string>& words) {
    std::map<std::string, int> intermediateResult;
    
    for (const std::string& word : words) {
        intermediateResult[word]++;
    }
    
    return intermediateResult;
}

std::map<std::string, int> reduceFunction(const std::vector<std::map<std::string, int>>& intermediateResults) {
    std::map<std::string, int> finalResult;
    
    for (const auto& intermediateResult : intermediateResults) {
        for (const auto& pair : intermediateResult) {
            finalResult[pair.first] += pair.second;
        }
    }
    
    return finalResult;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    
    int chunkSize = words.size() / 2;
    
    std::vector<std::map<std::string, int>> intermediateResults;
    
    for (int i = 0; i < words.size(); i += chunkSize) {
        std::vector<std::string> chunk(words.begin() + i, words.begin() + i + chunkSize);
        intermediateResults.push_back(mapFunction(chunk));
    }
    
    std::map<std::string, int> finalResult = reduceFunction(intermediateResults);
    
    for (const auto& pair : finalResult) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
