module enable(
	input iCLK, iRSTn,
	input [15:0] iWdata,
	input [1:0] iAddr,
	input iWe,
	output reg [15:0] o_max_count,
	output reg [15:0] o_pwm_count,
	output reg [15:0] o_stop_count);

wire [2:0] en;

assign en[0] = (iAddr==0 && iAddr !=3 && iWe ==1) ? 1:0;
assign en[1] = (iAddr==1 && iAddr !=3 && iWe ==1) ? 1:0;
assign en[2] = (iAddr==2 && iAddr !=3 && iWe ==1) ? 1:0;

always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		o_max_count<=0;
	end
	else if(en[0]==1)
	begin
		o_max_count<=iWdata;
	end
end

always @(posed iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		o_pwm_count<=0;
	end
	else if(en[1]==1)
	begin
		o_pwm_count <=iWdata;
	end
end

always @(posedge iCLK, negedge iRSTn)
begin
	if(!iRSTn)
	begin
		if(!iRSTn)
		begin
			o_stop_count<=0;
		end
		else if(en[2]==1)
		begin
			o_stop_count <=iWdata;
		end
	end
end


endmodule

