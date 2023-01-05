// OBJETIVO : Usar o metodo de Ruge-Kutta para resolver EDO 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double f(double t, double x)
{
    return(x*0.5+t);
}


int main()
{
    double k_1,k_2,k_3 ,k_4,kk_1,kk_2,kk_3 ,kk_4;   // ABGULO DE RK. 
    double t_0 = 0.0 , x_0 = 0.0 , v_0 = 0.0;              // TEMPO/POSIÇÂO INICIAL.
    double t,x,x_n,v,v_n;                                    // POSIÇÃO.
    double t_f = 5;                                  // TEMPO FINAL.
    int    N   = 1000;                                // NUMEROS DE PASSOS. 
    double h   = ( t_f - t )/N;                      // TAMANHO DOS PASSO.

    x = x_0;
    t = t_0;
    v = v_0;
    cout<< "x(t=0) = "<<x<<" t ="<<t<<" v = "<<v<<"\n";
    
    fstream FILE;
    FILE.open("Dados", ios::out);
    FILE <<t<<"\t"<<x<<t<<"\t"<<v<<"\n";
    while(t<t_f-h)
    { 
        k_1  = h*f( t         , x           );
        kk_1 = h*(  v          );
        k_2  = h*f( t + 0.5*h , x + 0.5*kk_1);
        kk_2 = h*(  v + 0.5*k_1);
        k_3  = h*f( t + 0.5*h , x + 0.5*kk_2);
        kk_3 = h*(  v + 0.5*k_2);
        k_4  = h*f( t +     h , x +     kk_3);
        kk_4 = h*(  v +     k_3);
        
        v_n  = v + ( k_1  + 2*k_2  + 2*k_3  + k_4  )*0.16666666666;
        x_n  = x + ( kk_1 + 2*kk_2 + 2*kk_3 + kk_4 )*0.16666666666;

        x    = x_n;
        v    = v_n;
        t    = t+h;
        FILE <<t<<"\t"<<x<<"\t"<<v<<"\n";

    }
    FILE.close();
    cout<<"\n A data foi gerada com sucesso! \n\n";

}