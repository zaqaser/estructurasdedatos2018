#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
namespace std;
enum color_t: bool {BLACK = 0, RED = 1};
template <class K, class D>
class RedBlack;
template <class K, class D>
class Node
{private:
        K key;
        D data;
        Node<K,D> *p_child[2];
        color_t color;
    public:
        Node(){};
        ~Node(){}
        Node(const K & _key, const D & _data){
            key = _key;
            data = _data;
            color = RED;
            p_child[0] = NULL;
            p_child[1] = NULL;}
    friend class RedBlack<K,D>;};
template <class K, class D>
class RedBlack{
private:
    Node<K,D> * p_root;
public:
    RedBlack(){
        p_root = NULL;}
    ~RedBlack(){}
     bool insert(const K & _key, const D & _data);
    Node<K,D> * insert(const K & _key, const D & _data, Node<K,D> ** n,  Node<K,D> ** p);
    bool find(K _key);
    bool find_node(const K & _key, Node<K,D> *temp);
    bool remove(const K & key,const D & data);
    Node<K,D> * remove(const K & key,const D & data, Node<K,D> ** n, Node<K,D> ** p);
    Node<K,D> * min(Node<K,D> **n);
    void turn_side( Node<K,D> ** n, bool side);
    void inorder(Node<K,D> *n);
    void update_color(Node<K,D> * n);
    bool is_red(Node<K, D> * n);
    bool is_black(Node<K, D> * n);
    bool successor(Node<K,D> *nodo, Node<K,D> *sucesor);
    void print();
    void draw();
    D & operator[](const K & _key);
    void printARBOL(ofstream & es,Node<K,D> *n);
    void printARBOL(int num);
    void printCOLOR(ofstream & es,Node<K,D> *n);
private:
    bool draw(Node<K,D> *n, ofstream & os);};
#include "RedB.inl"
#endif
