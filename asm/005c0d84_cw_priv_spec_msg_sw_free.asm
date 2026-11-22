; func cw_priv_spec_msg_sw_free @ 0x005c0d84 size=0x3c
  5c0d84:	27bdffe0 	addiu	sp,sp,-32
  5c0d88:	afb00018 	sw	s0,24(sp)
  5c0d8c:	00808021 	move	s0,a0
  5c0d90:	afbf001c 	sw	ra,28(sp)
  5c0d94:	8c840010 	lw	a0,16(a0)
  5c0d98:	10800005 	beqz	a0,0x5c0db0
  5c0d9c:	8fbf001c 	lw	ra,28(sp)
  5c0da0:	0c101f7c 	jal	0x407df0
  5c0da4:	00000000 	nop
  5c0da8:	ae000010 	sw	zero,16(s0)
  5c0dac:	8fbf001c 	lw	ra,28(sp)
  5c0db0:	00001021 	move	v0,zero
  5c0db4:	8fb00018 	lw	s0,24(sp)
  5c0db8:	03e00008 	jr	ra
  5c0dbc:	27bd0020 	addiu	sp,sp,32
