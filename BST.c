/* CS361 Project, Implementing Binary Search Tree.
Created by Munji Kahalah and Leo Pereda
Starting with Gerenric Balanced Tree
04/12/2018 */

#include <stdio.h>
#include <stdlib.h>

/* Struct - Creates a data type that can be used to group items
 of possibly different types into a single type. The basic start of our tree
 Tree node w integer data */

struct node
{
  int key;
  struct node *left;
  struct node *right;
};

/* Create a new BST node, just as a reminder, nodes are what
  connects the data */
  struct node *newNode(int item)
  {
    // allocate memory for new nodes
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // write ITEM into 'int' at address temp
    temp -> key = item;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
  }

  /*inorder traversal, root is beggining of tree */
  void inOrder(struct node *root)
  {
    if (root != NULL)
    {
      inOrder(root -> left);
      printf("%d \n", root -> key);
      inOrder(root -> right);
    }
  }
  /* inserting in the BST */
  struct node* insert(struct node* node, int key)
  {
    if (node == NULL) {
      return newNode(key);
    }
    /* if our data is less than the current node, then go left */
    if (key < node -> key) {
      node -> left = insert(node -> left, key);
    }
    /* if our data is bigger than the current node, then go right */
    else if (key > node -> key) {
      node -> right = insert(node -> right, key);
    }
    return node;
  }


  int main()
  {


  }
