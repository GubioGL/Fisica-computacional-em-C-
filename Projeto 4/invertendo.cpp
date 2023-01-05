#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>

using namespace std;

int main()
{
    int n,value,value1,i=0,precisao;
    
    double alpha_k,eta_k,soma;
    string m,m1;
    int entrada;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////                Condições inicias para o usuario        //////////////////////////////////////////////////////
    cout<< "Type 1 if you dont want type a matrix"<<endl;
    cin>> entrada; 
    cout <<"What is the dimension of the matrix " << "\n";
    cin >>n;

    string A[2*n][2*n];
    float M[2*n][2*n], A_n[n][n],M_invertida[2*n][2*n];

    if (entrada==1)
    {     //// Fiz essa parte para não ficar digirando toda hora  
            M[0][0]=5 ;M[0][1]=4 ;M[0][2]=2 ;M[0][3]=0 ;M[0][4]=7 ;M[0][5]=-1;
            M[1][0]=4 ;M[1][1]=1 ;M[1][2]=3 ;M[1][3]=-7;M[1][4]=0 ;M[1][5]=4 ;
            M[2][0]=2 ;M[2][1]=3 ;M[2][2]=8 ;M[2][3]=1 ;M[2][4]=-4;M[2][5]=0 ;
            M[3][0]=0 ;M[3][1]=-7;M[3][2]=1 ;M[3][3]=5 ;M[3][4]=4 ;M[3][5]=2 ;
            M[4][0]=7 ;M[4][1]=0 ;M[4][2]=-4;M[4][3]=4 ;M[4][4]= 1;M[4][5]=3 ;
            M[5][0]=-1;M[5][1]=4 ;M[5][2]=0 ;M[5][3]=2 ;M[5][4]=3 ;M[5][5]=8 ;      
         
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"--------------------------------------------"<<"\n";
    cout <<"-------   View od the Matrices  ------------"<<"\n";
    cout <<"--------------------------------------------"<<"\n";

    cout <<"\n";
    cout <<"A'[nxn]:"<<"\n";
    cout <<"[";
    for(int i=0;i<n*2;i++)
    {
        cout <<"[";
        for(int j=0;j<n*2;j++)
        {            
            cout <<M[i][j];
            M_invertida[i][j] = M[i][j];
            cout<< ",";
        }
        cout <<"]"<<"\n";
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    cout <<"---------------------------------------------"<<"\n";
//    cout <<"-------------- Eigenvector ------------------"<<"\n";
    double I[2*n][2*n];
    /// 2° Criando a matrix identidade
    cout <<"\n";
    cout <<"I[nxn]:"<<"\n";
    cout <<"[";
    for (int i=0; i<n*2; i++)
    {
        cout <<"[";
        for (int j=0; j<n*2; j++)
        {
            if(i==j)
            {
                I[i][j]=1;

                cout <<I[i][j];
                cout<< ",";
            }
            else
            {
                I[i][j]=0;
                cout <<I[i][j];
                cout<< ",";
            }

        }
        cout <<"]"<<"\n";
    }
   
    cout <<"------   Invertendo a matriz   ----------------"<<"\n";
    ///     3°
    for (int j=0; j<n*2; j++)
    {
        bool Rep=true;
        for (int i=0; i<n*2; i++)
        {    
            /// i e j ira serve como idice para guiar qual elemento anular 
            if(i==j)
            {
                continue;/// Não podemos anular o elemento i==j
            } 
            else if(i<j)
            {
                if (Rep ==true)
                {
                    double normalizar =M_invertida[j][j];
                    for(int jj=0; jj<n*2 ; jj++)
                    {
                        M_invertida[j][jj] = (M_invertida[j][jj])/normalizar;
                        I[j][jj] = (  I[j][jj]  )/normalizar;
                        Rep = false;
                        //cout<<"M_invertida[i+1][jj]"<<M_invertida[j][jj]<<"\n";
                    }
                }

                /// 2° Zera termo da linha i j
                double constante= M_invertida[i][j];
                
                for (int jj=0; jj<n*2; jj++)
                {
                    M_invertida[i][jj] = -constante*M_invertida[j][jj] + M_invertida[i][jj]; 
                    I[i][jj] = -constante*I[j][jj] + I[i][jj];
                    //cout<<" M_invertida[i][jj] " <<M_invertida[i][jj]<<"\n";
                    //cout<<" i "<<i<<" j "<<j<<"\n";
              } 
            }
            else if (i>j) /// i<j parte de baixo da diagonal.
            {
                /// 1° Dividindo tudo por termo [i][i]
                
                if (Rep ==true)
                {
                    double normalizar =M_invertida[j][j];
                    for(int jj=0; jj<n*2 ; jj++)
                    {
                        M_invertida[i-1][jj] = (M_invertida[i-1][jj])/normalizar;
                        I[i-1][jj] = (  I[i-1][jj]  )/normalizar;
                        Rep = false;
                    }
                }

                /// 2° Zera termo da linha i j
                double constante= M_invertida[i][j];
                for (int jj=0; jj<n*2; jj++)
                {
                    M_invertida[i][jj] = -constante*M_invertida[j][jj] + M_invertida[i][jj]; 
                    I[i][jj] = -constante*I[j][jj] + I[i][jj];
                    //cout<<" M_invertida[i][jj] " <<M_invertida[i][jj]<<"\n";
                    //cout<<" i "<<i<<" j "<<j<<"\n";
                }
            }
        }               
    }
  
    cout <<"\n";
    cout <<"M^T[nxn]:"<<"\n";
    cout <<"[";
    for(i=0;i<n*2;i++)
    {
        cout <<"[";
        for(int j=0;j<n*2;j++)
        {
            cout <<M_invertida[i][j];
            cout<< ",";
        }
        cout <<"]"<<"\n";
    }

    cout <<"\n";
    cout <<"I[nxn]:"<<"\n";
    cout <<"[";
    for (int i=0; i<n*2; i++)
    {
        cout <<"[";
        for (int j=0; j<n*2; j++)
        {
            if(i==j)
            {

                cout <<I[i][j];
                cout<< ",";
            }
            else
            {
                cout <<I[i][j];
                cout<< ",";
            }

        }
        cout <<"]"<<"\n";
    }


}