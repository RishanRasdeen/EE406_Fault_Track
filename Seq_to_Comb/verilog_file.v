module counter (
\count[0], 
\count[1], 
\count[2], 
clk, 
en, 
rst,
_00_, 
_01_, 
_02_
);
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  wire _07_;
  wire _08_;
  wire _09_;
  input \count[0];
  input \count[1];
  input \count[2];
  input clk;
  input en;
  input rst;
  output _00_;
  output _01_;
  output _02_;
  AND _10_ (
    .A(en),
    .B(\count[0] ),
    .Y(_09_)
  );
  NOR _11_ (
    .A(en),
    .B(\count[0] ),
    .Y(_03_)
  );
  OR _12_ (
    .A(rst),
    .B(_03_),
    .Y(_04_)
  );
  NOR _13_ (
    .A(_09_),
    .B(_04_),
    .Y(_00_)
  );
  NAND _14_ (
    .A(\count[1] ),
    .B(_09_),
    .Y(_05_)
  );
  NOR _15_ (
    .A(\count[1] ),
    .B(_09_),
    .Y(_06_)
  );
  NOR _16_ (
    .A(rst),
    .B(_06_),
    .Y(_07_)
  );
  AND _17_ (
    .A(_05_),
    .B(_07_),
    .Y(_01_)
  );
  XOR _18_ (
    .A(\count[2] ),
    .B(_05_),
    .Y(_08_)
  );
  NOR _19_ (
    .A(rst),
    .B(_08_),
    .Y(_02_)
  );
endmodule
