; func rb_first @ 0x0051f7a0 size=0x28
  51f7a0:	8c820000 	lw	v0,0(a0)
  51f7a4:	54400004 	bnezl	v0,0x51f7b8
  51f7a8:	8c430008 	lw	v1,8(v0)
  51f7ac:	10000004 	b	0x51f7c0
  51f7b0:	00000000 	nop
  51f7b4:	8c430008 	lw	v1,8(v0)
  51f7b8:	5460fffe 	bnezl	v1,0x51f7b4
  51f7bc:	00601021 	move	v0,v1
  51f7c0:	03e00008 	jr	ra
  51f7c4:	00000000 	nop
