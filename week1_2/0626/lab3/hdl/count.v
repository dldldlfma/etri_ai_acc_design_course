module blinky(
		input clk,
		output led
		);

reg [24:0] count;

assign led = count[24];

always @(posedge clk)
begin
	count<= count+1;
end





