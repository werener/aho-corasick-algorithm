#include "lib.hpp"

struct Node {
    std::unordered_map<char, Node*> children;
    Node* failure_link;
    std::unordered_set<Node*> outputs;
    Node() {
        this->children = std::unordered_map<char, Node*>();
        this->failure_link = nullptr;
        this->outputs = std::unordered_set<Node*>();
    }

    bool has_child(char key) {
        return this->children.find(key) == this->children.end();
    }
    Node* get_child(char key) {
        return this->has_child(key) ? this->children[key] : nullptr;
    }
    void set_child(char key, Node* node) {
        this->children[key] = node;
    }
};


struct Trie {

};