#include "Trie.hpp"

int main() {
    Trie t = Trie(std::vector<string>{"1234", "228", "1337"});
    // auto test = std::unordered_map<char, int>();
    t.print();
}