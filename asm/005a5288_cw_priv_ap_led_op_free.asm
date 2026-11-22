; func cw_priv_ap_led_op_free @ 0x005a5288 size=0x3c
  5a5288:	27bdffe0 	addiu	sp,sp,-32
  5a528c:	afb00018 	sw	s0,24(sp)
  5a5290:	00808021 	move	s0,a0
  5a5294:	afbf001c 	sw	ra,28(sp)
  5a5298:	8c840010 	lw	a0,16(a0)
  5a529c:	10800005 	beqz	a0,0x5a52b4
  5a52a0:	8fbf001c 	lw	ra,28(sp)
  5a52a4:	0c101f7c 	jal	0x407df0
  5a52a8:	00000000 	nop
  5a52ac:	ae000010 	sw	zero,16(s0)
  5a52b0:	8fbf001c 	lw	ra,28(sp)
  5a52b4:	00001021 	move	v0,zero
  5a52b8:	8fb00018 	lw	s0,24(sp)
  5a52bc:	03e00008 	jr	ra
  5a52c0:	27bd0020 	addiu	sp,sp,32
