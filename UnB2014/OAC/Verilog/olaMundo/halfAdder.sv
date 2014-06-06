module halfAdder(sum, carry_out, a, b);

input a, b; //define entradas de 1 bit

output sum, carry_out; //define saidas de 1 bit

xor(sum, a, b); 

and(carry_out, a, b);

endmodule