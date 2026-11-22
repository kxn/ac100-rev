; func cw_capwap_local_ipv4_address_create @ 0x00570ea0 size=0xdc
  570ea0:	27bdffd8 	addiu	sp,sp,-40
  570ea4:	24050004 	li	a1,4
  570ea8:	afb0001c 	sw	s0,28(sp)
  570eac:	afbf0024 	sw	ra,36(sp)
  570eb0:	0c15c8cc 	jal	0x572330
  570eb4:	afb10020 	sw	s1,32(sp)
  570eb8:	1040000d 	beqz	v0,0x570ef0
  570ebc:	00408021 	move	s0,v0
  570ec0:	2404001e 	li	a0,30
  570ec4:	24050004 	li	a1,4
  570ec8:	0c15c943 	jal	0x57250c
  570ecc:	00403021 	move	a2,v0
  570ed0:	10400017 	beqz	v0,0x570f30
  570ed4:	00408821 	move	s1,v0
  570ed8:	8fbf0024 	lw	ra,36(sp)
  570edc:	02201021 	move	v0,s1
  570ee0:	8fb10020 	lw	s1,32(sp)
  570ee4:	8fb0001c 	lw	s0,28(sp)
  570ee8:	03e00008 	jr	ra
  570eec:	27bd0028 	addiu	sp,sp,40
  570ef0:	3c020075 	lui	v0,0x75
  570ef4:	8c42cf58 	lw	v0,-12456(v0)
  570ef8:	1040fff7 	beqz	v0,0x570ed8
  570efc:	00008821 	move	s1,zero
  570f00:	0c16276a 	jal	0x589da8
  570f04:	00000000 	nop
  570f08:	5040fff4 	beqzl	v0,0x570edc
  570f0c:	8fbf0024 	lw	ra,36(sp)
  570f10:	3c04006d 	lui	a0,0x6d
  570f14:	3c05006d 	lui	a1,0x6d
  570f18:	248434fc 	addiu	a0,a0,13564
  570f1c:	24a57a90 	addiu	a1,a1,31376
  570f20:	0c101b74 	jal	0x406dd0
  570f24:	24060099 	li	a2,153
  570f28:	0815c3b7 	j	0x570edc
  570f2c:	8fbf0024 	lw	ra,36(sp)
  570f30:	3c020075 	lui	v0,0x75
  570f34:	8c42cf58 	lw	v0,-12456(v0)
  570f38:	14400005 	bnez	v0,0x570f50
  570f3c:	00000000 	nop
  570f40:	0c101f7c 	jal	0x407df0
  570f44:	02002021 	move	a0,s0
  570f48:	0815c3b7 	j	0x570edc
  570f4c:	8fbf0024 	lw	ra,36(sp)
  570f50:	0c16276a 	jal	0x589da8
  570f54:	00000000 	nop
  570f58:	1040fff9 	beqz	v0,0x570f40
  570f5c:	3c04006d 	lui	a0,0x6d
  570f60:	3c05006d 	lui	a1,0x6d
  570f64:	248447f0 	addiu	a0,a0,18416
  570f68:	24a57a90 	addiu	a1,a1,31376
  570f6c:	0c101b74 	jal	0x406dd0
  570f70:	240600a1 	li	a2,161
  570f74:	0815c3d0 	j	0x570f40
  570f78:	00000000 	nop
