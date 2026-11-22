; func cw_priv_spec_rssi_create @ 0x005c111c size=0xdc
  5c111c:	27bdffd8 	addiu	sp,sp,-40
  5c1120:	24050004 	li	a1,4
  5c1124:	afb0001c 	sw	s0,28(sp)
  5c1128:	afbf0024 	sw	ra,36(sp)
  5c112c:	0c15c8cc 	jal	0x572330
  5c1130:	afb10020 	sw	s1,32(sp)
  5c1134:	1040000d 	beqz	v0,0x5c116c
  5c1138:	00408021 	move	s0,v0
  5c113c:	2404003e 	li	a0,62
  5c1140:	24050004 	li	a1,4
  5c1144:	0c15c943 	jal	0x57250c
  5c1148:	00403021 	move	a2,v0
  5c114c:	10400017 	beqz	v0,0x5c11ac
  5c1150:	00408821 	move	s1,v0
  5c1154:	8fbf0024 	lw	ra,36(sp)
  5c1158:	02201021 	move	v0,s1
  5c115c:	8fb10020 	lw	s1,32(sp)
  5c1160:	8fb0001c 	lw	s0,28(sp)
  5c1164:	03e00008 	jr	ra
  5c1168:	27bd0028 	addiu	sp,sp,40
  5c116c:	3c020075 	lui	v0,0x75
  5c1170:	8c42cf58 	lw	v0,-12456(v0)
  5c1174:	1040fff7 	beqz	v0,0x5c1154
  5c1178:	00008821 	move	s1,zero
  5c117c:	0c16276a 	jal	0x589da8
  5c1180:	00000000 	nop
  5c1184:	5040fff4 	beqzl	v0,0x5c1158
  5c1188:	8fbf0024 	lw	ra,36(sp)
  5c118c:	3c04006d 	lui	a0,0x6d
  5c1190:	3c05006f 	lui	a1,0x6f
  5c1194:	248434fc 	addiu	a0,a0,13564
  5c1198:	24a5f420 	addiu	a1,a1,-3040
  5c119c:	0c101b74 	jal	0x406dd0
  5c11a0:	240600a2 	li	a2,162
  5c11a4:	08170456 	j	0x5c1158
  5c11a8:	8fbf0024 	lw	ra,36(sp)
  5c11ac:	3c020075 	lui	v0,0x75
  5c11b0:	8c42cf58 	lw	v0,-12456(v0)
  5c11b4:	14400005 	bnez	v0,0x5c11cc
  5c11b8:	00000000 	nop
  5c11bc:	0c101f7c 	jal	0x407df0
  5c11c0:	02002021 	move	a0,s0
  5c11c4:	08170456 	j	0x5c1158
  5c11c8:	8fbf0024 	lw	ra,36(sp)
  5c11cc:	0c16276a 	jal	0x589da8
  5c11d0:	00000000 	nop
  5c11d4:	1040fff9 	beqz	v0,0x5c11bc
  5c11d8:	3c04006d 	lui	a0,0x6d
  5c11dc:	3c05006f 	lui	a1,0x6f
  5c11e0:	248447f0 	addiu	a0,a0,18416
  5c11e4:	24a5f420 	addiu	a1,a1,-3040
  5c11e8:	0c101b74 	jal	0x406dd0
  5c11ec:	240600aa 	li	a2,170
  5c11f0:	0817046f 	j	0x5c11bc
  5c11f4:	00000000 	nop
