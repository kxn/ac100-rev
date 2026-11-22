; func cw_dtls_pkt_sh_get @ 0x005985bc size=0x6c
  5985bc:	27bdffd8 	addiu	sp,sp,-40
  5985c0:	00001021 	move	v0,zero
  5985c4:	afbf0024 	sw	ra,36(sp)
  5985c8:	afb10020 	sw	s1,32(sp)
  5985cc:	10800011 	beqz	a0,0x598614
  5985d0:	afb0001c 	sw	s0,28(sp)
  5985d4:	24840004 	addiu	a0,a0,4
  5985d8:	0c10206c 	jal	0x4081b0
  5985dc:	24100016 	li	s0,22
  5985e0:	1040000c 	beqz	v0,0x598614
  5985e4:	24110002 	li	s1,2
  5985e8:	9043000c 	lbu	v1,12(v0)
  5985ec:	14700005 	bne	v1,s0,0x598604
  5985f0:	00000000 	nop
  5985f4:	8c43001c 	lw	v1,28(v0)
  5985f8:	90630000 	lbu	v1,0(v1)
  5985fc:	10710006 	beq	v1,s1,0x598618
  598600:	8fbf0024 	lw	ra,36(sp)
  598604:	0c1021a0 	jal	0x408680
  598608:	00402021 	move	a0,v0
  59860c:	5440fff7 	bnezl	v0,0x5985ec
  598610:	9043000c 	lbu	v1,12(v0)
  598614:	8fbf0024 	lw	ra,36(sp)
  598618:	8fb10020 	lw	s1,32(sp)
  59861c:	8fb0001c 	lw	s0,28(sp)
  598620:	03e00008 	jr	ra
  598624:	27bd0028 	addiu	sp,sp,40
