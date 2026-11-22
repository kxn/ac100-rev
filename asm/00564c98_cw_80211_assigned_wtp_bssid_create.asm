; func cw_80211_assigned_wtp_bssid_create @ 0x00564c98 size=0xdc
  564c98:	27bdffd8 	addiu	sp,sp,-40
  564c9c:	24050008 	li	a1,8
  564ca0:	afb0001c 	sw	s0,28(sp)
  564ca4:	afbf0024 	sw	ra,36(sp)
  564ca8:	0c15c8cc 	jal	0x572330
  564cac:	afb10020 	sw	s1,32(sp)
  564cb0:	1040000d 	beqz	v0,0x564ce8
  564cb4:	00408021 	move	s0,v0
  564cb8:	24040402 	li	a0,1026
  564cbc:	24050008 	li	a1,8
  564cc0:	0c15c943 	jal	0x57250c
  564cc4:	00403021 	move	a2,v0
  564cc8:	10400017 	beqz	v0,0x564d28
  564ccc:	00408821 	move	s1,v0
  564cd0:	8fbf0024 	lw	ra,36(sp)
  564cd4:	02201021 	move	v0,s1
  564cd8:	8fb10020 	lw	s1,32(sp)
  564cdc:	8fb0001c 	lw	s0,28(sp)
  564ce0:	03e00008 	jr	ra
  564ce4:	27bd0028 	addiu	sp,sp,40
  564ce8:	3c020075 	lui	v0,0x75
  564cec:	8c42cf58 	lw	v0,-12456(v0)
  564cf0:	1040fff7 	beqz	v0,0x564cd0
  564cf4:	00008821 	move	s1,zero
  564cf8:	0c16276a 	jal	0x589da8
  564cfc:	00000000 	nop
  564d00:	5040fff4 	beqzl	v0,0x564cd4
  564d04:	8fbf0024 	lw	ra,36(sp)
  564d08:	3c04006d 	lui	a0,0x6d
  564d0c:	3c05006d 	lui	a1,0x6d
  564d10:	248434fc 	addiu	a0,a0,13564
  564d14:	24a53f80 	addiu	a1,a1,16256
  564d18:	0c101b74 	jal	0x406dd0
  564d1c:	240600bd 	li	a2,189
  564d20:	08159335 	j	0x564cd4
  564d24:	8fbf0024 	lw	ra,36(sp)
  564d28:	3c020075 	lui	v0,0x75
  564d2c:	8c42cf58 	lw	v0,-12456(v0)
  564d30:	14400005 	bnez	v0,0x564d48
  564d34:	00000000 	nop
  564d38:	0c101f7c 	jal	0x407df0
  564d3c:	02002021 	move	a0,s0
  564d40:	08159335 	j	0x564cd4
  564d44:	8fbf0024 	lw	ra,36(sp)
  564d48:	0c16276a 	jal	0x589da8
  564d4c:	00000000 	nop
  564d50:	1040fff9 	beqz	v0,0x564d38
  564d54:	3c04006d 	lui	a0,0x6d
  564d58:	3c05006d 	lui	a1,0x6d
  564d5c:	24843580 	addiu	a0,a0,13696
  564d60:	24a53f80 	addiu	a1,a1,16256
  564d64:	0c101b74 	jal	0x406dd0
  564d68:	240600c5 	li	a2,197
  564d6c:	0815934e 	j	0x564d38
  564d70:	00000000 	nop
	...
