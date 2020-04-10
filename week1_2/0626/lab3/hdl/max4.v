module max4(
	input [3:0] iA, iB, iC, iD,
	output [3:0] oMax);

wire [3:0] Max0;
wire [3:0] Max1;

assign Max0 = (iA > iB) ? iA:iB;
assign Max1 = (iC > iD) ? iC:iD;

assign oMax = (Max0 > max1) ? Max0:Max1;

endmodule



