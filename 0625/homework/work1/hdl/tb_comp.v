`timescale 1ns/100ps

module tb_comp;
	reg A, B;
	wire X, Y, Z;

	comp(.A(A), .B(B), .X(X), .Y(Y), .Z(Z));

	initial
	begin 
	A=0;
	B=0;
	#5 A=1;
	#5 B=1;
	#5 A=0;
	#5 B=0;
	$finish;
end
endmodule
