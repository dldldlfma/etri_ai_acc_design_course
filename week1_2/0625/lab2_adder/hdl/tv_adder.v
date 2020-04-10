`timescale 1ns/10ps
module tb_adder_4bit;
	reg clk;
	reg [3:0] iA;
	reg [3:0] iB;
	wire [3:0] oSum;
	wire oCout;

	adder_4bit tb_ad(.iA(iA), .iB(iB), .oS(oSum), .oCout(oCout));

	always #10 iA = $random;
	always #10 iB = $random;
	always #5 clk = clk;
	initial
	begin
		clk =0;
		iA=0;
		iB=0;
		repeat(30) @(posedge clk);
		$finish;
	end
endmodule
