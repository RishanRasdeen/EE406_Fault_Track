/* Generated by Yosys 0.9 (git sha1 1979e0b) */

(* src = "Hazard_Detect.v:23" *)
module Hazard_Detect(\IF_IDrs1_i[0] , \IF_IDrs1_i[1] , \IF_IDrs1_i[2] , \IF_IDrs1_i[3] , \IF_IDrs1_i[4] , \IF_IDrs2_i[0] , \IF_IDrs2_i[1] , \IF_IDrs2_i[2] , \IF_IDrs2_i[3] , \IF_IDrs2_i[4] , \ID_EXrd_i[0] , \ID_EXrd_i[1] , \ID_EXrd_i[2] , \ID_EXrd_i[3] , \ID_EXrd_i[4] , ID_EX_MemRead_i, Hazard_o);
  wire _00_;
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
  wire _12_;
  wire _13_;
  wire _14_;
  wire _15_;
  wire _16_;
  wire _17_;
  wire _18_;
  wire _19_;
  wire _20_;
  wire _21_;
  wire _22_;
  wire _23_;
  wire _24_;
  wire _25_;
  wire _26_;
  wire _27_;
  wire _28_;
  wire _29_;
  wire _30_;
  wire _31_;
  (* src = "Hazard_Detect.v:33" *)
  output Hazard_o;
  (* src = "Hazard_Detect.v:31" *)
  input ID_EX_MemRead_i;
  (* src = "Hazard_Detect.v:32" *)
  input \ID_EXrd_i[0] ;
  (* src = "Hazard_Detect.v:32" *)
  input \ID_EXrd_i[1] ;
  (* src = "Hazard_Detect.v:32" *)
  input \ID_EXrd_i[2] ;
  (* src = "Hazard_Detect.v:32" *)
  input \ID_EXrd_i[3] ;
  (* src = "Hazard_Detect.v:32" *)
  input \ID_EXrd_i[4] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs1_i[0] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs1_i[1] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs1_i[2] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs1_i[3] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs1_i[4] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs2_i[0] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs2_i[1] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs2_i[2] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs2_i[3] ;
  (* src = "Hazard_Detect.v:32" *)
  input \IF_IDrs2_i[4] ;
  NOT _32_ (
    .A(\ID_EXrd_i[2] ),
    .Y(_00_)
  );
  NOT _33_ (
    .A(\ID_EXrd_i[3] ),
    .Y(_01_)
  );
  NOT _34_ (
    .A(\IF_IDrs2_i[4] ),
    .Y(_02_)
  );
  XOR _35_ (
    .A(\IF_IDrs1_i[0] ),
    .B(\ID_EXrd_i[0] ),
    .Y(_03_)
  );
  NAND _36_ (
    .A(_00_),
    .B(\IF_IDrs1_i[2] ),
    .Y(_04_)
  );
  OR _37_ (
    .A(_01_),
    .B(\IF_IDrs1_i[3] ),
    .Y(_05_)
  );
  NAND _38_ (
    .A(_01_),
    .B(\IF_IDrs1_i[3] ),
    .Y(_06_)
  );
  OR _39_ (
    .A(_00_),
    .B(\IF_IDrs1_i[2] ),
    .Y(_07_)
  );
  XOR _40_ (
    .A(\IF_IDrs1_i[1] ),
    .B(\ID_EXrd_i[1] ),
    .Y(_08_)
  );
  NAND _41_ (
    .A(_04_),
    .B(_05_),
    .Y(_09_)
  );
  NOR _42_ (
    .A(_08_),
    .B(_09_),
    .Y(_10_)
  );
  NAND _43_ (
    .A(_06_),
    .B(_07_),
    .Y(_11_)
  );
  OR _44_ (
    .A(_03_),
    .B(_11_),
    .Y(_12_)
  );
  XOR _45_ (
    .A(\ID_EXrd_i[4] ),
    .B(\IF_IDrs1_i[4] ),
    .Y(_13_)
  );
  NOR _46_ (
    .A(_12_),
    .B(_13_),
    .Y(_14_)
  );
  NAND _47_ (
    .A(_10_),
    .B(_14_),
    .Y(_15_)
  );
  XOR _48_ (
    .A(\ID_EXrd_i[0] ),
    .B(\IF_IDrs2_i[0] ),
    .Y(_16_)
  );
  NAND _49_ (
    .A(_02_),
    .B(\ID_EXrd_i[4] ),
    .Y(_17_)
  );
  NAND _50_ (
    .A(\IF_IDrs2_i[3] ),
    .B(_01_),
    .Y(_18_)
  );
  NAND _51_ (
    .A(_17_),
    .B(_18_),
    .Y(_19_)
  );
  NOR _52_ (
    .A(_16_),
    .B(_19_),
    .Y(_20_)
  );
  OR _53_ (
    .A(\IF_IDrs2_i[3] ),
    .B(_01_),
    .Y(_21_)
  );
  NAND _54_ (
    .A(\IF_IDrs2_i[2] ),
    .B(_00_),
    .Y(_22_)
  );
  AND _55_ (
    .A(_21_),
    .B(_22_),
    .Y(_23_)
  );
  XOR _56_ (
    .A(\ID_EXrd_i[1] ),
    .B(\IF_IDrs2_i[1] ),
    .Y(_24_)
  );
  OR _57_ (
    .A(_02_),
    .B(\ID_EXrd_i[4] ),
    .Y(_25_)
  );
  OR _58_ (
    .A(\IF_IDrs2_i[2] ),
    .B(_00_),
    .Y(_26_)
  );
  NAND _59_ (
    .A(_25_),
    .B(_26_),
    .Y(_27_)
  );
  NOR _60_ (
    .A(_24_),
    .B(_27_),
    .Y(_28_)
  );
  AND _61_ (
    .A(_23_),
    .B(_28_),
    .Y(_29_)
  );
  NAND _62_ (
    .A(_20_),
    .B(_29_),
    .Y(_30_)
  );
  NAND _63_ (
    .A(_15_),
    .B(_30_),
    .Y(_31_)
  );
  AND _64_ (
    .A(ID_EX_MemRead_i),
    .B(_31_),
    .Y(Hazard_o)
  );
endmodule