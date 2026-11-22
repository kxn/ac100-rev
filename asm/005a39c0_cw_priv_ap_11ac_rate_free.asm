; func cw_priv_ap_11ac_rate_free @ 0x005a39c0 size=0x3c
  5a39c0:	27bdffe0 	addiu	sp,sp,-32
  5a39c4:	afb00018 	sw	s0,24(sp)
  5a39c8:	00808021 	move	s0,a0
  5a39cc:	afbf001c 	sw	ra,28(sp)
  5a39d0:	8c840010 	lw	a0,16(a0)
  5a39d4:	10800005 	beqz	a0,0x5a39ec
  5a39d8:	8fbf001c 	lw	ra,28(sp)
  5a39dc:	0c101f7c 	jal	0x407df0
  5a39e0:	00000000 	nop
  5a39e4:	ae000010 	sw	zero,16(s0)
  5a39e8:	8fbf001c 	lw	ra,28(sp)
  5a39ec:	00001021 	move	v0,zero
  5a39f0:	8fb00018 	lw	s0,24(sp)
  5a39f4:	03e00008 	jr	ra
  5a39f8:	27bd0020 	addiu	sp,sp,32
