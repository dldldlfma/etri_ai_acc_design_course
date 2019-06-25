module comp(
	input A, B,
	output X,Y,Z);

assign X = (A>B);
assign Y = (A<B);
assign Z = (A==B);

endmodule
