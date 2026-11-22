; func cw_priv_ap_capacity_free @ 0x005a40b0 size=0x3c
  5a40b0:	27bdffe0 	addiu	sp,sp,-32
  5a40b4:	afb00018 	sw	s0,24(sp)
  5a40b8:	00808021 	move	s0,a0
  5a40bc:	afbf001c 	sw	ra,28(sp)
  5a40c0:	8c840010 	lw	a0,16(a0)
  5a40c4:	10800005 	beqz	a0,0x5a40dc
  5a40c8:	8fbf001c 	lw	ra,28(sp)
  5a40cc:	0c101f7c 	jal	0x407df0
  5a40d0:	00000000 	nop
  5a40d4:	ae000010 	sw	zero,16(s0)
  5a40d8:	8fbf001c 	lw	ra,28(sp)
  5a40dc:	00001021 	move	v0,zero
  5a40e0:	8fb00018 	lw	s0,24(sp)
  5a40e4:	03e00008 	jr	ra
  5a40e8:	27bd0020 	addiu	sp,sp,32
