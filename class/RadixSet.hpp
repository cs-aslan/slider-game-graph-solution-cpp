#ifndef radixset_hpp
#define radixset_hpp

// Código retirado de https://codereview.stackexchange.com/questions/129815/radixset-a-growing-only-radix-patricia-tree


#include <string>

class RadixSet {
public:

   RadixSet() : isword(false), children(nullptr) { }

    ~RadixSet() {
    if (children != nullptr) {
      for (auto i = 0; i < 256; i++) {
         delete children[i];
      }
      delete[] children;
    }
    }


   void insert(std::string str) {
   RadixSet* node = this;
   for (unsigned char c : str) {
      if (node->children == nullptr) {
         node->children = new RadixSet*[256];
         for (auto i = 0; i < 256; i++) {
            node->children[i] = new RadixSet;
         }
      }
      node = node->children[c];
    }
    node->isword = true;
    }


    bool contains(std::string str) {
      RadixSet* node = this;
      for (unsigned char c : str) {
         if (node == nullptr || node->children == nullptr) {
            return false;
         }
         node = node->children[c];
      }
      return node->isword;
    }

private:
    bool isword;
    RadixSet** children;
};

#endif