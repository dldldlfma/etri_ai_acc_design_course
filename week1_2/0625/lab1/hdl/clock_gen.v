`timescale 1ns/1ns

module clock_gen;
	reg clk;
	
	initial
	begin
		clk=0;
		$display("Hello Verilog \n");
		repeat(100) @(posedge clk);
		$finish;
	end

	always #5 clk = ~clk;
endmodule

