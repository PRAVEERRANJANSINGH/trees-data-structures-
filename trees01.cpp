#include<iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void display(node *root){
  if (root == NULL)  return;
  cout<<root->val<<" ";
  display(root->left);  
  display(root->right);
}
void displayright(node *root){
  if (root == NULL)  return;
  cout<<root->val<<" ";
  display(root->right);
  display(root->left);  
  
}
int treesum(node *root){
  if (root == NULL)  return 0;
  return root->val + treesum(root->left) + treesum(root->right);
}
int treesize(node *root){
  if (root == NULL)  return 0;
  return 1 + treesize(root->left) + treesize(root->right);
}

int maxintree(node *root){
  if (root == NULL)  return INT_MIN;
  return max(root->val,max(maxintree(root->left),maxintree(root->right)));
}
int treemult(node *root){
  if (root == NULL)  return 1;
  return root->val * treemult(root->left) * treemult(root->right);

}
int minintree(node *root){
  if (root == NULL)  return INT_MAX;
  return min(root->val,min(minintree(root->left),minintree(root->right)));
}
int leveloftree(node *root){
  if(root == NULL) return 0;
  return 1 + max(leveloftree(root->left),leveloftree(root->right));   

}
int main()
{
  node *a= new node(1);
  node *b= new node(2); 
  node *c= new node(3);
  node *d= new node(4);
  node *e= new node(5);
  node *f= new node(6); 
  node *g= new node(7);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  display(a);
  cout<<endl;
  displayright(a);
  cout<<endl;

  cout<<treesize(a);
  cout<<endl;

  cout<<treesum(a);
  cout<<endl;
  cout<<treemult(a);
  cout<<endl;
  cout<<maxintree(a);
 
  cout<<endl;
  cout<<leveloftree(a);
  return 0;
}