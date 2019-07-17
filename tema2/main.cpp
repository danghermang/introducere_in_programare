#include "exercises.h"
unsigned int computeFactorial(unsigned int number)
{
    int n=number,s=1;
    while(n>0)
        {
            s=s*n;
            n--;
        }
    return s;
}
unsigned int countTrailingZeroes(unsigned int number)
{
    int k=0,nr=computeFactorial(number);
    while(nr%10==0)
    {
        k++;
        nr=nr/10;
    }
    return k;
}

double max(double a, double b, double c)
{
    int maxim=a;
    if(maxim<b)
        maxim=b;
    if(maxim<c)
        maxim=c;
    return maxim;
}

double min(double a, double b, double c)
{
    int minim=a;
    if(minim>b)
        minim=b;
    if(minim>c)
        minim=c;
    return minim;
}

double arithmeticMean(double a, double b, double c)
{
    return (a+b+c)/3;
}

double geometricMean(double a, double b, double c)
{
    if(a*b*c>0)
        return pow(a*b*c,1.0/3.0);
    else
        return -pow(a*b*c,1.0/3.0);
}

double harmonicMean(double a, double b, double c)
{
    if(a==0&&b==0&&c==0)
        return 0;
    return (3*a*c*b)/(b*c+c*a+a*b);
}



bool canBeTriangle(double a, double b, double c)
{
    if(a==0||b==0||c==0)
        return 0;
    if((a+b<=c)||(c+a<=b)||(c+b<=a))
        return 0;
    return 1;
}


TriangleShapeByAngle classifyTriangleByAngle(Triangle t)
{
     double a=t.a,b=t.b,c=t.c;
     double cosa,cosb,cosc;
     if(a==0||b==0||c==0)
        return NoAngleTriangleType;
     cosa=(b*b+c*c-a*a)/(2*b*c);
     cosb=(a*a+c*c-b*b)/(2*a*c);
     cosc=(a*a+b*b-c*c)/(2*a*b);
     if((cosa==0)||(cosb==0)||(cosc==0))
        return RightTriangle;
     if((cosa<0)||(cosb<0)||(cosc<0))
        return ObtuseTriangle;
     if((cosa>0)&&(cosb>0)&&(cosc>0))
        return AcuteTriangle;
}

TriangleShapeBySide classifyTriangleBySide(Triangle t)
{
    double a=t.a,b=t.b,c=t.c;
    if((a==b)&&(b==c)&&(c==a))
        return EquilateralTriangle;
    else
        if((a==b)||(b==c)||(a==c))
                return IsoscelesTriangle;
    if((a>0&&b>0&&c>0)&&(a+b>c)&&(a+c>b)&&(b+c>a))
        return ScaleneTriangle;
    else
        return NoSideTriangleType;
}

double computePerimeter(Triangle t)
{
    if (canBeTriangle(t.a,t.b,t.c)==0)
        return 0;
    return t.a+t.b+t.c;
}

double computeArea(Triangle t)
{
    if (canBeTriangle(t.a,t.b,t.c)==0)
        return 0;
    double p=(t.a+t.b+t.c)/2;
    return sqrt(p*(p-t.a)*(p-t.b)*(p-t.c)); //formula lui Heron
    //Alte 2 metode sunt l*h/2 (l fiind o latura a triunghiului iar h inaltimea respectiva laturii date) si a*b*c/4*R ( a,b,c fiind laturile triunghiului iar R raza cercului circumscris)

}

double getMaxMedian(Triangle t)
{
    double ma,mb,mc,a=t.a,b=t.b,c=t.c;
    if (canBeTriangle(a,b,c)==0)
        {return 0;}
    ma=sqrt((2*b*b+2*c*c-a*a)/4);
    mb=sqrt((2*a*a+2*c*c-b*b)/4);
    mc=sqrt((2*a*a+2*b*b-c*c)/4);
    return max(ma,mb,mc);
}

double getMinHeight(Triangle t)
{
    double ha,hb,hc,aria,a=t.a,b=t.b,c=t.c;
    if (canBeTriangle(a,b,c)==0)
        {return 0;}
    aria=computeArea(t);
    ha=aria*2/a;
    hb=aria*2/b;
    hc=aria*2/c;
    return min(ha,hb,hc);

}

Vector getSquares(double a, double b, double c)
{
    double maxim,minim,aux;
    Vector v;
    v.length=0;
    if(a<0)
        {a=-a;}
    if(b<0)
        {b=-b;}
    if(c<0)
        {c=-c;}
    maxim=max(a,b,c);
    minim=min(a,b,c);
    for(int i=0;i<=maxim;i++)
    {
        if(i*i>=minim&&i*i<=maxim)
            {
                v.values[v.length]=i;
                v.length++;
                v.values[v.length]=-i;
                v.length++;
            }
        if(i*i>maxim)
            {break;}
    }
    return v;
}

Vector getCubes(double a, double b, double c)
{
    double maxim,minim,aux;
    Vector v;
    v.length=0;
    maxim=max(a,b,c);
    minim=min(a,b,c);
    if(minim>=0)
    {
        for(int i=0;i<=maxim;i++)
        {
            if(i*i*i>=minim&&i*i*i<=maxim)
                {
                    v.values[v.length]=i;
                    v.length++;
                }
            if(i*i*i>maxim)
                {break;}
        }
    }
    else {
            if(maxim<0)
            {
              aux=maxim;
              maxim=-minim;
              minim=-aux;
              for(int i=0;i<=maxim;i++)
                {
                    if(i*i*i>=minim&&i*i*i<=maxim)
                        {
                            v.values[v.length]=-i;
                            v.length++;
                        }
                    if(i*i*i>maxim)
                        {break;}
                }
            }
            else
            {
               for(int i=0;i<=maxim;i++)
                {
                    if(i*i*i>=0&&i*i*i<=maxim)
                        {
                            v.values[v.length]=i;
                            v.length++;
                        }
                    if(i*i*i>maxim)
                        {break;}
                }
                for(int i=0;i<=-minim;i++)
                {
                    if(i*i*i>0&&i*i*i<=-minim)
                        {
                            v.values[v.length]=-i;
                            v.length++;
                        }
                    if(i*i*i>-minim)
                        {break;}
                }
            }
        }
    return v;
}

Vector getNthRoots(double a, double b, double c, int n)
{
    double maxim,minim,aux;
    Vector v;
    v.length=0;
    maxim=max(a,b,c);
    minim=min(a,b,c);
    if(minim>=0)
    {
        for(int i=0;i<=maxim;i++)
        {
            if(pow(i,n)>=minim&&pow(i,n)<=maxim)
                {
                    v.values[v.length]=i;
                    v.length++;
                }
            if(pow(i,n)>maxim)
                {break;}
        }
    }
    else {
            if(maxim<0)
            {
              aux=maxim;
              maxim=-minim;
              minim=-aux;
              for(int i=0;i<=maxim;i++)
                {
                    if(pow(i,n)>=minim&&pow(i,n)<=maxim)
                        {
                            v.values[v.length]=-i;
                            v.length++;
                        }
                    if(pow(i,n)>maxim)
                        {break;}
                }
            }
            else
            {
               for(int i=0;i<=maxim;i++)
                {
                    if(pow(i,n)>=0&&pow(i,n)<=maxim)
                        {
                            v.values[v.length]=i;
                            v.length++;
                        }
                    if(pow(i,n)>maxim)
                        {break;}
                }
                for(int i=0;i<=-minim;i++)
                {
                    if(pow(i,n)>0&&pow(i,n)<=-minim)
                        {
                            v.values[v.length]=-i;
                            v.length++;
                        }
                    if(pow(i,n)>-minim)
                        {break;}
                }
            }
        }
    return v;
}

DiophantineSolution solveDiophantineEquation(DiophantineEquation e)
{
    DiophantineSolution s;
    int a,b,cmmdc,z;
    a=e.a;
    b=e.b;
    while(a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;
    cmmdc=a;
    if (cmmdc%e.c!=0)
    {
        s.hasSolutions=0;
        s.ax=0;
        s.bx=0;
        s.ay=0;
        s.by=0;
    }
    else
        s.hasSolutions=1;
    z=e.c/cmmdc;
    return s;
}

void get_complex_number(Complex c1)
{
    cin>>c1.a;
    cin>>c1.b;
}
Complex sum(Complex c1, Complex c2)
{
    Complex c3;
    c3.a=c1.a+c2.a;
    c3.b=c1.b+c2.b;
    return c3;
}

Complex product(Complex c1, Complex c2)
{
    Complex c3;
    c3.a=c1.a*c2.a-c1.b*c2.b;
    c3.b=c1.b*c2.a+c1.a*c2.b;
    return c3;
}
