/* Somador de 4 bits com conversor de 7 segmentos */
/* 	TESTE UTILIZADO EM LABORATÓRIO 
module lab2v(oHEX0_D,iSW); // Entradas e saidas para a placa DE2-70

output reg[6:0]oHEX0_D;

input iSW[7:0];

wire [3:0]In;

add4v(In,iSW[3:0],iSW[7:4]);

decoder7(In,oHEX0_D);

endmodule
* */

module test;

  reg [3:0]inputA;
  reg [3:0]inputB;
  wire [3:0]outputA;
  
	initial begin
	inputA = 4'b000;
	inputB = 4'b000;
     # 10 inputA = 4'b0001;
	 # 10 inputA = 4'b0010;
	 # 10 inputA = 4'b0011;
	 # 10 inputA = 4'b0100;
     # 10 inputB = 4'b0001;
	 # 10 inputB = 4'b0010;
	 # 10 inputB = 4'b0011;
	 # 10 inputB = 4'b0100;
     # 10 $stop;
  end
  
  add4v my4Adder(.soma(outputA),.A(inputA),.B(inputB));
  
  initial
     $monitor("At time %t, A = %b,B = %b,SOMA = %b \n",
              $time, inputA, inputB, outputA);

endmodule //test