; func cw_maximum_message_length_create @ 0x00577eac size=0xdc
  577eac:	27bdffd8 	addiu	sp,sp,-40
  577eb0:	24050002 	li	a1,2
  577eb4:	afb0001c 	sw	s0,28(sp)
  577eb8:	afbf0024 	sw	ra,36(sp)
  577ebc:	0c15c8cc 	jal	0x572330
  577ec0:	afb10020 	sw	s1,32(sp)
  577ec4:	1040000d 	beqz	v0,0x577efc
  577ec8:	00408021 	move	s0,v0
  577ecc:	2404001d 	li	a0,29
  577ed0:	24050002 	li	a1,2
  577ed4:	0c15c943 	jal	0x57250c
  577ed8:	00403021 	move	a2,v0
  577edc:	10400017 	beqz	v0,0x577f3c
  577ee0:	00408821 	move	s1,v0
  577ee4:	8fbf0024 	lw	ra,36(sp)
  577ee8:	02201021 	move	v0,s1
  577eec:	8fb10020 	lw	s1,32(sp)
  577ef0:	8fb0001c 	lw	s0,28(sp)
  577ef4:	03e00008 	jr	ra
  577ef8:	27bd0028 	addiu	sp,sp,40
  577efc:	3c020075 	lui	v0,0x75
  577f00:	8c42cf58 	lw	v0,-12456(v0)
  577f04:	1040fff7 	beqz	v0,0x577ee4
  577f08:	00008821 	move	s1,zero
  577f0c:	0c16276a 	jal	0x589da8
  577f10:	00000000 	nop
  577f14:	5040fff4 	beqzl	v0,0x577ee8
  577f18:	8fbf0024 	lw	ra,36(sp)
  577f1c:	3c04006e 	lui	a0,0x6e
  577f20:	3c05006e 	lui	a1,0x6e
  577f24:	248485d4 	addiu	a0,a0,-31276
  577f28:	24a59400 	addiu	a1,a1,-27648
  577f2c:	0c101b74 	jal	0x406dd0
  577f30:	240600a3 	li	a2,163
  577f34:	0815dfba 	j	0x577ee8
  577f38:	8fbf0024 	lw	ra,36(sp)
  577f3c:	3c020075 	lui	v0,0x75
  577f40:	8c42cf58 	lw	v0,-12456(v0)
  577f44:	14400005 	bnez	v0,0x577f5c
  577f48:	00000000 	nop
  577f4c:	0c101f7c 	jal	0x407df0
  577f50:	02002021 	move	a0,s0
  577f54:	0815dfba 	j	0x577ee8
  577f58:	8fbf0024 	lw	ra,36(sp)
  577f5c:	0c16276a 	jal	0x589da8
  577f60:	00000000 	nop
  577f64:	1040fff9 	beqz	v0,0x577f4c
  577f68:	3c04006d 	lui	a0,0x6d
  577f6c:	3c05006e 	lui	a1,0x6e
  577f70:	248447f0 	addiu	a0,a0,18416
  577f74:	24a59400 	addiu	a1,a1,-27648
  577f78:	0c101b74 	jal	0x406dd0
  577f7c:	240600ab 	li	a2,171
  577f80:	0815dfd3 	j	0x577f4c
  577f84:	00000000 	nop
