; func cw_priv_sta_pmk_req_free @ 0x005c70bc size=0x3c
  5c70bc:	27bdffe0 	addiu	sp,sp,-32
  5c70c0:	afb00018 	sw	s0,24(sp)
  5c70c4:	00808021 	move	s0,a0
  5c70c8:	afbf001c 	sw	ra,28(sp)
  5c70cc:	8c840010 	lw	a0,16(a0)
  5c70d0:	10800005 	beqz	a0,0x5c70e8
  5c70d4:	8fbf001c 	lw	ra,28(sp)
  5c70d8:	0c101f7c 	jal	0x407df0
  5c70dc:	00000000 	nop
  5c70e0:	ae000010 	sw	zero,16(s0)
  5c70e4:	8fbf001c 	lw	ra,28(sp)
  5c70e8:	00001021 	move	v0,zero
  5c70ec:	8fb00018 	lw	s0,24(sp)
  5c70f0:	03e00008 	jr	ra
  5c70f4:	27bd0020 	addiu	sp,sp,32
