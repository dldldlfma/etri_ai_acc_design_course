module counter(
	input clk, rst,
	output [3:0] count);

always @(posedge clk, negedge rst)
	if(!rst) count <=0;
	begin
		if(count ==4'd10) count<=0;
		else count <= count+1;
	end
end
endmodule



