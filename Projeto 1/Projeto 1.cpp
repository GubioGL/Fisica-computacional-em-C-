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
    float gamma;               //~// Condições iniciais 
    cout<<" Digite o valor de Gamma da sua molecula =";
    cin >> gamma;
    float E = -1;                   // Energia normalizada between -1 and 0.
    float delta_E = 0.001;          // Incremento na energia 
                                    //~// FIM-Condições iniciais    
                                    //~// BUSCANDO OS LIMITES DE INTEGRAÇÃO //~// 
    int N = 100;                    // Quantidade de vezes que vamos dividir o intervalo entre a e b.
    float h,a,b;                    // Tamanho do intervalo.
                                    //~// FIM //~// 
                                    //~// Verificação e comparação //~//
                                    //~// Condições iniciais 
    
    fstream FILE;
    FILE.open("resultado1", ios::out);
    FILE<<"Gamma = "<<gamma<<"\n";  
    for(int n=0; n<3; n++)          // Número do estado.   
    { 
        float parametro = 1; 
        bool Q = false;
        bool P = false;
                       
        while(abs(parametro)>0.001)
        {       
            E = E + delta_E;
                                            //~// BUSCANDO OS LIMITES DE INTEGRAÇÃO //~// 
            a = Limite_inf(1.0,0.01,E);     //Limite superior. 1°- Valor maximo; 2° passos; 3° Energia
            b = Limite_sup(1.7,0.01,E);     //Limite inferiro. 1°- Valor minimo; 2° passos; 3° Energia
            h = (b-a)/N;                    //Tamanho do intervalo.1.56457
            float parametro_0 = Integral(N,h,E,a);
            float parametro_1 = (n+0.5)*M_PI/gamma;
            parametro = parametro_0 - parametro_1;
            cout << "Para a: "<<a<<" e b: "<<b<<" E : "<<E<<", obtemos = "<<parametro<<"\n";
            //FILE<<"Limite inferior :"<<a<<" superior :"<<b<<"  I- (~) ="<<parametro<<"\n";   
            if(E>-0.1){break;}

            if(parametro>0.001)
            {
                E = E - 2*delta_E;
                continue;
            }
            else if( (parametro>-0.001)&&(P==false) )
            {
                delta_E = delta_E/2;
                parametro = 1;
                P = true;
                continue;
            } // Se ele for meno que -0.001 que dizer que ele esta proximo e precisamos diminir o pasos da energia
            else if((parametro>- 0.01)&&(Q==false))
            {
                delta_E = delta_E/2;
                parametro = 1;
                Q = true;
                continue;
            }// Se ele for meno que -0.01 que dizer que esta proximo e precisamos diminuir o passo da energia
            else if(parametro<-0.000000000001){parametro = 1;}// Se ele for um numero negativo ele parae o loop logo preccisamos deixar ele positivo
            else if (isnan(parametro)){parametro = 1;continue;}// Esse caso é para quando a a diferença de NAN
        }
        cout<<"Limite inferior :"<<a<<" superior :"<<b<<"  I- (~) ="<<parametro<<" E ="<<E<<" n = "<<n<<"\n";
        FILE<<"Limite inferior :"<<a<<" superior :"<<b<<"  I- (~) ="<<parametro<<" E ="<<E<<" n = "<<n<<"\n";
    }    
    FILE.close();                   // FIM ////   
    system("pause"); //
}