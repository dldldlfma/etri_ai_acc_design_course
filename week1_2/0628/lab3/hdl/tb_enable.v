`timescale 1ns/10ps

module tb_enable;
	reg iCLK, iRSTn;
	reg [15:0] iWdata;
	reg [1:0] iWdata;
	reg iWe;
	wire [15:0] o_max, o_pwm, o_stop;

	enable tb(iCLK, iRSTn, iWdata, iAddr, iWe, o_max, o_pwm, o_stop);

	always #5 iCLK = ~iCLK;
	always #6 iWe=~iWe;

	always @(posedge iCLK) #1 iWdata = $random;

	initial
	begin
		iCLK=0;
		iRSTn=0;
		iWdata=0;
		iAddr=0;
		iWe=0;
		@(posedge iCLK)
		#1 iRSTn=1;
		@(posedge iCLK)
		#1 iRSTn=0;
		@(posedge iCLK)
		#1 iRSTn=1;
		repeat(20)
		begin
			@(posedge iCLK)
			#1 iAddr=iAddr+1;
		end
		$finish;
	end

endmodule
