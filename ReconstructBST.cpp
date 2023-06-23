using namespace std;
// Reconstruct a BST from a vector containing the PreOrderTraversal of the BST. 
// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST *insert(BST *tree, BST *node) {
  if (node->value < tree->value) {
    if (tree->left) {
      return insert(tree->left, node); 
    }
    else {
      tree->left = node; 
      return tree; 
    }
  }
  if (node->value >= tree->value) {
    if (tree->right) {
      return insert(tree->right, node); 
    }
    else {
      tree->right = node; 
      return tree; 
    }
  }
}

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.
  BST *answer = new BST(preOrderTraversalValues[0]);
  preOrderTraversalValues.erase(preOrderTraversalValues.begin());
  //cout << "root: " << answer->value << endl; 
  while (preOrderTraversalValues.size() > 0) {
    BST *current = new BST(preOrderTraversalValues[0]);
    //cout << "current value: " << current->value << endl; 
    preOrderTraversalValues.erase(preOrderTraversalValues.begin());
    insert(answer, current); 
  } 
  return answer;
}
