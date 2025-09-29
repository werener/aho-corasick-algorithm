#include "lib.hpp"

#define output_type string


struct Node {
    std::unordered_map<char, Node*> children;
    Node* failure_link;
    std::unordered_set<output_type> outputs;
    Node() {
        this->children = std::unordered_map<char, Node*>();
        this->failure_link = nullptr;
        this->outputs = std::unordered_set<output_type>();
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

    void add_output(output_type output) {
        this->outputs.insert(output);
    }
    void copy_outputs(Node* target) {
        for (output_type output: target->outputs)
            this->outputs.insert(output);
    }
};

template<typename Collection>
struct Trie {
    Node root;
    Trie(Collection patterns) {
        this->root = Node();
        for (string pattern: patterns) {

        }
    }
};