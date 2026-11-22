; func cw_data_transfer_mode_free @ 0x0057309c size=0x3c
  57309c:	27bdffe0 	addiu	sp,sp,-32
  5730a0:	afb00018 	sw	s0,24(sp)
  5730a4:	00808021 	move	s0,a0
  5730a8:	afbf001c 	sw	ra,28(sp)
  5730ac:	8c840010 	lw	a0,16(a0)
  5730b0:	10800005 	beqz	a0,0x5730c8
  5730b4:	8fbf001c 	lw	ra,28(sp)
  5730b8:	0c101f7c 	jal	0x407df0
  5730bc:	00000000 	nop
  5730c0:	ae000010 	sw	zero,16(s0)
  5730c4:	8fbf001c 	lw	ra,28(sp)
  5730c8:	00001021 	move	v0,zero
  5730cc:	8fb00018 	lw	s0,24(sp)
  5730d0:	03e00008 	jr	ra
  5730d4:	27bd0020 	addiu	sp,sp,32
