#include "test_runner.h"
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;


struct Node {
    Node(int v, Node* p)
            : value(v)
            , parent(p)
    {}

    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent;
};


class NodeBuilder {
public:
    Node* CreateRoot(int value) {
        nodes.emplace_back(value, nullptr);
        return &nodes.back();
    }

    Node* CreateLeftSon(Node* me, int value) {
        assert( me->left == nullptr );
        nodes.emplace_back(value, me);
        me->left = &nodes.back();
        return me->left;
    }

    Node* CreateRightSon(Node* me, int value) {
        assert( me->right == nullptr );
        nodes.emplace_back(value, me);
        me->right = &nodes.back();
        return me->right;
    }

private:
    deque<Node> nodes;
};

Node* Next(Node* me) {
    if (me->right != nullptr) {
        auto buf = me->right;
        while (buf->left != nullptr) {
            buf = buf->left;
        }
        return buf;
    }
    // no parent no right
    if (me->parent == nullptr) {
        return nullptr;
    }
    // is parent's left side
    if (me->parent->left == me) {
        return me->parent;
    }
    // is parent's right side
    auto buf = me->parent;
    while (buf->parent != nullptr && buf->parent->right == buf) {
        buf = buf->parent;
    }
    return buf->parent;
}