; func cw_dtls_pkt_chm_get @ 0x005987c0 size=0x68
  5987c0:	27bdffd8 	addiu	sp,sp,-40
  5987c4:	00001021 	move	v0,zero
  5987c8:	afbf0024 	sw	ra,36(sp)
  5987cc:	afb10020 	sw	s1,32(sp)
  5987d0:	10800010 	beqz	a0,0x598814
  5987d4:	afb0001c 	sw	s0,28(sp)
  5987d8:	24840004 	addiu	a0,a0,4
  5987dc:	0c10206c 	jal	0x4081b0
  5987e0:	24100016 	li	s0,22
  5987e4:	1040000b 	beqz	v0,0x598814
  5987e8:	24110001 	li	s1,1
  5987ec:	9043000c 	lbu	v1,12(v0)
  5987f0:	14700004 	bne	v1,s0,0x598804
  5987f4:	00000000 	nop
  5987f8:	94430010 	lhu	v1,16(v0)
  5987fc:	10710006 	beq	v1,s1,0x598818
  598800:	8fbf0024 	lw	ra,36(sp)
  598804:	0c1021a0 	jal	0x408680
  598808:	00402021 	move	a0,v0
  59880c:	5440fff8 	bnezl	v0,0x5987f0
  598810:	9043000c 	lbu	v1,12(v0)
  598814:	8fbf0024 	lw	ra,36(sp)
  598818:	8fb10020 	lw	s1,32(sp)
  59881c:	8fb0001c 	lw	s0,28(sp)
  598820:	03e00008 	jr	ra
  598824:	27bd0028 	addiu	sp,sp,40
