module add32(Soma, carry_out, A, B, carry_in);
	output [31:0]Soma;
	output carry_out;
	input [31:0] A, B; //tanto A como B são entradas de 4 bits
	input carry_in;
	
	wire L0;
	
	add16 a0(Soma[15:0], L0, A[15:0], B[15:0], carry_in);
	add16 a1(Soma[31:16], carry_out, A[31:16], B[31:16], L0);
		
endmodule