; func uac_wserv_packet_dump_all @ 0x005dae48 size=0x78
  5dae48:	27bdffd8 	addiu	sp,sp,-40
  5dae4c:	2405ffff 	li	a1,-1
  5dae50:	afb10020 	sw	s1,32(sp)
  5dae54:	3c110076 	lui	s1,0x76
  5dae58:	afbf0024 	sw	ra,36(sp)
  5dae5c:	afb0001c 	sw	s0,28(sp)
  5dae60:	00008021 	move	s0,zero
  5dae64:	0c1020b4 	jal	0x4082d0
  5dae68:	8e2498e4 	lw	a0,-26396(s1)
  5dae6c:	3c04006f 	lui	a0,0x6f
  5dae70:	0c101dd4 	jal	0x407750
  5dae74:	248447a4 	addiu	a0,a0,18340
  5dae78:	08176ba2 	j	0x5dae88
  5dae7c:	00000000 	nop
  5dae80:	0c176afe 	jal	0x5dabf8
  5dae84:	26100001 	addiu	s0,s0,1
  5dae88:	0c1506a9 	jal	0x541aa4
  5dae8c:	00000000 	nop
  5dae90:	0202102a 	slt	v0,s0,v0
  5dae94:	5440fffa 	bnezl	v0,0x5dae80
  5dae98:	02002021 	move	a0,s0
  5dae9c:	3c04006f 	lui	a0,0x6f
  5daea0:	0c101dd4 	jal	0x407750
  5daea4:	248447d0 	addiu	a0,a0,18384
  5daea8:	8e2498e4 	lw	a0,-26396(s1)
  5daeac:	8fbf0024 	lw	ra,36(sp)
  5daeb0:	8fb10020 	lw	s1,32(sp)
  5daeb4:	8fb0001c 	lw	s0,28(sp)
  5daeb8:	08101fcc 	j	0x407f30
  5daebc:	27bd0028 	addiu	sp,sp,40
