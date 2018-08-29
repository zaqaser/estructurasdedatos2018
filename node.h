#ifndef NODE_H
#define NODE_H
template <class K, class D>
class Node
{
private:

public:
    K key;
    D dato;
    Node* siguiente;
    Node* anterior;


    Node(K p_key, D p_dato);
    K GetKey();
    D GetDato();
    void  SetSiguiente(Node* p_node);
    Node* GetAnterior()
    {
        return anterior;
    }
    Node* GetSiguiente()
    {
        return siguiente;
    }
    ~Node();
};

#include "Node.inl"
#endif // NODE_H
