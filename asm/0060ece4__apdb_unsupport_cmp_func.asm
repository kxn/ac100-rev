; func _apdb_unsupport_cmp_func @ 0x0060ece4 size=0x6c
  60ece4:	27bdffd8 	addiu	sp,sp,-40
  60ece8:	afb20020 	sw	s2,32(sp)
  60ecec:	00a09021 	move	s2,a1
  60ecf0:	afb1001c 	sw	s1,28(sp)
  60ecf4:	00808821 	move	s1,a0
  60ecf8:	afb00018 	sw	s0,24(sp)
  60ecfc:	00008021 	move	s0,zero
  60ed00:	1080000c 	beqz	a0,0x60ed34
  60ed04:	afbf0024 	sw	ra,36(sp)
  60ed08:	10a0000b 	beqz	a1,0x60ed38
  60ed0c:	8fbf0024 	lw	ra,36(sp)
  60ed10:	0c101f44 	jal	0x407d10
  60ed14:	00000000 	nop
  60ed18:	14400007 	bnez	v0,0x60ed38
  60ed1c:	8fbf0024 	lw	ra,36(sp)
  60ed20:	26240042 	addiu	a0,s1,66
  60ed24:	26450042 	addiu	a1,s2,66
  60ed28:	0c101e4c 	jal	0x407930
  60ed2c:	24060004 	li	a2,4
  60ed30:	2c500001 	sltiu	s0,v0,1
  60ed34:	8fbf0024 	lw	ra,36(sp)
  60ed38:	02001021 	move	v0,s0
  60ed3c:	8fb20020 	lw	s2,32(sp)
  60ed40:	8fb1001c 	lw	s1,28(sp)
  60ed44:	8fb00018 	lw	s0,24(sp)
  60ed48:	03e00008 	jr	ra
  60ed4c:	27bd0028 	addiu	sp,sp,40
