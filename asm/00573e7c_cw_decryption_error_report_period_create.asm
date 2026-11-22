; func cw_decryption_error_report_period_create @ 0x00573e7c size=0xdc
  573e7c:	27bdffd8 	addiu	sp,sp,-40
  573e80:	24050004 	li	a1,4
  573e84:	afb0001c 	sw	s0,28(sp)
  573e88:	afbf0024 	sw	ra,36(sp)
  573e8c:	0c15c8cc 	jal	0x572330
  573e90:	afb10020 	sw	s1,32(sp)
  573e94:	1040000d 	beqz	v0,0x573ecc
  573e98:	00408021 	move	s0,v0
  573e9c:	24040010 	li	a0,16
  573ea0:	24050003 	li	a1,3
  573ea4:	0c15c943 	jal	0x57250c
  573ea8:	00403021 	move	a2,v0
  573eac:	10400017 	beqz	v0,0x573f0c
  573eb0:	00408821 	move	s1,v0
  573eb4:	8fbf0024 	lw	ra,36(sp)
  573eb8:	02201021 	move	v0,s1
  573ebc:	8fb10020 	lw	s1,32(sp)
  573ec0:	8fb0001c 	lw	s0,28(sp)
  573ec4:	03e00008 	jr	ra
  573ec8:	27bd0028 	addiu	sp,sp,40
  573ecc:	3c020075 	lui	v0,0x75
  573ed0:	8c42cf58 	lw	v0,-12456(v0)
  573ed4:	1040fff7 	beqz	v0,0x573eb4
  573ed8:	00008821 	move	s1,zero
  573edc:	0c16276a 	jal	0x589da8
  573ee0:	00000000 	nop
  573ee4:	5040fff4 	beqzl	v0,0x573eb8
  573ee8:	8fbf0024 	lw	ra,36(sp)
  573eec:	3c04006d 	lui	a0,0x6d
  573ef0:	3c05006e 	lui	a1,0x6e
  573ef4:	24847098 	addiu	a0,a0,28824
  573ef8:	24a58500 	addiu	a1,a1,-31488
  573efc:	0c101b74 	jal	0x406dd0
  573f00:	240600aa 	li	a2,170
  573f04:	0815cfae 	j	0x573eb8
  573f08:	8fbf0024 	lw	ra,36(sp)
  573f0c:	3c020075 	lui	v0,0x75
  573f10:	8c42cf58 	lw	v0,-12456(v0)
  573f14:	14400005 	bnez	v0,0x573f2c
  573f18:	00000000 	nop
  573f1c:	0c101f7c 	jal	0x407df0
  573f20:	02002021 	move	a0,s0
  573f24:	0815cfae 	j	0x573eb8
  573f28:	8fbf0024 	lw	ra,36(sp)
  573f2c:	0c16276a 	jal	0x589da8
  573f30:	00000000 	nop
  573f34:	1040fff9 	beqz	v0,0x573f1c
  573f38:	3c04006d 	lui	a0,0x6d
  573f3c:	3c05006e 	lui	a1,0x6e
  573f40:	248447f0 	addiu	a0,a0,18416
  573f44:	24a58500 	addiu	a1,a1,-31488
  573f48:	0c101b74 	jal	0x406dd0
  573f4c:	240600b2 	li	a2,178
  573f50:	0815cfc7 	j	0x573f1c
  573f54:	00000000 	nop
	...
