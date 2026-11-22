; func reset_acs_container @ 0x004845ec size=0x30
  4845ec:	27bdffe0 	addiu	sp,sp,-32
  4845f0:	afb00018 	sw	s0,24(sp)
  4845f4:	afbf001c 	sw	ra,28(sp)
  4845f8:	0c12116b 	jal	0x4845ac
  4845fc:	3c100076 	lui	s0,0x76
  484600:	0c102024 	jal	0x408090
  484604:	8e047614 	lw	a0,30228(s0)
  484608:	8fbf001c 	lw	ra,28(sp)
  48460c:	ae007614 	sw	zero,30228(s0)
  484610:	8fb00018 	lw	s0,24(sp)
  484614:	03e00008 	jr	ra
  484618:	27bd0020 	addiu	sp,sp,32
