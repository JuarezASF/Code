/* teste.v */

/****************************************
*    UnB - OAC - Prof. Marcus Lamar      *
*    Laborat�rio 2    - DE-2 70          *
*    Exemplo 1                           *
*************************************** */

// Este exemplo visa apresentar as facilidades de IO
// da plataforma de desenvolvimento Altera - DE2 70


module teste (iSW, iKEY, oLEDR, oLEDG, oHEX0_D,oHEX0_DP, 
			oHEX1_D,oHEX1_DP, oHEX2_D,oHEX2_DP, oHEX3_D,oHEX3_DP);
	input [17:0] iSW; 
	input [3:0] iKEY;
	output [17:0] oLEDR; 
	output [8:0] oLEDG;
	output [6:0] oHEX0_D, oHEX1_D, oHEX2_D, oHEX3_D;
	output oHEX0_DP, oHEX1_DP, oHEX2_DP, oHEX3_DP;

	assign oLEDR = iSW;
	assign oLEDG[0] = iKEY[0];
	assign oLEDG[1] = ~iKEY[0];
	assign oLEDG[2] = iKEY[1];
	assign oLEDG[3] = ~iKEY[1];
	assign oLEDG[4] = iKEY[2];
	assign oLEDG[5] = ~iKEY[2];
	assign oLEDG[6] = iKEY[3];
	assign oLEDG[7] = ~iKEY[3];

	assign oHEX0_DP=1'b1;
	assign oHEX1_DP=1'b1;
	assign oHEX2_DP=1'b1;
	assign oHEX3_DP=1'b1;

	xor x1 (oLEDG[8],iSW[17],iSW[16]); // Exemplo de uso de porta logica
	
	decoder7 u0 (iSW[3:0],oHEX0_D);
	decoder7 u1 (iSW[7:4],oHEX1_D);
	decoder7 u2 (iSW[11:8],oHEX2_D);
	decoder7 u3 (iSW[15:12],oHEX3_D);

endmodule
