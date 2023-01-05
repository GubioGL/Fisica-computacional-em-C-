#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//----------------------------------------------------------------
float F(float x,float E)
{
    float aa;
    aa =  pow(E - 4*(pow(x,-12)- pow(x,-6))  ,1/2);
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

int main()
{   
    float b =Limite_sup(1.7,0.01,-0.99);
    float a =Limite_inf(0.5,0.01,-0.99);
    cout<<"Limite inferiro :"<<a<<"\n"; // 1° x;  2° h ; 3° Energia; 
    cout<<"Limite Superior :"<<b<<"\n"; // 1° x;  2° h ; 3° Energia;
    cout<<"Test inferiorF-> "<< F(a,-0.99)<<"\n";
    cout<<"Test SuperiorF-> "<< F(b,-0.99)<<"\n";
    cout<<"Test inferior-> "<< f(a,-0.99)<<"\n";
    cout<<"Test Superior-> "<< f(b,-0.99)<<"\n";
}