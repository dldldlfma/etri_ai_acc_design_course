`timescale 1ns/100ps
module tb_dff;
	reg i_clk, i_rst, i_D;
	wire o_Q;

dff tb(.i_clk(i_clk), .i_rst(i_rst), .i_D(i_D), .o_Q(o_Q));

initial
begin
	i_clk=0;
	i_rst=0;
	i_D=0;
	@(posedge i_clk);
	#1 i_rst=1;
	@(posedge i_clk);
	#1 i_D=1;
	@(posedge i_clk);
	#1 i_D=0;
	@(posedge i_clk);
	#1 i_D=1;
	
	repeat(2) @(posedge i_clk);
	#1 i_D=0;
	repeat(5) @(posedge i_clk);
	
	$finish;
end

	
always #5 i_clk=~i_clk;
always #6 i_D=~i_D;

endmodule

