`timescale 1ns / 1ps

module DFFS1 (C,D,SE,SI,Q);
input C, D, SE, SI;
output reg Q;
  // D flip-flop scan implementation
  always @(posedge C) 
  begin
    if (!SE)
      Q <= D;  // Normal operation, data doesn't change
    else
      Q <= SI;    
  end
endmodule


module DFFS2 (C, D, SE, SI, Q, S, R);
input C, D, SE, SI, S, R;
output reg Q;

always @(posedge C, posedge S, posedge R)
	if (S)
		Q <= 1'b1;
	else if (R)
		Q <= 1'b0;
	else
		if (!SE)
      Q <= D;  // Normal operation, data doesn't change
    else
      Q <= SI; 
endmodule