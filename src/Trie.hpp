#include "lib.hpp"

#define string string


struct Node {
    std::unordered_map<char, Node> children;
    Node* failure_link;
    std::unordered_set<string> outputs;
    Node() {
        this->children = std::unordered_map<char, Node>();
        this->failure_link = nullptr;
        this->outputs = std::unordered_set<string>();
    }

    bool has_child(char key) {
        return this->children.find(key) == this->children.end();
    }
    Node* get_child(char key) {
        return this->has_child(key) ? &(this->children[key]) : nullptr;
    }
    void set_child(char key, Node node) {
        this->children[key] = node;
    }

    void add_output(string output) {
        this->outputs.insert(output);
    }
    void copy_outputs(Node* target) {
        for (string output: target->outputs)
            this->outputs.insert(output);
    }
};


struct Trie {
    Node root;

    void insert(string pattern) {
        Node cur_node = this->root;
        for (char key : pattern) {
            if (!cur_node.has_child(key)) 
                cur_node.set_child(key, Node());
            cur_node = *cur_node.get_child(key);
        }
        cur_node.add_output(pattern);
    }

    template<typename Collection>
    Trie(Collection patterns) {
        this->root = Node();
        for (string pattern: patterns) 
            this->insert(pattern);
    }
};