1timescale 1ns/100ps
module tb_bit_comp;

reg clk;
reg [9:0] A, B;
wire [3:0] NumOfBits;

bit_comp tb(A,B,NumOfBits);

initial
begin
	clk=0;
	A=0;
	B=0;
	repeat(15) @(posedge clk);
	$finish;
end

always #5 clk=~clk;
always #5 A=$random;
always #5 B=$random;

endmodule
