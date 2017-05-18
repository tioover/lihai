#pragma once

using Elem = int;


static SplayNode* null_node = new SplayNode(0);


class SplayNode {
    static SplayNode* single_rotate_with_left(SplayNode* a) {
        SplayNode* b = a->left;
        a->left = b->right;
        b->right = a;
        return b;
    };
    static SplayNode* single_rotate_with_right(SplayNode* a) {
        SplayNode* b = a->right;
        a->right = b->left;
        b->left = a;
        return b;
    };
public:
    Elem elem;
    SplayNode* left;
    SplayNode* right;

    SplayNode(Elem x) {
        elem = x;
        left = null_node;
        right = null_node;
    }

    SplayNode* splay(Elem x) {
        static SplayNode work(0);
        SplayNode *left_tree_max, *right_tree_min;

        work.left = work.right = null_node;
        left_tree_max = right_tree_min = &work;
        null_node->elem = x;

        SplayNode* now = this;

        while (x != now->elem) {
            if (x < now->elem) {
                if (x < now->left->elem) { now = single_rotate_with_left(now); }
                if (now->left == null_node) { break; }
                /* Link right */
                right_tree_min->left = now;
                right_tree_min = now;
                now = now->left;
            }
            else {
                if (x > now->right->elem) { now = single_rotate_with_right(now); }
                if (now->right == null_node) { break; }
                /* Link left */
                left_tree_max->right = now;
                left_tree_max = now;
                now = now->right;
            }

        }

        left_tree_max->right = now->left;
        right_tree_min->left = now->right;
        now->left = work.right;
        now->right = work.left;
        return now;
    }
};
