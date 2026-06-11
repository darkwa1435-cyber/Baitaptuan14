#include<iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    int height;
    node (int d, node* l, node* r, int h){
        data = d;
        left = l;
        right = r;
        height = h;
    }
};
int getheight(node* t){
    return (t == NULL) ? -1 : t -> height;
}
int balancefactor(node* t){
    return getheight(t -> left) - getheight(t -> right);
}
void rotateright(node* & k2){
    node* k1 = k2 -> left;
    k2 -> left = k1 -> right;
    k1 -> right = k2;
    k2 -> height = max(getheight(k2 -> left), getheight(k2 -> right)) + 1;
    k1 -> height = max(getheight(k1 -> left), getheight(k2 -> right)) + 1;
    k2 = k1;
}
void rotateleft(node * &k1){
    node* k2 = k1 -> right;
    k1 -> right = k2 -> left;
    k2 -> left = k1;
    k1 -> height = max(getheight(k1 -> left),getheight(k1 -> right)) + 1;
    k2 -> height = max(getheight(k2->left), getheight(k1->right)) + 1;
    k1 = k2;
}
void LRrotate(node* &k3){
    rotateleft(k3->left);
    rotateright(k3);
}
void RLrotate(node* &k1){
    rotateright(k1->right);
    rotateleft(k1);
}
void insert(int x, node* &t){
    if (t == NULL) t = new node(x, NULL, NULL, 0);
    else if (x < t -> data){
        insert(x, t -> left);
        if (balancefactor(t) == 2){
            if (x < t -> left -> data) rotateright(t);
            else LRrotate(t);
        }
    }
    else if (x > t -> data){
        insert(x, t -> right);
        if (balancefactor(t) == -2){
            if (x > t -> right -> data) rotateleft(t);
            else RLrotate(t);
        }
    }
    t -> height = max(getheight(t -> left), getheight(t -> right)) + 1;
}
void preorder(node* root){
    if (root != NULL){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
int main(){
    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = 9;
    node* root = NULL;
    for (int i = 0; i < n; i++){
        insert(a[i], root);
    }
    cout << "cay sau khi duyet tung phan tu: ";
    preorder(root);
    return 0;
}


