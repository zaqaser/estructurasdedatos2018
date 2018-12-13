#include "ranget.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include <QPainter>
#include<QPen>
#include<QColor>
static bool xcomp(point p1,point p2){ return p1.x>p2.x;}
static bool ycomp(point p1,point p2){ return p1.y>p2.y;}

static void swap(double *a,double*b)
{
double temp;
temp=*a;
*a=*b;
*b=temp;
}

assNode::assNode(vector<point>point,int start, int end){

    double maxh=-1;

    for(int m=start;m<=end;m++){
        if(maxh>point[m].h)
            maxh=point[m].h;
    }


    if(start==end){
        hmax =maxh;
        yval=point[start].y;
        laTree=NULL;
        raTree=NULL;
        isChild=true;

    return;
    }

    else{
        int mid=(start+end)/2;
        hmax =maxh;
        yval=point[mid].y;
        laTree= new assNode(point,start,mid);
        raTree= new assNode(point,mid+1,end);
        isChild=false;
  }
}

assNode* assNode::find1DsplitNode(assNode*Tree,double y1,double y2){

    if(y1>y2)
        swap(&y1,&y2);

    assNode *temp=Tree;

    while(!temp->isChild && (temp->yval>=y2 || temp->yval<y1))
    {
    if(temp->yval>=y2)
        temp=temp->laTree;
    else
        temp=temp->raTree;
    }

    return temp;
}

void assNode::range1Dquery(assNode*Tree,double y1,double y2,QPainter* drawhe, double x){

    assNode *split=find1DsplitNode(Tree,y1,y2);


    if(split ->isChild){
        if(y1<=split->yval && y2>=split->yval){

            //QColor color("red");
            //lapiz = new QPen(color);
           // drawhe->setPen (lapiz);
            drawhe->setPen ( QColor("red"));
            drawhe->drawEllipse(x-1,split->yval-1,2,2);
            return;
}
        else
            return ;}

    else
    {
        assNode* leftNode=split->laTree;

        while(!leftNode ->isChild)
        {
            if(y1>=leftNode->yval)
            {
                 leftNode->range1Dquery (leftNode,y1,y2,drawhe,x);
                leftNode=leftNode->laTree;
            }
            else
                leftNode=leftNode->raTree;

         }


         if(y1 <= leftNode->yval&&y2>=leftNode->yval){
            leftNode->range1Dquery (leftNode,y1,y2,drawhe,x);
            /*if(maxh<k)
                maxh=k;*/
         }

    }

    assNode *rigthNode=split->raTree;
    while(!rigthNode->isChild)
    {
    if(y2>=rigthNode->yval)
    {
        rigthNode->range1Dquery (rigthNode,y1,y2,drawhe,x);
           /* double m=rigthNode->laTree->hmax;
            if(maxh<m)
                maxh=m;*/
            rigthNode=rigthNode->raTree;
    }
    if(y1<=rigthNode->yval&&y2>=rigthNode->yval)
    {
        rigthNode->range1Dquery (rigthNode,y1,y2,drawhe,x);
       /* if(maxh<k)
            maxh=k;*/
    }
    return range1Dquery (Tree,y1,y2,drawhe,x);
    }
}


RangeT::RangeT(vector<point>Points,int start,int end){
cout << "rangeT" << endl;
    vector<point> yPoints;

    for(int m=start;m<=end;m++){

        yPoints.push_back(Points[m]);
    }

        sort(yPoints.begin(),yPoints.end(),ycomp);
        assNode* AssTree= new assNode(yPoints,0,yPoints.size()-1);

    if(start==end){
        yTree=AssTree;
        xval=Points[start].x;
        rTree=NULL;
        lTree=NULL;
        isChild=true;

        return;
    }
    else{
        int mid=(start+end)/2;
        yTree=AssTree;
        xval=Points[mid].x;
        rTree=new RangeT(Points,mid+1,end);
        lTree=new RangeT(Points,start,mid);
        isChild=false;
        }


}

RangeT* RangeT::find2DsplitNode(RangeT*Tree,double x1,double x2){
    if(x1>x2)
        swap(&x1,&x2);

   RangeT* temp=Tree;
    while (!temp->isChild &&(temp->xval>=x2||temp->xval<x1))
    {
        if(temp->xval>=2)
            temp=temp->lTree;
        else
            temp=temp->rTree;
    }
    return temp;
}
void RangeT::range2Dquery(RangeT*Tree,rectangle R, QPainter* drawhe )//QPainter * DH
    {
        //double maxh=-1;

        RangeT* split =find2DsplitNode(Tree,R.x1,R.x2);
        if(split->isChild)	{

            if(R.x1 <=split->xval&& R.x2>=split->xval)
                return split->yTree->range1Dquery(split->yTree,R.y1,R.y2, drawhe ,split->xval); //pasar qPainter
            else
                return ; //return;
        }
        else
        {

            RangeT *leftNode=split->lTree;
            while(!leftNode->isChild){
        if(R.x1<=leftNode->xval){
          leftNode->rTree->yTree->range1Dquery(leftNode->rTree->yTree,R.y1,R.y1,drawhe, split->xval); //Borrar
            /*if(maxh>m)
                   maxh=m;  */
        leftNode=leftNode->lTree;
        }
        else
            leftNode=leftNode->rTree;
        }
            if(R.x1<=leftNode->xval&&R.x2>=leftNode->xval){
            leftNode->yTree->range1Dquery(leftNode->yTree,R.y1,R.y2, drawhe, split->xval);
              /* if(maxh<m)
                    maxh=m;*/
        }
            RangeT *rigthNode=split->rTree;
            while(!rigthNode ->isChild)
            {
                if(R.x2>=rigthNode->xval){
                    rigthNode->lTree->yTree->range1Dquery(rigthNode->lTree->yTree,R.y1,R.y2, drawhe, split->xval);
                    /*if(maxh<m)
                        maxh=m;*/
                    rigthNode=rigthNode->rTree;
                }
                if(R.x1<=rigthNode->xval&&R.x2>=rigthNode->xval)
                {
                    rigthNode->yTree->range1Dquery(rigthNode->yTree,R.y1,R.y2,drawhe, split->xval); //cada que se llama 1d query se le pasa el qpainter
                 /*   if (maxh<m)
                        maxh=m;*/
                }
                return ; //return
            }
        }
    }


