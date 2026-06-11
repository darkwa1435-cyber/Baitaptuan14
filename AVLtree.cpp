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
void preorder(node* root){
    if (root != NULL){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
int main(){
   /* int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66}; */
   node* root = new node(30, NULL, NULL, 3);
   root -> left = new node(20, NULL, NULL, 2);
   root -> left -> left = new node(10, NULL, NULL, 1);
   cout << "cay ban dau: ";
    preorder(root);
    cout << endl;
    rotateright(root);
    cout << "cay sau khi xoay phai: ";
    preorder(root);
    cout << endl;
}


