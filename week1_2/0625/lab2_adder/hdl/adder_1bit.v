module adder_1bit(
	input iA, iB, iCin,
	output oS oCout);

	assign {oCout, oS} = iA + iB + iCin;
endmodule
