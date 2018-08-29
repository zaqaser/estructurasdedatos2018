template <class K, class D>
LinkedList<K,D>::LinkedList()
{
        raiz = nullptr;
}

template <class K, class D>
LinkedList<K,D>::~LinkedList()
{
}

template <class K, class D>
bool LinkedList<K,D>::InsertFront(const K & p_key, const D & p_dato)
{
        if (raiz == nullptr)
        {
                raiz = new Node<K,D>(p_key, p_dato);
                return true;
        }
        else
        {
                Node<K,D>* actual = raiz;

                while (actual!=nullptr)
                {
                        if (actual->GetSiguiente()==nullptr)
                        {
                                Node<K,D>* Nuevo= new Node<K,D>(p_key, p_dato);
                                actual->SetSiguiente(Nuevo);
                                Nuevo->siguiente = nullptr;
                                return true;
                        }
                        else
                        {
                                actual=actual->GetSiguiente();
                        }
                }


                return true;
        }
}

template <class K, class D>
void LinkedList<K,D>::Show()
{
        Node<K,D>* actual = raiz;
        while(actual!=nullptr)
        {
                cout << actual->GetKey()<<"->";
                actual = actual->GetSiguiente();
        }
}

template <class K, class D>
bool LinkedList<K,D>::RemoveFront()
{
        if (raiz != nullptr)
        {
                Node<K,D>* Actual = raiz;
                Node<K,D>* Temp = Actual;

                while (Actual->siguiente != nullptr)
                {
                        Temp = Actual;
                        Actual = Actual->siguiente;

            }
                Temp->siguiente = Actual->siguiente;
                delete Actual;
                return true;
        }
        else
                return false;
        return false;
}

template <class K, class D>
Node<K,D>* LinkedList<K,D>::GetRaiz()
{
        return raiz;
}
template <class K, class D>
bool LinkedList<K,D>::InsertBack(const K & p_key, const D & p_dato){
        if (raiz == nullptr)
        {
                raiz = new Node<K,D>(p_key, p_dato);
                return true;
        }
        else
        {
                Node<K,D>* actual = raiz;
                Node<K,D>* Nuevo= new Node<K,D>(p_key, p_dato);
                Nuevo->siguiente = actual;
                raiz = Nuevo;
                return true;
        }
}

template <class K, class D>
bool LinkedList<K,D>::RemoveBack(){
        if (raiz != nullptr)
        {
                Node<K,D>* Actual = raiz;

                if(Actual->siguiente != nullptr)
                {
                        raiz = Actual->siguiente;
                        Actual = nullptr;
                        delete Actual;
                        return true;
                }

                else
                {
                        raiz = nullptr;
                        delete raiz;
                        return true;
                }
        }
        else{
                return false;
        }
        return false;
}
