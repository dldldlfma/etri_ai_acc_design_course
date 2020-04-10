module dff_en(
	input [7:0] i_Data,
	input clk, en, rst,
	output [7:0] o_Data);

always @(posedge clk, negedge rst)
begin
	if(!rst) o_Data <= 0;
	else if(en == 1)
	begin
		o_Data<=i_Data;
	end
end

endmodule

