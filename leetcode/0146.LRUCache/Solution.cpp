#include "../../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node()
        : val(0), next(nullptr), prev(nullptr) {
    }
    Node(int x)
        : val(x), next(nullptr), prev(nullptr) {
    }
    Node(int x, Node* next, Node* prev)
        : val(x), next(next), prev(prev) {
    }
};

ostream& operator<<(ostream& os, const Node* head) {
    while (head) {
        os << head->val << " ";
        head = head->next;
    }
    return os;
}

class LRUCache {
  public:
    int capacity, size;
    Node *head, *tail;
    map<int, int> kv_map;
    map<int, Node*> p_map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = new Node;
        this->tail = new Node;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        if (this->p_map.find(key) != this->p_map.end()) {
            this->swim(key);
            return this->kv_map[key];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        // not exist
        if (this->p_map.find(key) == this->p_map.end()) {
            // create node
            Node* p = new Node(key);
            this->p_map[key] = p;
            this->add_to_head(p);

            // check size
            this->size++;
            if (this->size > this->capacity) {
                this->kv_map.erase(tail->prev->val);
                this->p_map.erase(tail->prev->val);
                Node* last = tail->prev;
                tail->prev = last->prev;
                cout << (last->prev == nullptr) << endl;
                last->prev->next = tail;
                delete last;
                this->size--;
            }
        } else {
            this->swim(key);
        }
        this->kv_map[key] = value;
    }

    void swim(int key) {
        Node* p = this->p_map[key];
        p->prev->next = p->next;
        p->next->prev = p->prev;
        this->add_to_head(p);
    }

    void add_to_head(Node* p) {
        p->next = head->next;
        head->next->prev = p;
        p->prev = head;
        head->next = p;
    }
};

int main() {
    LRUCache* cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);      // 返回  1
    cache->put(3, 3);   // 该操作会使得关键字 2 作废
    cache->get(2);      // 返回 -1 (未找到)
    cache->put(4, 4);   // 该操作会使得关键字 1 作废
    cache->get(1);      // 返回 -1 (未找到)
    cache->get(3);      // 返回  3
    cache->get(4);      // 返回  4
    return 0;
}
