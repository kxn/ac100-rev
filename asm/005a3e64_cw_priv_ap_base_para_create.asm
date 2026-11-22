; func cw_priv_ap_base_para_create @ 0x005a3e64 size=0xdc
  5a3e64:	27bdffd8 	addiu	sp,sp,-40
  5a3e68:	24050008 	li	a1,8
  5a3e6c:	afb0001c 	sw	s0,28(sp)
  5a3e70:	afbf0024 	sw	ra,36(sp)
  5a3e74:	0c15c8cc 	jal	0x572330
  5a3e78:	afb10020 	sw	s1,32(sp)
  5a3e7c:	1040000d 	beqz	v0,0x5a3eb4
  5a3e80:	00408021 	move	s0,v0
  5a3e84:	24040005 	li	a0,5
  5a3e88:	24050008 	li	a1,8
  5a3e8c:	0c15c943 	jal	0x57250c
  5a3e90:	00403021 	move	a2,v0
  5a3e94:	10400017 	beqz	v0,0x5a3ef4
  5a3e98:	00408821 	move	s1,v0
  5a3e9c:	8fbf0024 	lw	ra,36(sp)
  5a3ea0:	02201021 	move	v0,s1
  5a3ea4:	8fb10020 	lw	s1,32(sp)
  5a3ea8:	8fb0001c 	lw	s0,28(sp)
  5a3eac:	03e00008 	jr	ra
  5a3eb0:	27bd0028 	addiu	sp,sp,40
  5a3eb4:	3c020075 	lui	v0,0x75
  5a3eb8:	8c42cf58 	lw	v0,-12456(v0)
  5a3ebc:	1040fff7 	beqz	v0,0x5a3e9c
  5a3ec0:	00008821 	move	s1,zero
  5a3ec4:	0c16276a 	jal	0x589da8
  5a3ec8:	00000000 	nop
  5a3ecc:	5040fff4 	beqzl	v0,0x5a3ea0
  5a3ed0:	8fbf0024 	lw	ra,36(sp)
  5a3ed4:	3c04006d 	lui	a0,0x6d
  5a3ed8:	3c05006e 	lui	a1,0x6e
  5a3edc:	248434fc 	addiu	a0,a0,13564
  5a3ee0:	24a57350 	addiu	a1,a1,29520
  5a3ee4:	0c101b74 	jal	0x406dd0
  5a3ee8:	240600a6 	li	a2,166
  5a3eec:	08168fa8 	j	0x5a3ea0
  5a3ef0:	8fbf0024 	lw	ra,36(sp)
  5a3ef4:	3c020075 	lui	v0,0x75
  5a3ef8:	8c42cf58 	lw	v0,-12456(v0)
  5a3efc:	14400005 	bnez	v0,0x5a3f14
  5a3f00:	00000000 	nop
  5a3f04:	0c101f7c 	jal	0x407df0
  5a3f08:	02002021 	move	a0,s0
  5a3f0c:	08168fa8 	j	0x5a3ea0
  5a3f10:	8fbf0024 	lw	ra,36(sp)
  5a3f14:	0c16276a 	jal	0x589da8
  5a3f18:	00000000 	nop
  5a3f1c:	1040fff9 	beqz	v0,0x5a3f04
  5a3f20:	3c04006d 	lui	a0,0x6d
  5a3f24:	3c05006e 	lui	a1,0x6e
  5a3f28:	248447f0 	addiu	a0,a0,18416
  5a3f2c:	24a57350 	addiu	a1,a1,29520
  5a3f30:	0c101b74 	jal	0x406dd0
  5a3f34:	240600ae 	li	a2,174
  5a3f38:	08168fc1 	j	0x5a3f04
  5a3f3c:	00000000 	nop
