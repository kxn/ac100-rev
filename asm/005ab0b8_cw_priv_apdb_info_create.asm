; func cw_priv_apdb_info_create @ 0x005ab0b8 size=0x1a4
  5ab0b8:	27bdffd8 	addiu	sp,sp,-40
  5ab0bc:	24050008 	li	a1,8
  5ab0c0:	afb10020 	sw	s1,32(sp)
  5ab0c4:	afb0001c 	sw	s0,28(sp)
  5ab0c8:	afbf0024 	sw	ra,36(sp)
  5ab0cc:	0c15c8cc 	jal	0x572330
  5ab0d0:	00808021 	move	s0,a0
  5ab0d4:	10400025 	beqz	v0,0x5ab16c
  5ab0d8:	00408821 	move	s1,v0
  5ab0dc:	ac400004 	sw	zero,4(v0)
  5ab0e0:	96050000 	lhu	a1,0(s0)
  5ab0e4:	50a00009 	beqzl	a1,0x5ab10c
  5ab0e8:	96250000 	lhu	a1,0(s1)
  5ab0ec:	8e040004 	lw	a0,4(s0)
  5ab0f0:	1080003a 	beqz	a0,0x5ab1dc
  5ab0f4:	3c020075 	lui	v0,0x75
  5ab0f8:	0c15c8cc 	jal	0x572330
  5ab0fc:	00000000 	nop
  5ab100:	1040003d 	beqz	v0,0x5ab1f8
  5ab104:	ae220004 	sw	v0,4(s1)
  5ab108:	96250000 	lhu	a1,0(s1)
  5ab10c:	24040051 	li	a0,81
  5ab110:	0c15c943 	jal	0x57250c
  5ab114:	02203021 	move	a2,s1
  5ab118:	10400007 	beqz	v0,0x5ab138
  5ab11c:	00408021 	move	s0,v0
  5ab120:	8fbf0024 	lw	ra,36(sp)
  5ab124:	02001021 	move	v0,s0
  5ab128:	8fb10020 	lw	s1,32(sp)
  5ab12c:	8fb0001c 	lw	s0,28(sp)
  5ab130:	03e00008 	jr	ra
  5ab134:	27bd0028 	addiu	sp,sp,40
  5ab138:	3c020075 	lui	v0,0x75
  5ab13c:	8c42cf58 	lw	v0,-12456(v0)
  5ab140:	1440001a 	bnez	v0,0x5ab1ac
  5ab144:	00000000 	nop
  5ab148:	8e240004 	lw	a0,4(s1)
  5ab14c:	10800003 	beqz	a0,0x5ab15c
  5ab150:	00000000 	nop
  5ab154:	0c101f7c 	jal	0x407df0
  5ab158:	00000000 	nop
  5ab15c:	0c101f7c 	jal	0x407df0
  5ab160:	02202021 	move	a0,s1
  5ab164:	0816ac49 	j	0x5ab124
  5ab168:	8fbf0024 	lw	ra,36(sp)
  5ab16c:	3c020075 	lui	v0,0x75
  5ab170:	8c42cf58 	lw	v0,-12456(v0)
  5ab174:	1040ffea 	beqz	v0,0x5ab120
  5ab178:	00008021 	move	s0,zero
  5ab17c:	0c16276a 	jal	0x589da8
  5ab180:	00000000 	nop
  5ab184:	5040ffe7 	beqzl	v0,0x5ab124
  5ab188:	8fbf0024 	lw	ra,36(sp)
  5ab18c:	3c04006d 	lui	a0,0x6d
  5ab190:	3c05006f 	lui	a1,0x6f
  5ab194:	248434fc 	addiu	a0,a0,13564
  5ab198:	24a59690 	addiu	a1,a1,-26992
  5ab19c:	0c101b74 	jal	0x406dd0
  5ab1a0:	240600e0 	li	a2,224
  5ab1a4:	0816ac49 	j	0x5ab124
  5ab1a8:	8fbf0024 	lw	ra,36(sp)
  5ab1ac:	0c16276a 	jal	0x589da8
  5ab1b0:	00000000 	nop
  5ab1b4:	5040ffe5 	beqzl	v0,0x5ab14c
  5ab1b8:	8e240004 	lw	a0,4(s1)
  5ab1bc:	3c04006d 	lui	a0,0x6d
  5ab1c0:	3c05006f 	lui	a1,0x6f
  5ab1c4:	248447f0 	addiu	a0,a0,18416
  5ab1c8:	24a59690 	addiu	a1,a1,-26992
  5ab1cc:	0c101b74 	jal	0x406dd0
  5ab1d0:	240600fb 	li	a2,251
  5ab1d4:	0816ac53 	j	0x5ab14c
  5ab1d8:	8e240004 	lw	a0,4(s1)
  5ab1dc:	8c42cf58 	lw	v0,-12456(v0)
  5ab1e0:	14400015 	bnez	v0,0x5ab238
  5ab1e4:	00000000 	nop
  5ab1e8:	0c101f7c 	jal	0x407df0
  5ab1ec:	02202021 	move	a0,s1
  5ab1f0:	0816ac48 	j	0x5ab120
  5ab1f4:	00008021 	move	s0,zero
  5ab1f8:	3c020075 	lui	v0,0x75
  5ab1fc:	8c42cf58 	lw	v0,-12456(v0)
  5ab200:	1040fff9 	beqz	v0,0x5ab1e8
  5ab204:	00000000 	nop
  5ab208:	0c16276a 	jal	0x589da8
  5ab20c:	00000000 	nop
  5ab210:	1040fff5 	beqz	v0,0x5ab1e8
  5ab214:	3c04006e 	lui	a0,0x6e
  5ab218:	3c05006f 	lui	a1,0x6f
  5ab21c:	24848050 	addiu	a0,a0,-32688
  5ab220:	24a59690 	addiu	a1,a1,-26992
  5ab224:	240600f1 	li	a2,241
  5ab228:	0c101b74 	jal	0x406dd0
  5ab22c:	00000000 	nop
  5ab230:	0816ac7a 	j	0x5ab1e8
  5ab234:	00000000 	nop
  5ab238:	0c16276a 	jal	0x589da8
  5ab23c:	00000000 	nop
  5ab240:	1040ffe9 	beqz	v0,0x5ab1e8
  5ab244:	3c04006e 	lui	a0,0x6e
  5ab248:	3c05006f 	lui	a1,0x6f
  5ab24c:	248480d8 	addiu	a0,a0,-32552
  5ab250:	24a59690 	addiu	a1,a1,-26992
  5ab254:	0816ac8a 	j	0x5ab228
  5ab258:	240600ea 	li	a2,234
