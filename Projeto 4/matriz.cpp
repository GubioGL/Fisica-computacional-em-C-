#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>

using namespace std;

int main()
{
    int n,value,value1,i=0,precisao,entrada;
    double alpha_k,eta_k,soma;
    string m,m1;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////                Condições inicias para o usuario        //////////////////////////////////////////////////////
    cout<< "Type 1 if you dont want type a matrix"<<endl;
    cin>> entrada; 
    cout <<"What is the dimension of the matrix " << "\n";
    cin >>n;
    cout <<"What is the precision of elements of matriz " << "\n";
    cin >>precisao;
    string A[n][n];
    float M[2*n][2*n], A_n[2*n][2*n],M2[2*n][2*n];
    /// M é a matriz original 2nx2n.
    ///  A_n é a matriz original 2x2 uso apenas para printar os elementos
    /// M2 é uma copia de M para manipular 

    if (entrada==1)
    {         //// Fiz essa parte para não ficar digirando toda hora  
        if(n==3)
        {  
            M[0][0]=5 ;M[0][1]=4 ;M[0][2]=2 ;M[0][3]=0 ;M[0][4]=7 ;M[0][5]=-1;
            M[1][0]=4 ;M[1][1]=1 ;M[1][2]=3 ;M[1][3]=-7;M[1][4]=0 ;M[1][5]=4 ;
            M[2][0]=2 ;M[2][1]=3 ;M[2][2]=8 ;M[2][3]=1 ;M[2][4]=-4;M[2][5]=0 ;
            M[3][0]=0 ;M[3][1]=-7;M[3][2]=1 ;M[3][3]=5 ;M[3][4]=4 ;M[3][5]=2 ;
            M[4][0]=7 ;M[4][1]=0 ;M[4][2]=-4;M[4][3]=4 ;M[4][4]= 1;M[4][5]=3 ;
            M[5][0]=-1;M[5][1]=4 ;M[5][2]=0 ;M[5][3]=2 ;M[5][4]=3 ;M[5][5]=8 ;      
         
           /* M[0][0]=1 ;M[0][1]=2 ;M[0][2]=3 ;
            M[1][0]=-3;M[1][1]=1 ;M[1][2]=5 ;
            M[2][0]=2 ;M[2][1]=3 ;M[2][2]=-1;*/
        }
        else if(n==2)
        {
            M[0][0]=4 ;M[0][1]=0 ;M[0][2]=0 ;M[0][3]=2 ;//M[0][4]=7 ;M[0][5]=-1;
            M[1][0]=0 ;M[1][1]=2 ;M[1][2]=-2;M[1][3]=0 ;//M[1][4]=0 ;M[1][5]=4 ;
            M[2][0]=0 ;M[2][1]=-2;M[2][2]=4 ;M[2][3]=0 ;//M[2][4]=-4;M[2][5]=0 ;
            M[3][0]=2 ;M[3][1]=0 ;M[3][2]=0 ;M[3][3]=2 ;//M[3][4]=4 ;M[3][5]=2 ;
            //M[4][0]=7 ;M[4][1]=0 ;M[4][2]=-4;M[4][3]=4 ;M[4][4]= 1;M[4][5]=3 ;
            //M[5][0]=-1;M[5][1]=4 ;M[5][2]=0 ;M[5][3]=2 ;M[5][4]=3 ;M[5][5]=0 ;
        }
        else{cout<<"Dont have matrix for this dimension. Try n=2 or n= 3. By!";}

        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            value = M[i][j];
            value1= M[i+n][j];
            
            if (value==0)
            {
                if (value1==0)
                {
                    A[i][j] = "   ";
                }
                else if (value1==1)
                {
                    A[i][j] = " i ";
                }
                else if (value1==-1)
                {
                    A[i][j] = " -i ";
                }
                else
                {
                    m1= to_string(value1);
                    A[i][j] = m1+"i ";
                }
            }
            else
            {
                m = to_string(value);
                m1 = to_string(value1);

                if (value1==0)
                {
                    A[i][j] =" "+ m +" ";
                }
                else if (value1==1)
                {
                    A[i][j] = m+" + i";
                }
                else if (value1==-1)
                {
                    A[i][j] = m+" - i";
                }
                else if (value1<0)
                {
                    A[i][j] = m+" "+ m1 + "i";
                }
                else 
                {
                    A[i][j] = m+" + "+ m1 + "i";
                }        
            }
            }
        }
    }
    else
    {
    ////               Essa parte é para esscrever a matriz nxn    
        cout <<"Type x and y value of complex number(x+iy)"<<"\n";
        cout <<" In the format-> x space y"<<"\n";    
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            cout << "A[" << i+1 << "][" << j+1 << "]:" << "\n";
            cin >>value>>value1;
            
            if (value==0)
            {
                if (value1==0)
                {
                    A[i][j] = " 0  ";
                }
                else if (value1==1)
                {
                    A[i][j] = " i ";
                }
                else if (value1==-1)
                {
                    A[i][j] = " -i ";
                }
                else
                {
                    m1= to_string(value1);
                    A[i][j] = m1+"i ";
                }
            }
            else
            {
                m = to_string(value);
                m1 = to_string(value1);

                if (value1==0)
                {
                    A[i][j] =" "+ m +" ";
                }
                else if (value1==1)
                {
                    A[i][j] = m+" + i";
                }
                else if (value1==-1)
                {
                    A[i][j] = m+" - i";
                }
                else if (value1<0)
                {
                    A[i][j] = m+" "+ m1 + "i";
                }
                else 
                {
                    A[i][j] = m+" + "+ m1 + "i";
                }        
            }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////           Essa parte é para escrever a matriz 2nx2n     //////////////////////////////////////////////////////
            M[ i ][ j ] = value ;
            M[i+n][ j ] = value1 ;
            M[ i ][j+n] = -value1 ;
            M[i+n][j+n] = value ;
            //cout << "R(M)[" << i+1 << "][" << j+1 << "]:"<<M[i][j];
            //cout <<" IM(M)["<< i+n+1<< "][" << j+1 << "]:"<<M[i+n][j]<< "\n";
            }
        }
  
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"--------------------------------------------"<<"\n";
    cout <<"-------   View of the Matrices  ------------"<<"\n";
    cout <<"--------------------------------------------"<<"\n";
    cout <<"A[nxn]:"<<"\n";
    cout <<"[";
    for(i=0;i<n;i++)
    {
        cout <<"[";
        for(int j=0;j<n;j++)
        {   
            if((j>0)&&(j<n)){cout<< ",";}
            cout <<A[i][j];if((j==n-1)&&(i==n-1)){cout<<"]"<<"\n";}
        }
        cout <<"]"<<"\n";
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"\n";
    cout <<"A'[2nx2n]:"<<"\n";
    cout <<"[";
    for(i=0;i<2*n;i++)
    {
        cout <<"[";
        for(int j=0;j<2*n;j++)
        {
            if((j>0)&&(j<2*n)){cout<< ",";}
            cout <<M[i][j];
            M2[i][j] =M[i][j];                                                 /// copia de M 
            if((j==2*n-1)&&(i==2*n-1)){cout<<"]"<<"\n";}
        }
        cout <<"]"<<"\n";
    }
    cout<<fixed<<setprecision(precisao);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"--------------------------------------------"<<"\n";
    cout <<"----------- Tridiagonalization -------------"<<"\n";
    cout <<"---------------------------------------------"<<"\n";

    for(int k =1;k<=2*n-2;k++)
    {   
        //cout<<"k = "<<k<<"\n";
        soma = 0;                                                                   /// Variavel para armazenar a soma.
        for(i = k; i<2*n; i++)  
        {
            soma =  soma + pow(M2[k-1][i],2);                                        /// Realizando uma soma
            
        }
        alpha_k = pow( soma ,0.5);                                                  /// Calculando alpha com a soma 
        //cout<<"alpha"<< alpha_k<<"\n"; //verificado 
        if(alpha_k*M2[k-1][k] <0)
        {
            //cout<< "alpha e A[k][k+1] tem sinais diferentes";
            //cout<< "alpha "<<alpha_k;
            //cout<< "A[k][k+1] "<<M[k-1][k];
            alpha_k= -alpha_k;
  
        } /// Verificando se alpha tem o mesmo sinal que M[k][k+1]
        if((abs(alpha_k) <0.0000000001)||(alpha_k==0))
        {
            //cout<< "alpha is zero, so jump!"<<"\n";
            continue;
        }
        eta_k = alpha_k*( alpha_k + M2[k-1][k] );  
        //cout<<"M[k-1][k]"<<M[k-1][k]<<"\n";                                       /// Calculando eta 
        //cout<<"eta_k:"<< eta_k<<"\n"; 
        float w_k[2*n], O_k[2*n][2*n], AO[2*n][2*n];
        //cout<<"w_k=[";
        for( int l=0 ; l<2*n ; l++ )                                               /// Calculando o vetor w_k
        {
            if( l<= k-1 ){ w_k[l] = 0; }
            else if(l== k){ w_k[l] = M2[k-1][l] + alpha_k;}
            else if(l>=k+1){ w_k[l] = M2[k-1][l];} 
            //cout<< w_k[l]<<",";  //verificado 
        }
        //cout<<"]"<<"\n";
        //cout<<"O_k :"<<"\n";
        for(int i=0 ; i<2*n ; i++ )                                                ///  Calculando  O_k
        {
            //cout<<"[";
            for(int j=0 ; j<2*n ; j++ )
            {

                if(i==j)
                {
                    O_k[i][j]= 1 - w_k[i]*w_k[j]/eta_k;
                    //cout<< O_k[i][j];
                }
                else
                {
                    O_k[i][j]= - w_k[i]*w_k[j]/eta_k;
                    //cout<< O_k[i][j] ;
                }
                //cout<<", ";
            }
            //cout<<"]\n";
        }
        //cout<<"AO :"<<"\n";
        for(int i=0 ; i<2*n ; i++ )                                                ///  Calculando  O_k
        {
            //cout<<"[";
            for(int j=0 ; j<2*n ; j++ )
            {
                double A_O=0;
                for(int ii=0 ; ii<2*n ; ii++ )                                        ///  Calculando  A_k*O_k 
                {
                    A_O = A_O + M2[i][ii]*O_k[ii][j];
                }
                AO[i][j] =A_O;// round(A_O);
                //cout<< AO[i][j]<<", ";
            }
            //cout<<"]\n";
        }
        cout<<"OAO :"<<"\n";
        for(int i=0 ; i<2*n ; i++ )                                                ///  Calculando  [O_k]^T*A_k*O_k
        {
            cout<<"[";
            for(int j=0 ; j<2*n ; j++ )
            {
                double A_O=0;
                for(int ii=0 ; ii<2*n ; ii++ )
                {
                    A_O = A_O + O_k[ii][i]*AO[ii][j];
                }
                M2[i][j] =   A_O ;
                A_n[i][j] =   A_O ;
                //cout<<setprecision(precisao)<<fixed;
                cout<< M2[i][j]<< ", ";
            }
            cout<<"]\n";
        }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"---------------------------------------------"<<"\n";
    cout <<"------ Characteristic polynomials -----------"<<"\n";
    cout <<"---------------------------------------------"<<"\n";

    double P_n[2*n+2],lambda_inicial,delta;
    double lambda[2*n];
    int contador,indice_autovalor =0;
    float A_maxi_mini=0;
    bool bole=false,bole2=false,bole3=false;

    P_n[0] = 0;
    P_n[1] = 1;

    for(int j=0; j<2*n ;j++)                                           /// Determinando o máximo e mínimo do loop.
    {
        for(int i=0; i<2*n ;i++)
        {
            A_maxi_mini = A_maxi_mini +abs(A_n[j][i]);                         /// Calculando o valor inicial para o chute
        }   
    }
    lambda_inicial = - A_maxi_mini ; 
    cout<<"Esta iniciando de "<< lambda_inicial <<" ate "<<A_maxi_mini<<"\n";
    
    //cout <<"\n";
    if(n==2)
    {
        delta  = 0.00001;
    }
    else
    {
        delta  = 0.00001;
    }
                                                                                    
    while(lambda_inicial <A_maxi_mini)                                 /// Loop para encontrar os Auto=valores.
    {     
        for(int j=0; j<2*n;j++)                                         
        {                                                               /// Aqui vou calcular todos os polinimio para o chute inicial 
            P_n[j+2] = ( A_n[j][j] - lambda_inicial )*P_n[j+1] - pow(A_n[j][j-1],2)*P_n[j] ;  
            contador = j;
        } 
        if( (abs(P_n[contador+2]) < 0.01  )&&( bole == false) )
        {                                                               /// Verificando se esse chute foi bom o suficiente 
            lambda_inicial = lambda_inicial- 100*delta;
            delta = delta/10;
            bole  = true;
        
        }
        else if ((abs(P_n[contador+2])<0.1  )&&( bole2 == false))
        {
            lambda_inicial = lambda_inicial- 100*delta;
            delta = delta/10;
            bole2 =true;     
         
        }
        else if ((n!=2)&&(abs(P_n[contador+2])<10  )&&( bole3 == false))
        {
            lambda_inicial = lambda_inicial- 100*delta;
            delta = delta/10;
            bole3 =true;             
            cout<<"Encontrei algo ! "<<"\n";   
        }
        if( abs(P_n[contador+2])<0.00002)                                /// Verificando se esse chute foi bom o suficiente 
        {                 
            lambda[indice_autovalor]= lambda_inicial; 
            cout<<" Auto valor encontrado : "<<lambda[indice_autovalor]<<"\n";
            delta = 0.000001;
            bole   = false;
            bole2  = false;
            bole3  = false;
            lambda_inicial   = lambda_inicial + 0.1 ;
            indice_autovalor = indice_autovalor +1 ;
        }
 
        lambda_inicial = lambda_inicial + delta;                        /// Dano o passo.    
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout <<"\n";
    cout <<"--------------------------------------------"<<"\n";
    cout <<"----- Eigenvector and Eigenvaluer ----------"<<"\n";
    cout <<"--------------------------------------------"<<"\n";
    cout <<"\n";
    //double Eigenvectot[2*n],
    
    double ETA = 0, vector[2*n], I[2*n][2*n],M_invertida[2*n][2*n];
    /// 1° Criando a matriz para vai ser invertida.
    int contador2=0;
    while(contador2<indice_autovalor)
    {
        double LAMBDA = lambda[contador2];
        cout<< ">>> AUTO-VALOR ="<<LAMBDA<<"  <<<"<<"\n";
        cout<< " Matrix que queremos inverter  :"<<"\n";
        //cout <<" M:"<<"\n";
        cout <<"[";
        for (int i=0; i<2*n; i++)
        {
            cout <<"[";
            for (int j=0; j<2*n; j++)
            {
                if (i==j)
                {
                    M_invertida[i][j] = M[i][j]-LAMBDA ;
                    cout <<M_invertida[i][j];
                    cout<< ",";      //// A - Lamb*I -lambda[indice_autovalor]
                }
                else
                {
                    M_invertida[i][j] = M[i][j];
                    cout <<M[i][j];
                    cout<< ",";
                }
            }
            cout <<"]"<<"\n";
        }
        /// 2° Criando a matrix identidade
        cout <<"\n";
        //cout <<"I:"<<"\n";
        //cout <<"[";
        for (int i=0; i<2*n; i++)
        {
            //cout <<"[";
            for (int j=0; j<2*n; j++)
            {
                if(i==j)
                {
                    I[i][j]=1;
                    //cout<< ",";
                    //cout <<I[i][j];
                    //cout<< ",";
                }
                else
                {
                    I[i][j]=0;
                    //if((j>0)&&(j<n)){cout<< ",";}
                    //cout <<I[i][j];
                    //cout<< ",";
                }

            }
            //cout <<"]"<<"\n";
        }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//        cout <<"\n";
//        cout <<">>>---------------------------------------------<<<"<<"\n";
//        cout <<">>>---------------- Sub-rotina ----------------<<<"<<"\n";
//        cout <<"---------   Invertendo a matriz...   -----------<<<"<<"\n";
//        cout <<"\n";
//        
        for (int j=0; j<2*n; j++)
        {
            bool Rep=true;
            for (int i=0; i<2*n; i++)
            {    
                //cout<<" i "<<i<<" j "<<j<<"\n";
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
                        for(int jj=0; jj<2*n ; jj++)
                        {
                            M_invertida[j][jj] = (M_invertida[j][jj])/normalizar;
                            I[j][jj] = (  I[j][jj]  )/normalizar;
                            Rep = false;
                            //cout<<"M_invertida[i+1][jj]"<<M_invertida[j][jj]<<"\n";
                        }
                    }

                    /// 2° Zera termo da linha i j
                    double constante= M_invertida[i][j];
                    if (abs(constante)<0.0001){continue;} /// se ja for zero mandie pular o elemento 
                    for (int jj=0; jj<2*n; jj++)
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
                        for(int jj=0; jj<2*n ; jj++)
                        {
                            //cout << "M_invertida[i-1][jj] "<<M_invertida[j][jj]<<"\n";
                            M_invertida[j][jj] = (M_invertida[j][jj])/normalizar;
                            I[j][jj] = (  I[j][jj]  )/normalizar;
                            Rep = false;
                            
                        }
                    }
                    
                    /// 2° Zera termo da linha i j
                    double constante= M_invertida[i][j];
                    if (abs(constante)<0.0001){continue;}/// se ja for zero mandie pular o elemento 
                    for (int jj=0; jj<2*n; jj++)
                    {
                        //cout<<" i "<<i<<" j "<<j<<" jj "<<jj<<"\n";
                        //cout<<"antes  M_invertida[i][jj] " <<M_invertida[i][jj]<<"\n";
                        //cout<<"antes  M_invertida[j][jj]] " <<M_invertida[j][jj]<<"\n";
                        
                        M_invertida[i][jj] = -constante*M_invertida[j][jj] + M_invertida[i][jj]; 
                        I[i][jj] = -constante*I[j][jj] + I[i][jj];
                        //cout<<"depois  M_invertida[i][jj] " <<M_invertida[i][jj]<<"\n";
                    
                    }
                }
    /*
                cout<< " Matrix  invertetida  :"<<"\n";
                cout <<"\n";
                cout <<"M^T[2nx2n]:"<<"\n";
                cout <<"[";
                for(i=0;i<2*n;i++)
                {
                    cout <<"[";
                    for(int j=0;j<2*n;j++)
                    {
                        if(abs(M_invertida[i][j])==0){cout <<abs(M_invertida[i][j]);} 
                        else{cout <<M_invertida[i][j];}
                        cout<< ",";
                    }
                    cout <<"]"<<"\n";
                }

                cout <<"\n";
                cout <<"I[2nx2n]:"<<"\n";
                cout <<"[";
                for (int i=0; i<2*n; i++)
                {
                    cout <<"[";
                    for (int j=0; j<2*n; j++)
                    {
                        if(abs(I[i][j])==0){cout <<abs(I[i][j]);} 
                        else{cout <<I[i][j];}
                        cout<< ",";
                    }
                    cout <<"]"<<"\n";
                }
    */
            } 
        }
        
        cout<< "Matrix  invertetida :"<<"\n";
        //cout <<"\n";
        //cout <<"M^T[2nx2n]:"<<"\n";
        cout <<"[";
        for(i=0;i<2*n;i++)
        {
            cout <<"[";
            for(int j=0;j<2*n;j++)
            {
                if(abs(M_invertida[i][j])==0){cout <<abs(M_invertida[i][j]);} 
                else{cout <<M_invertida[i][j];}
                cout<< ",";
            }
            cout <<"]"<<"\n";
        }

        cout <<"\n";
        cout <<"I[2nx2n]:"<<"\n";
        cout <<"[";
        for (int i=0; i<2*n; i++)
        {
            cout <<"[";
            for (int j=0; j<2*n; j++)
            {
                if(abs(I[i][j])==0){cout <<abs(I[i][j]);} 
                else{cout <<I[i][j];}
                cout<< ",";
            }
            cout <<"]"<<"\n";
        }


        //cout<< fixed<<setprecision(precisao);
        cout<<"\n";
//        cout <<">>>---------------------------------------------<<<"<<"\n";
//        cout <<">>>-------------- Sub-rotina  ------------------<<<"<<"\n";
//        cout <<">>>--------       Eigenvector       ------------<<<"<<"\n";
        
        float *Eigenvector = new float [2*n],maximo =0;;
        int cont=0;
        while ( cont <1)
        {
            float chute[1] ={10};
                
                for(int i=0; i<2*n; i++)/// dando o chute inicial 
                {
                    Eigenvector[i] = chute[cont];
                }



                int contador =0;
                while(contador<=100000)
                {
                    maximo =0;
                    //cout<<"vector[0] :[";
                    for (int i=0; i<2*n; i++)
                    {
                            double soma =0;
                            for (int j=0; j<2*n; j++)
                            {
                                soma = soma + I[i][j]*Eigenvector[j];
                            }
                            vector[i] = soma;
                            //cout<<vector[i]<<",";
                            if (soma>maximo){maximo = soma;}       
                    }
                    //cout<<"]"<<"\n";
                    
                    /// Normalizar
                    //cout<<"N vector[0] :[";
                    for (int i=0; i<2*n; i++)
                    {
                        vector[i] =vector[i]/maximo;
                        //Soma_dos_elementos = Soma_dos_elementos + abs(Eigenvector[i] - vector[i]);
                        Eigenvector[i] = vector[i];
                        //cout<<Eigenvector[i]<<",";
                    }
                    //cout<<"]"<<"\n";
                    //cout<<"\n";
                    contador++;
                }  
                
                //// print do auto vetor encontrado 
                
                cout<<"AUTO-VETOR =[";
                for (int i=0; i<2*n; i++)
                {
                    cout<<Eigenvector[i]<<",";
                }
                cout<<"]"<<"\n";
                cout<<"\n";

               // cout <<"        Vamos testar o auto vetor         "<<"\n";
               // cout <<"\n";

                // Estamos verificando se o autovetor satifas a equação de auto valor para o lambda determinado 
                for (int i = 0; i <2*n;i++)
                {
                    soma=0;
                    for (int jj = 0; jj <2*n;jj++)
                    {
                        soma = soma + M[i][jj]*Eigenvector[jj] ;
                        //cout <<"M[i][jj] = "<<M[i][jj]<<" Eigenvector  " <<Eigenvector[jj]<<" Soma  = "<< soma<<"" <<"\n";
                    }
                    //cout <<"lamb*vector = "<< LAMBDA*Eigenvector[i] <<"\n";
                    cout <<"(A-lamb)vector = "<<soma - LAMBDA*Eigenvector[i] <<"\n";
                } /// Chuter inicial normalizado   
                //cout <<"\n";
        
                cont++;
        }
    contador2++;
    cout <<"\n";
    }

}