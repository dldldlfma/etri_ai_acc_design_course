`timescale 1ns/100ps
module tb_dff_en;
	reg [7:0] i_D,
	reg clk, rst, en;
	wire [7:0] o_D;

	dff_en tb(.i_Data(i_D), .clk(clk), .rst(rst), .en(en), .o_Data(o_D));

	always #5 clk=~clk;
	always #5 i_D=$random;
	always #11 en=~en;

	initial
	begin
		clk=0;
		en=0;
		@(posedge clk);
		#1 rst=1;
		@(posedge clk);
		#1 rst=0;
		@(posedge clk);
		#1 rst=1;
		@(posedge clk);
		repeat(20) #5;
		@(posedge clk);
		$finish;
	end
endmodule
