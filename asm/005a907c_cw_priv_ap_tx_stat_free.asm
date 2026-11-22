; func cw_priv_ap_tx_stat_free @ 0x005a907c size=0x3c
  5a907c:	27bdffe0 	addiu	sp,sp,-32
  5a9080:	afb00018 	sw	s0,24(sp)
  5a9084:	00808021 	move	s0,a0
  5a9088:	afbf001c 	sw	ra,28(sp)
  5a908c:	8c840010 	lw	a0,16(a0)
  5a9090:	10800005 	beqz	a0,0x5a90a8
  5a9094:	8fbf001c 	lw	ra,28(sp)
  5a9098:	0c101f7c 	jal	0x407df0
  5a909c:	00000000 	nop
  5a90a0:	ae000010 	sw	zero,16(s0)
  5a90a4:	8fbf001c 	lw	ra,28(sp)
  5a90a8:	00001021 	move	v0,zero
  5a90ac:	8fb00018 	lw	s0,24(sp)
  5a90b0:	03e00008 	jr	ra
  5a90b4:	27bd0020 	addiu	sp,sp,32
