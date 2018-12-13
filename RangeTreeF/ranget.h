#ifndef RANGET_H
#define RANGET_H
#include <QPainter>
#include <QPen>
#include<QColor>
#include<vector>
#include<iostream>

using namespace std;

struct point{

double x,y,h;

};

struct rectangle{
double x1,x2,y1,y2;
};

class RangeT;

class assNode{

    double yval;
    double hmax;
    assNode* laTree;
    assNode* raTree;
    bool isChild;

    assNode*find1DsplitNode(assNode*Tree,double y1,double y2); //QPainter * DH

public:
    void range1Dquery(assNode*Tree, double y1, double y2, QPainter* drawhe,double x);
    assNode(vector<point>point,int start, int end);
  };

class RangeT{

    double xval;
    RangeT* lTree;
    RangeT* rTree;

    assNode* yTree;
    bool isChild;

    RangeT* find2DsplitNode(RangeT*Tree,double x1,double x2);


public:
    void range2Dquery(RangeT*Tree, rectangle R, QPainter *drawhe); //QPainter * DH
    RangeT(vector<point>point,int start,int end);
};

#endif // RANGET_H
