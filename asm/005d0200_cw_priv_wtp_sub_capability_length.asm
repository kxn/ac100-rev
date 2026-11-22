; func cw_priv_wtp_sub_capability_length @ 0x005d0200 size=0x48
  5d0200:	1080000f 	beqz	a0,0x5d0240
  5d0204:	00001021 	move	v0,zero
  5d0208:	94850000 	lhu	a1,0(a0)
  5d020c:	00001821 	move	v1,zero
  5d0210:	0817408d 	j	0x5d0234
  5d0214:	24020002 	li	v0,2
  5d0218:	000330c0 	sll	a2,v1,0x3
  5d021c:	24630001 	addiu	v1,v1,1
  5d0220:	00e63021 	addu	a2,a3,a2
  5d0224:	94c60002 	lhu	a2,2(a2)
  5d0228:	24c60004 	addiu	a2,a2,4
  5d022c:	00461021 	addu	v0,v0,a2
  5d0230:	3042ffff 	andi	v0,v0,0xffff
  5d0234:	0065302a 	slt	a2,v1,a1
  5d0238:	54c0fff7 	bnezl	a2,0x5d0218
  5d023c:	8c870004 	lw	a3,4(a0)
  5d0240:	03e00008 	jr	ra
  5d0244:	00000000 	nop
