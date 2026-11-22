; func cw_priv_sub_fireware_action_free @ 0x005c8cc0 size=0x3c
  5c8cc0:	27bdffe0 	addiu	sp,sp,-32
  5c8cc4:	afb00018 	sw	s0,24(sp)
  5c8cc8:	00808021 	move	s0,a0
  5c8ccc:	afbf001c 	sw	ra,28(sp)
  5c8cd0:	8c840010 	lw	a0,16(a0)
  5c8cd4:	10800005 	beqz	a0,0x5c8cec
  5c8cd8:	8fbf001c 	lw	ra,28(sp)
  5c8cdc:	0c101f7c 	jal	0x407df0
  5c8ce0:	00000000 	nop
  5c8ce4:	ae000010 	sw	zero,16(s0)
  5c8ce8:	8fbf001c 	lw	ra,28(sp)
  5c8cec:	00001021 	move	v0,zero
  5c8cf0:	8fb00018 	lw	s0,24(sp)
  5c8cf4:	03e00008 	jr	ra
  5c8cf8:	27bd0020 	addiu	sp,sp,32
