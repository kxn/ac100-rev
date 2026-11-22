; func rb_last @ 0x0051f7c8 size=0x28
  51f7c8:	8c820000 	lw	v0,0(a0)
  51f7cc:	54400004 	bnezl	v0,0x51f7e0
  51f7d0:	8c430004 	lw	v1,4(v0)
  51f7d4:	10000004 	b	0x51f7e8
  51f7d8:	00000000 	nop
  51f7dc:	8c430004 	lw	v1,4(v0)
  51f7e0:	5460fffe 	bnezl	v1,0x51f7dc
  51f7e4:	00601021 	move	v0,v1
  51f7e8:	03e00008 	jr	ra
  51f7ec:	00000000 	nop
