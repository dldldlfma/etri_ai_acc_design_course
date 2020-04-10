module lab1(
	input[5:0] A,
	output[6:0] B
	);

assign B = (A>=0 && A<5) ? A+10:
		   (A>=5 && A<10) ? A*2:
		   (A>=10 && A<15) ? A<<<3:
		   (A>=15 && A<20) ? A:0;

endmodule
		   
