module adder(sum,carry_out,a,b,carry_in);

input carry_in, a, b;
output sum, carry_out;

wire L1, L2, L3; //fios para ligar os componentes

halfAdder primeira_soma(L1,L2,a,b);
//a saida soma(L1) do primeiro somador vai na entrada do segundo
//a saida carry out(L2) vai para a porta OR
halfAdder segunda_soma(sum, L3, L1, carry_in);
or(carry_out, L3, L2);

endmodule

