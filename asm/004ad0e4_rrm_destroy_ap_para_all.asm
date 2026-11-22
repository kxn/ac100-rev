; func rrm_destroy_ap_para_all @ 0x004ad0e4 size=0x54
  4ad0e4:	27bdffd8 	addiu	sp,sp,-40
  4ad0e8:	afb0001c 	sw	s0,28(sp)
  4ad0ec:	3c100076 	lui	s0,0x76
  4ad0f0:	afb10020 	sw	s1,32(sp)
  4ad0f4:	26107bf8 	addiu	s0,s0,31736
  4ad0f8:	afbf0024 	sw	ra,36(sp)
  4ad0fc:	2611000c 	addiu	s1,s0,12
  4ad100:	8e040000 	lw	a0,0(s0)
  4ad104:	50800005 	beqzl	a0,0x4ad11c
  4ad108:	26100004 	addiu	s0,s0,4
  4ad10c:	0c12cbea 	jal	0x4b2fa8
  4ad110:	00000000 	nop
  4ad114:	ae000000 	sw	zero,0(s0)
  4ad118:	26100004 	addiu	s0,s0,4
  4ad11c:	5611fff9 	bnel	s0,s1,0x4ad104
  4ad120:	8e040000 	lw	a0,0(s0)
  4ad124:	8fbf0024 	lw	ra,36(sp)
  4ad128:	8fb10020 	lw	s1,32(sp)
  4ad12c:	8fb0001c 	lw	s0,28(sp)
  4ad130:	03e00008 	jr	ra
  4ad134:	27bd0028 	addiu	sp,sp,40
