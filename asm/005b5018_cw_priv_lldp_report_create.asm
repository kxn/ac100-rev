; func cw_priv_lldp_report_create @ 0x005b5018 size=0x1bc
  5b5018:	27bdffd8 	addiu	sp,sp,-40
  5b501c:	24050008 	li	a1,8
  5b5020:	afb10020 	sw	s1,32(sp)
  5b5024:	afb0001c 	sw	s0,28(sp)
  5b5028:	afbf0024 	sw	ra,36(sp)
  5b502c:	0c15c8cc 	jal	0x572330
  5b5030:	00808821 	move	s1,a0
  5b5034:	1040002b 	beqz	v0,0x5b50e4
  5b5038:	00408021 	move	s0,v0
  5b503c:	ac400004 	sw	zero,4(v0)
  5b5040:	ac400000 	sw	zero,0(v0)
  5b5044:	8e250000 	lw	a1,0(s1)
  5b5048:	10a0000d 	beqz	a1,0x5b5080
  5b504c:	24040068 	li	a0,104
  5b5050:	8e240004 	lw	a0,4(s1)
  5b5054:	1080003f 	beqz	a0,0x5b5154
  5b5058:	3c020075 	lui	v0,0x75
  5b505c:	24a50001 	addiu	a1,a1,1
  5b5060:	0c15c8cc 	jal	0x572330
  5b5064:	30a5ffff 	andi	a1,a1,0xffff
  5b5068:	10400041 	beqz	v0,0x5b5170
  5b506c:	ae020004 	sw	v0,4(s0)
  5b5070:	8e220000 	lw	v0,0(s1)
  5b5074:	ae020000 	sw	v0,0(s0)
  5b5078:	8e250000 	lw	a1,0(s1)
  5b507c:	24040068 	li	a0,104
  5b5080:	02003021 	move	a2,s0
  5b5084:	24a50004 	addiu	a1,a1,4
  5b5088:	0c15c943 	jal	0x57250c
  5b508c:	30a5ffff 	andi	a1,a1,0xffff
  5b5090:	10400007 	beqz	v0,0x5b50b0
  5b5094:	00408821 	move	s1,v0
  5b5098:	8fbf0024 	lw	ra,36(sp)
  5b509c:	02201021 	move	v0,s1
  5b50a0:	8fb10020 	lw	s1,32(sp)
  5b50a4:	8fb0001c 	lw	s0,28(sp)
  5b50a8:	03e00008 	jr	ra
  5b50ac:	27bd0028 	addiu	sp,sp,40
  5b50b0:	3c020075 	lui	v0,0x75
  5b50b4:	8c42cf58 	lw	v0,-12456(v0)
  5b50b8:	1440001a 	bnez	v0,0x5b5124
  5b50bc:	00000000 	nop
  5b50c0:	8e040004 	lw	a0,4(s0)
  5b50c4:	10800003 	beqz	a0,0x5b50d4
  5b50c8:	00000000 	nop
  5b50cc:	0c101f7c 	jal	0x407df0
  5b50d0:	00000000 	nop
  5b50d4:	0c101f7c 	jal	0x407df0
  5b50d8:	02002021 	move	a0,s0
  5b50dc:	0816d427 	j	0x5b509c
  5b50e0:	8fbf0024 	lw	ra,36(sp)
  5b50e4:	3c020075 	lui	v0,0x75
  5b50e8:	8c42cf58 	lw	v0,-12456(v0)
  5b50ec:	1040ffea 	beqz	v0,0x5b5098
  5b50f0:	00008821 	move	s1,zero
  5b50f4:	0c16276a 	jal	0x589da8
  5b50f8:	00000000 	nop
  5b50fc:	5040ffe7 	beqzl	v0,0x5b509c
  5b5100:	8fbf0024 	lw	ra,36(sp)
  5b5104:	3c04006d 	lui	a0,0x6d
  5b5108:	3c05006f 	lui	a1,0x6f
  5b510c:	248434fc 	addiu	a0,a0,13564
  5b5110:	24a5c1f0 	addiu	a1,a1,-15888
  5b5114:	0c101b74 	jal	0x406dd0
  5b5118:	240600bb 	li	a2,187
  5b511c:	0816d427 	j	0x5b509c
  5b5120:	8fbf0024 	lw	ra,36(sp)
  5b5124:	0c16276a 	jal	0x589da8
  5b5128:	00000000 	nop
  5b512c:	5040ffe5 	beqzl	v0,0x5b50c4
  5b5130:	8e040004 	lw	a0,4(s0)
  5b5134:	3c04006d 	lui	a0,0x6d
  5b5138:	3c05006f 	lui	a1,0x6f
  5b513c:	248447f0 	addiu	a0,a0,18416
  5b5140:	24a5c1f0 	addiu	a1,a1,-15888
  5b5144:	0c101b74 	jal	0x406dd0
  5b5148:	240600d6 	li	a2,214
  5b514c:	0816d431 	j	0x5b50c4
  5b5150:	8e040004 	lw	a0,4(s0)
  5b5154:	8c42cf58 	lw	v0,-12456(v0)
  5b5158:	14400015 	bnez	v0,0x5b51b0
  5b515c:	00000000 	nop
  5b5160:	0c101f7c 	jal	0x407df0
  5b5164:	02002021 	move	a0,s0
  5b5168:	0816d426 	j	0x5b5098
  5b516c:	00008821 	move	s1,zero
  5b5170:	3c020075 	lui	v0,0x75
  5b5174:	8c42cf58 	lw	v0,-12456(v0)
  5b5178:	1040fff9 	beqz	v0,0x5b5160
  5b517c:	00000000 	nop
  5b5180:	0c16276a 	jal	0x589da8
  5b5184:	00000000 	nop
  5b5188:	1040fff5 	beqz	v0,0x5b5160
  5b518c:	3c04006e 	lui	a0,0x6e
  5b5190:	3c05006f 	lui	a1,0x6f
  5b5194:	24848050 	addiu	a0,a0,-32688
  5b5198:	24a5c1f0 	addiu	a1,a1,-15888
  5b519c:	240600cc 	li	a2,204
  5b51a0:	0c101b74 	jal	0x406dd0
  5b51a4:	00000000 	nop
  5b51a8:	0816d458 	j	0x5b5160
  5b51ac:	00000000 	nop
  5b51b0:	0c16276a 	jal	0x589da8
  5b51b4:	00000000 	nop
  5b51b8:	1040ffe9 	beqz	v0,0x5b5160
  5b51bc:	3c04006e 	lui	a0,0x6e
  5b51c0:	3c05006f 	lui	a1,0x6f
  5b51c4:	248480d8 	addiu	a0,a0,-32552
  5b51c8:	24a5c1f0 	addiu	a1,a1,-15888
  5b51cc:	0816d468 	j	0x5b51a0
  5b51d0:	240600c5 	li	a2,197
