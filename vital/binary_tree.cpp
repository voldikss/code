#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : left(nullptr), right(nullptr) {
    }
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
};

// use stack(bfs) to create a binary tree
TreeNode *build_binary_tree(const vector<variant<int, nullptr_t>> &nodes) {
    auto &x = nodes[0];
    if (auto n = std::get_if<nullptr_t>(&x)) return nullptr;

    queue<TreeNode *> q;
    TreeNode *tree = new TreeNode(-1);
    tree->left = new TreeNode(get<int>(nodes[0]));
    q.push(tree->left);
    int i = 1;
    while (i < nodes.size()) {
        if (q.empty()) break;
        TreeNode *node = q.front();
        q.pop();

        auto &x = nodes[i++];
        if (auto n = std::get_if<int>(&x)) {
            node->left = new TreeNode(*n);
            q.push(node->left);
        }

        if (i >= nodes.size()) break;

        auto &y = nodes[i++];
        if (auto n = std::get_if<int>(&y)) {
            node->right = new TreeNode(*n);
            q.push(node->right);
        }
    }
    return tree->left;
}

TreeNode *find_min(TreeNode *t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->left == nullptr) {
        return t;
    } else {
        return find_min(t->left);
    }
}

TreeNode *find_max(TreeNode *t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->right == nullptr) {
        return t;
    } else {
        return find_max(t->right);
    }
}

TreeNode *find(int elem, TreeNode *t) {
    if (t == nullptr) {
        return nullptr;
    }

    if (elem < t->val) {
        return find(elem, t->left);
    } else if (elem > t->val) {
        return find(elem, t->right);
    } else {
        return t;
    }
}

//Insert i into the tree t, duplicate will be discarded
//Return a pointer to the resulting tree.
TreeNode *insert(int value, TreeNode *t) {
    TreeNode *new_node;

    if (t == nullptr) {
        new_node = new TreeNode;
        if (new_node == nullptr) {
            return t;
        }

        new_node->val = value;

        new_node->left = new_node->right = nullptr;
        return new_node;
    }

    if (value < t->val) {
        t->left = insert(value, t->left);
    } else if (value > t->val) {
        t->right = insert(value, t->right);
    } else {
        //duplicate, ignore it
        return t;
    }
    return t;
}

TreeNode *destroy(int value, TreeNode *t) {
    //Deletes node from the tree
    // Return a pointer to the resulting tree
    TreeNode *x;
    TreeNode *tmp_cell;

    if (t == nullptr) return nullptr;

    if (value < t->val) {
        t->left = destroy(value, t->left);
    } else if (value > t->val) {
        t->right = destroy(value, t->right);
    } else if (t->left && t->right) {
        tmp_cell = find_min(t->right);
        t->val = tmp_cell->val;
        t->right = destroy(t->val, t->right);
    } else {
        tmp_cell = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete tmp_cell;
    }

    return t;
}

//printing tree in ascii

struct asciinode {
    asciinode *left, *right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int lablen;

    //-1=I am left, 0=I am root, 1=right
    int parent_dir;

    //max supported unit32 in dec, 10 digits max
    char label[11];
};

#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1 << 20)

//adjust gap between left and right nodes
int gap = 3;

//used for printing next node in the same level,
//this is the x coordinate of the next char printed
int print_next;

asciinode *build_ascii_tree_recursive(TreeNode *t) {
    asciinode *node = new asciinode;

    if (t) {
        node->left = build_ascii_tree_recursive(t->left);
        node->right = build_ascii_tree_recursive(t->right);

        if (node->left) node->left->parent_dir = -1;
        if (node->right) node->right->parent_dir = 1;

        sprintf(node->label, "%d", t->val);
    } else {
        sprintf(node->label, "%s", "#");
    }
    node->lablen = strlen(node->label);
    return node;
}

//Copy the tree into the ascii node structre
asciinode *build_ascii_tree(TreeNode *t) {
    asciinode *node;
    if (t == nullptr) return nullptr;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

void free_ascii_tree(asciinode *node) {
    if (node == nullptr) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    delete node;
}

void compute_lprofile(asciinode *node, int x, int y) {
    int i, isleft;
    if (node == nullptr) return;
    isleft = (node->parent_dir == -1);
    lprofile[y] = min(lprofile[y], x - ((node->lablen - isleft) / 2));
    if (node->left != nullptr) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            lprofile[y + i] = min(lprofile[y + i], x - i);
        }
    }
    compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_rprofile(asciinode *node, int x, int y) {
    int i, notleft;
    if (node == nullptr) return;
    notleft = (node->parent_dir != -1);
    rprofile[y] = max(rprofile[y], x + ((node->lablen - notleft) / 2));
    if (node->right != nullptr) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            rprofile[y + i] = max(rprofile[y + i], x + i);
        }
    }
    compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_edge_lengths(asciinode *node) {
    int h, hmin, i, delta;
    if (node == nullptr) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    /* first fill in the edge_length of node */
    if (node->right == nullptr && node->left == nullptr) {
        node->edge_length = 0;
    } else {
        if (node->left != nullptr) {
            for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++) {
                rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        } else {
            hmin = 0;
        }
        if (node->right != nullptr) {
            for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++) {
                lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = min(node->right->height, hmin);
        } else {
            hmin = 0;
        }
        delta = 4;
        for (i = 0; i < hmin; i++) {
            delta = max(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }

        //If the node has two children of height 1, then we allow the
        //two leaves to be within 1, instead of 2
        if (((node->left != nullptr && node->left->height == 1) ||
             (node->right != nullptr && node->right->height == 1)) &&
            delta > 4) {
            delta--;
        }

        node->edge_length = ((delta + 1) / 2) - 1;
    }

    //now fill in the height of node
    h = 1;
    if (node->left != nullptr) {
        h = max(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != nullptr) {
        h = max(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level) {
    int i, isleft;
    if (node == nullptr) return;
    isleft = (node->parent_dir == -1);
    if (level == 0) {
        for (i = 0; i < (x - print_next - ((node->lablen - isleft) / 2)); i++) {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    } else if (node->edge_length >= level) {
        if (node->left != nullptr) {
            for (i = 0; i < (x - print_next - (level)); i++) {
                printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != nullptr) {
            for (i = 0; i < (x - print_next + (level)); i++) {
                printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left,
                    x - node->edge_length - 1,
                    level - node->edge_length - 1);
        print_level(node->right,
                    x + node->edge_length + 1,
                    level - node->edge_length - 1);
    }
}

// prints ascii tree for given Tree structure
// from https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
void print_ascii_tree(TreeNode *t) {
    asciinode *proot;
    int xmin, i;
    if (t == nullptr) return;
    proot = build_ascii_tree(t);
    compute_edge_lengths(proot);
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        xmin = min(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT) {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    free_ascii_tree(proot);
}
