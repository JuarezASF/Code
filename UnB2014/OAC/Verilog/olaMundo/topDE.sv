module topDE(out, overflow, inA, inB);
	output [7:0]out;
	output overflow;
	input [7:0]inA, inB;
	
	add4(out, overflow, inA, inB, 0);
	
endmodule