; func _uac_wserv_packet_waiting_status_get_by_ap_id @ 0x005d7dc0 size=0xb4
  5d7dc0:	27bdffd8 	addiu	sp,sp,-40
  5d7dc4:	afb10020 	sw	s1,32(sp)
  5d7dc8:	00a08821 	move	s1,a1
  5d7dcc:	afb0001c 	sw	s0,28(sp)
  5d7dd0:	00808021 	move	s0,a0
  5d7dd4:	04800006 	bltz	a0,0x5d7df0
  5d7dd8:	afbf0024 	sw	ra,36(sp)
  5d7ddc:	0c1506a9 	jal	0x541aa4
  5d7de0:	00000000 	nop
  5d7de4:	0202102a 	slt	v0,s0,v0
  5d7de8:	1440000f 	bnez	v0,0x5d7e28
  5d7dec:	00000000 	nop
  5d7df0:	3c02007d 	lui	v0,0x7d
  5d7df4:	8c42bee4 	lw	v0,-16668(v0)
  5d7df8:	10400005 	beqz	v0,0x5d7e10
  5d7dfc:	2411ffff 	li	s1,-1
  5d7e00:	0c16276a 	jal	0x589da8
  5d7e04:	00000000 	nop
  5d7e08:	14400012 	bnez	v0,0x5d7e54
  5d7e0c:	3c04006f 	lui	a0,0x6f
  5d7e10:	8fbf0024 	lw	ra,36(sp)
  5d7e14:	02201021 	move	v0,s1
  5d7e18:	8fb10020 	lw	s1,32(sp)
  5d7e1c:	8fb0001c 	lw	s0,28(sp)
  5d7e20:	03e00008 	jr	ra
  5d7e24:	27bd0028 	addiu	sp,sp,40
  5d7e28:	1220fff2 	beqz	s1,0x5d7df4
  5d7e2c:	3c02007d 	lui	v0,0x7d
  5d7e30:	2403000c 	li	v1,12
  5d7e34:	3c020076 	lui	v0,0x76
  5d7e38:	72038002 	mul	s0,s0,v1
  5d7e3c:	8c4298e8 	lw	v0,-26392(v0)
  5d7e40:	00508021 	addu	s0,v0,s0
  5d7e44:	92020002 	lbu	v0,2(s0)
  5d7e48:	a2220000 	sb	v0,0(s1)
  5d7e4c:	08175f84 	j	0x5d7e10
  5d7e50:	00008821 	move	s1,zero
  5d7e54:	3c05006f 	lui	a1,0x6f
  5d7e58:	24843cac 	addiu	a0,a0,15532
  5d7e5c:	24a56adc 	addiu	a1,a1,27356
  5d7e60:	240600d4 	li	a2,212
  5d7e64:	0c101b74 	jal	0x406dd0
  5d7e68:	02003821 	move	a3,s0
  5d7e6c:	08175f85 	j	0x5d7e14
  5d7e70:	8fbf0024 	lw	ra,36(sp)
