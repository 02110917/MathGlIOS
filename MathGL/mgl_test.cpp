//
//  mgl_test.cpp
//  MathGL
//
//  Created by administrator on 15/1/26.
//  Copyright (c) 2015年 zhangmin. All rights reserved.
//

#include "mgl.h"
#include "mgl_bigmap.h"
extern "C" void test(struct mgl_bigmap *bitmap);
int sample(mglGraph *gr);
extern "C" void test(struct mgl_bigmap *bitmap)
{
    mglGraph gr;
//    gr.FSurf("x+y-8");
    sample(&gr);
//    gr.WritePNG(filename);
    bitmap->width=gr.GetWidth();
    bitmap->height=gr.GetHeight();
    bitmap->data=gr.GetRGBA();
}
void mgls_prepare2d(mglData *a, mglData *b=0, mglData *v=0)
{
     long i,j,n=50,m=40,i0;
    if(a) a->Create(n,m); if(b) b->Create(n,m);
    if(v) { v->Create(9); v->Fill(-1,1); }
    mreal x,y;
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    {
        x = i/(n-1.); y = j/(m-1.); i0 = i+n*j;
        if(a) a->a[i0] = 0.6*sin(2*M_PI*x)*sin(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
        if(b) b->a[i0] = 0.6*cos(2*M_PI*x)*cos(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
    }
}
int sample(mglGraph *gr)
{
    mglData a;
    mgls_prepare2d(&a);
    gr->SubPlot(2,2,0); gr->Title("Surf plot (default)");
    gr->Light(true); gr->Rotate(50,60); gr->Box(); gr->Surf(a);
    gr->SubPlot(2,2,1); gr->Title("’\\#’ style; meshnum 10");
    gr->Rotate(50,60); gr->Box(); gr->Surf(a,"#","meshnum 10");
    gr->SubPlot(2,2,2); gr->Title("’.’ style");
    gr->Rotate(50,60); gr->Box(); gr->Surf(a,".");
    gr->SubPlot(2,2,3); gr->Title("parametric form");
    mglData x(50,40),y(50,40),z(50,40);
    gr->Fill(x,"0.8*sin(pi*x)*sin(pi*(y+1)/2)");
    gr->Fill(y,"0.8*cos(pi*x)*sin(pi*(y+1)/2)");
    gr->Fill(z,"0.8*cos(pi*(y+1)/2)");
    gr->Rotate(50,60); gr->Box(); gr->Surf(x,y,z,"BbwrR");
    return 0;
}