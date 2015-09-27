#include <iostream>
#include <memory>

#include "linkedList.hpp"

int main( void ) {
    auto list = std::make_shared<bcTools::linkedList<uint>>();

    uint allocCount = 32;
    
    for(uint i = 0; i <= 4;i++) {
      for(uint add1 = 0; add1 < allocCount; add1++) {
	       list->push_end(add1 * i);
      }

      for(uint rem1 = 0; rem1 < allocCount/2; rem1++) {
	       list->remove_end();
      }
      std::cout << "Member count: " << list->size() << std::endl;
    }

    bcTools::node<uint>* node_ptrs[8];
    for(uint i = 0; i < list->size(); i += 8) {

      for(uint ii = 0; ii < 8; ii++) {
	       node_ptrs[ii] = list->lookup_index(i + ii);
      }

      for(auto node_ptr : node_ptrs) {
	       std::cout << node_ptr->value << ' ';
      }
      std::cout << std::endl;
    }
    return 0;
}
