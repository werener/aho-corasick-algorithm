#include "lib.hpp"


struct Node {
    std::unordered_map<char, Node*> children;
    Node* failure_link;
    std::unordered_set<string> outputs;
    Node() {
        this->children = std::unordered_map<char, Node*>();
        this->failure_link = nullptr;
        this->outputs = std::unordered_set<string>();
    }

    bool has_child(char key) {
        return (this->children.find(key) != this->children.end());
    }
    Node* get_child(char key) {
        return this->has_child(key) ? this->children[key] : nullptr;
    }
    void set_child(char key, Node* node) {
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
    Node* root;
    
    
    void insert(string pattern) {
        Node *cur_node = this->root;
        // std::cout << pattern << std::endl;
        for (char key : pattern) {
            // std::cout << key << "->";
            // std::flush(std::cout);
            if (!(cur_node->has_child(key))) {
                cur_node->set_child(key, new Node());
            }
            cur_node = cur_node->get_child(key);
        }
        // std::cout << std::endl;
        cur_node->add_output(pattern);
        cur_node = this->root;
    }

    void print() {
        for (const auto& [key, child] : this->root->children) {
            std::flush(std::cout);
        }
        std::cout << this->root->children.size();
        std::cout << "\n";
    }
    
    template<typename Collection>
    Trie(Collection patterns) {
        this->root = new Node();
        // (this->root).failure_link = &(this->root);
        for (string pattern: patterns) 
            this->insert(pattern);
    }


};