module timer(
		input iCLK, iRSTn,
		input [1:0] iAddr,
		input iStart, iWe,
		input [15:0] iWdata,
		output reg oPWM,
		output reg oTimer_End);

wire [2:0] en;

reg start_flag;
reg end_flag;

reg [15:0] count;
reg [15:0] cycle_count;

reg [15:0] max_count;
reg [15:0] pwm_count;
reg [15:0] stop_count;

reg [3:0] end_signal_count;
localparam end_signal_len=10;


// clk and cycle clk set up
// standard : max_count, stop_count, start_flag
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		count<=0;
		cycle_count<=0;
	end
	else if(count<max_count && start_flag)
	begin
		count<=count+1;
	end
	else if(count==max_count)
	begin
		count<=0;
		if(cycle_count < stop_count)
		begin
			cycle_count<=cycle_count+1;
		end
		else if(cycle_count ==stop_count)
		begin
			cycle_count<=0;
		end
	end
end

//Set-up start_flag, end_flag, end_signal_count
//standard: iStart, (count, max_count), (cycle_count, stop_count)
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		start_flag <=0;
		end_flag <=1;
		end_signal_count<=0;
	end

	else if(iStart ==1 && end_flag ==1 && start_flag ==0)
	begin
		start_flag <=1;
		end_flag<=0;
	end	

	//-------------------------after end---------------------------
	if(start_flag==1 && count==max_count && cycle_count==stop_count )
	begin
		start_flag<=0;
		end_signal_count<=end_signal_count+1;
	end
	else if( start_flag==0 &&
			 end_flag==0 &&
			 end_signal_count<end_signal_len)
	begin
		end_signal_count <= end_signal_count +1;
	end
	else if( start_flag==0&&
			 end_flag==0 &&
			 end_signal_count==end_signal_len)
	begin
		end_flag<=1;
		end_signal_count <=0;
	end

end

// oTimer_End & set up codea
// standard : start_flag, end_flag, (end_signal_count, end_signal_len)
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		oTimer_End<=0;		
	end
	else if(start_flag==0 && end_flag==0 && end_signal_count<=end_signal_len)
	begin
		oTimer_End<=1;
	end
	else
	begin
		oTimer_End<=0;
	end
end



// oPWM set up code
// standard : count, pwm_count, max_count
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		oPWM<=0;
	end
	else if(count>=pwm_count-1 && count<max_count)
	begin
		oPWM<=1;
	end
	else
	begin
		oPWM<=0;
	end
end


// en setup code
// standard : iAddr, iWe
assign en[0] = (iAddr == 0 && iWe==1) ? 1:0;
assign en[1] = (iAddr == 1 && iWe==1) ? 1:0;
assign en[2] = (iAddr == 2 && iWe==1) ? 1:0;


// max_count set up code
// standard : en[0]
// input : iWdata
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		max_count <=0;		
	end
	else if(en[0] ==1)
	begin
		max_count <= iWdata;
	end

end

// pwm_count set up code
// standard : en[1]
// input : iWdata
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		pwm_count <=0;		
	end
	else if(en[1] ==1)
	begin
		pwm_count <= iWdata;
	end

end

// stop_count set up code
// standard : en[2]
// input : iWdata
always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		stop_count <=0;		
	end
	else if(en[2] ==1)
	begin
		stop_count <= iWdata;
	end

end

endmodule

