; func cw_80211_tx_power_create @ 0x00569cb8 size=0xdc
  569cb8:	27bdffd8 	addiu	sp,sp,-40
  569cbc:	24050004 	li	a1,4
  569cc0:	afb0001c 	sw	s0,28(sp)
  569cc4:	afbf0024 	sw	ra,36(sp)
  569cc8:	0c15c8cc 	jal	0x572330
  569ccc:	afb10020 	sw	s1,32(sp)
  569cd0:	1040000d 	beqz	v0,0x569d08
  569cd4:	00408021 	move	s0,v0
  569cd8:	24040411 	li	a0,1041
  569cdc:	24050004 	li	a1,4
  569ce0:	0c15c943 	jal	0x57250c
  569ce4:	00403021 	move	a2,v0
  569ce8:	10400017 	beqz	v0,0x569d48
  569cec:	00408821 	move	s1,v0
  569cf0:	8fbf0024 	lw	ra,36(sp)
  569cf4:	02201021 	move	v0,s1
  569cf8:	8fb10020 	lw	s1,32(sp)
  569cfc:	8fb0001c 	lw	s0,28(sp)
  569d00:	03e00008 	jr	ra
  569d04:	27bd0028 	addiu	sp,sp,40
  569d08:	3c020075 	lui	v0,0x75
  569d0c:	8c42cf58 	lw	v0,-12456(v0)
  569d10:	1040fff7 	beqz	v0,0x569cf0
  569d14:	00008821 	move	s1,zero
  569d18:	0c16276a 	jal	0x589da8
  569d1c:	00000000 	nop
  569d20:	5040fff4 	beqzl	v0,0x569cf4
  569d24:	8fbf0024 	lw	ra,36(sp)
  569d28:	3c04006d 	lui	a0,0x6d
  569d2c:	3c05006d 	lui	a1,0x6d
  569d30:	248434fc 	addiu	a0,a0,13564
  569d34:	24a556c0 	addiu	a1,a1,22208
  569d38:	0c101b74 	jal	0x406dd0
  569d3c:	240600bc 	li	a2,188
  569d40:	0815a73d 	j	0x569cf4
  569d44:	8fbf0024 	lw	ra,36(sp)
  569d48:	3c020075 	lui	v0,0x75
  569d4c:	8c42cf58 	lw	v0,-12456(v0)
  569d50:	14400005 	bnez	v0,0x569d68
  569d54:	00000000 	nop
  569d58:	0c101f7c 	jal	0x407df0
  569d5c:	02002021 	move	a0,s0
  569d60:	0815a73d 	j	0x569cf4
  569d64:	8fbf0024 	lw	ra,36(sp)
  569d68:	0c16276a 	jal	0x589da8
  569d6c:	00000000 	nop
  569d70:	1040fff9 	beqz	v0,0x569d58
  569d74:	3c04006d 	lui	a0,0x6d
  569d78:	3c05006d 	lui	a1,0x6d
  569d7c:	248447f0 	addiu	a0,a0,18416
  569d80:	24a556c0 	addiu	a1,a1,22208
  569d84:	0c101b74 	jal	0x406dd0
  569d88:	240600c4 	li	a2,196
  569d8c:	0815a756 	j	0x569d58
  569d90:	00000000 	nop
	...
