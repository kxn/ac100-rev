; func cw_priv_data_tunnel_mode_free @ 0x005aee98 size=0x3c
  5aee98:	27bdffe0 	addiu	sp,sp,-32
  5aee9c:	afb00018 	sw	s0,24(sp)
  5aeea0:	00808021 	move	s0,a0
  5aeea4:	afbf001c 	sw	ra,28(sp)
  5aeea8:	8c840010 	lw	a0,16(a0)
  5aeeac:	10800005 	beqz	a0,0x5aeec4
  5aeeb0:	8fbf001c 	lw	ra,28(sp)
  5aeeb4:	0c101f7c 	jal	0x407df0
  5aeeb8:	00000000 	nop
  5aeebc:	ae000010 	sw	zero,16(s0)
  5aeec0:	8fbf001c 	lw	ra,28(sp)
  5aeec4:	00001021 	move	v0,zero
  5aeec8:	8fb00018 	lw	s0,24(sp)
  5aeecc:	03e00008 	jr	ra
  5aeed0:	27bd0020 	addiu	sp,sp,32
