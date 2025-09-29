#include "lib.hpp"

struct Node {
    std::unordered_map<char, Node*> children;
    Node* failure_link;
    std::unordered_set<string> dict_links;
    Node() {
        this->children = std::unordered_map<char, Node*>();
        this->failure_link = nullptr;
        this->dict_links = std::unordered_set<string>();
    }

    

    //  Children manipulation
    bool has_child(char key) {
        return (this->children.find(key) != this->children.end());
    }
    Node* get_child(char key) {
        return this->has_child(key) ? this->children[key] : nullptr;
    }
    void set_child(char key, Node* node) {
        this->children[key] = node;
    }

    //  Dictionary links
    void add_dict_link(string dict_link) {
        this->dict_links.insert(dict_link);
    }
    void copy_dict_links(Node* target) {
        for (string dict_link: target->dict_links)
            this->dict_links.insert(dict_link);    
    }
};


template<typename Collection>
class Trie {
protected:
    Node* Root;
    
    //  Add new pattern into the trie
    void add_pattern(string pattern) {
        Node *cur_node = Root;
        for (char key : pattern) {
            if (!(cur_node->has_child(key))) 
                cur_node->set_child(key, new Node());
            cur_node = cur_node->get_child(key);
        }
        cur_node->add_dict_link(pattern);
    }

    //  Create failure and dictionary links
    void InitializeLinks() {
        Node *cur_node;
        Root->failure_link = Root;
        std::queue<Node*> queue;

        for (const auto& [_, c] : Root->children) {
            c->failure_link = Root;
            queue.push(c);
        }

        while(!queue.empty()) {
            cur_node = queue.front();
            queue.pop();         
            for (const auto& [key, child] : cur_node->children) {
                queue.push(child);

            /*  
            Trace back the failure link by searching until we:
                a) Find the Node with (key) as a child
                b) Get into a root self-loop
            */
                Node* Traceback = cur_node->failure_link;
                while (!Traceback->has_child(key) && (Traceback != Root)) 
                    Traceback = Traceback->failure_link;
                

                child->failure_link = 
                Traceback->get_child(key) == nullptr 
                    ? Root 
                    : Traceback->get_child(key);    
                child->copy_dict_links(child->failure_link);
            }
        }
    }

public:
    Trie(Collection patterns) {
        this->Root = new Node();
        for (string pattern: patterns) 
            this->add_pattern(pattern);
        InitializeLinks();
    }

    //  Add new pattern for search (TBD)
    
};