module dff(
	input i_clk, i_rst, i_D,
	output reg o_Q);

always @(posedge i_clk, negedge i_rst)
begin
	if(!i_rst) o_Q<=0;
	else o_Q<=i_D;
end
endmodule
