#include <cstdio>

#define N 9

struct r {
    int v;
    r *left{nullptr};
    r *right{nullptr};
};

r* insert(r* root, int i) {
    if (not root) return new r{i};
    if (i < root->v)
        root->left = insert(root->left, i);
    else             
        root->right = insert(root->right, i); 
    return root;    
}

void print(r* root) {
    if (root) {    
        // pre-order
        print(root->left);
        // in-order
        printf("%d ", root->v);

        print(root->right);
        // post-order
    }
}

void find(r* root, int i) {
    if (not root) return;
    if (root->v == i) printf("%p %d ", (void*)root, i);
    else if (root->v > i)
        find(root->left, i);
    else 
        find(root->right, i);
}

void clear(r* &root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

int main() {

    int a[] = {5, 1, 3, 7, 8, 2, 4, 9, 6};

    r* root = nullptr;
    for (size_t i = 0; i < N; i++)
    {
        root = insert(root, a[i]);
    }

    print(root);

    clear(root);
}
