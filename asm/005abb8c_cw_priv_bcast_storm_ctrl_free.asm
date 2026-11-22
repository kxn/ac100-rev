; func cw_priv_bcast_storm_ctrl_free @ 0x005abb8c size=0x3c
  5abb8c:	27bdffe0 	addiu	sp,sp,-32
  5abb90:	afb00018 	sw	s0,24(sp)
  5abb94:	00808021 	move	s0,a0
  5abb98:	afbf001c 	sw	ra,28(sp)
  5abb9c:	8c840010 	lw	a0,16(a0)
  5abba0:	10800005 	beqz	a0,0x5abbb8
  5abba4:	8fbf001c 	lw	ra,28(sp)
  5abba8:	0c101f7c 	jal	0x407df0
  5abbac:	00000000 	nop
  5abbb0:	ae000010 	sw	zero,16(s0)
  5abbb4:	8fbf001c 	lw	ra,28(sp)
  5abbb8:	00001021 	move	v0,zero
  5abbbc:	8fb00018 	lw	s0,24(sp)
  5abbc0:	03e00008 	jr	ra
  5abbc4:	27bd0020 	addiu	sp,sp,32
