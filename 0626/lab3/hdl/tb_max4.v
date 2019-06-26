`timescale 1ns/100ps
module tb_max4;

reg [3:0] iA, iB, iC, iD;

wire [3:0] oMax;

max4 tb(iA, iB, iC, iD, oMax);

initial
begin
	iA=0;
	iB=0;
	iC=0;
	iD=0;
	repeat(15) #5;
	$finish;
end

always
begin
	#5;
	iA=$random;
	iB=$random;
	iC=$random;
	iD=$random;
end

endmodule
