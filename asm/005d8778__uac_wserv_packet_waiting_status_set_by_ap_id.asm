; func _uac_wserv_packet_waiting_status_set_by_ap_id @ 0x005d8778 size=0xa4
  5d8778:	27bdffd8 	addiu	sp,sp,-40
  5d877c:	afb10020 	sw	s1,32(sp)
  5d8780:	00a08821 	move	s1,a1
  5d8784:	afb0001c 	sw	s0,28(sp)
  5d8788:	00808021 	move	s0,a0
  5d878c:	04800006 	bltz	a0,0x5d87a8
  5d8790:	afbf0024 	sw	ra,36(sp)
  5d8794:	0c1506a9 	jal	0x541aa4
  5d8798:	00000000 	nop
  5d879c:	0202102a 	slt	v0,s0,v0
  5d87a0:	14400018 	bnez	v0,0x5d8804
  5d87a4:	2403000c 	li	v1,12
  5d87a8:	3c02007d 	lui	v0,0x7d
  5d87ac:	8c42bee4 	lw	v0,-16668(v0)
  5d87b0:	14400006 	bnez	v0,0x5d87cc
  5d87b4:	00000000 	nop
  5d87b8:	8fbf0024 	lw	ra,36(sp)
  5d87bc:	8fb10020 	lw	s1,32(sp)
  5d87c0:	8fb0001c 	lw	s0,28(sp)
  5d87c4:	03e00008 	jr	ra
  5d87c8:	27bd0028 	addiu	sp,sp,40
  5d87cc:	0c16276a 	jal	0x589da8
  5d87d0:	00000000 	nop
  5d87d4:	1040fff9 	beqz	v0,0x5d87bc
  5d87d8:	8fbf0024 	lw	ra,36(sp)
  5d87dc:	3c04006f 	lui	a0,0x6f
  5d87e0:	3c05006f 	lui	a1,0x6f
  5d87e4:	8fb10020 	lw	s1,32(sp)
  5d87e8:	02003821 	move	a3,s0
  5d87ec:	8fb0001c 	lw	s0,28(sp)
  5d87f0:	24843cac 	addiu	a0,a0,15532
  5d87f4:	24a56c58 	addiu	a1,a1,27736
  5d87f8:	240600e0 	li	a2,224
  5d87fc:	08101b74 	j	0x406dd0
  5d8800:	27bd0028 	addiu	sp,sp,40
  5d8804:	3c020076 	lui	v0,0x76
  5d8808:	72038002 	mul	s0,s0,v1
  5d880c:	8c4298e8 	lw	v0,-26392(v0)
  5d8810:	00508021 	addu	s0,v0,s0
  5d8814:	081761ee 	j	0x5d87b8
  5d8818:	a2110002 	sb	s1,2(s0)
