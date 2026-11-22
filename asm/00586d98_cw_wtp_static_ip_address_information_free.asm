; func cw_wtp_static_ip_address_information_free @ 0x00586d98 size=0x3c
  586d98:	27bdffe0 	addiu	sp,sp,-32
  586d9c:	afb00018 	sw	s0,24(sp)
  586da0:	00808021 	move	s0,a0
  586da4:	afbf001c 	sw	ra,28(sp)
  586da8:	8c840010 	lw	a0,16(a0)
  586dac:	10800005 	beqz	a0,0x586dc4
  586db0:	8fbf001c 	lw	ra,28(sp)
  586db4:	0c101f7c 	jal	0x407df0
  586db8:	00000000 	nop
  586dbc:	ae000010 	sw	zero,16(s0)
  586dc0:	8fbf001c 	lw	ra,28(sp)
  586dc4:	00001021 	move	v0,zero
  586dc8:	8fb00018 	lw	s0,24(sp)
  586dcc:	03e00008 	jr	ra
  586dd0:	27bd0020 	addiu	sp,sp,32
