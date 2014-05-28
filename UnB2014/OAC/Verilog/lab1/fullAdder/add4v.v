/* Somador completo de 4 bits */

module add4v (soma,A,B); //Define as entradas e saidas do somador

output [3:0]soma; // Vetor de saida dos somadores

input [3:0] A, B; // Vetor de entrada dos 4 bits para cada entrada

wire s1,s2,s3; // Fios para passar o carry de um somador para outro

full_addv fullAdd1(soma[0],s1,A[0],B[0],0); // Primeiro somador da cascata

full_addv fullAdd2(soma[1],s2,A[1],B[1],s1); // Segundo somador

full_addv fullAdd3(soma[2],s3,A[2],B[2],s2); // Terceiro somador

full_addv fullAdd4(soma[3],X,A[3],B[3],s3); // Quarto somador

endmodule