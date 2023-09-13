module counter_tb;

  /* Make a reset pulse and specify dump file */
  reg rst = 0;
  reg se = 0;
  reg si = 1;
  initial begin
     $dumpfile("counter_tb.vcd");
     $dumpvars(0,counter_tb);

     # 0 rst = 1;
     # 4 rst = 0;
     # 36 //rst = 1;
      se = 1;
      si =0;
      #2
      si =1;
      #2
      si = 0;
     # 4  
     rst = 0;
     
     # 6 $finish;
  end

  /* Make enable with period of 8 and 6,7 low */
  reg en = 1;
  always begin
    en = 1;
    #6;
    en = 0;
    #2;
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #1 clk = !clk;

  /* UUT */
  wire [2:0] count;
  counter c1 (clk, rst,se,si ,en, count);

endmodule
