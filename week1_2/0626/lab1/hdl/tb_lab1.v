`timescale 1ns/100ps

module tb_lab1;

reg clk;
reg[5:0] A;
wire[6:0] B;

integer i=0;

lab1 tb(.A(A), .B(B));

initial
begin
	clk-0;
	A=0;

	for(i=0; i<30; i=i+1)
	begin
		#5;
		A=i;
	end
	$finish;
end

endmodule

