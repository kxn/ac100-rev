; func cw_priv_cwver_create @ 0x005aec18 size=0xdc
  5aec18:	27bdffd8 	addiu	sp,sp,-40
  5aec1c:	24050004 	li	a1,4
  5aec20:	afb0001c 	sw	s0,28(sp)
  5aec24:	afbf0024 	sw	ra,36(sp)
  5aec28:	0c15c8cc 	jal	0x572330
  5aec2c:	afb10020 	sw	s1,32(sp)
  5aec30:	1040000d 	beqz	v0,0x5aec68
  5aec34:	00408021 	move	s0,v0
  5aec38:	00002021 	move	a0,zero
  5aec3c:	24050004 	li	a1,4
  5aec40:	0c15c943 	jal	0x57250c
  5aec44:	00403021 	move	a2,v0
  5aec48:	10400017 	beqz	v0,0x5aeca8
  5aec4c:	00408821 	move	s1,v0
  5aec50:	8fbf0024 	lw	ra,36(sp)
  5aec54:	02201021 	move	v0,s1
  5aec58:	8fb10020 	lw	s1,32(sp)
  5aec5c:	8fb0001c 	lw	s0,28(sp)
  5aec60:	03e00008 	jr	ra
  5aec64:	27bd0028 	addiu	sp,sp,40
  5aec68:	3c020075 	lui	v0,0x75
  5aec6c:	8c42cf58 	lw	v0,-12456(v0)
  5aec70:	1040fff7 	beqz	v0,0x5aec50
  5aec74:	00008821 	move	s1,zero
  5aec78:	0c16276a 	jal	0x589da8
  5aec7c:	00000000 	nop
  5aec80:	5040fff4 	beqzl	v0,0x5aec54
  5aec84:	8fbf0024 	lw	ra,36(sp)
  5aec88:	3c04006d 	lui	a0,0x6d
  5aec8c:	3c05006f 	lui	a1,0x6f
  5aec90:	248434fc 	addiu	a0,a0,13564
  5aec94:	24a5a600 	addiu	a1,a1,-23040
  5aec98:	0c101b74 	jal	0x406dd0
  5aec9c:	240600a6 	li	a2,166
  5aeca0:	0816bb15 	j	0x5aec54
  5aeca4:	8fbf0024 	lw	ra,36(sp)
  5aeca8:	3c020075 	lui	v0,0x75
  5aecac:	8c42cf58 	lw	v0,-12456(v0)
  5aecb0:	14400005 	bnez	v0,0x5aecc8
  5aecb4:	00000000 	nop
  5aecb8:	0c101f7c 	jal	0x407df0
  5aecbc:	02002021 	move	a0,s0
  5aecc0:	0816bb15 	j	0x5aec54
  5aecc4:	8fbf0024 	lw	ra,36(sp)
  5aecc8:	0c16276a 	jal	0x589da8
  5aeccc:	00000000 	nop
  5aecd0:	1040fff9 	beqz	v0,0x5aecb8
  5aecd4:	3c04006d 	lui	a0,0x6d
  5aecd8:	3c05006f 	lui	a1,0x6f
  5aecdc:	248447f0 	addiu	a0,a0,18416
  5aece0:	24a5a600 	addiu	a1,a1,-23040
  5aece4:	0c101b74 	jal	0x406dd0
  5aece8:	240600ae 	li	a2,174
  5aecec:	0816bb2e 	j	0x5aecb8
  5aecf0:	00000000 	nop
