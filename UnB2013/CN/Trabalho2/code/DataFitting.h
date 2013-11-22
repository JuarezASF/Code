#ifndef DATA_FITTING_H
#define DATA_FITTING_H

Matrix *PolynomialFitting(const char *file, int M_data \
										  , int N_grau);
/*Retorna matriz alocada com os coeficientes do polinômio
 * de grau n.
 *A convenção adotada é A[0] = alpha_0, A[n] = alpha_n
 * onde:
 * p(t) = alhpa_0 + alpha_1.t + ... + alpha_n . t^n
 * 
 * Deve receber:
 * - Arquivo com os dados em duas colunas
 * 			sendo a forma (t_k, y_k) adotada
 * - número M de pontos a serem considerados
 * - númeor N do polinômio a ser gerado
 * 
 * Basicamente o algoritmo resolve o sistema:
 * 
 * (A^t . A)x = A^ty
 * 
 * Notamos:
 * 	-A^t . A = D
 * 	-A^ty	 = E
 * 
 * portanto basta resolver D.x = E
 * 
 * para isso podemos fazer:
 * -	x = D^{-1}.E
 * -	Jacobi ou Gauss-Seidel
 * -	eliminação gaussiana
 * 
 * Nessa versão do código usamos a primeira opção  por sim-
 * plicidade
 * 
 * Algoritmo e notação seguindo 
 * Numerical Analysis Lectures Notes - Peter J. Oliver
 * cap: 13 Approxiation and Interpolation; pgs 224-230 
 * 
 * obs. : Se 
 *  m+1 = n temos um fitting perfeito para os dados
 *  m+1 > n temos o erro quadrático mínimo
 *  m+1 < n ??? 
 * */

void MakeGnuplotMultPlotScript(const char *file, \
					const char *data, Matrix **X, \
                       int N_x, const char *eps_name);
//imprime em file os comandos no gnuplot para traçar
//os pontos juntos com vários ajustes

void MakeGnuplotScript(const char *file, const char *data,\
						Matrix *X, \
					   const char *eps_name, int n_ordem, \
					   int m_data);
//imprime em file os comandos no gnuplot para traçar
//os pontos junto com um ajutes

Matrix *LinearDataFittingBySum(const char *file, int M_data);
/* Retorna a matriz X alocada contendo (alpha, beta)
 * -O algortimo usa a fórmula:
 * beta = 
 *((t.y)_{avg} - t_{avg}.y_{avg}) /((t^2)_{avg} (t_{avg})^2)
 * 
 * alpha =
 * y_{avg} -t_{avg}.Beta
 * 
 *onde A_{avg} denot a média da variável A nos dados tomados
 *!não confundir (t.y)_{avg} com t_{avg}.y_{avg}
 * 
 * Mais descrições em:
 * Numerical Analysis Lectures Notes - Peter J. Oliver
 * cap: 13 Approxiation and Interpolation; pgs 221-223   
 * 
 * Código por :
 * 				Juarez A.S.F.
 * 
 * Motivação:
 * 			curso de	Cálculo Numérico UnB - 1º/2013
*/

double FindFittingError(Matrix *X, const char *file,\
										int M_data);
/*recebe:
 * - vetor com os coeficiente calculados 
 * - arquivo com os dados 
 * 
 * retorn:
 * erro quaratico medio
*/

void print_coeff_table(Matrix *X, const char *file);
/*deve receber:
 *  - o vetor com os coeficientes
 *  - o nome do arquivo
 * faz:  
 *	- escreve no arquivo uma matriz com os coeficientes
 *  */
#include "DataFitting.c"
#endif
