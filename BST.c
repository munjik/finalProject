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
