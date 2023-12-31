/* Generated by Yosys 0.9 (git sha1 1979e0b) */

(* src = "Forwarding_unit.v:22" *)
module Forwarding_unit(EX_MEM_RegWrite_i, \EX_MEM_RD_i[0] , \EX_MEM_RD_i[1] , \EX_MEM_RD_i[2] , \EX_MEM_RD_i[3] , \EX_MEM_RD_i[4] , \ID_EX_RS_i[0] , \ID_EX_RS_i[1] , \ID_EX_RS_i[2] , \ID_EX_RS_i[3] , \ID_EX_RS_i[4] , \ID_EX_RT_i[0] , \ID_EX_RT_i[1] , \ID_EX_RT_i[2] , \ID_EX_RT_i[3] , \ID_EX_RT_i[4] , MEM_WB_RegWrite_i, \MEM_WB_RD_i[0] , \MEM_WB_RD_i[1] , \MEM_WB_RD_i[2] , \MEM_WB_RD_i[3] , \MEM_WB_RD_i[4] , \ForwardA_o[0] , \ForwardA_o[1] , \ForwardB_o[0] , \ForwardB_o[1] );
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
  wire _32_;
  wire _33_;
  wire _34_;
  wire _35_;
  wire _36_;
  wire _37_;
  wire _38_;
  wire _39_;
  wire _40_;
  wire _41_;
  wire _42_;
  wire _43_;
  wire _44_;
  wire _45_;
  wire _46_;
  wire _47_;
  (* src = "Forwarding_unit.v:35" *)
  input \EX_MEM_RD_i[0] ;
  (* src = "Forwarding_unit.v:35" *)
  input \EX_MEM_RD_i[1] ;
  (* src = "Forwarding_unit.v:35" *)
  input \EX_MEM_RD_i[2] ;
  (* src = "Forwarding_unit.v:35" *)
  input \EX_MEM_RD_i[3] ;
  (* src = "Forwarding_unit.v:35" *)
  input \EX_MEM_RD_i[4] ;
  (* src = "Forwarding_unit.v:34" *)
  input EX_MEM_RegWrite_i;
  (* src = "Forwarding_unit.v:36" *)
  output \ForwardA_o[0] ;
  (* src = "Forwarding_unit.v:36" *)
  output \ForwardA_o[1] ;
  (* src = "Forwarding_unit.v:36" *)
  output \ForwardB_o[0] ;
  (* src = "Forwarding_unit.v:36" *)
  output \ForwardB_o[1] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RS_i[0] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RS_i[1] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RS_i[2] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RS_i[3] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RS_i[4] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RT_i[0] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RT_i[1] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RT_i[2] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RT_i[3] ;
  (* src = "Forwarding_unit.v:35" *)
  input \ID_EX_RT_i[4] ;
  (* src = "Forwarding_unit.v:35" *)
  input \MEM_WB_RD_i[0] ;
  (* src = "Forwarding_unit.v:35" *)
  input \MEM_WB_RD_i[1] ;
  (* src = "Forwarding_unit.v:35" *)
  input \MEM_WB_RD_i[2] ;
  (* src = "Forwarding_unit.v:35" *)
  input \MEM_WB_RD_i[3] ;
  (* src = "Forwarding_unit.v:35" *)
  input \MEM_WB_RD_i[4] ;
  (* src = "Forwarding_unit.v:34" *)
  input MEM_WB_RegWrite_i;
  NOR _48_ (
    .A(\EX_MEM_RD_i[1] ),
    .B(\EX_MEM_RD_i[0] ),
    .Y(_00_)
  );
  NOR _49_ (
    .A(\EX_MEM_RD_i[3] ),
    .B(\EX_MEM_RD_i[4] ),
    .Y(_01_)
  );
  NAND _50_ (
    .A(_00_),
    .B(_01_),
    .Y(_02_)
  );
  OR _51_ (
    .A(\EX_MEM_RD_i[2] ),
    .B(_02_),
    .Y(_03_)
  );
  AND _52_ (
    .A(EX_MEM_RegWrite_i),
    .B(_03_),
    .Y(_04_)
  );
  XOR _53_ (
    .A(\EX_MEM_RD_i[3] ),
    .B(\ID_EX_RS_i[3] ),
    .Y(_05_)
  );
  XOR _54_ (
    .A(\EX_MEM_RD_i[4] ),
    .B(\ID_EX_RS_i[4] ),
    .Y(_06_)
  );
  NOR _55_ (
    .A(_05_),
    .B(_06_),
    .Y(_07_)
  );
  XOR _56_ (
    .A(\EX_MEM_RD_i[1] ),
    .B(\ID_EX_RS_i[1] ),
    .Y(_08_)
  );
  XOR _57_ (
    .A(\EX_MEM_RD_i[2] ),
    .B(\ID_EX_RS_i[2] ),
    .Y(_09_)
  );
  XOR _58_ (
    .A(\EX_MEM_RD_i[0] ),
    .B(\ID_EX_RS_i[0] ),
    .Y(_10_)
  );
  OR _59_ (
    .A(_09_),
    .B(_10_),
    .Y(_11_)
  );
  NOR _60_ (
    .A(_08_),
    .B(_11_),
    .Y(_12_)
  );
  AND _61_ (
    .A(_07_),
    .B(_12_),
    .Y(_13_)
  );
  AND _62_ (
    .A(_04_),
    .B(_13_),
    .Y(\ForwardA_o[1] )
  );
  XOR _63_ (
    .A(\EX_MEM_RD_i[2] ),
    .B(\ID_EX_RT_i[2] ),
    .Y(_14_)
  );
  XOR _64_ (
    .A(\EX_MEM_RD_i[1] ),
    .B(\ID_EX_RT_i[1] ),
    .Y(_15_)
  );
  NOR _65_ (
    .A(_14_),
    .B(_15_),
    .Y(_16_)
  );
  XOR _66_ (
    .A(\EX_MEM_RD_i[3] ),
    .B(\ID_EX_RT_i[3] ),
    .Y(_17_)
  );
  XOR _67_ (
    .A(\EX_MEM_RD_i[4] ),
    .B(\ID_EX_RT_i[4] ),
    .Y(_18_)
  );
  XOR _68_ (
    .A(\EX_MEM_RD_i[0] ),
    .B(\ID_EX_RT_i[0] ),
    .Y(_19_)
  );
  OR _69_ (
    .A(_18_),
    .B(_19_),
    .Y(_20_)
  );
  NOR _70_ (
    .A(_17_),
    .B(_20_),
    .Y(_21_)
  );
  AND _71_ (
    .A(_16_),
    .B(_21_),
    .Y(_22_)
  );
  AND _72_ (
    .A(_04_),
    .B(_22_),
    .Y(\ForwardB_o[1] )
  );
  NOR _73_ (
    .A(\MEM_WB_RD_i[1] ),
    .B(\MEM_WB_RD_i[0] ),
    .Y(_23_)
  );
  NOR _74_ (
    .A(\MEM_WB_RD_i[3] ),
    .B(\MEM_WB_RD_i[4] ),
    .Y(_24_)
  );
  NAND _75_ (
    .A(_23_),
    .B(_24_),
    .Y(_25_)
  );
  OR _76_ (
    .A(\MEM_WB_RD_i[2] ),
    .B(_25_),
    .Y(_26_)
  );
  AND _77_ (
    .A(MEM_WB_RegWrite_i),
    .B(_26_),
    .Y(_27_)
  );
  XOR _78_ (
    .A(\ID_EX_RT_i[4] ),
    .B(\MEM_WB_RD_i[4] ),
    .Y(_28_)
  );
  XOR _79_ (
    .A(\ID_EX_RT_i[1] ),
    .B(\MEM_WB_RD_i[1] ),
    .Y(_29_)
  );
  NOR _80_ (
    .A(_28_),
    .B(_29_),
    .Y(_30_)
  );
  XOR _81_ (
    .A(\ID_EX_RT_i[2] ),
    .B(\MEM_WB_RD_i[2] ),
    .Y(_31_)
  );
  XOR _82_ (
    .A(\ID_EX_RT_i[0] ),
    .B(\MEM_WB_RD_i[0] ),
    .Y(_32_)
  );
  XOR _83_ (
    .A(\ID_EX_RT_i[3] ),
    .B(\MEM_WB_RD_i[3] ),
    .Y(_33_)
  );
  OR _84_ (
    .A(_32_),
    .B(_33_),
    .Y(_34_)
  );
  NOR _85_ (
    .A(_31_),
    .B(_34_),
    .Y(_35_)
  );
  AND _86_ (
    .A(_30_),
    .B(_35_),
    .Y(_36_)
  );
  NAND _87_ (
    .A(_27_),
    .B(_36_),
    .Y(_37_)
  );
  NOR _88_ (
    .A(\ForwardB_o[1] ),
    .B(_37_),
    .Y(\ForwardB_o[0] )
  );
  XOR _89_ (
    .A(\ID_EX_RS_i[0] ),
    .B(\MEM_WB_RD_i[0] ),
    .Y(_38_)
  );
  XOR _90_ (
    .A(\ID_EX_RS_i[3] ),
    .B(\MEM_WB_RD_i[3] ),
    .Y(_39_)
  );
  NOR _91_ (
    .A(_38_),
    .B(_39_),
    .Y(_40_)
  );
  XOR _92_ (
    .A(\ID_EX_RS_i[4] ),
    .B(\MEM_WB_RD_i[4] ),
    .Y(_41_)
  );
  XOR _93_ (
    .A(\ID_EX_RS_i[2] ),
    .B(\MEM_WB_RD_i[2] ),
    .Y(_42_)
  );
  XOR _94_ (
    .A(\ID_EX_RS_i[1] ),
    .B(\MEM_WB_RD_i[1] ),
    .Y(_43_)
  );
  OR _95_ (
    .A(_42_),
    .B(_43_),
    .Y(_44_)
  );
  NOR _96_ (
    .A(_41_),
    .B(_44_),
    .Y(_45_)
  );
  AND _97_ (
    .A(_40_),
    .B(_45_),
    .Y(_46_)
  );
  NAND _98_ (
    .A(_27_),
    .B(_46_),
    .Y(_47_)
  );
  NOR _99_ (
    .A(\ForwardA_o[1] ),
    .B(_47_),
    .Y(\ForwardA_o[0] )
  );
endmodule
