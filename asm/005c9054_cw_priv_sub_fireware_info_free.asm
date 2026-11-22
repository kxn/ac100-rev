; func cw_priv_sub_fireware_info_free @ 0x005c9054 size=0x3c
  5c9054:	27bdffe0 	addiu	sp,sp,-32
  5c9058:	afb00018 	sw	s0,24(sp)
  5c905c:	00808021 	move	s0,a0
  5c9060:	afbf001c 	sw	ra,28(sp)
  5c9064:	8c840010 	lw	a0,16(a0)
  5c9068:	10800005 	beqz	a0,0x5c9080
  5c906c:	8fbf001c 	lw	ra,28(sp)
  5c9070:	0c101f7c 	jal	0x407df0
  5c9074:	00000000 	nop
  5c9078:	ae000010 	sw	zero,16(s0)
  5c907c:	8fbf001c 	lw	ra,28(sp)
  5c9080:	00001021 	move	v0,zero
  5c9084:	8fb00018 	lw	s0,24(sp)
  5c9088:	03e00008 	jr	ra
  5c908c:	27bd0020 	addiu	sp,sp,32
