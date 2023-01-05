#include <iostream>
#include <cmath>
#include <fstream>
#include <stdio.h>

using namespace std;

double V(double x)
{
    return 6*( 1.0/2.0 - 1.0/(cosh(x)*cosh(x)));
}
double F(double x,double E)
{
    return ( E - V(x));
}
double c_(double x,double h,double E)
{
    return 1 + 2*F(x,E)*h*h/12;
}
double c_i(double x,double h,double E)
{
    return 2 - 5*F(x,E)*h*h/6;
}
double turning_point(double E, double xii,double hh)
{
    double x,f,ff;
    while(hh>0.00001)
    {
        x  = xii;         f  = F(x,E);
        x  = xii + hh;    ff = F(x,E);
        if(f*ff<0)
        {
            hh = hh/2;
        }
        else
        {
            xii= x;
        }
    }

    return x;
}
double wave(double E,double h)
{
    double xi,xf,xii,hh,phi_0,phi_i,phi_1,max1,max2,PHI,PHI2,A1;
    double x_turning = turning_point(E,xii=0,hh=10); 
        
    phi_0 = 0; phi_i = 0.01; xi = -10 ;max1 = 0;
    while(xi <x_turning+h )
    { 
        PHI   = ( c_i( xi + h, h, E)*phi_i - c_( xi,h,E)*phi_0 )/c_( xi+2*h, h, E);
        if(abs(PHI)>max1)
        {
            max1 = abs(PHI) ;
        }
        phi_0 = phi_i;
        phi_i = PHI;
        xi = xi + h; 
    };  
        
    phi_1 = 0; phi_i = 0.01; xf= +10 ; max2 = 0;
    while(xf >x_turning-h )
    { 
        PHI2   = ( c_i( xf - h, h, E)*phi_i - c_( xf,h,E)*phi_1 )/c_(xf-2*h,h,E);
        if(abs(PHI2)>max2){max2 = abs(PHI2);}
            phi_1 = phi_i;
            phi_i = PHI2;
            xf = xf - h; 
        }
    double maximo = max1;
    if(max1<max2){maximo=max2;}
    
    A1 = ( PHI - PHI2)/maximo; 
    return A1;
}
double d_wave(double E,double h)
{
    double xi,xf,xii,hh,phi_0,phi_i,phi_1,max1,max2,PHI,PHI2,A1;
    double x_turning = turning_point(E,xii=0,hh=10); 
        
    phi_0 = 0; phi_i = 0.01; xi = -10 ;max1 = 0;
    while(xi <x_turning+h )
    { 
        PHI   = ( c_i( xi + h, h, E)*phi_i - c_( xi,h,E)*phi_0 )/c_( xi+2*h, h, E);
        if(abs(PHI)>max1)
        {
            max1 = abs(PHI) ;
        }
        phi_0 = phi_i;
        phi_i = PHI;
        xi = xi + h; 
    };  
        
    phi_1 = 0; phi_i = 0.01; xf= +10 ; max2 = 0;
    while(xf >x_turning-h )
    { 
        PHI2   = ( c_i( xf - h, h, E)*phi_i - c_( xf,h,E)*phi_1 )/c_(xf-2*h,h,E);
        if(abs(PHI2)>max2){max2 = abs(PHI2);}
            phi_1 = phi_i;
            phi_i = PHI2;
            xf = xf - h; 
        }
    double maximo = max1;
    if(max1<max2){maximo=max2;}
    
    A1 = (( PHI - phi_0) + ( PHI2- phi_1 ))/maximo; 
    return A1;
}


int main()
{
    /////////////////////  Definindo variaveis e condições inicia//////////////////////////////////////////////////////////
    double xi,xf,hh=10,x_turning,max1,max2,PHI,PHI_e,delta;
    double phi_0,phi_i,phi_1,E,h,A1,B1;
    double d_PHI,PHI2,deltai;
    double dif1,dif2,Dif1,Dif2;
    int contador=1;
    h = 0.0001 ;

    fstream FILE;                                        // DECLARANDO A VARIAVEL
    FILE.open("Data/E.csv", ios::out);                 // ABRINDO FILE PARA ESCREVER
    FILE<<"Niveis de energia encontrados :"<<"\n";     
    cout<<" Procurnado os niveis de energia"<<"\n";
    /////////////////////                       PROCURANDO AS ENERGIAS                                  /////////////////////
    deltai = 0.01;                                        // variação inicial , criada para otimizar a procura
    delta  = deltai;                                      // variação que pode ser ajustada para obter uma melhor aproximação;
    E      = -2;                                        // Energia inical da busca.
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (E<2.99)
    {   
        // Vamos realizar um busca direta //
        dif1 = wave(E,h);
        Dif1 = d_wave(E,h);
        E    = E + delta ;
        dif2 = wave(E,h);
        Dif2 = d_wave(E,h);
        //cout<<E<<"\n";
       //////////////////////////////////////////
       ////////    Condicionais      ///////
        if( (abs(dif1*dif2 ) <0.000001) && ( abs(Dif1*Dif2 ) <0.00000000000001 )  )
        {
            cout <<"Auto valor = "<< E <<"\n";
            cout<<" Procurnado outro niveis de energia ... "<<"\n";
            delta = deltai; 
            E     = E + delta ;
            contador = 1;
            
            FILE<<"E,"<< E <<"\n";   // Salvando os niveis lando 
            continue ;
        }
        if( ( dif1*dif2 < 0 ) && ( delta > 0.00001 ) && ( Dif1*Dif2 < 0 ) )
        {
            E        = E - deltai/(contador) ;
            contador = contador +2;
            delta    = delta/10;
            cout<<" Encontrei algo proximo de "<< E <<"\n";
        }       
    }
    cout<<" FIM!! "<<"\n";
    FILE.close();


}