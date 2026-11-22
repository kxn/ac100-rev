; func cw_priv_image_update_result_create @ 0x005b3e70 size=0xdc
  5b3e70:	27bdffd8 	addiu	sp,sp,-40
  5b3e74:	24050004 	li	a1,4
  5b3e78:	afb0001c 	sw	s0,28(sp)
  5b3e7c:	afbf0024 	sw	ra,36(sp)
  5b3e80:	0c15c8cc 	jal	0x572330
  5b3e84:	afb10020 	sw	s1,32(sp)
  5b3e88:	1040000d 	beqz	v0,0x5b3ec0
  5b3e8c:	00408021 	move	s0,v0
  5b3e90:	2404001c 	li	a0,28
  5b3e94:	24050004 	li	a1,4
  5b3e98:	0c15c943 	jal	0x57250c
  5b3e9c:	00403021 	move	a2,v0
  5b3ea0:	10400017 	beqz	v0,0x5b3f00
  5b3ea4:	00408821 	move	s1,v0
  5b3ea8:	8fbf0024 	lw	ra,36(sp)
  5b3eac:	02201021 	move	v0,s1
  5b3eb0:	8fb10020 	lw	s1,32(sp)
  5b3eb4:	8fb0001c 	lw	s0,28(sp)
  5b3eb8:	03e00008 	jr	ra
  5b3ebc:	27bd0028 	addiu	sp,sp,40
  5b3ec0:	3c020075 	lui	v0,0x75
  5b3ec4:	8c42cf58 	lw	v0,-12456(v0)
  5b3ec8:	1040fff7 	beqz	v0,0x5b3ea8
  5b3ecc:	00008821 	move	s1,zero
  5b3ed0:	0c16276a 	jal	0x589da8
  5b3ed4:	00000000 	nop
  5b3ed8:	5040fff4 	beqzl	v0,0x5b3eac
  5b3edc:	8fbf0024 	lw	ra,36(sp)
  5b3ee0:	3c04006d 	lui	a0,0x6d
  5b3ee4:	3c05006f 	lui	a1,0x6f
  5b3ee8:	248434fc 	addiu	a0,a0,13564
  5b3eec:	24a5bcd0 	addiu	a1,a1,-17200
  5b3ef0:	0c101b74 	jal	0x406dd0
  5b3ef4:	240600a3 	li	a2,163
  5b3ef8:	0816cfab 	j	0x5b3eac
  5b3efc:	8fbf0024 	lw	ra,36(sp)
  5b3f00:	3c020075 	lui	v0,0x75
  5b3f04:	8c42cf58 	lw	v0,-12456(v0)
  5b3f08:	14400005 	bnez	v0,0x5b3f20
  5b3f0c:	00000000 	nop
  5b3f10:	0c101f7c 	jal	0x407df0
  5b3f14:	02002021 	move	a0,s0
  5b3f18:	0816cfab 	j	0x5b3eac
  5b3f1c:	8fbf0024 	lw	ra,36(sp)
  5b3f20:	0c16276a 	jal	0x589da8
  5b3f24:	00000000 	nop
  5b3f28:	1040fff9 	beqz	v0,0x5b3f10
  5b3f2c:	3c04006d 	lui	a0,0x6d
  5b3f30:	3c05006f 	lui	a1,0x6f
  5b3f34:	248447f0 	addiu	a0,a0,18416
  5b3f38:	24a5bcd0 	addiu	a1,a1,-17200
  5b3f3c:	0c101b74 	jal	0x406dd0
  5b3f40:	240600ab 	li	a2,171
  5b3f44:	0816cfc4 	j	0x5b3f10
  5b3f48:	00000000 	nop
