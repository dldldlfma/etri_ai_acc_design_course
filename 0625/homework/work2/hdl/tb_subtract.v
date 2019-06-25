`timescale 1ns/100ps

module tb_subtract;
reg clk;
reg [3:0] A;
reg [3:0] B;
wire [3:0] Y;

subtract sub(.A(A), .B(B), .Y(Y));

initial
begin
	A=0;
	B=0;
	repeat(10) @(posedge clk);
	$finish
end

always #5 A = $random;
always #5 B = $random;
always #5 clk = ~clk;
endmodule

