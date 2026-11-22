; func get_mac @ 0x005949dc size=0x3c
  5949dc:	27bdffe0 	addiu	sp,sp,-32
  5949e0:	afb00018 	sw	s0,24(sp)
  5949e4:	00008021 	move	s0,zero
  5949e8:	10800006 	beqz	a0,0x594a04
  5949ec:	afbf001c 	sw	ra,28(sp)
  5949f0:	24050026 	li	a1,38
  5949f4:	0c158a95 	jal	0x562a54
  5949f8:	24060004 	li	a2,4
  5949fc:	54400001 	bnezl	v0,0x594a04
  594a00:	8c500010 	lw	s0,16(v0)
  594a04:	8fbf001c 	lw	ra,28(sp)
  594a08:	02001021 	move	v0,s0
  594a0c:	8fb00018 	lw	s0,24(sp)
  594a10:	03e00008 	jr	ra
  594a14:	27bd0020 	addiu	sp,sp,32
