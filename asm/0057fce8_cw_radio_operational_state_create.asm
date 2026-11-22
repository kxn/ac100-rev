; func cw_radio_operational_state_create @ 0x0057fce8 size=0xdc
  57fce8:	27bdffd8 	addiu	sp,sp,-40
  57fcec:	24050003 	li	a1,3
  57fcf0:	afb0001c 	sw	s0,28(sp)
  57fcf4:	afbf0024 	sw	ra,36(sp)
  57fcf8:	0c15c8cc 	jal	0x572330
  57fcfc:	afb10020 	sw	s1,32(sp)
  57fd00:	1040000d 	beqz	v0,0x57fd38
  57fd04:	00408021 	move	s0,v0
  57fd08:	24040020 	li	a0,32
  57fd0c:	24050003 	li	a1,3
  57fd10:	0c15c943 	jal	0x57250c
  57fd14:	00403021 	move	a2,v0
  57fd18:	10400017 	beqz	v0,0x57fd78
  57fd1c:	00408821 	move	s1,v0
  57fd20:	8fbf0024 	lw	ra,36(sp)
  57fd24:	02201021 	move	v0,s1
  57fd28:	8fb10020 	lw	s1,32(sp)
  57fd2c:	8fb0001c 	lw	s0,28(sp)
  57fd30:	03e00008 	jr	ra
  57fd34:	27bd0028 	addiu	sp,sp,40
  57fd38:	3c020075 	lui	v0,0x75
  57fd3c:	8c42cf58 	lw	v0,-12456(v0)
  57fd40:	1040fff7 	beqz	v0,0x57fd20
  57fd44:	00008821 	move	s1,zero
  57fd48:	0c16276a 	jal	0x589da8
  57fd4c:	00000000 	nop
  57fd50:	5040fff4 	beqzl	v0,0x57fd24
  57fd54:	8fbf0024 	lw	ra,36(sp)
  57fd58:	3c04006d 	lui	a0,0x6d
  57fd5c:	3c05006e 	lui	a1,0x6e
  57fd60:	248434fc 	addiu	a0,a0,13564
  57fd64:	24a5b310 	addiu	a1,a1,-19696
  57fd68:	0c101b74 	jal	0x406dd0
  57fd6c:	240600d2 	li	a2,210
  57fd70:	0815ff49 	j	0x57fd24
  57fd74:	8fbf0024 	lw	ra,36(sp)
  57fd78:	3c020075 	lui	v0,0x75
  57fd7c:	8c42cf58 	lw	v0,-12456(v0)
  57fd80:	14400005 	bnez	v0,0x57fd98
  57fd84:	00000000 	nop
  57fd88:	0c101f7c 	jal	0x407df0
  57fd8c:	02002021 	move	a0,s0
  57fd90:	0815ff49 	j	0x57fd24
  57fd94:	8fbf0024 	lw	ra,36(sp)
  57fd98:	0c16276a 	jal	0x589da8
  57fd9c:	00000000 	nop
  57fda0:	1040fff9 	beqz	v0,0x57fd88
  57fda4:	3c04006e 	lui	a0,0x6e
  57fda8:	3c05006e 	lui	a1,0x6e
  57fdac:	2484b2c0 	addiu	a0,a0,-19776
  57fdb0:	24a5b310 	addiu	a1,a1,-19696
  57fdb4:	0c101b74 	jal	0x406dd0
  57fdb8:	240600da 	li	a2,218
  57fdbc:	0815ff62 	j	0x57fd88
  57fdc0:	00000000 	nop
	...
