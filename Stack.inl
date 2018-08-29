template <class K, class D>
void Stack<K,D>::Push(const K & p_key, const D & p_dato)
{
        List.InsertBack(p_key, p_dato);
}

template <class K, class D>
void Stack<K,D>::Pop()
{
        List.RemoveBack();
}

template <class K, class D>
K Stack<K,D>::Top()
{
        cout<<"top ->" << List.raiz->key << endl;
        //return List.raiz->dato;
}

template <class K, class D>
void Stack<K,D>::Print()
{
        List.Show();
}

template <class K, class D>
Stack<K,D>::Stack()
{
}

template <class K, class D>
Stack<K,D>::~Stack()
{
}
