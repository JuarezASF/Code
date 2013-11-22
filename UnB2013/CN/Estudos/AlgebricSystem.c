//#include "all.h"


double F1(double x, double y)
//define a função F1 a ser usada, usar como exemplo
{
//return(pow(x, 3) - 3*x*pow(y, 2) - 1);
//return(x + y -5);
return(2*cos(x) +1*cos(y) - 1);
}

double F2(double x, double y)
//Define a função F2 a ser utilizada, serve como exemplo
{
//return(3*pow(x, 2)*y - pow(y, 3));
//return( x - y - 1);
return(2*sin(x) +1*sin(y) - 1);

}

Matrix *evaluate(VectorValuedFunction *F, Matrix *u)
//retorna matrix alocada com a avaliação de F em u: F(u)
//nessa primeira versão trabalhamos somente em 2 dimensões
{
    Matrix *FU;

    FU = new_M(2,1);

    FU->a[0][0] = F->f1(u->a[0][0], u->a[1][0]);

    FU->a[1][0] = F->f2(u->a[0][0], u->a[1][0]);


    return(FU);

}

double ddx(double (*f)(double , double ), double x, double y)
//deve receber a função e o ponto em que a derivada deve ser
//avaliada
{
    double h;

    h = pow(10, -6);

    return( (f(x+h, y) - f(x-h, y))/(2*h)  );
    //método de diferenças finitas de segunda ordem para a
    //primeira derivada em x
}


double ddy(double (*f)(double , double ), double x, double y)
//valem as mesmas condições que a função ddx
{
    double h;

    h = pow(10, -6);

    return( (f(x, y+h) - f(x, y-h))/(2*h)  );
    //método de diferenças finitas de segunda ordem para a
    //primeira derivada em y
}

Matrix *EvalueDF(VectorValuedFunction *F, Matrix *u)
//Calcula a derivada de F(matriz) no ponto u(vetor)
//para ser usada no algoritmo de Newton versão vetorial
{
    double x,y;
    Matrix *DF;

    DF = new_M(2,2);

    x = u->a[0][0];
    y = u->a[0][1];

    DF->a[0][0] = ddx(F->f1, x, y);
    DF->a[0][1] = ddy(F->f1, x, y);
    DF->a[1][0] = ddx(F->f2, x, y);
    DF->a[1][1] = ddy(F->f2, x, y);

    return(DF);

}


void VectorValuetedNewton(VectorValuedFunction *F, Matrix *u)
//deve receber o sistema R^2 -> R^2
//e o chute inicial em u
//Implementa o método de Newton versão vetorial
//Limitação para matrizes 2x2: ainda deve ser generalizado
//Algoritmo descrito em:
//                  Numeral Analysis Lecture Notes 
//                  Peter J. Oliver
//                  capítulo 9: 
//                  Numerical Solution of Algebric Systems
//                  pgs:145 - 147
//
//
//O processo iterativo utilizado é;
//   u^{(k+1)} = u^{(k)} - f'(u^{(k))^{-1}. f(u^{(k)}
//  * aqui tudo é vetorial
//  *f é uma função R^n -> R^n
//  *u é um vetor no R^n
//
//  o chato aqui é ficar avaliando essas funções vetorias e
//  invertendo. achar a derivada tbm é chato
//  achamos a derivada através de diferença finitas de
//  segunda ordem para a primeira derivada parcial em x e em
//  y
//
//  *Os testes com os exemplos do livro funcionaram, apesar
//  de não convergirem da mesma forma. O teste da pag.
//  149(de dois braços robóticos) convergiram para outra
//  solução mas igualmente correte. Os testes com o cálculos
//  das raízes cúbicas da unidade (pg 148) só convergiram
//  para a raíz real.
//
//  *Notou-se um bug no teste do braço robótico ao tentar
//  dar chute inicial com primeira entradad 0. Será que é
//  problema no algoritmo ou na função que cria as matrizes?
//  verificar!
//
//  A FAZER: ACRESCENTAR TESTES PARA VERIFICAR SE A ENTRADA
//  É VALIDA OU NAO!
{
    int n, N_MAX;
    Matrix *DF_inv, *F_u, *DF_inv_cross_F_u, *DF;
    Matrix *u_next;

    N_MAX = 30;
    for(n=0; n < N_MAX; n++)
        {
            DF = EvalueDF(F, u);
            DF_inv = Inverse(DF);
            F_u = evaluate(F, u);
            DF_inv_cross_F_u = M_cross_N(DF_inv, F_u);
        
            u_next = subtract(u, DF_inv_cross_F_u);

            kill_M(&DF);
            kill_M(&DF_inv);
            kill_M(&F_u);
            kill_M(&DF_inv_cross_F_u);
            kill_M(&u);

            u = copy_M(u_next);

            kill_M(&u_next);
           printf("n = %d\n", n);
            print_M(u);
        }


}


/*
int main()
{
    Matrix *f, *u;
    
    VectorValuedFunction F;


    F.f1 = &F1;
    F.f2 = &F2;

    u = new_M_from_string(2,1, "1.5708 0");

    //f = new_M_from_string(2,2, "2 1 2 1");
    //f = evaluate(&F, u);
    
    VectorValuetedNewton(&F, u);
    
    print_M(u);

    //kill_M(&f);
    kill_M(&u);
    

    EndProgram();

    return(0);
}*/
