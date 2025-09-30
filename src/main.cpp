#include "Trie.hpp"

int main() {
    Trie t = Trie(std::vector<string>{"anus", "anal", "penis", "islam"});
    // auto test = std::unordered_map<char, int>();
    // t.print(t.root);
    
    std::vector<entry> a = t.search("anuslampenislamanalkal");
    for (entry b: a)
        std::cout << std::get<1>(b) << "-" << std::get<2>(b) << ":\t" << std::get<0>(b) << std::endl; 
}