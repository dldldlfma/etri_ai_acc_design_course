module counter(
	input clk, rst,
	output reg [3:0] count);

always @(posedge clk, negedge rst)
begin
	if(!rst) count <=0;
	else if(rst==1)
	begin
		count <= count +1;
	end
end

endmodule
