(* src = "FourBitAdder.v:3" *)
module FourBitAdder(a, b, cin, sum, cout);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  (* src = "FourBitAdder.v:11" *)
  input a;
  (* src = "FourBitAdder.v:12" *)
  input b;
  (* src = "FourBitAdder.v:13" *)
  input cin;
  (* src = "FourBitAdder.v:14" *)
  output cout;
  (* src = "FourBitAdder.v:15" *)
  output sum;
  NOT _07_ (
    .A(cin),
    .Y(_03_)
  );
  OR _08_ (
    .A(b),
    .B(a),
    .Y(_04_)
  );
  NAND _09_ (
    .A(b),
    .B(a),
    .Y(_05_)
  );
  NAND _10_ (
    .A(cin),
    .B(_04_),
    .Y(_06_)
  );
  NAND _11_ (
    .A(_05_),
    .B(_06_),
    .Y(cout)
  );
  OR _12_ (
    .A(cin),
    .B(_04_),
    .Y(_00_)
  );
  OR _13_ (
    .A(_03_),
    .B(_05_),
    .Y(_01_)
  );
  NAND _14_ (
    .A(cout),
    .B(_01_),
    .Y(_02_)
  );
  AND _15_ (
    .A(_00_),
    .B(_02_),
    .Y(sum)
  );

endmodule
