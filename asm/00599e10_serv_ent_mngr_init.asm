; func serv_ent_mngr_init @ 0x00599e10 size=0xdc
  599e10:	27bdffd8 	addiu	sp,sp,-40
  599e14:	afb00018 	sw	s0,24(sp)
  599e18:	3c10007c 	lui	s0,0x7c
  599e1c:	afb20020 	sw	s2,32(sp)
  599e20:	24120004 	li	s2,4
  599e24:	afb1001c 	sw	s1,28(sp)
  599e28:	261059c0 	addiu	s0,s0,22976
  599e2c:	00008821 	move	s1,zero
  599e30:	afbf0024 	sw	ra,36(sp)
  599e34:	8e020000 	lw	v0,0(s0)
  599e38:	50400015 	beqzl	v0,0x599e90
  599e3c:	24040010 	li	a0,16
  599e40:	8e040000 	lw	a0,0(s0)
  599e44:	00002821 	move	a1,zero
  599e48:	0c101cf0 	jal	0x4073c0
  599e4c:	24060010 	li	a2,16
  599e50:	8e020000 	lw	v0,0(s0)
  599e54:	a4510000 	sh	s1,0(v0)
  599e58:	26310001 	addiu	s1,s1,1
  599e5c:	8e040000 	lw	a0,0(s0)
  599e60:	26100004 	addiu	s0,s0,4
  599e64:	0c146b62 	jal	0x51ad88
  599e68:	24840004 	addiu	a0,a0,4
  599e6c:	5632fff2 	bnel	s1,s2,0x599e38
  599e70:	8e020000 	lw	v0,0(s0)
  599e74:	00001021 	move	v0,zero
  599e78:	8fbf0024 	lw	ra,36(sp)
  599e7c:	8fb20020 	lw	s2,32(sp)
  599e80:	8fb1001c 	lw	s1,28(sp)
  599e84:	8fb00018 	lw	s0,24(sp)
  599e88:	03e00008 	jr	ra
  599e8c:	27bd0028 	addiu	sp,sp,40
  599e90:	0c102114 	jal	0x408450
  599e94:	24050322 	li	a1,802
  599e98:	1440ffe9 	bnez	v0,0x599e40
  599e9c:	ae020000 	sw	v0,0(s0)
  599ea0:	3c020075 	lui	v0,0x75
  599ea4:	8c42cf58 	lw	v0,-12456(v0)
  599ea8:	14400005 	bnez	v0,0x599ec0
  599eac:	00000000 	nop
  599eb0:	0c166761 	jal	0x599d84
  599eb4:	00000000 	nop
  599eb8:	0816679e 	j	0x599e78
  599ebc:	2402ffff 	li	v0,-1
  599ec0:	0c16276a 	jal	0x589da8
  599ec4:	00000000 	nop
  599ec8:	1040fff9 	beqz	v0,0x599eb0
  599ecc:	3c05006e 	lui	a1,0x6e
  599ed0:	3c04006e 	lui	a0,0x6e
  599ed4:	248439b0 	addiu	a0,a0,14768
  599ed8:	24a53c40 	addiu	a1,a1,15424
  599edc:	0c101b74 	jal	0x406dd0
  599ee0:	24060325 	li	a2,805
  599ee4:	081667ac 	j	0x599eb0
  599ee8:	00000000 	nop
