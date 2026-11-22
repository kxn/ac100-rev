; func cw_priv_bluetooth_config_create @ 0x005ac044 size=0xdc
  5ac044:	27bdffd8 	addiu	sp,sp,-40
  5ac048:	2405000c 	li	a1,12
  5ac04c:	afb0001c 	sw	s0,28(sp)
  5ac050:	afbf0024 	sw	ra,36(sp)
  5ac054:	0c15c8cc 	jal	0x572330
  5ac058:	afb10020 	sw	s1,32(sp)
  5ac05c:	1040000d 	beqz	v0,0x5ac094
  5ac060:	00408021 	move	s0,v0
  5ac064:	240400a7 	li	a0,167
  5ac068:	24050009 	li	a1,9
  5ac06c:	0c15c943 	jal	0x57250c
  5ac070:	00403021 	move	a2,v0
  5ac074:	10400017 	beqz	v0,0x5ac0d4
  5ac078:	00408821 	move	s1,v0
  5ac07c:	8fbf0024 	lw	ra,36(sp)
  5ac080:	02201021 	move	v0,s1
  5ac084:	8fb10020 	lw	s1,32(sp)
  5ac088:	8fb0001c 	lw	s0,28(sp)
  5ac08c:	03e00008 	jr	ra
  5ac090:	27bd0028 	addiu	sp,sp,40
  5ac094:	3c020075 	lui	v0,0x75
  5ac098:	8c42cf58 	lw	v0,-12456(v0)
  5ac09c:	1040fff7 	beqz	v0,0x5ac07c
  5ac0a0:	00008821 	move	s1,zero
  5ac0a4:	0c16276a 	jal	0x589da8
  5ac0a8:	00000000 	nop
  5ac0ac:	5040fff4 	beqzl	v0,0x5ac080
  5ac0b0:	8fbf0024 	lw	ra,36(sp)
  5ac0b4:	3c04006d 	lui	a0,0x6d
  5ac0b8:	3c05006f 	lui	a1,0x6f
  5ac0bc:	248434fc 	addiu	a0,a0,13564
  5ac0c0:	24a59b20 	addiu	a1,a1,-25824
  5ac0c4:	0c101b74 	jal	0x406dd0
  5ac0c8:	240600a1 	li	a2,161
  5ac0cc:	0816b020 	j	0x5ac080
  5ac0d0:	8fbf0024 	lw	ra,36(sp)
  5ac0d4:	3c020075 	lui	v0,0x75
  5ac0d8:	8c42cf58 	lw	v0,-12456(v0)
  5ac0dc:	14400005 	bnez	v0,0x5ac0f4
  5ac0e0:	00000000 	nop
  5ac0e4:	0c101f7c 	jal	0x407df0
  5ac0e8:	02002021 	move	a0,s0
  5ac0ec:	0816b020 	j	0x5ac080
  5ac0f0:	8fbf0024 	lw	ra,36(sp)
  5ac0f4:	0c16276a 	jal	0x589da8
  5ac0f8:	00000000 	nop
  5ac0fc:	1040fff9 	beqz	v0,0x5ac0e4
  5ac100:	3c04006d 	lui	a0,0x6d
  5ac104:	3c05006f 	lui	a1,0x6f
  5ac108:	24843580 	addiu	a0,a0,13696
  5ac10c:	24a59b20 	addiu	a1,a1,-25824
  5ac110:	0c101b74 	jal	0x406dd0
  5ac114:	240600a9 	li	a2,169
  5ac118:	0816b039 	j	0x5ac0e4
  5ac11c:	00000000 	nop
