/* CS361 Project, Implementing Binary Search Tree.
Created by Munji Kahalah and Leo Pereda
Starting with Gerenric Balanced Tree
04/12/2018 testing */

#include <stdio.h>
#include <stdlib.h>

/* Struct - Creates a data type that can be used to group items
 of possibly different types into a single type. The basic start of our tree
 Tree node w integer data */
struct node
{
  int key;
  struct node *left; // left side of the tree
  struct node *right; // right side of the tree
};

/*setting up inorder, root is beggining of tree */
void setOrder(struct node *root)
{
  if (root != NULL)
  {
    setOrder(root -> left);
    printf("%d ", root -> key);
    setOrder(root -> right);
  }
}
/* searching through our data, if the data is less than the one in the root,
  * go left, if its bigger than the givin root go right. */
struct node *searchingData(struct node *root, int key)
{
  if (root == NULL || root -> key == key) {
    return root;
  }
  if (root -> key > key) {
    return searchingData(root -> left, key);
  } else {
    return searchingData(root -> right, key);
  }
}

/* Create a new BST node, just as a reminder, nodes are what
  connects the data */
  struct node *createNode(int data)
  {
    // allocate memory for new nodes
    struct node *make = (struct node *)malloc(sizeof(struct node));
    // write ITEM into 'int' at address make
    make -> left = NULL;
    make -> right = NULL;
    make -> key = data;

    return make;
  }

  /* inserting in the BST */
  struct node* insertBST(struct node* node, int key)
  {
    if (node == NULL) {
      return createNode(key);
    }
    /* if our data is less than the current node, then go left */
    if (key < node -> key) {
      node -> left = insertBST(node -> left, key);
    }
    /* if our data is bigger than the current node, then go right */
    else if (key > node -> key) {
      node -> right = insertBST(node -> right, key);
    }
    return node;
  }
  /* Return node with the minimum key data in that tree */
  struct node * minimumNode(struct node* node)
  {
      struct node* current = node;

      /* loop down to find the leftmost leaf */
      while (current->left != NULL)
          current = current->left;

      return current;
  }

  /* with this function we will be deleting the key and return a new root for
  our BST */
  struct node *deleteBSTnode(struct node *root, int key)
  {

    if (key > root-> key) {
      root -> right = deleteBSTnode(root -> right, key);

    } else if (key < root ->key ) {
      root -> left = deleteBSTnode(root -> left, key);
    }
    else {
      if (root -> left == NULL) {
        struct node *make = root -> right;
        free(root);
        return(make);
      }
      else if(root -> right == NULL) {
        struct node *make = root-> left;
        free(root);
        return make;
      }
      if (root == NULL) {
        return root;
      }

      struct node* make = minimumNode(root->right);
      root->key = make->key;
      root->right = deleteBSTnode(root->right, make->key);
    }
    return root;
  }


  int main()
  {

    struct node *root = NULL;
    root = insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 5);
    insertBST(root, 6);
    insertBST(root, 7);
    insertBST(root, 8);
    insertBST(root, 9);
// print numbers from least to greatest of the BST

  printf("Numbers of given tree \n");
  setOrder(root);
  printf("\n");

  printf("Delete 5\n");
  root = deleteBSTnode(root, 5);
  printf("Updated Tree:\n");
  setOrder(root);
  printf("\n");

  printf("delete 3\n");
  root = deleteBSTnode(root , 3);
  printf("Updated Tree:\n");
  setOrder(root);
  printf("\n");

  return 0;

  }
