// OBJETIVO : Usar o metodo de Ruge-Kutta para resolver EDO 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double f_x( double x, double y)
{
    return( - x - 2*x*y );
}
double f_y( double x, double y)
{
    return( - y - pow(x,2) + pow(y,2));
}

double PP(double E,double p_y, double x, double y)
{
    return pow( 2*E - pow(p_y,2) - pow(x,2) - pow(y,2) - 2*pow(x,2)*y  + pow(y,3)*0.6666666667 , 0.5 );
}

int main()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
{
    ////////////////////////////////////////////////////////////////////////////
    double k_1 ,k_2 ,k_3 ,k_4 ,kk_1 ,kk_2 ,kk_3 ,kk_4;          // PARA X E  Y. 
    double m_1 ,m_2 ,m_3 ,m_4 ,mm_1 ,mm_2 ,mm_3 ,mm_4;          // PARA P_X E  P_Y. 
    double x ,x_n ,p_x, px_n ,y ,y_n ,p_y , py_n;               // POSICOES E MOMENTOS.
    double y_0[6]={0.02,0.2,-0.1,-0.05,0.3,-0.12}, E=0.083334 ; // CONDIÇÕES INICIAIS.
    double p_y_0[6] = {-0.08,0,0.04,0.2,0.3,0},h = 0.1, x_0 = 0;// CONDIÇÕES INICIAIS.
    int N, N_max = 3000, i=5;
    ////////////////////////////////////////////////////////////////////////////
   
    fstream FILE;                                         // DECLARANDO A VARIAVEL
    FILE.open("E12/Data/x_zeros5.csv", ios::out);         // ABRINDO FILE PARA ESCREVER
    FILE<<"x,y,p_y"<<"\n";                                // COLACANDO TÍTULO NAS COLUNAS
    while(i<6)
    {
        //////// CONDIÇÕES INICIAS //////////////////////////////////////////////    
        x   = x_0;
        y   = y_0[i];
        p_y = p_y_0[i];
        p_x = PP(E,p_y,x,y);
        /////////////////////////////////////////////////////////////////////////
        N   = 0;
        FILE<< x <<","<< y <<","<< p_y <<"\n";             // ESCREVENDO AS C.I.
        
        while(N < N_max)
        { 
        ////////// RUNGE-KUTTA //////////////////////////////////////////////////
            k_1   = h*( p_x );
            kk_1  = h*( p_y );
            m_1   = h*f_x( x , y );
            mm_1  = h*f_y( x , y );

            k_2   = h*( p_x + 0.5*m_1 );
            kk_2  = h*( p_y + 0.5*mm_1 );
            m_2   = h*f_x( x + 0.5*k_1 , y + 0.5*kk_1 );
            mm_2  = h*f_y( x + 0.5*k_1 , y + 0.5*kk_1 );

            k_3   = h*( p_x + 0.5*m_2 );
            kk_3  = h*( p_y + 0.5*mm_2 );
            m_3   = h*f_x( x + 0.5*k_2 , y + 0.5*kk_2 );
            mm_3  = h*f_y( x + 0.5*k_2 , y + 0.5*kk_2 );

            k_4   = h*( p_x + m_3 );   
            kk_4  = h*( p_y + mm_3 );
            m_4   = h*f_x( x + k_3 , y + kk_3 );   
            mm_4  = h*f_y( x + k_3 , y + kk_3 );

            x_n   = x   + ( k_1  + 2*k_2  + 2*k_3  + k_4  )/6;
            y_n   = y   + ( kk_1 + 2*kk_2 + 2*kk_3 + kk_4 )/6;       
            px_n  = p_x + ( m_1  + 2*m_2  + 2*m_3  + m_4  )/6;
            py_n  = p_y + ( mm_1 + 2*mm_2 + 2*mm_3 + mm_4 )/6;
        //////////////////////////////////////////////////////////////////////////
        ////////// NOVAS VARIAVEIS ///////////////////////////////////////////////
            x     = x_n;
            y     = y_n;
            p_x   = px_n;
            p_y   = py_n;
            N     = N+1;
            
            FILE<< x <<","<< y <<","<< p_y <<"\n"; // GRAVAR EM FILER
        ///////////////Essa parte é pra quada os valores de x~0/////////////////////////////////////////////
            if (abs(x)<0.01)
            {
                FILE<< x <<","<< y <<","<< p_y <<"\n"; // GRAVAR EM FILER.
            } 
        
        }
        FILE<<"\n";
        i=i+1;
    }
    FILE.close();
}