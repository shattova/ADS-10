// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include  <iostream>
#include <vector>


class Tree {
 private:
    struct Node {
        bool isRoot = false;
        char value;
        std::vector<Node*> Nvect;
    };
    Node* root;
    std::vector<std::vector<char>> permutes;
    void findPermutes(Node* root, std::vector<char> CHvect) {
        if (!root->isRoot)
            CHvect.push_back(root->value);
        if (root->Nvect.empty()) {
            permutes.push_back(CHvect);
        } else {
            for (Node* child : root->Nvect) {
                findPermutes(child, CHvect);
            }
        }
    }
    void insert(Node* root, const std::vector<char>& CHvect) {
        for (char ch : CHvect) {
            Node* tmpl = new Node;
            tmpl->value = ch;
            root->Nvect.push_back(tmpl);
            std::vector<char> Chars(CHvect);
            Chars.erase(std::find(Chars.begin(), \
                Chars.end(), ch));
            insert(tmpl, Chars);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vect) {
        root = new Node;
        root->isRoot = true;
        insert(root, vect);
        std::vector<char> data;
        findPermutes(root, data);
    }
    std::vector<std::vector<char>> getAllPermutes() const {
        return permutes;
    }
};
#endif  // INCLUDE_TREE_H_
