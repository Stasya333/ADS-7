// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
 private:
    struct Item {
        T val;
        Item* next;
    };
    Item* head;
    Item* create(const T& val) {
        Item* tmp = new Item;
        tmp->val = val;
        tmp->next = nullptr;
        return tmp;
    }

 public:
    TPQueue() : head(nullptr) {}
    void push(const T& val) {
        if (head == nullptr) {
            head = create(val);
        } else {
            Item* cur = head;
            int ind = 0;
            while (cur) {
                if (cur->val.prior < val.prior) {
                    break;
                }
                ind++;
                cur = cur->next;
            }
            if (ind == 0) {
                Item* tmp = new Item;
                tmp->val = val;
                tmp->next = head;
                head = tmp;
            } else {
            cur = head;
            for (int j = 0; j < ind - 1; j++) {
                cur = cur->next;
            }
            Item* tmp = new Item;
            tmp->val = val;
            tmp->next = cur->next;
            cur->next = tmp;
            }
        }
    }
    T pop() {
        if (head == nullptr) {
            throw std::string("Empty");
        } else {
            Item* tmp = head->next;
            T val = head->val;
            delete head;
            head = tmp;
            return val;
        }
    }
    ~TPQueue() {
        while (head) {
            Item* tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
