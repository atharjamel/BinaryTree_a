#pragma once
#include<iostream>
#include <stdexcept>
#include<sstream>
#include<fstream>
#include <string>


using namespace  std;
namespace ariel
{
    template<typename T>

    class BinaryTree {

    
    struct Node {
        T value;
        Node* right=nullptr;
        Node* left=nullptr;
        Node(T val ) : value(val),right(nullptr),left(nullptr) {}
       };

               
    class iterator {
    private:
        Node* p_node;

    public:

        iterator(Node* n = nullptr): p_node(n) {}
       
        T& operator*() const {
            return p_node->value;
        }

        T* operator->() const {
            return &(p_node->value);
        }

        iterator& operator++() {
            return *this;
        }

        const iterator operator++(int) {
            return *this;
        }

        bool operator==(const iterator& other ) const {
            return p_node == other.p_node;
        }

        bool operator!=(const iterator& other) const {
            return p_node != other.p_node;
        }
    };  
    
      Node *root;

    public :
      BinaryTree ():root(nullptr){};
    ~BinaryTree (){}
           
        
            BinaryTree<T> add_root(const T& parent){
            return *this;
        }
        BinaryTree<T> add_left(const T& val,const T& l_node){
            return *this;
        }
        BinaryTree<T> add_right(const T& val ,const T& r_node){
            return *this;
        }
         iterator begin(){
            return iterator {root};
        }                         
        iterator end(){
            return iterator {root};
        }

        iterator begin_preorder(){
            return iterator {root};
        }
        iterator end_preorder(){
            return iterator {root};
        }

        iterator begin_inorder(){
            return iterator {root};
        }

        iterator end_inorder(){
            return iterator {root};
        }
        iterator begin_postorder(){
            return iterator {root};
        }

        iterator end_postorder(){
            return iterator {root};
        } 
       

     friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &b)
        {
            os<<"BinaryTree output!"<<endl;
            return os;
        }
    }; // END OF BinaryTree
}