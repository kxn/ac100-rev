; func cw_priv_ap_led_mode_ctrl_create @ 0x005a502c size=0xdc
  5a502c:	27bdffd8 	addiu	sp,sp,-40
  5a5030:	24050004 	li	a1,4
  5a5034:	afb0001c 	sw	s0,28(sp)
  5a5038:	afbf0024 	sw	ra,36(sp)
  5a503c:	0c15c8cc 	jal	0x572330
  5a5040:	afb10020 	sw	s1,32(sp)
  5a5044:	1040000d 	beqz	v0,0x5a507c
  5a5048:	00408021 	move	s0,v0
  5a504c:	2404006f 	li	a0,111
  5a5050:	24050004 	li	a1,4
  5a5054:	0c15c943 	jal	0x57250c
  5a5058:	00403021 	move	a2,v0
  5a505c:	10400017 	beqz	v0,0x5a50bc
  5a5060:	00408821 	move	s1,v0
  5a5064:	8fbf0024 	lw	ra,36(sp)
  5a5068:	02201021 	move	v0,s1
  5a506c:	8fb10020 	lw	s1,32(sp)
  5a5070:	8fb0001c 	lw	s0,28(sp)
  5a5074:	03e00008 	jr	ra
  5a5078:	27bd0028 	addiu	sp,sp,40
  5a507c:	3c020075 	lui	v0,0x75
  5a5080:	8c42cf58 	lw	v0,-12456(v0)
  5a5084:	1040fff7 	beqz	v0,0x5a5064
  5a5088:	00008821 	move	s1,zero
  5a508c:	0c16276a 	jal	0x589da8
  5a5090:	00000000 	nop
  5a5094:	5040fff4 	beqzl	v0,0x5a5068
  5a5098:	8fbf0024 	lw	ra,36(sp)
  5a509c:	3c04006d 	lui	a0,0x6d
  5a50a0:	3c05006e 	lui	a1,0x6e
  5a50a4:	248434fc 	addiu	a0,a0,13564
  5a50a8:	24a578d0 	addiu	a1,a1,30928
  5a50ac:	0c101b74 	jal	0x406dd0
  5a50b0:	240600a2 	li	a2,162
  5a50b4:	0816941a 	j	0x5a5068
  5a50b8:	8fbf0024 	lw	ra,36(sp)
  5a50bc:	3c020075 	lui	v0,0x75
  5a50c0:	8c42cf58 	lw	v0,-12456(v0)
  5a50c4:	14400005 	bnez	v0,0x5a50dc
  5a50c8:	00000000 	nop
  5a50cc:	0c101f7c 	jal	0x407df0
  5a50d0:	02002021 	move	a0,s0
  5a50d4:	0816941a 	j	0x5a5068
  5a50d8:	8fbf0024 	lw	ra,36(sp)
  5a50dc:	0c16276a 	jal	0x589da8
  5a50e0:	00000000 	nop
  5a50e4:	1040fff9 	beqz	v0,0x5a50cc
  5a50e8:	3c04006d 	lui	a0,0x6d
  5a50ec:	3c05006e 	lui	a1,0x6e
  5a50f0:	248447f0 	addiu	a0,a0,18416
  5a50f4:	24a578d0 	addiu	a1,a1,30928
  5a50f8:	0c101b74 	jal	0x406dd0
  5a50fc:	240600aa 	li	a2,170
  5a5100:	08169433 	j	0x5a50cc
  5a5104:	00000000 	nop
