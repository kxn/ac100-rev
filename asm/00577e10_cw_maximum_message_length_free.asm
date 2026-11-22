; func cw_maximum_message_length_free @ 0x00577e10 size=0x3c
  577e10:	27bdffe0 	addiu	sp,sp,-32
  577e14:	afb00018 	sw	s0,24(sp)
  577e18:	00808021 	move	s0,a0
  577e1c:	afbf001c 	sw	ra,28(sp)
  577e20:	8c840010 	lw	a0,16(a0)
  577e24:	10800005 	beqz	a0,0x577e3c
  577e28:	8fbf001c 	lw	ra,28(sp)
  577e2c:	0c101f7c 	jal	0x407df0
  577e30:	00000000 	nop
  577e34:	ae000010 	sw	zero,16(s0)
  577e38:	8fbf001c 	lw	ra,28(sp)
  577e3c:	00001021 	move	v0,zero
  577e40:	8fb00018 	lw	s0,24(sp)
  577e44:	03e00008 	jr	ra
  577e48:	27bd0020 	addiu	sp,sp,32
