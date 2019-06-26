`timescale 1ns/100ps

module tb_gray;
reg [3:0] A;
wire [3:0] gray;
integer i=0;

gray tb(.A(A), .gray(gray));

initial
begin
	A=0;
	for(i=0; i<16; i=i+1)
	begin
		#5;
		A=i;
	end
	$finish;
end
endmodule

