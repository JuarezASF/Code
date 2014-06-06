module add16(Soma, carry_out, A, B, carry_in);
	output [15:0]Soma;
	output carry_out;
	input [15:0] A, B; //tanto A como B são entradas de 4 bits
	input carry_in;
	
	wire L0, L1, L2;
	
	add4 a0(Soma[3:0], L0, A[3:0], B[3:0], carry_in);
	add4 a1(Soma[7:4], L1, A[7:4], B[7:4], L0);
	add4 a2(Soma[11:8], L2, A[11:8], B[11:8], L1);
	add4 a3(Soma[15:12], carry_out, A[15:12], B[15:12], L2);
	
endmodule