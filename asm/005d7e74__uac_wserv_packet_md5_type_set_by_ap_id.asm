; func _uac_wserv_packet_md5_type_set_by_ap_id @ 0x005d7e74 size=0xa4
  5d7e74:	27bdffd8 	addiu	sp,sp,-40
  5d7e78:	afb10020 	sw	s1,32(sp)
  5d7e7c:	00a08821 	move	s1,a1
  5d7e80:	afb0001c 	sw	s0,28(sp)
  5d7e84:	00808021 	move	s0,a0
  5d7e88:	04800006 	bltz	a0,0x5d7ea4
  5d7e8c:	afbf0024 	sw	ra,36(sp)
  5d7e90:	0c1506a9 	jal	0x541aa4
  5d7e94:	00000000 	nop
  5d7e98:	0202102a 	slt	v0,s0,v0
  5d7e9c:	14400018 	bnez	v0,0x5d7f00
  5d7ea0:	2403000c 	li	v1,12
  5d7ea4:	3c02007d 	lui	v0,0x7d
  5d7ea8:	8c42bee4 	lw	v0,-16668(v0)
  5d7eac:	14400006 	bnez	v0,0x5d7ec8
  5d7eb0:	00000000 	nop
  5d7eb4:	8fbf0024 	lw	ra,36(sp)
  5d7eb8:	8fb10020 	lw	s1,32(sp)
  5d7ebc:	8fb0001c 	lw	s0,28(sp)
  5d7ec0:	03e00008 	jr	ra
  5d7ec4:	27bd0028 	addiu	sp,sp,40
  5d7ec8:	0c16276a 	jal	0x589da8
  5d7ecc:	00000000 	nop
  5d7ed0:	1040fff9 	beqz	v0,0x5d7eb8
  5d7ed4:	8fbf0024 	lw	ra,36(sp)
  5d7ed8:	3c04006f 	lui	a0,0x6f
  5d7edc:	3c05006f 	lui	a1,0x6f
  5d7ee0:	8fb10020 	lw	s1,32(sp)
  5d7ee4:	02003821 	move	a3,s0
  5d7ee8:	8fb0001c 	lw	s0,28(sp)
  5d7eec:	24843cac 	addiu	a0,a0,15532
  5d7ef0:	24a56c30 	addiu	a1,a1,27696
  5d7ef4:	240600f4 	li	a2,244
  5d7ef8:	08101b74 	j	0x406dd0
  5d7efc:	27bd0028 	addiu	sp,sp,40
  5d7f00:	3c020076 	lui	v0,0x76
  5d7f04:	72038002 	mul	s0,s0,v1
  5d7f08:	8c4298e8 	lw	v0,-26392(v0)
  5d7f0c:	00508021 	addu	s0,v0,s0
  5d7f10:	08175fad 	j	0x5d7eb4
  5d7f14:	a2110003 	sb	s1,3(s0)
