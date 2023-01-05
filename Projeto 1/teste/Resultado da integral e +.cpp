#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//----------------------------------------------------------------
float F(float x,float E)
{
    float aa;
    aa =  pow(E - 4*(pow(x,-12)- pow(x,-6)) ,0.5);
    return aa;
}
//----------------------------------------------------------------
float f(float x,float E) 
{   
    float a;
    a = 4 - 4*pow(x,6) - E*pow(x,12) ; //pow(E - 4*pow(x,-12) +  4*pow(x,-6),0.5) ;
    return a;
}
//----------------------------------------------------------------
float Limite_inf(float x,float h,float E)
{   
    float x_inicial = x;
    float h_inicial = h;
    int i = 0;
    float a;
    float b;
    while(h > 0.00000001)
    {
        a = f(x,E);
        if(abs(a)<0.00000001 )
        {
            break;
        }
        x = x +h ;
        b = f(x,E);       
        if( a*b <0.00000001 )
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
    return x+0.0002;
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
        
        if( a*b <0.00000001 )
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
    return x-0.0002;
}
//----------------------------------------------------------------
float Integral( int N, float h, float E, float a)
{
                                /// INTEGRAÇÃO ///
    float A = 0;                //Variável para armazenar o cálculo de cada área. 
    for (int i = 0; i < N; i=i)
    {
        float f_0 = F(a+i*h,E);
        i++;
        float f_1 = F(a+i*h,E);  
        A = (h/2)*( f_0 + f_1)+A;
    }
    return A;
/// FIM ////
}
//Metodo de simpson
//----------------------------------------------------------------

int main()
{ 
    int n = 0;                                 
    float E = -1;                
    float delta_E = 0.001;             
    int N = 200;                 
    float h,a,b, parametro_0 ; 
    float gamma=21.7;
    //cin >>gamma;
    float parametro_1 = (n+0.5)*M_PI;

    
    fstream FILE;
    FILE.open("Integral", ios::out);
    if(FILE.is_open())
    {           
        FILE<<"Gamma = "<<gamma<<" parametro_1: "<<parametro_1<<"\n";               
        while(E<-0.1)
        {   
            E = E + delta_E;
            a = Limite_inf(1.0,0.01,E);
            b = Limite_sup(1.7,0.01,E);
            h = (b-a)/N;      
            parametro_0 = Integral(N,h,E,a)*gamma;        
            FILE<<"Lim_inf:"<<a<<" sup:"<<b<<";    E ="<<E<<" I = "<<parametro_0 - parametro_1<<"\n";
        }
    }  
    FILE.close()  ;                               /// FIM ////
}