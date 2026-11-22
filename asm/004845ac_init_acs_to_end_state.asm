; func init_acs_to_end_state @ 0x004845ac size=0x40
  4845ac:	27bdffe0 	addiu	sp,sp,-32
  4845b0:	2405ffff 	li	a1,-1
  4845b4:	afb00018 	sw	s0,24(sp)
  4845b8:	3c100076 	lui	s0,0x76
  4845bc:	afbf001c 	sw	ra,28(sp)
  4845c0:	0c1020b4 	jal	0x4082d0
  4845c4:	8e0475c0 	lw	a0,30144(s0)
  4845c8:	3c020076 	lui	v0,0x76
  4845cc:	8e0475c0 	lw	a0,30144(s0)
  4845d0:	8fbf001c 	lw	ra,28(sp)
  4845d4:	8fb00018 	lw	s0,24(sp)
  4845d8:	27bd0020 	addiu	sp,sp,32
  4845dc:	ac4075c4 	sw	zero,30148(v0)
  4845e0:	3c020076 	lui	v0,0x76
  4845e4:	08101fcc 	j	0x407f30
  4845e8:	ac407618 	sw	zero,30232(v0)
