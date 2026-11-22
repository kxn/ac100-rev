; func cw_80211_update_wlan_create @ 0x0056ade8 size=0x178
  56ade8:	27bdffd8 	addiu	sp,sp,-40
  56adec:	2405000c 	li	a1,12
  56adf0:	afb10020 	sw	s1,32(sp)
  56adf4:	afb0001c 	sw	s0,28(sp)
  56adf8:	afbf0024 	sw	ra,36(sp)
  56adfc:	0c15c8cc 	jal	0x572330
  56ae00:	00808021 	move	s0,a0
  56ae04:	10400027 	beqz	v0,0x56aea4
  56ae08:	00408821 	move	s1,v0
  56ae0c:	ac400008 	sw	zero,8(v0)
  56ae10:	96050006 	lhu	a1,6(s0)
  56ae14:	50a00009 	beqzl	a1,0x56ae3c
  56ae18:	96250006 	lhu	a1,6(s1)
  56ae1c:	8e040008 	lw	a0,8(s0)
  56ae20:	50800006 	beqzl	a0,0x56ae3c
  56ae24:	96250006 	lhu	a1,6(s1)
  56ae28:	0c15c8cc 	jal	0x572330
  56ae2c:	00000000 	nop
  56ae30:	10400038 	beqz	v0,0x56af14
  56ae34:	ae220008 	sw	v0,8(s1)
  56ae38:	96250006 	lhu	a1,6(s1)
  56ae3c:	24040414 	li	a0,1044
  56ae40:	02203021 	move	a2,s1
  56ae44:	24a50008 	addiu	a1,a1,8
  56ae48:	0c15c943 	jal	0x57250c
  56ae4c:	30a5ffff 	andi	a1,a1,0xffff
  56ae50:	10400007 	beqz	v0,0x56ae70
  56ae54:	00408021 	move	s0,v0
  56ae58:	8fbf0024 	lw	ra,36(sp)
  56ae5c:	02001021 	move	v0,s0
  56ae60:	8fb10020 	lw	s1,32(sp)
  56ae64:	8fb0001c 	lw	s0,28(sp)
  56ae68:	03e00008 	jr	ra
  56ae6c:	27bd0028 	addiu	sp,sp,40
  56ae70:	3c020075 	lui	v0,0x75
  56ae74:	8c42cf58 	lw	v0,-12456(v0)
  56ae78:	1440001a 	bnez	v0,0x56aee4
  56ae7c:	00000000 	nop
  56ae80:	8e240008 	lw	a0,8(s1)
  56ae84:	10800003 	beqz	a0,0x56ae94
  56ae88:	00000000 	nop
  56ae8c:	0c101f7c 	jal	0x407df0
  56ae90:	00000000 	nop
  56ae94:	0c101f7c 	jal	0x407df0
  56ae98:	02202021 	move	a0,s1
  56ae9c:	0815ab97 	j	0x56ae5c
  56aea0:	8fbf0024 	lw	ra,36(sp)
  56aea4:	3c020075 	lui	v0,0x75
  56aea8:	8c42cf58 	lw	v0,-12456(v0)
  56aeac:	1040ffea 	beqz	v0,0x56ae58
  56aeb0:	00008021 	move	s0,zero
  56aeb4:	0c16276a 	jal	0x589da8
  56aeb8:	00000000 	nop
  56aebc:	5040ffe7 	beqzl	v0,0x56ae5c
  56aec0:	8fbf0024 	lw	ra,36(sp)
  56aec4:	3c04006d 	lui	a0,0x6d
  56aec8:	3c05006d 	lui	a1,0x6d
  56aecc:	248434fc 	addiu	a0,a0,13564
  56aed0:	24a55b48 	addiu	a1,a1,23368
  56aed4:	0c101b74 	jal	0x406dd0
  56aed8:	240600ff 	li	a2,255
  56aedc:	0815ab97 	j	0x56ae5c
  56aee0:	8fbf0024 	lw	ra,36(sp)
  56aee4:	0c16276a 	jal	0x589da8
  56aee8:	00000000 	nop
  56aeec:	5040ffe5 	beqzl	v0,0x56ae84
  56aef0:	8e240008 	lw	a0,8(s1)
  56aef4:	3c04006d 	lui	a0,0x6d
  56aef8:	3c05006d 	lui	a1,0x6d
  56aefc:	24843580 	addiu	a0,a0,13696
  56af00:	24a55b48 	addiu	a1,a1,23368
  56af04:	0c101b74 	jal	0x406dd0
  56af08:	24060114 	li	a2,276
  56af0c:	0815aba1 	j	0x56ae84
  56af10:	8e240008 	lw	a0,8(s1)
  56af14:	3c020075 	lui	v0,0x75
  56af18:	8c42cf58 	lw	v0,-12456(v0)
  56af1c:	14400005 	bnez	v0,0x56af34
  56af20:	00000000 	nop
  56af24:	0c101f7c 	jal	0x407df0
  56af28:	02202021 	move	a0,s1
  56af2c:	0815ab96 	j	0x56ae58
  56af30:	00008021 	move	s0,zero
  56af34:	0c16276a 	jal	0x589da8
  56af38:	00000000 	nop
  56af3c:	1040fff9 	beqz	v0,0x56af24
  56af40:	3c04006d 	lui	a0,0x6d
  56af44:	3c05006d 	lui	a1,0x6d
  56af48:	24843528 	addiu	a0,a0,13608
  56af4c:	24a55b48 	addiu	a1,a1,23368
  56af50:	0c101b74 	jal	0x406dd0
  56af54:	2406010a 	li	a2,266
  56af58:	0815abc9 	j	0x56af24
  56af5c:	00000000 	nop
