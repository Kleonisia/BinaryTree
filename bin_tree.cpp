#include <iostream>
struct bin_tree {
    int key;
    bin_tree* prev;
    bin_tree* left;
    bin_tree* right;
};
class Binary_Tree {
private:
    bin_tree* T;
public:
    Binary_Tree() {
        T = NULL;
    }
    void Insert(int e) {
        if (T == NULL) {
            T = new bin_tree;
            T->key = e;
            T->left = NULL;
            T->right = NULL;
            T->prev = NULL;
            return;
        }
        bin_tree* q = T;
        while (true) {
            if (e < q->key) {
                if (q->left == NULL) {
                    bin_tree* p = new bin_tree;
                    p->key = e;
                    p->left = NULL;
                    p->right = NULL;
                    q->left = p;
                    p->prev = q;
                    break;
                }
                q = q->left;
            }
            else if (e > q->key) {
                if (q->right == NULL) {
                    bin_tree* p = new bin_tree;
                    p->key = e;
                    p->left = NULL;
                    p->right = NULL;
                    q->right = p;
                    p->prev = q;
                    break;
                }
                q = q->right;
            }
        }
        return;
    }
    void Remove(int e) {
        bin_tree* q = T;
        while (q != NULL and q->key != e) {
            if (q->key > e) {
                q = q->left;
            }
            else {
                q = q->right;
            }
        }
        if (q == NULL) {
            std::cout << "nothing to remove";
            return;
        }
        bin_tree* p = q;
        if (p->right == NULL) {
            if (p->left == NULL) {
                if (p->prev == NULL) {
                    T = NULL;
                    delete p;
                    std::cout << "ok";
                    return;
                }
                if (p->prev->left == p) {
                    p->prev->left = NULL;
                    delete p;
                }
                else {
                    p->prev->right = NULL;
                    delete p;
                }
            }
            else {
                if (p->prev == NULL) {
                    T = p->left;
                    T->prev = NULL;
                    delete p;
                    std::cout << "ok";
                    return;
                }
                if (p->prev->left == p) {
                    p->prev->left = p->left;
                    p->left->prev = p->prev;
                    delete p;
                }
                else {
                    p->prev->right = p->left;
                    p->left->prev = p->prev;
                    delete p;
                }
            }
            std::cout << "ok";
            return;
        }
        p = p->right;
        if (p->left == NULL) {
            q->key = p->key;
            q->right = p->right;
            delete p;
            std::cout << "ok";
            return;
        }
        while (p->left != NULL) {
            p = p->left;
        }
        if (p->right == NULL) {
            q->key = p->key;
            p->prev->left = NULL;
            delete p;
            std::cout << "ok";
            return;
        }
        else {
            q->key = p->key;
            p->prev->left = p->right;
            p->right->prev = p->prev;
            delete p;
        }
        std::cout << "ok";
        return;
    }
    void Search(int e) {
        bin_tree* q = T;
        while (q != NULL and q->key != e) {
            if (q->key > e) {
                q = q->left;
            }
            else {
                q = q->right;
            }
        }
        if (q == NULL) {
            std::cout << "nothing found";
            return;
        }
        else {
            std::cout << "e";
            return;
        }
    }
};
int main() {
    Binary_Tree t;
    int n, el;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> el;
        t.Insert(el);
    }
    return 0;
}
