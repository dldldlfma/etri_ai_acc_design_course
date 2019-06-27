module counter(
	input clk, rst, en,
	output reg [4:0] count);

always @(posedge clk, negedge rst)
begin
	if(!rst) count <=0;
	else if(rst==1 && en ==1)
	begin
		if(count == 5'd25)
		begin
			count<=0;
		end
		else count <= count +1;
	end
end

endmodule

