; func cw_wtp_fallback_free @ 0x00585148 size=0x3c
  585148:	27bdffe0 	addiu	sp,sp,-32
  58514c:	afb00018 	sw	s0,24(sp)
  585150:	00808021 	move	s0,a0
  585154:	afbf001c 	sw	ra,28(sp)
  585158:	8c840010 	lw	a0,16(a0)
  58515c:	10800005 	beqz	a0,0x585174
  585160:	8fbf001c 	lw	ra,28(sp)
  585164:	0c101f7c 	jal	0x407df0
  585168:	00000000 	nop
  58516c:	ae000010 	sw	zero,16(s0)
  585170:	8fbf001c 	lw	ra,28(sp)
  585174:	00001021 	move	v0,zero
  585178:	8fb00018 	lw	s0,24(sp)
  58517c:	03e00008 	jr	ra
  585180:	27bd0020 	addiu	sp,sp,32
