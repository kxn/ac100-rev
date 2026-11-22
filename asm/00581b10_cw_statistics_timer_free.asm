; func cw_statistics_timer_free @ 0x00581b10 size=0x3c
  581b10:	27bdffe0 	addiu	sp,sp,-32
  581b14:	afb00018 	sw	s0,24(sp)
  581b18:	00808021 	move	s0,a0
  581b1c:	afbf001c 	sw	ra,28(sp)
  581b20:	8c840010 	lw	a0,16(a0)
  581b24:	10800005 	beqz	a0,0x581b3c
  581b28:	8fbf001c 	lw	ra,28(sp)
  581b2c:	0c101f7c 	jal	0x407df0
  581b30:	00000000 	nop
  581b34:	ae000010 	sw	zero,16(s0)
  581b38:	8fbf001c 	lw	ra,28(sp)
  581b3c:	00001021 	move	v0,zero
  581b40:	8fb00018 	lw	s0,24(sp)
  581b44:	03e00008 	jr	ra
  581b48:	27bd0020 	addiu	sp,sp,32
