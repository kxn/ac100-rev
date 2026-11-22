; func cw_ecn_support_free @ 0x00576070 size=0x3c
  576070:	27bdffe0 	addiu	sp,sp,-32
  576074:	afb00018 	sw	s0,24(sp)
  576078:	00808021 	move	s0,a0
  57607c:	afbf001c 	sw	ra,28(sp)
  576080:	8c840010 	lw	a0,16(a0)
  576084:	10800005 	beqz	a0,0x57609c
  576088:	8fbf001c 	lw	ra,28(sp)
  57608c:	0c101f7c 	jal	0x407df0
  576090:	00000000 	nop
  576094:	ae000010 	sw	zero,16(s0)
  576098:	8fbf001c 	lw	ra,28(sp)
  57609c:	00001021 	move	v0,zero
  5760a0:	8fb00018 	lw	s0,24(sp)
  5760a4:	03e00008 	jr	ra
  5760a8:	27bd0020 	addiu	sp,sp,32
