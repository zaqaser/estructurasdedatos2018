#include <iostream>
#include "RedBlack.h"
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
using namespace std;

int main(){
    RedBlack<int, int> MyRBTree;
    int Zed, Yasuo;
    srand (time(NULL));


  for(int x=1;x<30;x++){
        MyRBTree[x] = x;
        MyRBTree.printARBOL(x);
    }

    for(int m=31;m<50;m++){
        Yasuo = rand() % 10 + 1;
        MyRBTree.remove(Yasuo, 0);
        MyRBTree.printARBOL(m+51);
    }



    return 0;
}
