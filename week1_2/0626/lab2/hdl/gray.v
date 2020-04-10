module gray(
	input [3:0] A,
	output [3:0] gray);

assign gray[0] = A[0]^A[1];
assign gray[1] = A[1]^A[0];
assign gray[2] = A[2]^A[1];
assign gray[3] = A[3];

endmodule

