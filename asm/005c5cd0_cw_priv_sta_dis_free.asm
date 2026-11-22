; func cw_priv_sta_dis_free @ 0x005c5cd0 size=0x3c
  5c5cd0:	27bdffe0 	addiu	sp,sp,-32
  5c5cd4:	afb00018 	sw	s0,24(sp)
  5c5cd8:	00808021 	move	s0,a0
  5c5cdc:	afbf001c 	sw	ra,28(sp)
  5c5ce0:	8c840010 	lw	a0,16(a0)
  5c5ce4:	10800005 	beqz	a0,0x5c5cfc
  5c5ce8:	8fbf001c 	lw	ra,28(sp)
  5c5cec:	0c101f7c 	jal	0x407df0
  5c5cf0:	00000000 	nop
  5c5cf4:	ae000010 	sw	zero,16(s0)
  5c5cf8:	8fbf001c 	lw	ra,28(sp)
  5c5cfc:	00001021 	move	v0,zero
  5c5d00:	8fb00018 	lw	s0,24(sp)
  5c5d04:	03e00008 	jr	ra
  5c5d08:	27bd0020 	addiu	sp,sp,32
