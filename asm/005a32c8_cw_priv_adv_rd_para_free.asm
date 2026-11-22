; func cw_priv_adv_rd_para_free @ 0x005a32c8 size=0x3c
  5a32c8:	27bdffe0 	addiu	sp,sp,-32
  5a32cc:	afb00018 	sw	s0,24(sp)
  5a32d0:	00808021 	move	s0,a0
  5a32d4:	afbf001c 	sw	ra,28(sp)
  5a32d8:	8c840010 	lw	a0,16(a0)
  5a32dc:	10800005 	beqz	a0,0x5a32f4
  5a32e0:	8fbf001c 	lw	ra,28(sp)
  5a32e4:	0c101f7c 	jal	0x407df0
  5a32e8:	00000000 	nop
  5a32ec:	ae000010 	sw	zero,16(s0)
  5a32f0:	8fbf001c 	lw	ra,28(sp)
  5a32f4:	00001021 	move	v0,zero
  5a32f8:	8fb00018 	lw	s0,24(sp)
  5a32fc:	03e00008 	jr	ra
  5a3300:	27bd0020 	addiu	sp,sp,32
