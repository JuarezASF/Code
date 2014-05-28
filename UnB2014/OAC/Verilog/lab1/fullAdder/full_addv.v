/* Somador completo */

module full_addv (sum,carry,A,B,Cin); //Define entrada e saida do modulo

output sum, carry; // Define as saidas de 1 bit cada

input A, B, Cin; // Define as entradas de 1 bit cada

wire L1,L2,L3; // Fios que ligam dois meio somadores

half_addv  half1(L1,L2,A,B); // Primeiro meio somador

half_addv half2(sum,L3,L1,Cin); // Segundo meio somador

or(carry,L3,L2); // Porta OU

endmodule