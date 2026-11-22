; func _uac_wserv_packet_last_send_status_set_by_ap_id @ 0x005d89b4 size=0xa4
  5d89b4:	27bdffd8 	addiu	sp,sp,-40
  5d89b8:	afb10020 	sw	s1,32(sp)
  5d89bc:	00a08821 	move	s1,a1
  5d89c0:	afb0001c 	sw	s0,28(sp)
  5d89c4:	00808021 	move	s0,a0
  5d89c8:	04800006 	bltz	a0,0x5d89e4
  5d89cc:	afbf0024 	sw	ra,36(sp)
  5d89d0:	0c1506a9 	jal	0x541aa4
  5d89d4:	00000000 	nop
  5d89d8:	0202102a 	slt	v0,s0,v0
  5d89dc:	14400018 	bnez	v0,0x5d8a40
  5d89e0:	2403000c 	li	v1,12
  5d89e4:	3c02007d 	lui	v0,0x7d
  5d89e8:	8c42bee4 	lw	v0,-16668(v0)
  5d89ec:	14400006 	bnez	v0,0x5d8a08
  5d89f0:	00000000 	nop
  5d89f4:	8fbf0024 	lw	ra,36(sp)
  5d89f8:	8fb10020 	lw	s1,32(sp)
  5d89fc:	8fb0001c 	lw	s0,28(sp)
  5d8a00:	03e00008 	jr	ra
  5d8a04:	27bd0028 	addiu	sp,sp,40
  5d8a08:	0c16276a 	jal	0x589da8
  5d8a0c:	00000000 	nop
  5d8a10:	1040fff9 	beqz	v0,0x5d89f8
  5d8a14:	8fbf0024 	lw	ra,36(sp)
  5d8a18:	3c04006f 	lui	a0,0x6f
  5d8a1c:	3c05006f 	lui	a1,0x6f
  5d8a20:	8fb10020 	lw	s1,32(sp)
  5d8a24:	02003821 	move	a3,s0
  5d8a28:	8fb0001c 	lw	s0,28(sp)
  5d8a2c:	24843cac 	addiu	a0,a0,15532
  5d8a30:	24a56b4c 	addiu	a1,a1,27468
  5d8a34:	240600ea 	li	a2,234
  5d8a38:	08101b74 	j	0x406dd0
  5d8a3c:	27bd0028 	addiu	sp,sp,40
  5d8a40:	3c020076 	lui	v0,0x76
  5d8a44:	72038002 	mul	s0,s0,v1
  5d8a48:	8c4298e8 	lw	v0,-26392(v0)
  5d8a4c:	00508021 	addu	s0,v0,s0
  5d8a50:	0817627d 	j	0x5d89f4
  5d8a54:	a2110004 	sb	s1,4(s0)
