(* src = "counter.v:1" *)

module counter(clk, rst, en, count);

  (* src = "counter.v:6" *)

  wire [2:0] _00_;

  wire _01_;

  wire _02_;

  wire _03_;

  wire _04_;

  wire _05_;

  wire _06_;

  wire _07_;

  wire _08_;

  wire _09_;

  wire _10_;

  wire _11_;

  (* src = "counter.v:3" *)

  input clk;

  (* src = "counter.v:4" *)

  output [2:0] count;

  (* src = "counter.v:3" *)

  input en;

  (* src = "counter.v:3" *)

  input rst;

  NOT _12_ (

    .A(count[1]),

    .Y(_11_)

  );

  NOT _13_ (

    .A(rst),

    .Y(_01_)

  );

  NAND _14_ (

    .A(en),

    .B(count[0]),

    .Y(_02_)

  );

  NOR _15_ (

    .A(en),

    .B(count[0]),

    .Y(_03_)

  );

  NAND _16_ (

    .A(_01_),

    .B(_02_),

    .Y(_04_)

  );

  NOR _17_ (

    .A(_03_),

    .B(_04_),

    .Y(_00_[0])

  );

  NOR _18_ (

    .A(_11_),

    .B(_02_),

    .Y(_05_)

  );

  NAND _19_ (

    .A(_11_),

    .B(_02_),

    .Y(_06_)

  );

  NAND _20_ (

    .A(_01_),

    .B(_06_),

    .Y(_07_)

  );

  NOR _21_ (

    .A(_05_),

    .B(_07_),

    .Y(_00_[1])

  );

  NOR _22_ (

    .A(count[2]),

    .B(_05_),

    .Y(_08_)

  );

  NAND _23_ (

    .A(count[2]),

    .B(_05_),

    .Y(_09_)

  );

  NAND _24_ (

    .A(_01_),

    .B(_09_),

    .Y(_10_)

  );

  NOR _25_ (

    .A(_08_),

    .B(_10_),

    .Y(_00_[2])

  );

  (* src = "counter.v:6" *)


  (* src = "counter.v:6" *)


  (* src = "counter.v:6" *)


endmodule
