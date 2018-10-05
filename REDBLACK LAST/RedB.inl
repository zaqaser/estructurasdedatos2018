template <class K, class D>
bool RedBlack<K,D>::insert(const K & _key, const D & _data){
    insert(_key,_data,&p_root,NULL);
    return true;
}
//print
template<class K, class D>
void RedBlack<K,D>::printARBOL(ofstream & es,Node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[0]->key<<endl;
            printARBOL(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[1]->key<<endl;
            printARBOL(es,n->p_child[1]);
        }
    }
}

//operator
template <class K, class D>
D & RedBlack<K,D>::operator[](const K & _key){
    D _data =0;
    Node<K,D> *temp;
    if(find_node(_key,temp)){
        return p_root->data;
    }
    else{
        insert(_key,_data);
        find_node(_key,temp);
        return p_root->data;
    }
}


//DRAW
template<class K, class D>
bool RedBlack<K,D>::draw(Node<K,D> *n, ofstream & os){
    if(!n) return false;
    queue<Node<K,D> *> q;
    os.open("Red-Back_tree.txt");
    os <<"digraph { "<<endl;
    q.push(p_root);
    while(!q.empty()){

        int level = q.size();
        while( level > 0){
            Node<K,D> **temp;
            temp = &q.front();
            q.pop();
            if((*temp)->color == RED){
                os<<"   "<<"{"<<endl;
                os<<"   "<<(*temp)->key<<" [shape=circle, color=red]"<<endl;
                os<<"   "<<"}"<<endl;
            }
            if((*temp)->p_child[0]){
                q.push((*temp)->p_child[0]);
                os<<"   "<<(*temp)->key<<" -> "<<(*temp)->p_child[0]->key<<endl;
            }
            if((*temp)->p_child[1]){
                q.push((*temp)->p_child[1]);
                os<<"   "<<(*temp)->key<<" -> "<<(*temp)->p_child[1]->key<<endl;
            }
            level--;
        }
    }
    os<<"}"<<endl;
    os.close();
    return true;
}
//PRINT COLOR VERSION MAU
template<class K, class D>
void RedBlack<K,D>::printCOLOR(ofstream & es,Node<K,D> *ptr){
  if (ptr == NULL)
    return;
  if(ptr->color == 0){
    es<< ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  }
  else es<< ptr->key << "[style=filled, fillcolor=red]"<< endl;
  printCOLOR(es,ptr->p_child[0]);
  printCOLOR(es,ptr->p_child[1]);
}

//PRINT
template<class K, class D>
void RedBlack<K,D>::printARBOL(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.exe.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    printARBOL(es,p_root);
    printCOLOR(es,p_root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}
//INSERT
template <class K, class D>
Node<K,D> * RedBlack<K,D>::insert(const K & _key, const D & _data, Node<K,D> ** n,  Node<K,D> ** p){
    if(!(*n)){
        (*n) = new Node<K,D>(_key,_data);
        (*n)->color = RED;
        p_root->color = BLACK;
        return (*n);
    }
    if((*n)->key == _key) return NULL;
    int idx_child = ((*n)->key < _key);
    Node <K,D> *child = insert(_key,_data,&(*n)->p_child[idx_child],n);
    if(!child)
        return (*n);
    if(!p)
        return NULL;
    if(is_red(child) && is_red(*n)){
        int idx_parent = ((*p)->p_child[1] == (*n));
        Node<K,D> *uncle = (*p)->p_child[!idx_parent];
        if(is_red(uncle)){
            (*n)->color = BLACK;
            uncle->color = BLACK;
            (*p)->color = RED;
            p_root->color = BLACK;
            return (*n );
        }
        if(is_black(uncle)){
            if(idx_child != idx_parent){
                turn_side(n,idx_child);
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_child[0]->color = RED;
                (*p)->p_child[1]->color = RED;
                p_root->color = BLACK;
            }
            else{
                turn_side(p,idx_parent);
                (*p)->color = BLACK,
                (*p)->p_child[!idx_parent]->color = RED;
                p_root->color =BLACK;
            }
        }
    }
    return (*n );
}
//FIND
template <class K, class D>
bool RedBlack<K,D>::find(K _key){
    Node<K,D> * temp = p_root;
    if(!temp) return false;
    while(temp){
        if(temp->key == _key) return true;
        temp = temp->p_child[temp->key < _key];
    }
    return false;
}

template <class K, class D>
bool RedBlack<K,D>::find_node(const K & _key, Node<K,D> *temp){
    temp = p_root;
    while(temp)
    {
        if( (temp)->key == _key ) return true;
        temp = temp->p_child[ (temp)->key < _key ];
        }
    return false;
}
//SIDE
template <class K, class D>
void RedBlack<K,D>::turn_side( Node<K,D> ** n, bool side){
    Node<K,D> *aux = (*n)->p_child[side];
    (*n)->p_child[side] = aux->p_child[!side];
    aux->p_child[!side] = (*n);
    (*n) = aux;
}

template <class K, class D>
void RedBlack<K,D>::inorder(Node<K,D> *n){
    if(!n) return;
    if(n->p_child[0]) inorder(n->p_child[0]);
    cout<<n->key<<" -> ";
    if(n->p_child[1]) inorder(n->p_child[1]);
}
//IN
template <class K, class D>
void RedBlack<K,D>::update_color(Node<K,D> * n){
    if(!n) return;
    p_root->color =BLACK;
}
//RED WHO?
template <class K, class D>
bool RedBlack<K,D>::is_red(Node<K, D> * n){
    if(!n) return false;
    if(n->color == RED)return true;
    else return false;
}

template <class K, class D>
bool RedBlack<K,D>::is_black(Node<K, D> * n){
    if(!n) return true;
    if(n->color == BLACK)return true;
    else return false;
}

template <class K, class D>
bool RedBlack<K,D>::successor(Node<K,D> *nodo, Node<K,D> *sucesor){
    if(!nodo->p_child[1]) return false;
    sucesor = nodo->p_child[1];
    while(sucesor->p_child[0]){
        sucesor = sucesor->p_child[0];
    }
    return true;
}
//BYE
template<class K,class D>
bool RedBlack<K,D>::remove(const K & key,const D & data){
    remove(key, data, &p_root, NULL);
    return true;
}
//BYE
template<class K, class D>
Node<K,D> * RedBlack<K,D>::remove(const K & key,const D & data, Node<K,D> ** n, Node<K,D> ** p){
    Node<K,D> *tmp;
    if(!(*n))
        return NULL;

    if((*n)->key==key){
        if((*n)->p_child[0] and (*n)->p_child[1]){
            tmp = min(&(*n)->p_child[1]);
            (*n)->key = tmp->key;
            remove((*n)->key,(*n)->data,&(*n)->p_child[1],NULL);
        }
        else{
            tmp = (*n);
            if(!((*n)->p_child[0])){
                (*n) = (*n)->p_child[1];
            }
            else{
                if(!((*n)->p_child[1])){
                    (*n) = (*n)->p_child[0];
                }
            }
            delete tmp;
        }
        if(!(*n)){
            return NULL;
        }
    }
    bool idx_child = ((*n)->key < key);
    Node<K,D> *child = remove(key,data,&(*n)->p_child[idx_child],n);
    if(!child){
        return (*n);
    }
    if(!p){
        return NULL;
    }
    if(is_red(child) and is_red(*n)){
        bool idx_parent = ((*p)->p_child[1] == (*n));
        Node<K,D> *uncle = (*p)->p_child[!idx_parent];
        if(is_red(uncle)){
            (*n)->color = BLACK;
            uncle->color = BLACK;
            (*p)->color = RED;
            p_root->color = BLACK;
            return (*n);
        }
        if(is_black(uncle)){
            if(idx_child!=idx_parent){
                turn_side(n,idx_child);
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_child[0]->color = RED;
                (*p)->p_child[1]->color = RED;
                p_root->color = BLACK;
            }
            else{
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_child[!idx_parent]->color = RED;
                p_root->color = BLACK;
            }
        }
    }
    return (*n);
}

template <class K, class D>
void RedBlack<K,D>::print(){
    inorder(p_root);
}
//DRAW INCOMPLETO
template <class K, class D>
void RedBlack<K,D>::draw(){
    ofstream newFile;
    draw(p_root,newFile);
}
template<class K,class D>
Node<K,D>* RedBlack<K,D>::min(Node<K,D> **n)
{
    if (!(*n))
    {
        return NULL;
    }
    else{
        if(!((*n)->p_child[0])){
            return (*n);
        }
        else{
            return min(&((*n)->p_child[0]));
        }
    }
}





