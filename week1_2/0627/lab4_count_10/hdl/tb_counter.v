`timescale 1ns/100ps
module tb_counter;
	reg clk, rst;
	wire [3:0] count;


	counter tb(clk, rst, count);

	always #5 clk = ~clk;

	initial
	begin
		clk=0;
		rst=0;
		@(posedge clk);
		#1 rst=1;
		repeat(55) @(posedge clk);
		$finish;
	end
	
	endmodule

