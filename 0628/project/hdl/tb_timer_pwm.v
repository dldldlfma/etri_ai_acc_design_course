`timescale 1ns/10ps
module tb_timer_pwm;
	reg iCLK, iRSTn;
	reg [1:0] iAddr;
	reg iStart, iWe;
	reg [15:0] iWdata;
	wire oPWM;
	wire oTimer_End;

	timer_pwm tb(.iCLK(iCLK),
				 .iRSTn(iRSTn),
				 .iAddr(iAddr),
				 .iStart(iStart),
				 .iWe(iWe),
				 .iWdata(iWdata),
				 .oPWM(oPWM),
				 .oTimer_End(oTimer_End));


	always #5 iCLK=~iCLK;

	initial
	begin
		iCLK=0;
		iRSTn=0;
		iAddr=0;
		iStart=0;

		iWe=0;
		iWdata=0;

		//reset test code
		@(posedge iCLK)
		#1 iRSTn=1;
		@(posedge iCLK)
		#1 iRSTn=0;
		@(posedge iCLK)
		#1 iRSTn=1;

		//iWe, iWdata input test code
		
		//max_count_setup iAddr=0 
		@(posedge iCLK)
		#1 iWdata = 15;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//pwm_count_setup iAddr=1
		@(posedge iCLK)
		#1 iAddr = 1;
		@(posedge iCLK)
		#1 iWdata = 5;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//stop_count_setup iAddr=1
		@(posedge iCLK)
		#1 iAddr=2;
		@(posedge iCLK)
		#1 iWdata = 0;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//iStart Test
		@(posedge iCLK)
		#1 iStart=1;
		//iStart Stop Test
		@(posedge iCLK)
		#1 iStart=0;
		//iStart ReStart in counting
		@(posedge iCLK)
		#3 iStart =1;
	    @(posedge iCLK)
		#1 iStart =0;



		//counting test
		repeat(150)	#1 @(posedge iCLK);

		//Re-Setup of max_count, pwm_count, stop_count
			
		//max_count_setup iAddr=0 
		@(posedge iCLK)
		#1 iAddr =0;
		@(posedge iCLK)
		#1 iWdata = 10;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//pwm_count_setup iAddr=1
		@(posedge iCLK)
		#1 iAddr = 1;
		@(posedge iCLK)
		#1 iWdata = 6;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//stop_count_setup iAddr=1
		@(posedge iCLK)
		#1 iAddr=2;
		@(posedge iCLK)
		#1 iWdata = 2;
		@(posedge iCLK)
		#1 iWe=1;
		@(posedge iCLK)
		#1 iWe=0;

		//iStart Test after 1cycle
		@(posedge iCLK)
		#1 iStart=1;
		//iStart Stop Test
		@(posedge iCLK)
		#1 iStart=0;
		//iStart ReStart in counting
		@(posedge iCLK)
		#3 iStart =1;
	    @(posedge iCLK)
		#1 iStart =0;

		//counting test
		repeat(150)	#1 @(posedge iCLK);


		$finish;
	end
endmodule
