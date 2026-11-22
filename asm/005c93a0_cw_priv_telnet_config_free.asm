; func cw_priv_telnet_config_free @ 0x005c93a0 size=0x3c
  5c93a0:	27bdffe0 	addiu	sp,sp,-32
  5c93a4:	afb00018 	sw	s0,24(sp)
  5c93a8:	00808021 	move	s0,a0
  5c93ac:	afbf001c 	sw	ra,28(sp)
  5c93b0:	8c840010 	lw	a0,16(a0)
  5c93b4:	10800005 	beqz	a0,0x5c93cc
  5c93b8:	8fbf001c 	lw	ra,28(sp)
  5c93bc:	0c101f7c 	jal	0x407df0
  5c93c0:	00000000 	nop
  5c93c4:	ae000010 	sw	zero,16(s0)
  5c93c8:	8fbf001c 	lw	ra,28(sp)
  5c93cc:	00001021 	move	v0,zero
  5c93d0:	8fb00018 	lw	s0,24(sp)
  5c93d4:	03e00008 	jr	ra
  5c93d8:	27bd0020 	addiu	sp,sp,32
