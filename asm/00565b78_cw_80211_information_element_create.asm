; func cw_80211_information_element_create @ 0x00565b78 size=0x178
  565b78:	27bdffd8 	addiu	sp,sp,-40
  565b7c:	2405000c 	li	a1,12
  565b80:	afb10020 	sw	s1,32(sp)
  565b84:	afb0001c 	sw	s0,28(sp)
  565b88:	afbf0024 	sw	ra,36(sp)
  565b8c:	0c15c8cc 	jal	0x572330
  565b90:	00808021 	move	s0,a0
  565b94:	10400027 	beqz	v0,0x565c34
  565b98:	00408821 	move	s1,v0
  565b9c:	ac400008 	sw	zero,8(v0)
  565ba0:	96050004 	lhu	a1,4(s0)
  565ba4:	50a00009 	beqzl	a1,0x565bcc
  565ba8:	96250004 	lhu	a1,4(s1)
  565bac:	8e040008 	lw	a0,8(s0)
  565bb0:	50800006 	beqzl	a0,0x565bcc
  565bb4:	96250004 	lhu	a1,4(s1)
  565bb8:	0c15c8cc 	jal	0x572330
  565bbc:	00000000 	nop
  565bc0:	10400038 	beqz	v0,0x565ca4
  565bc4:	ae220008 	sw	v0,8(s1)
  565bc8:	96250004 	lhu	a1,4(s1)
  565bcc:	24040405 	li	a0,1029
  565bd0:	02203021 	move	a2,s1
  565bd4:	24a50003 	addiu	a1,a1,3
  565bd8:	0c15c943 	jal	0x57250c
  565bdc:	30a5ffff 	andi	a1,a1,0xffff
  565be0:	10400007 	beqz	v0,0x565c00
  565be4:	00408021 	move	s0,v0
  565be8:	8fbf0024 	lw	ra,36(sp)
  565bec:	02001021 	move	v0,s0
  565bf0:	8fb10020 	lw	s1,32(sp)
  565bf4:	8fb0001c 	lw	s0,28(sp)
  565bf8:	03e00008 	jr	ra
  565bfc:	27bd0028 	addiu	sp,sp,40
  565c00:	3c020075 	lui	v0,0x75
  565c04:	8c42cf58 	lw	v0,-12456(v0)
  565c08:	1440001a 	bnez	v0,0x565c74
  565c0c:	00000000 	nop
  565c10:	8e240008 	lw	a0,8(s1)
  565c14:	10800003 	beqz	a0,0x565c24
  565c18:	00000000 	nop
  565c1c:	0c101f7c 	jal	0x407df0
  565c20:	00000000 	nop
  565c24:	0c101f7c 	jal	0x407df0
  565c28:	02202021 	move	a0,s1
  565c2c:	081596fb 	j	0x565bec
  565c30:	8fbf0024 	lw	ra,36(sp)
  565c34:	3c020075 	lui	v0,0x75
  565c38:	8c42cf58 	lw	v0,-12456(v0)
  565c3c:	1040ffea 	beqz	v0,0x565be8
  565c40:	00008021 	move	s0,zero
  565c44:	0c16276a 	jal	0x589da8
  565c48:	00000000 	nop
  565c4c:	5040ffe7 	beqzl	v0,0x565bec
  565c50:	8fbf0024 	lw	ra,36(sp)
  565c54:	3c04006d 	lui	a0,0x6d
  565c58:	3c05006d 	lui	a1,0x6d
  565c5c:	248434fc 	addiu	a0,a0,13564
  565c60:	24a54600 	addiu	a1,a1,17920
  565c64:	0c101b74 	jal	0x406dd0
  565c68:	240600d9 	li	a2,217
  565c6c:	081596fb 	j	0x565bec
  565c70:	8fbf0024 	lw	ra,36(sp)
  565c74:	0c16276a 	jal	0x589da8
  565c78:	00000000 	nop
  565c7c:	5040ffe5 	beqzl	v0,0x565c14
  565c80:	8e240008 	lw	a0,8(s1)
  565c84:	3c04006d 	lui	a0,0x6d
  565c88:	3c05006d 	lui	a1,0x6d
  565c8c:	24843580 	addiu	a0,a0,13696
  565c90:	24a54600 	addiu	a1,a1,17920
  565c94:	0c101b74 	jal	0x406dd0
  565c98:	240600ee 	li	a2,238
  565c9c:	08159705 	j	0x565c14
  565ca0:	8e240008 	lw	a0,8(s1)
  565ca4:	3c020075 	lui	v0,0x75
  565ca8:	8c42cf58 	lw	v0,-12456(v0)
  565cac:	14400005 	bnez	v0,0x565cc4
  565cb0:	00000000 	nop
  565cb4:	0c101f7c 	jal	0x407df0
  565cb8:	02202021 	move	a0,s1
  565cbc:	081596fa 	j	0x565be8
  565cc0:	00008021 	move	s0,zero
  565cc4:	0c16276a 	jal	0x589da8
  565cc8:	00000000 	nop
  565ccc:	1040fff9 	beqz	v0,0x565cb4
  565cd0:	3c04006d 	lui	a0,0x6d
  565cd4:	3c05006d 	lui	a1,0x6d
  565cd8:	248444d4 	addiu	a0,a0,17620
  565cdc:	24a54600 	addiu	a1,a1,17920
  565ce0:	0c101b74 	jal	0x406dd0
  565ce4:	240600e4 	li	a2,228
  565ce8:	0815972d 	j	0x565cb4
  565cec:	00000000 	nop
