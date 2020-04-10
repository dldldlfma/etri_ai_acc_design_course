`timescale 1ns/100ps

module tb_counter;
	reg clk, rst, en;
	wire [4:0] count;

	counter tb(clk, rst, en, count);

	always #5 clk = ~clk;

	initial
	begin
		clk =0;
		rst=0;
		en=0;
		@(posedge clk);
		#1 rst=1;
		@(posedge clk);
		#1 en=~en;
		repeat(5) @(posedge clk);
		#1 en=~en;
		repeat(9) @(posedge clk);
		#1 en=~en;
		repeat(3) @(posedge clk);
		#1 en=~en;
		repeat(7) @(posedge clk);
		#1 en=~en;
		repeat(10) @(posedge clk);
		#1 en=~en;
		repeat(5) @(posedge clk);
		$finish;
	end

	endmodule
