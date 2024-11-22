#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root,int data){
    struct node*temp;
    if(root==NULL)
    { 
        temp=createNode(data);
         return temp;
    }
    if(data<root->data)
     root->left=insert(root->left,data);
    else if(data>root->data)
     root->right=insert(root->right,data);

  return root;
}

struct node* search(struct node *root, int data) {
    if (root == NULL) {
        return 0; 
    }

    if (root->data == data) {
        return root;
; 

    }

    if (data > root->data) {
        return search(root->right, data); 

    } else {
        return search(root->left, data); 
    }
}
void preorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main()
{
    struct node* root= createNode(10);
    insert(root, 5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 20);
    insert(root, 11);
    insert(root, 21);
    int n;
   printf(" Enter the element to be searched\n3");
   scanf("%d",&n);
   struct node* ans=search(root,n);
   preorderTraversal(ans);
}
// tree
//      10
//   /      
//  5      20
// / \   /  
// 4  6  11 21



