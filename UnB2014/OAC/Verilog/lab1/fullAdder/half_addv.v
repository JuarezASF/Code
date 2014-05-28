/* Meio somador */

module half_addv (sum,carry,A,B); //Define entradas e saidas do modulo

output sum, carry; //Define as saidas de 1 bit cada

input A,B; //Define as entradas de 1 bit cada

xor(sum,A,B); //comportamento da saida sum de acordo com as entradas

and(carry,A,B); //comportamento da saida carry de acordo com as entradas

endmodule