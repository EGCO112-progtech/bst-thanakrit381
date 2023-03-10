// An integer binary search tree

struct TreeNode {
  struct TreeNode *leftPtr;  // pointer to left subtree
  int data;                  // node value
  struct TreeNode *rightPtr; // pointer to right subtree
};                           // end structure treeNode

typedef struct TreeNode *TreeNodePtr; // synonym for TreeNode*

typedef struct {
  int size;
  TreeNodePtr root;
} BST;

// prototypes

void insertNode_R(TreeNodePtr *t, int value) {
  if (*t == NULL) {
    *t = (TreeNodePtr)malloc(sizeof(struct TreeNode));
    (*t)->leftPtr = NULL;
    (*t)->rightPtr = NULL;
    (*t)->data = value;

  } else {
    if ((*t)->data >= value)
      insertNode_R(&((*t)->leftPtr), value);
    else
      insertNode_R(&((*t)->rightPtr), value);
  }
}

// /*void insertNode(BST *b, int value) {
//   TreeNodePtr t = b->root, new_node;
//   int inserted = 0;
//   new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
//   if (new_node) {
//     new_node->leftPtr = NULL;
//     new_node->rightPtr = NULL;
//     new_node->data = value;
//     /*First Node
//     if (!b->root)
//       b->root = new_node;
//     else {
//       while (!inserted) {

//         if (t->data >= value) {
//           /* move/insert to the left

//           if (t->leftPtr == NULL) {
//             t->leftPtr = new_node;
//             inserted = 1;
//           } else
//             t = t->leftPtr;
//         } else {
//           if (t->rightPtr == NULL) {
//             ;
//             t->rightPtr = new_node;
//             inserted = 1;
//           }
//           /* move/ insert to the right
//           else
//             t = t->rightPtr;
//         }
//       }
//       b->size++;
//     }
//   }
// } // end function */

void inOrder(TreeNodePtr treePtr) {
  // if tree is not empty, then traverse
  if (treePtr != NULL) {
    inOrder(treePtr->leftPtr);    // Recursion to the left
    printf("%5d", treePtr->data); // print the value
    inOrder(treePtr->rightPtr);   // Recursion to the right
  }
}
void preOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    printf("%5d", treePtr->data);
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr);
  }
}
void postOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    postOrder(treePtr->leftPtr);
    postOrder(treePtr->rightPtr);
    printf("%5d", treePtr->data);
  }
} // end

void printTree(TreeNodePtr treePtr, int space) {
  if(treePtr!=NULL){
    printTree(treePtr->rightPtr,space+5);
    for(int i=0;i<space;i++)
    {
      printf("   ");
    }
    printf("%3d\n",treePtr->data);
    printTree(treePtr->leftPtr,space+5);
  }
}