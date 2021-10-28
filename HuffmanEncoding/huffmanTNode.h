// Charles Brady, cjb5ct, 11/7/2020, huffmanTNode.h

#ifndef HUFFMANTNODE_H
#define HUFFMANTNODE_H

using namespace std;

class huffmanTNode {
 public:
  char data;
  huffmanTNode *leftChild = NULL;
  huffmanTNode *rightChild = NULL;
  int freq;

  huffmanTNode(char g,int f): data(g),freq(f) {}


};

#endif
