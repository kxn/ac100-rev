; func cw_priv_wlan_rssi_orient_create @ 0x005cbea4 size=0xdc
  5cbea4:	27bdffd8 	addiu	sp,sp,-40
  5cbea8:	24050008 	li	a1,8
  5cbeac:	afb0001c 	sw	s0,28(sp)
  5cbeb0:	afbf0024 	sw	ra,36(sp)
  5cbeb4:	0c15c8cc 	jal	0x572330
  5cbeb8:	afb10020 	sw	s1,32(sp)
  5cbebc:	1040000d 	beqz	v0,0x5cbef4
  5cbec0:	00408021 	move	s0,v0
  5cbec4:	2404004c 	li	a0,76
  5cbec8:	24050008 	li	a1,8
  5cbecc:	0c15c943 	jal	0x57250c
  5cbed0:	00403021 	move	a2,v0
  5cbed4:	10400017 	beqz	v0,0x5cbf34
  5cbed8:	00408821 	move	s1,v0
  5cbedc:	8fbf0024 	lw	ra,36(sp)
  5cbee0:	02201021 	move	v0,s1
  5cbee4:	8fb10020 	lw	s1,32(sp)
  5cbee8:	8fb0001c 	lw	s0,28(sp)
  5cbeec:	03e00008 	jr	ra
  5cbef0:	27bd0028 	addiu	sp,sp,40
  5cbef4:	3c020075 	lui	v0,0x75
  5cbef8:	8c42cf58 	lw	v0,-12456(v0)
  5cbefc:	1040fff7 	beqz	v0,0x5cbedc
  5cbf00:	00008821 	move	s1,zero
  5cbf04:	0c16276a 	jal	0x589da8
  5cbf08:	00000000 	nop
  5cbf0c:	5040fff4 	beqzl	v0,0x5cbee0
  5cbf10:	8fbf0024 	lw	ra,36(sp)
  5cbf14:	3c04006d 	lui	a0,0x6d
  5cbf18:	3c05006f 	lui	a1,0x6f
  5cbf1c:	248434fc 	addiu	a0,a0,13564
  5cbf20:	24a516e0 	addiu	a1,a1,5856
  5cbf24:	0c101b74 	jal	0x406dd0
  5cbf28:	240600b8 	li	a2,184
  5cbf2c:	08172fb8 	j	0x5cbee0
  5cbf30:	8fbf0024 	lw	ra,36(sp)
  5cbf34:	3c020075 	lui	v0,0x75
  5cbf38:	8c42cf58 	lw	v0,-12456(v0)
  5cbf3c:	14400005 	bnez	v0,0x5cbf54
  5cbf40:	00000000 	nop
  5cbf44:	0c101f7c 	jal	0x407df0
  5cbf48:	02002021 	move	a0,s0
  5cbf4c:	08172fb8 	j	0x5cbee0
  5cbf50:	8fbf0024 	lw	ra,36(sp)
  5cbf54:	0c16276a 	jal	0x589da8
  5cbf58:	00000000 	nop
  5cbf5c:	1040fff9 	beqz	v0,0x5cbf44
  5cbf60:	3c04006d 	lui	a0,0x6d
  5cbf64:	3c05006f 	lui	a1,0x6f
  5cbf68:	248447f0 	addiu	a0,a0,18416
  5cbf6c:	24a516e0 	addiu	a1,a1,5856
  5cbf70:	0c101b74 	jal	0x406dd0
  5cbf74:	240600c0 	li	a2,192
  5cbf78:	08172fd1 	j	0x5cbf44
  5cbf7c:	00000000 	nop
