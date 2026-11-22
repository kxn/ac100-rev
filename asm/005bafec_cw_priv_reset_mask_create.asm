; func cw_priv_reset_mask_create @ 0x005bafec size=0xdc
  5bafec:	27bdffd8 	addiu	sp,sp,-40
  5baff0:	24050004 	li	a1,4
  5baff4:	afb0001c 	sw	s0,28(sp)
  5baff8:	afbf0024 	sw	ra,36(sp)
  5baffc:	0c15c8cc 	jal	0x572330
  5bb000:	afb10020 	sw	s1,32(sp)
  5bb004:	1040000d 	beqz	v0,0x5bb03c
  5bb008:	00408021 	move	s0,v0
  5bb00c:	24040023 	li	a0,35
  5bb010:	24050004 	li	a1,4
  5bb014:	0c15c943 	jal	0x57250c
  5bb018:	00403021 	move	a2,v0
  5bb01c:	10400017 	beqz	v0,0x5bb07c
  5bb020:	00408821 	move	s1,v0
  5bb024:	8fbf0024 	lw	ra,36(sp)
  5bb028:	02201021 	move	v0,s1
  5bb02c:	8fb10020 	lw	s1,32(sp)
  5bb030:	8fb0001c 	lw	s0,28(sp)
  5bb034:	03e00008 	jr	ra
  5bb038:	27bd0028 	addiu	sp,sp,40
  5bb03c:	3c020075 	lui	v0,0x75
  5bb040:	8c42cf58 	lw	v0,-12456(v0)
  5bb044:	1040fff7 	beqz	v0,0x5bb024
  5bb048:	00008821 	move	s1,zero
  5bb04c:	0c16276a 	jal	0x589da8
  5bb050:	00000000 	nop
  5bb054:	5040fff4 	beqzl	v0,0x5bb028
  5bb058:	8fbf0024 	lw	ra,36(sp)
  5bb05c:	3c04006d 	lui	a0,0x6d
  5bb060:	3c05006f 	lui	a1,0x6f
  5bb064:	248434fc 	addiu	a0,a0,13564
  5bb068:	24a5d970 	addiu	a1,a1,-9872
  5bb06c:	0c101b74 	jal	0x406dd0
  5bb070:	240600a2 	li	a2,162
  5bb074:	0816ec0a 	j	0x5bb028
  5bb078:	8fbf0024 	lw	ra,36(sp)
  5bb07c:	3c020075 	lui	v0,0x75
  5bb080:	8c42cf58 	lw	v0,-12456(v0)
  5bb084:	14400005 	bnez	v0,0x5bb09c
  5bb088:	00000000 	nop
  5bb08c:	0c101f7c 	jal	0x407df0
  5bb090:	02002021 	move	a0,s0
  5bb094:	0816ec0a 	j	0x5bb028
  5bb098:	8fbf0024 	lw	ra,36(sp)
  5bb09c:	0c16276a 	jal	0x589da8
  5bb0a0:	00000000 	nop
  5bb0a4:	1040fff9 	beqz	v0,0x5bb08c
  5bb0a8:	3c04006d 	lui	a0,0x6d
  5bb0ac:	3c05006f 	lui	a1,0x6f
  5bb0b0:	248447f0 	addiu	a0,a0,18416
  5bb0b4:	24a5d970 	addiu	a1,a1,-9872
  5bb0b8:	0c101b74 	jal	0x406dd0
  5bb0bc:	240600aa 	li	a2,170
  5bb0c0:	0816ec23 	j	0x5bb08c
  5bb0c4:	00000000 	nop
