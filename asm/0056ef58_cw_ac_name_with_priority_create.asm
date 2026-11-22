; func cw_ac_name_with_priority_create @ 0x0056ef58 size=0x178
  56ef58:	27bdffd8 	addiu	sp,sp,-40
  56ef5c:	24050008 	li	a1,8
  56ef60:	afb10020 	sw	s1,32(sp)
  56ef64:	afb0001c 	sw	s0,28(sp)
  56ef68:	afbf0024 	sw	ra,36(sp)
  56ef6c:	0c15c8cc 	jal	0x572330
  56ef70:	00808021 	move	s0,a0
  56ef74:	10400027 	beqz	v0,0x56f014
  56ef78:	00408821 	move	s1,v0
  56ef7c:	ac400004 	sw	zero,4(v0)
  56ef80:	96050002 	lhu	a1,2(s0)
  56ef84:	50a00009 	beqzl	a1,0x56efac
  56ef88:	96250002 	lhu	a1,2(s1)
  56ef8c:	8e040004 	lw	a0,4(s0)
  56ef90:	50800006 	beqzl	a0,0x56efac
  56ef94:	96250002 	lhu	a1,2(s1)
  56ef98:	0c15c909 	jal	0x572424
  56ef9c:	00000000 	nop
  56efa0:	10400038 	beqz	v0,0x56f084
  56efa4:	ae220004 	sw	v0,4(s1)
  56efa8:	96250002 	lhu	a1,2(s1)
  56efac:	24040005 	li	a0,5
  56efb0:	02203021 	move	a2,s1
  56efb4:	24a50001 	addiu	a1,a1,1
  56efb8:	0c15c943 	jal	0x57250c
  56efbc:	30a5ffff 	andi	a1,a1,0xffff
  56efc0:	10400007 	beqz	v0,0x56efe0
  56efc4:	00408021 	move	s0,v0
  56efc8:	8fbf0024 	lw	ra,36(sp)
  56efcc:	02001021 	move	v0,s0
  56efd0:	8fb10020 	lw	s1,32(sp)
  56efd4:	8fb0001c 	lw	s0,28(sp)
  56efd8:	03e00008 	jr	ra
  56efdc:	27bd0028 	addiu	sp,sp,40
  56efe0:	3c020075 	lui	v0,0x75
  56efe4:	8c42cf58 	lw	v0,-12456(v0)
  56efe8:	1440001a 	bnez	v0,0x56f054
  56efec:	00000000 	nop
  56eff0:	8e240004 	lw	a0,4(s1)
  56eff4:	10800003 	beqz	a0,0x56f004
  56eff8:	00000000 	nop
  56effc:	0c101f7c 	jal	0x407df0
  56f000:	00000000 	nop
  56f004:	0c101f7c 	jal	0x407df0
  56f008:	02202021 	move	a0,s1
  56f00c:	0815bbf3 	j	0x56efcc
  56f010:	8fbf0024 	lw	ra,36(sp)
  56f014:	3c020075 	lui	v0,0x75
  56f018:	8c42cf58 	lw	v0,-12456(v0)
  56f01c:	1040ffea 	beqz	v0,0x56efc8
  56f020:	00008021 	move	s0,zero
  56f024:	0c16276a 	jal	0x589da8
  56f028:	00000000 	nop
  56f02c:	5040ffe7 	beqzl	v0,0x56efcc
  56f030:	8fbf0024 	lw	ra,36(sp)
  56f034:	3c04006d 	lui	a0,0x6d
  56f038:	3c05006d 	lui	a1,0x6d
  56f03c:	248434fc 	addiu	a0,a0,13564
  56f040:	24a57200 	addiu	a1,a1,29184
  56f044:	0c101b74 	jal	0x406dd0
  56f048:	240600a9 	li	a2,169
  56f04c:	0815bbf3 	j	0x56efcc
  56f050:	8fbf0024 	lw	ra,36(sp)
  56f054:	0c16276a 	jal	0x589da8
  56f058:	00000000 	nop
  56f05c:	5040ffe5 	beqzl	v0,0x56eff4
  56f060:	8e240004 	lw	a0,4(s1)
  56f064:	3c04006d 	lui	a0,0x6d
  56f068:	3c05006d 	lui	a1,0x6d
  56f06c:	24843580 	addiu	a0,a0,13696
  56f070:	24a57200 	addiu	a1,a1,29184
  56f074:	0c101b74 	jal	0x406dd0
  56f078:	240600be 	li	a2,190
  56f07c:	0815bbfd 	j	0x56eff4
  56f080:	8e240004 	lw	a0,4(s1)
  56f084:	3c020075 	lui	v0,0x75
  56f088:	8c42cf58 	lw	v0,-12456(v0)
  56f08c:	14400005 	bnez	v0,0x56f0a4
  56f090:	00000000 	nop
  56f094:	0c101f7c 	jal	0x407df0
  56f098:	02202021 	move	a0,s1
  56f09c:	0815bbf2 	j	0x56efc8
  56f0a0:	00008021 	move	s0,zero
  56f0a4:	0c16276a 	jal	0x589da8
  56f0a8:	00000000 	nop
  56f0ac:	1040fff9 	beqz	v0,0x56f094
  56f0b0:	3c04006d 	lui	a0,0x6d
  56f0b4:	3c05006d 	lui	a1,0x6d
  56f0b8:	24847068 	addiu	a0,a0,28776
  56f0bc:	24a57200 	addiu	a1,a1,29184
  56f0c0:	0c101b74 	jal	0x406dd0
  56f0c4:	240600b4 	li	a2,180
  56f0c8:	0815bc25 	j	0x56f094
  56f0cc:	00000000 	nop
