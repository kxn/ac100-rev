; func cw_priv_stat_prd_create @ 0x005c8104 size=0xdc
  5c8104:	27bdffd8 	addiu	sp,sp,-40
  5c8108:	24050008 	li	a1,8
  5c810c:	afb0001c 	sw	s0,28(sp)
  5c8110:	afbf0024 	sw	ra,36(sp)
  5c8114:	0c15c8cc 	jal	0x572330
  5c8118:	afb10020 	sw	s1,32(sp)
  5c811c:	1040000d 	beqz	v0,0x5c8154
  5c8120:	00408021 	move	s0,v0
  5c8124:	2404000c 	li	a0,12
  5c8128:	24050008 	li	a1,8
  5c812c:	0c15c943 	jal	0x57250c
  5c8130:	00403021 	move	a2,v0
  5c8134:	10400017 	beqz	v0,0x5c8194
  5c8138:	00408821 	move	s1,v0
  5c813c:	8fbf0024 	lw	ra,36(sp)
  5c8140:	02201021 	move	v0,s1
  5c8144:	8fb10020 	lw	s1,32(sp)
  5c8148:	8fb0001c 	lw	s0,28(sp)
  5c814c:	03e00008 	jr	ra
  5c8150:	27bd0028 	addiu	sp,sp,40
  5c8154:	3c020075 	lui	v0,0x75
  5c8158:	8c42cf58 	lw	v0,-12456(v0)
  5c815c:	1040fff7 	beqz	v0,0x5c813c
  5c8160:	00008821 	move	s1,zero
  5c8164:	0c16276a 	jal	0x589da8
  5c8168:	00000000 	nop
  5c816c:	5040fff4 	beqzl	v0,0x5c8140
  5c8170:	8fbf0024 	lw	ra,36(sp)
  5c8174:	3c04006d 	lui	a0,0x6d
  5c8178:	3c05006f 	lui	a1,0x6f
  5c817c:	248434fc 	addiu	a0,a0,13564
  5c8180:	24a50690 	addiu	a1,a1,1680
  5c8184:	0c101b74 	jal	0x406dd0
  5c8188:	240600a7 	li	a2,167
  5c818c:	08172050 	j	0x5c8140
  5c8190:	8fbf0024 	lw	ra,36(sp)
  5c8194:	3c020075 	lui	v0,0x75
  5c8198:	8c42cf58 	lw	v0,-12456(v0)
  5c819c:	14400005 	bnez	v0,0x5c81b4
  5c81a0:	00000000 	nop
  5c81a4:	0c101f7c 	jal	0x407df0
  5c81a8:	02002021 	move	a0,s0
  5c81ac:	08172050 	j	0x5c8140
  5c81b0:	8fbf0024 	lw	ra,36(sp)
  5c81b4:	0c16276a 	jal	0x589da8
  5c81b8:	00000000 	nop
  5c81bc:	1040fff9 	beqz	v0,0x5c81a4
  5c81c0:	3c04006d 	lui	a0,0x6d
  5c81c4:	3c05006f 	lui	a1,0x6f
  5c81c8:	248447f0 	addiu	a0,a0,18416
  5c81cc:	24a50690 	addiu	a1,a1,1680
  5c81d0:	0c101b74 	jal	0x406dd0
  5c81d4:	240600af 	li	a2,175
  5c81d8:	08172069 	j	0x5c81a4
  5c81dc:	00000000 	nop
