; func cw_dtls_pkt_shd_get @ 0x00598694 size=0x6c
  598694:	27bdffd8 	addiu	sp,sp,-40
  598698:	00001021 	move	v0,zero
  59869c:	afbf0024 	sw	ra,36(sp)
  5986a0:	afb10020 	sw	s1,32(sp)
  5986a4:	10800011 	beqz	a0,0x5986ec
  5986a8:	afb0001c 	sw	s0,28(sp)
  5986ac:	24840004 	addiu	a0,a0,4
  5986b0:	0c10206c 	jal	0x4081b0
  5986b4:	24100016 	li	s0,22
  5986b8:	1040000c 	beqz	v0,0x5986ec
  5986bc:	2411000e 	li	s1,14
  5986c0:	9043000c 	lbu	v1,12(v0)
  5986c4:	14700005 	bne	v1,s0,0x5986dc
  5986c8:	00000000 	nop
  5986cc:	8c43001c 	lw	v1,28(v0)
  5986d0:	90630000 	lbu	v1,0(v1)
  5986d4:	10710006 	beq	v1,s1,0x5986f0
  5986d8:	8fbf0024 	lw	ra,36(sp)
  5986dc:	0c1021a0 	jal	0x408680
  5986e0:	00402021 	move	a0,v0
  5986e4:	5440fff7 	bnezl	v0,0x5986c4
  5986e8:	9043000c 	lbu	v1,12(v0)
  5986ec:	8fbf0024 	lw	ra,36(sp)
  5986f0:	8fb10020 	lw	s1,32(sp)
  5986f4:	8fb0001c 	lw	s0,28(sp)
  5986f8:	03e00008 	jr	ra
  5986fc:	27bd0028 	addiu	sp,sp,40
