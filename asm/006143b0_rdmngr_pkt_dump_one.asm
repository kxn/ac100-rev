; func rdmngr_pkt_dump_one @ 0x006143b0 size=0x40
  6143b0:	27bdffe0 	addiu	sp,sp,-32
  6143b4:	afb00018 	sw	s0,24(sp)
  6143b8:	00808021 	move	s0,a0
  6143bc:	afbf001c 	sw	ra,28(sp)
  6143c0:	0c188759 	jal	0x621d64
  6143c4:	00a02021 	move	a0,a1
  6143c8:	54400005 	bnezl	v0,0x6143e0
  6143cc:	02002021 	move	a0,s0
  6143d0:	8fbf001c 	lw	ra,28(sp)
  6143d4:	8fb00018 	lw	s0,24(sp)
  6143d8:	03e00008 	jr	ra
  6143dc:	27bd0020 	addiu	sp,sp,32
  6143e0:	8fbf001c 	lw	ra,28(sp)
  6143e4:	8fb00018 	lw	s0,24(sp)
  6143e8:	08161d66 	j	0x587598
  6143ec:	27bd0020 	addiu	sp,sp,32
