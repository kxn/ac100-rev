; func rrm_reset_ap_pwr_para_all @ 0x004ad18c size=0x4c
  4ad18c:	27bdffd8 	addiu	sp,sp,-40
  4ad190:	afb0001c 	sw	s0,28(sp)
  4ad194:	3c100076 	lui	s0,0x76
  4ad198:	afb10020 	sw	s1,32(sp)
  4ad19c:	26107bec 	addiu	s0,s0,31724
  4ad1a0:	afbf0024 	sw	ra,36(sp)
  4ad1a4:	2611000c 	addiu	s1,s0,12
  4ad1a8:	8e040000 	lw	a0,0(s0)
  4ad1ac:	10800003 	beqz	a0,0x4ad1bc
  4ad1b0:	26100004 	addiu	s0,s0,4
  4ad1b4:	0c12cd85 	jal	0x4b3614
  4ad1b8:	00000000 	nop
  4ad1bc:	5611fffb 	bnel	s0,s1,0x4ad1ac
  4ad1c0:	8e040000 	lw	a0,0(s0)
  4ad1c4:	8fbf0024 	lw	ra,36(sp)
  4ad1c8:	8fb10020 	lw	s1,32(sp)
  4ad1cc:	8fb0001c 	lw	s0,28(sp)
  4ad1d0:	03e00008 	jr	ra
  4ad1d4:	27bd0028 	addiu	sp,sp,40
