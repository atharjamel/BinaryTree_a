#include"BinaryTree.hpp"
#include "doctest.h"
#include <iostream>
#include<stdexcept>
#include <fstream>
#include<sstream>
#include<string>

using namespace ariel;
using namespace std;

BinaryTree<int> tree_of_ints;
BinaryTree<string> tree_of_strings;

TEST_CASE ( "test of ints tree:"){
   BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(2));
    CHECK_NOTHROW(tree_of_ints.add_left(2,4));
    CHECK_NOTHROW(tree_of_ints.add_right(2,7));
    CHECK_NOTHROW(tree_of_ints.add_left(4,6));
    CHECK_NOTHROW(tree_of_ints.add_left(7,11));
    CHECK_NOTHROW(tree_of_ints.add_right(7,13));
    CHECK_NOTHROW(tree_of_ints.add_right(4,8));
    CHECK_NOTHROW(tree_of_ints.add_left(13,15));
    CHECK_NOTHROW(tree_of_ints.add_right(15,17));
    CHECK_THROWS(tree_of_ints.add_right(20,7));
   CHECK_THROWS(tree_of_ints.add_left(1,100));
   CHECK_THROWS(tree_of_ints.add_left(100,10));
   CHECK_THROWS(tree_of_ints.add_left('Z', 'G'));
}
TEST_CASE("test of string tree:"){

    BinaryTree<string> tree_of_strings;
    CHECK_NOTHROW(tree_of_strings.add_root("1"));
    CHECK_NOTHROW(tree_of_strings.add_left("1","9"));
    CHECK_NOTHROW(tree_of_strings.add_left("9","4"));
    CHECK_NOTHROW(tree_of_strings.add_right("9","5"));
    CHECK_NOTHROW(tree_of_strings.add_right("1","3"));
   CHECK_THROWS(tree_of_strings.add_right("12","7"));
   CHECK_THROWS(tree_of_strings.add_left("root","8"));
      
}


TEST_CASE("test of char tree:")
{
    BinaryTree<char> tree_of_char;
    CHECK_NOTHROW(tree_of_char.add_root('o'));
    CHECK_NOTHROW(tree_of_char.add_right('o', 'b'));
     CHECK_NOTHROW(tree_of_char.add_left('b', 'i'));
    CHECK_NOTHROW(tree_of_char.add_right('b', 'n'));

    CHECK_NOTHROW(tree_of_char.add_left('n', 'a'));
     CHECK_NOTHROW(tree_of_char.add_right('n', 'r'));
    CHECK_NOTHROW(tree_of_char.add_left('r', 'y'));

    CHECK_NOTHROW(tree_of_char.add_left('o', 't'));
    CHECK_NOTHROW(tree_of_char.add_right('t', 'r'));
    CHECK_NOTHROW(tree_of_char.add_left('r', 'e'));
    CHECK_NOTHROW(tree_of_char.add_left('e', 'e'));
    CHECK_THROWS(tree_of_char.add_right('z', 'g'));
    CHECK_THROWS(tree_of_char.add_left('a', 't'));
    CHECK_THROWS(tree_of_char.add_right('h', 's'));
    CHECK_NOTHROW(tree_of_char.add_root('p'));
}
TEST_CASE ("test tree with out root:"){  
    BinaryTree<char> tree_of_char;
    CHECK_THROWS(tree_of_char.add_right('n','o'));
    CHECK_THROWS(tree_of_char.add_left('n', 'g'));
}


    TEST_CASE(" test of operator <<:"){

CHECK_NOTHROW( cout << tree_of_ints << endl);
CHECK_NOTHROW( cout << tree_of_strings << endl);

}
TEST_CASE("Test of post order: "){ 
    BinaryTree<int> tree;
    // this is the tree (demo example:)
         
    CHECK_NOTHROW(tree.add_root(1));

    CHECK_NOTHROW(tree.add_left(1,2));
    CHECK_NOTHROW(tree.add_left(2,4));
    CHECK_NOTHROW(tree.add_right(2,5));  
    CHECK_NOTHROW(tree.add_right(1,3));
    
    string out="";

    for (auto i=tree.begin_postorder(); i != tree.end_postorder(); ++i) {
       out+=std::to_string(*i)+',';
    }
    CHECK_EQ(out,"7,6,3,5,4,2,1,");
    
    }
    TEST_CASE("Test of post_order: "){ 

    BinaryTree<string> tree;
    CHECK_NOTHROW(tree.add_root("Binary"));

    CHECK_NOTHROW(tree.add_left("Binary","Tree"));
    CHECK_NOTHROW(tree.add_left("Tree","object"));
    CHECK_NOTHROW(tree.add_right("Tree","Ex-5"));  
    CHECK_NOTHROW(tree.add_right("Binary","cpp"));
    
    string out="";
    for (auto i=tree.begin_preorder(); i != tree.end_preorder(); ++i) {
       out+=(*i)+',';
    }
    CHECK_EQ(out,"Binary,Tree,object,Ex-5,cpp,");
    
    }
    TEST_CASE("Test of inorder :"){ 

    BinaryTree<char> tree;
   
    CHECK_NOTHROW(tree.add_root('a'));
    CHECK_NOTHROW(tree.add_left('a','t'));
    CHECK_NOTHROW(tree.add_left('t','h'));
    CHECK_NOTHROW(tree.add_right('t','c'));  
    CHECK_NOTHROW(tree.add_right('a','r'));
    CHECK_NOTHROW(tree.add_right('r','x'));
    CHECK_NOTHROW(tree.add_left('r','r'));
     string out="";

    for (auto i=tree.begin_inorder(); i != tree.end_inorder(); ++i) {
       out+=std::to_string(*i)+',';
    }
    CHECK_EQ(out,"'h','t','c','a','r','x','r',");
    
    }

