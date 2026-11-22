; func cw_priv_port_info_free @ 0x005b8038 size=0x58
  5b8038:	27bdffe0 	addiu	sp,sp,-32
  5b803c:	afbf001c 	sw	ra,28(sp)
  5b8040:	afb00018 	sw	s0,24(sp)
  5b8044:	8c900010 	lw	s0,16(a0)
  5b8048:	5200000d 	beqzl	s0,0x5b8080
  5b804c:	8fbf001c 	lw	ra,28(sp)
  5b8050:	92020000 	lbu	v0,0(s0)
  5b8054:	10400007 	beqz	v0,0x5b8074
  5b8058:	00000000 	nop
  5b805c:	8e040004 	lw	a0,4(s0)
  5b8060:	10800004 	beqz	a0,0x5b8074
  5b8064:	00000000 	nop
  5b8068:	0c101f7c 	jal	0x407df0
  5b806c:	00000000 	nop
  5b8070:	ae000004 	sw	zero,4(s0)
  5b8074:	0c101f7c 	jal	0x407df0
  5b8078:	02002021 	move	a0,s0
  5b807c:	8fbf001c 	lw	ra,28(sp)
  5b8080:	00001021 	move	v0,zero
  5b8084:	8fb00018 	lw	s0,24(sp)
  5b8088:	03e00008 	jr	ra
  5b808c:	27bd0020 	addiu	sp,sp,32
