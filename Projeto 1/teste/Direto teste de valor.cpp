#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//----------------------------------------------------------------
float f(float x,float E)
{   
    float a;
    a = 4 - 4*pow(x,6) - E*pow(x,12) ; 
    return a;
}
//----------------------------------------------------------------
float F(float x,float E)
{
    float aa;
    aa =  pow(E - 4*(pow(x,-12)- pow(x,-6))  ,1/2);
    return aa;
}
//----------------------------------------------------------------
float Limite_inf(float x,float h,float E)
{   
    float x_inicial = x;
    float h_inicial = h;
    int i = 0;
    float a;
    float b;
    while(h > .00000001)
    {
        a = f(x,E);
        if(abs(a)<0.00000001 )
        {
            break;
        }
        x = x +h ;
        b = f(x,E);
        
        if( a*b <0.000000001 )
        {
            x = x-h;
            h = h/2;
        }
        //cout<<"f(x,E):"<<f(x,E)<<" x "<<x<<" h ="<<h<<"\n";
        i ++;
        if (i>4000)
        {   
            //cout<<" Cansei a";
            break;
        }
        else if (i>2000)
        {   
            //cout<<" Vou tentar mais uma vez com h/2";
            
            h=h_inicial/2;
            x = x_inicial;
        }
    }
    return x+0.00001;
}
//----------------------------------------------------------------
float Limite_sup(float x,float h,float E)
{   
    float x_inicial = x;
    float h_inicial = h;
    int i = 0;
    float a;
    float b;
    while(h > 0.00000001)
    {
        a = f(x,E);
        if(abs(a)<0.00000001 ){break;}
        x = x - h;
        b = f(x,E);
        
        if( a*b < 0.000000000001 )
        {
            x = x+h;
            h = h/2;
        }
        //cout<<"f(x,E):"<<f(x,E)<<" x "<<x<<" h ="<<h<<"\n";
        i ++;
        if (i>4000)
        {   
            //cout<<" Cansei b";
            break;
        }
        if (i>1000)
        {   
            //cout<<" Vou tentar mais uma vez com h/2";
            
            h = h_inicial/2;
            x = x_inicial;
        }
    }
    return x-0.00001;
}
//----------------------------------------------------------------
float Integral( int N, float h, float E, float a)
{
    float A = 0;               
    for (int i = 0; i < N; i=i)
    {
        float f_0 = F(a+i*h,E);
        i++;
        float f_1 = F(a+i*h,E);  
        A = (h/2)*( f_0 + f_1)+A;
    }
    return A;
}
//----------------------------------------------------------------

int main()
{ 
    int   n = 0;                                                           
    int   N = 1000;                 
    float h,a,b,parametro_0 ; 
    float gamma = 21.7;
    float parametro_1 = (n+0.5)*M_PI/gamma;
   
    fstream FILE;
    FILE.open("Integral Direto teste", ios::out);
    if(FILE.is_open())
    {           
        FILE<<"Gamma = "<<gamma<<" parametro_1: "<<parametro_1<<"\n";               
        float E = -0.7727;;
        a = 1.05224;
        b = 1.24833;
        h = (b-a)/N;      
        parametro_0 = Integral(N,h,E,a);        
        FILE<<"Lim_inf: "<<a<<" sup: "<<b<<";    E ="<<E<<" I = "<<parametro_0<<"\n";
    }  
    FILE.close()  ;                     
}