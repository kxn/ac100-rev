; func cw_priv_ndp_para_create @ 0x005b7e4c size=0xe0
  5b7e4c:	27bdffd8 	addiu	sp,sp,-40
  5b7e50:	24050034 	li	a1,52
  5b7e54:	afb0001c 	sw	s0,28(sp)
  5b7e58:	afbf0024 	sw	ra,36(sp)
  5b7e5c:	0c15c8cc 	jal	0x572330
  5b7e60:	afb10020 	sw	s1,32(sp)
  5b7e64:	10400016 	beqz	v0,0x5b7ec0
  5b7e68:	00408021 	move	s0,v0
  5b7e6c:	90450013 	lbu	a1,19(v0)
  5b7e70:	2404005c 	li	a0,92
  5b7e74:	00403021 	move	a2,v0
  5b7e78:	0c15c943 	jal	0x57250c
  5b7e7c:	24a50014 	addiu	a1,a1,20
  5b7e80:	10400007 	beqz	v0,0x5b7ea0
  5b7e84:	00408821 	move	s1,v0
  5b7e88:	8fbf0024 	lw	ra,36(sp)
  5b7e8c:	02201021 	move	v0,s1
  5b7e90:	8fb10020 	lw	s1,32(sp)
  5b7e94:	8fb0001c 	lw	s0,28(sp)
  5b7e98:	03e00008 	jr	ra
  5b7e9c:	27bd0028 	addiu	sp,sp,40
  5b7ea0:	3c020075 	lui	v0,0x75
  5b7ea4:	8c42cf58 	lw	v0,-12456(v0)
  5b7ea8:	14400015 	bnez	v0,0x5b7f00
  5b7eac:	00000000 	nop
  5b7eb0:	0c101f7c 	jal	0x407df0
  5b7eb4:	02002021 	move	a0,s0
  5b7eb8:	0816dfa3 	j	0x5b7e8c
  5b7ebc:	8fbf0024 	lw	ra,36(sp)
  5b7ec0:	3c020075 	lui	v0,0x75
  5b7ec4:	8c42cf58 	lw	v0,-12456(v0)
  5b7ec8:	1040ffef 	beqz	v0,0x5b7e88
  5b7ecc:	00008821 	move	s1,zero
  5b7ed0:	0c16276a 	jal	0x589da8
  5b7ed4:	00000000 	nop
  5b7ed8:	5040ffec 	beqzl	v0,0x5b7e8c
  5b7edc:	8fbf0024 	lw	ra,36(sp)
  5b7ee0:	3c04006d 	lui	a0,0x6d
  5b7ee4:	3c05006f 	lui	a1,0x6f
  5b7ee8:	248434fc 	addiu	a0,a0,13564
  5b7eec:	24a5ccc0 	addiu	a1,a1,-13120
  5b7ef0:	0c101b74 	jal	0x406dd0
  5b7ef4:	240600ea 	li	a2,234
  5b7ef8:	0816dfa3 	j	0x5b7e8c
  5b7efc:	8fbf0024 	lw	ra,36(sp)
  5b7f00:	0c16276a 	jal	0x589da8
  5b7f04:	00000000 	nop
  5b7f08:	1040ffe9 	beqz	v0,0x5b7eb0
  5b7f0c:	3c04006d 	lui	a0,0x6d
  5b7f10:	3c05006f 	lui	a1,0x6f
  5b7f14:	248447f0 	addiu	a0,a0,18416
  5b7f18:	24a5ccc0 	addiu	a1,a1,-13120
  5b7f1c:	0c101b74 	jal	0x406dd0
  5b7f20:	240600f2 	li	a2,242
  5b7f24:	0816dfac 	j	0x5b7eb0
  5b7f28:	00000000 	nop
  5b7f2c:	00000000 	nop
