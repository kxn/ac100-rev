; func cw_packet_queue_is_empty @ 0x0059bbdc size=0x90
  59bbdc:	27bdffd8 	addiu	sp,sp,-40
  59bbe0:	afb0001c 	sw	s0,28(sp)
  59bbe4:	00808021 	move	s0,a0
  59bbe8:	afbf0024 	sw	ra,36(sp)
  59bbec:	1080000f 	beqz	a0,0x59bc2c
  59bbf0:	afb10020 	sw	s1,32(sp)
  59bbf4:	8c840000 	lw	a0,0(a0)
  59bbf8:	0c1020b4 	jal	0x4082d0
  59bbfc:	2405ffff 	li	a1,-1
  59bc00:	8e02000c 	lw	v0,12(s0)
  59bc04:	8e040000 	lw	a0,0(s0)
  59bc08:	8c510008 	lw	s1,8(v0)
  59bc0c:	0c101fcc 	jal	0x407f30
  59bc10:	2e310001 	sltiu	s1,s1,1
  59bc14:	8fbf0024 	lw	ra,36(sp)
  59bc18:	02201021 	move	v0,s1
  59bc1c:	8fb10020 	lw	s1,32(sp)
  59bc20:	8fb0001c 	lw	s0,28(sp)
  59bc24:	03e00008 	jr	ra
  59bc28:	27bd0028 	addiu	sp,sp,40
  59bc2c:	3c020075 	lui	v0,0x75
  59bc30:	8c42cf58 	lw	v0,-12456(v0)
  59bc34:	1040fff7 	beqz	v0,0x59bc14
  59bc38:	00008821 	move	s1,zero
  59bc3c:	0c16276a 	jal	0x589da8
  59bc40:	00000000 	nop
  59bc44:	1040fff4 	beqz	v0,0x59bc18
  59bc48:	8fbf0024 	lw	ra,36(sp)
  59bc4c:	3c04006e 	lui	a0,0x6e
  59bc50:	3c05006e 	lui	a1,0x6e
  59bc54:	24843dc4 	addiu	a0,a0,15812
  59bc58:	24a54010 	addiu	a1,a1,16400
  59bc5c:	0c101b74 	jal	0x406dd0
  59bc60:	24060195 	li	a2,405
  59bc64:	08166f05 	j	0x59bc14
  59bc68:	00000000 	nop
