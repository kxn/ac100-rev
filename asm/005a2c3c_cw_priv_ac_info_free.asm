; func cw_priv_ac_info_free @ 0x005a2c3c size=0x3c
  5a2c3c:	27bdffe0 	addiu	sp,sp,-32
  5a2c40:	afb00018 	sw	s0,24(sp)
  5a2c44:	00808021 	move	s0,a0
  5a2c48:	afbf001c 	sw	ra,28(sp)
  5a2c4c:	8c840010 	lw	a0,16(a0)
  5a2c50:	10800005 	beqz	a0,0x5a2c68
  5a2c54:	8fbf001c 	lw	ra,28(sp)
  5a2c58:	0c101f7c 	jal	0x407df0
  5a2c5c:	00000000 	nop
  5a2c60:	ae000010 	sw	zero,16(s0)
  5a2c64:	8fbf001c 	lw	ra,28(sp)
  5a2c68:	00001021 	move	v0,zero
  5a2c6c:	8fb00018 	lw	s0,24(sp)
  5a2c70:	03e00008 	jr	ra
  5a2c74:	27bd0020 	addiu	sp,sp,32
