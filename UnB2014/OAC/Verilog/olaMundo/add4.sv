module add4(Soma, carry_out, A, B, carry_in);
	output [3:0]Soma;
	output carry_out;
	input [3:0] A, B; //tanto A como B são entradas de 4 bits
	input carry_in;
	
	wire L0, L1, L2;
	
	adder a0(Soma[0], L0, A[0], B[0], carry_in);
	adder a1(Soma[1], L1, A[1], B[1], L0);
	adder a2(Soma[2], L2, A[2], B[2], L1);
	adder a3(Soma[3], carry_out, A[3], B[3], L2);
	
endmodule