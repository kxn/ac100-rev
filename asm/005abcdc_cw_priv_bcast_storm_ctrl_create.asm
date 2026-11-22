; func cw_priv_bcast_storm_ctrl_create @ 0x005abcdc size=0xdc
  5abcdc:	27bdffd8 	addiu	sp,sp,-40
  5abce0:	24050008 	li	a1,8
  5abce4:	afb0001c 	sw	s0,28(sp)
  5abce8:	afbf0024 	sw	ra,36(sp)
  5abcec:	0c15c8cc 	jal	0x572330
  5abcf0:	afb10020 	sw	s1,32(sp)
  5abcf4:	1040000d 	beqz	v0,0x5abd2c
  5abcf8:	00408021 	move	s0,v0
  5abcfc:	24040046 	li	a0,70
  5abd00:	24050005 	li	a1,5
  5abd04:	0c15c943 	jal	0x57250c
  5abd08:	00403021 	move	a2,v0
  5abd0c:	10400017 	beqz	v0,0x5abd6c
  5abd10:	00408821 	move	s1,v0
  5abd14:	8fbf0024 	lw	ra,36(sp)
  5abd18:	02201021 	move	v0,s1
  5abd1c:	8fb10020 	lw	s1,32(sp)
  5abd20:	8fb0001c 	lw	s0,28(sp)
  5abd24:	03e00008 	jr	ra
  5abd28:	27bd0028 	addiu	sp,sp,40
  5abd2c:	3c020075 	lui	v0,0x75
  5abd30:	8c42cf58 	lw	v0,-12456(v0)
  5abd34:	1040fff7 	beqz	v0,0x5abd14
  5abd38:	00008821 	move	s1,zero
  5abd3c:	0c16276a 	jal	0x589da8
  5abd40:	00000000 	nop
  5abd44:	5040fff4 	beqzl	v0,0x5abd18
  5abd48:	8fbf0024 	lw	ra,36(sp)
  5abd4c:	3c04006d 	lui	a0,0x6d
  5abd50:	3c05006f 	lui	a1,0x6f
  5abd54:	248434fc 	addiu	a0,a0,13564
  5abd58:	24a59a10 	addiu	a1,a1,-26096
  5abd5c:	0c101b74 	jal	0x406dd0
  5abd60:	240600a4 	li	a2,164
  5abd64:	0816af46 	j	0x5abd18
  5abd68:	8fbf0024 	lw	ra,36(sp)
  5abd6c:	3c020075 	lui	v0,0x75
  5abd70:	8c42cf58 	lw	v0,-12456(v0)
  5abd74:	14400005 	bnez	v0,0x5abd8c
  5abd78:	00000000 	nop
  5abd7c:	0c101f7c 	jal	0x407df0
  5abd80:	02002021 	move	a0,s0
  5abd84:	0816af46 	j	0x5abd18
  5abd88:	8fbf0024 	lw	ra,36(sp)
  5abd8c:	0c16276a 	jal	0x589da8
  5abd90:	00000000 	nop
  5abd94:	1040fff9 	beqz	v0,0x5abd7c
  5abd98:	3c04006d 	lui	a0,0x6d
  5abd9c:	3c05006f 	lui	a1,0x6f
  5abda0:	24843580 	addiu	a0,a0,13696
  5abda4:	24a59a10 	addiu	a1,a1,-26096
  5abda8:	0c101b74 	jal	0x406dd0
  5abdac:	240600ac 	li	a2,172
  5abdb0:	0816af5f 	j	0x5abd7c
  5abdb4:	00000000 	nop
