; func cw_priv_time_sync_free @ 0x005c96b4 size=0x3c
  5c96b4:	27bdffe0 	addiu	sp,sp,-32
  5c96b8:	afb00018 	sw	s0,24(sp)
  5c96bc:	00808021 	move	s0,a0
  5c96c0:	afbf001c 	sw	ra,28(sp)
  5c96c4:	8c840010 	lw	a0,16(a0)
  5c96c8:	10800005 	beqz	a0,0x5c96e0
  5c96cc:	8fbf001c 	lw	ra,28(sp)
  5c96d0:	0c101f7c 	jal	0x407df0
  5c96d4:	00000000 	nop
  5c96d8:	ae000010 	sw	zero,16(s0)
  5c96dc:	8fbf001c 	lw	ra,28(sp)
  5c96e0:	00001021 	move	v0,zero
  5c96e4:	8fb00018 	lw	s0,24(sp)
  5c96e8:	03e00008 	jr	ra
  5c96ec:	27bd0020 	addiu	sp,sp,32
