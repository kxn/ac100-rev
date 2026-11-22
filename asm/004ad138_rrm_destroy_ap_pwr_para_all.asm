; func rrm_destroy_ap_pwr_para_all @ 0x004ad138 size=0x54
  4ad138:	27bdffd8 	addiu	sp,sp,-40
  4ad13c:	afb0001c 	sw	s0,28(sp)
  4ad140:	3c100076 	lui	s0,0x76
  4ad144:	afb10020 	sw	s1,32(sp)
  4ad148:	26107bec 	addiu	s0,s0,31724
  4ad14c:	afbf0024 	sw	ra,36(sp)
  4ad150:	2611000c 	addiu	s1,s0,12
  4ad154:	8e040000 	lw	a0,0(s0)
  4ad158:	50800005 	beqzl	a0,0x4ad170
  4ad15c:	26100004 	addiu	s0,s0,4
  4ad160:	0c12ccc2 	jal	0x4b3308
  4ad164:	00000000 	nop
  4ad168:	ae000000 	sw	zero,0(s0)
  4ad16c:	26100004 	addiu	s0,s0,4
  4ad170:	5611fff9 	bnel	s0,s1,0x4ad158
  4ad174:	8e040000 	lw	a0,0(s0)
  4ad178:	8fbf0024 	lw	ra,36(sp)
  4ad17c:	8fb10020 	lw	s1,32(sp)
  4ad180:	8fb0001c 	lw	s0,28(sp)
  4ad184:	03e00008 	jr	ra
  4ad188:	27bd0028 	addiu	sp,sp,40
