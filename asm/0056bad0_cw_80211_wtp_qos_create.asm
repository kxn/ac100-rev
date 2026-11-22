; func cw_80211_wtp_qos_create @ 0x0056bad0 size=0xdc
  56bad0:	27bdffd8 	addiu	sp,sp,-40
  56bad4:	2405002a 	li	a1,42
  56bad8:	afb0001c 	sw	s0,28(sp)
  56badc:	afbf0024 	sw	ra,36(sp)
  56bae0:	0c15c8cc 	jal	0x572330
  56bae4:	afb10020 	sw	s1,32(sp)
  56bae8:	1040000d 	beqz	v0,0x56bb20
  56baec:	00408021 	move	s0,v0
  56baf0:	24040415 	li	a0,1045
  56baf4:	24050022 	li	a1,34
  56baf8:	0c15c943 	jal	0x57250c
  56bafc:	00403021 	move	a2,v0
  56bb00:	10400017 	beqz	v0,0x56bb60
  56bb04:	00408821 	move	s1,v0
  56bb08:	8fbf0024 	lw	ra,36(sp)
  56bb0c:	02201021 	move	v0,s1
  56bb10:	8fb10020 	lw	s1,32(sp)
  56bb14:	8fb0001c 	lw	s0,28(sp)
  56bb18:	03e00008 	jr	ra
  56bb1c:	27bd0028 	addiu	sp,sp,40
  56bb20:	3c020075 	lui	v0,0x75
  56bb24:	8c42cf58 	lw	v0,-12456(v0)
  56bb28:	1040fff7 	beqz	v0,0x56bb08
  56bb2c:	00008821 	move	s1,zero
  56bb30:	0c16276a 	jal	0x589da8
  56bb34:	00000000 	nop
  56bb38:	5040fff4 	beqzl	v0,0x56bb0c
  56bb3c:	8fbf0024 	lw	ra,36(sp)
  56bb40:	3c04006d 	lui	a0,0x6d
  56bb44:	3c05006d 	lui	a1,0x6d
  56bb48:	248434fc 	addiu	a0,a0,13564
  56bb4c:	24a55d10 	addiu	a1,a1,23824
  56bb50:	0c101b74 	jal	0x406dd0
  56bb54:	240600f5 	li	a2,245
  56bb58:	0815aec3 	j	0x56bb0c
  56bb5c:	8fbf0024 	lw	ra,36(sp)
  56bb60:	3c020075 	lui	v0,0x75
  56bb64:	8c42cf58 	lw	v0,-12456(v0)
  56bb68:	14400005 	bnez	v0,0x56bb80
  56bb6c:	00000000 	nop
  56bb70:	0c101f7c 	jal	0x407df0
  56bb74:	02002021 	move	a0,s0
  56bb78:	0815aec3 	j	0x56bb0c
  56bb7c:	8fbf0024 	lw	ra,36(sp)
  56bb80:	0c16276a 	jal	0x589da8
  56bb84:	00000000 	nop
  56bb88:	1040fff9 	beqz	v0,0x56bb70
  56bb8c:	3c04006d 	lui	a0,0x6d
  56bb90:	3c05006d 	lui	a1,0x6d
  56bb94:	248447f0 	addiu	a0,a0,18416
  56bb98:	24a55d10 	addiu	a1,a1,23824
  56bb9c:	0c101b74 	jal	0x406dd0
  56bba0:	240600fd 	li	a2,253
  56bba4:	0815aedc 	j	0x56bb70
  56bba8:	00000000 	nop
  56bbac:	00000000 	nop
