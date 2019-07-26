module adder_4bit(
	input [3:0] iA,
	input [3:0] iB,
	output [3:0] oS,
	output oCout);

	wire [3:0] Cin;

	assign Cin[0] = 0;

	adder_1bit ad0(iA[0], iB[0], Cin[0], oS[0], Cin[1]);
	adder_1bit ad0(iA[1], iB[1], Cin[1], oS[1], Cin[2]);
	adder_1bit ad0(iA[2], iB[2], Cin[2], oS[2], Cin[3]);
	adder_1bit ad0(iA[3], iB[3], Cin[3], oS[3], oCout);
endmodule

