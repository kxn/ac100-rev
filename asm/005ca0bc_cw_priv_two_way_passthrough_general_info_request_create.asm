; func cw_priv_two_way_passthrough_general_info_request_create @ 0x005ca0bc size=0x1ac
  5ca0bc:	27bdffd8 	addiu	sp,sp,-40
  5ca0c0:	24050010 	li	a1,16
  5ca0c4:	afb10020 	sw	s1,32(sp)
  5ca0c8:	afb0001c 	sw	s0,28(sp)
  5ca0cc:	afbf0024 	sw	ra,36(sp)
  5ca0d0:	0c15c8cc 	jal	0x572330
  5ca0d4:	00808021 	move	s0,a0
  5ca0d8:	10400027 	beqz	v0,0x5ca178
  5ca0dc:	00408821 	move	s1,v0
  5ca0e0:	ac40000c 	sw	zero,12(v0)
  5ca0e4:	8e050008 	lw	a1,8(s0)
  5ca0e8:	50a00009 	beqzl	a1,0x5ca110
  5ca0ec:	8e250008 	lw	a1,8(s1)
  5ca0f0:	8e04000c 	lw	a0,12(s0)
  5ca0f4:	1080003c 	beqz	a0,0x5ca1e8
  5ca0f8:	3c020075 	lui	v0,0x75
  5ca0fc:	0c15c8cc 	jal	0x572330
  5ca100:	30a5ffff 	andi	a1,a1,0xffff
  5ca104:	1040003f 	beqz	v0,0x5ca204
  5ca108:	ae22000c 	sw	v0,12(s1)
  5ca10c:	8e250008 	lw	a1,8(s1)
  5ca110:	240400a5 	li	a0,165
  5ca114:	02203021 	move	a2,s1
  5ca118:	24a5000c 	addiu	a1,a1,12
  5ca11c:	0c15c943 	jal	0x57250c
  5ca120:	30a5ffff 	andi	a1,a1,0xffff
  5ca124:	10400007 	beqz	v0,0x5ca144
  5ca128:	00408021 	move	s0,v0
  5ca12c:	8fbf0024 	lw	ra,36(sp)
  5ca130:	02001021 	move	v0,s0
  5ca134:	8fb10020 	lw	s1,32(sp)
  5ca138:	8fb0001c 	lw	s0,28(sp)
  5ca13c:	03e00008 	jr	ra
  5ca140:	27bd0028 	addiu	sp,sp,40
  5ca144:	3c020075 	lui	v0,0x75
  5ca148:	8c42cf58 	lw	v0,-12456(v0)
  5ca14c:	1440001a 	bnez	v0,0x5ca1b8
  5ca150:	00000000 	nop
  5ca154:	8e24000c 	lw	a0,12(s1)
  5ca158:	10800003 	beqz	a0,0x5ca168
  5ca15c:	00000000 	nop
  5ca160:	0c101f7c 	jal	0x407df0
  5ca164:	00000000 	nop
  5ca168:	0c101f7c 	jal	0x407df0
  5ca16c:	02202021 	move	a0,s1
  5ca170:	0817284c 	j	0x5ca130
  5ca174:	8fbf0024 	lw	ra,36(sp)
  5ca178:	3c020075 	lui	v0,0x75
  5ca17c:	8c42cf58 	lw	v0,-12456(v0)
  5ca180:	1040ffea 	beqz	v0,0x5ca12c
  5ca184:	00008021 	move	s0,zero
  5ca188:	0c16276a 	jal	0x589da8
  5ca18c:	00000000 	nop
  5ca190:	5040ffe7 	beqzl	v0,0x5ca130
  5ca194:	8fbf0024 	lw	ra,36(sp)
  5ca198:	3c04006d 	lui	a0,0x6d
  5ca19c:	3c05006f 	lui	a1,0x6f
  5ca1a0:	248434fc 	addiu	a0,a0,13564
  5ca1a4:	24a50ff0 	addiu	a1,a1,4080
  5ca1a8:	0c101b74 	jal	0x406dd0
  5ca1ac:	240600ca 	li	a2,202
  5ca1b0:	0817284c 	j	0x5ca130
  5ca1b4:	8fbf0024 	lw	ra,36(sp)
  5ca1b8:	0c16276a 	jal	0x589da8
  5ca1bc:	00000000 	nop
  5ca1c0:	5040ffe5 	beqzl	v0,0x5ca158
  5ca1c4:	8e24000c 	lw	a0,12(s1)
  5ca1c8:	3c04006d 	lui	a0,0x6d
  5ca1cc:	3c05006f 	lui	a1,0x6f
  5ca1d0:	248447f0 	addiu	a0,a0,18416
  5ca1d4:	24a50ff0 	addiu	a1,a1,4080
  5ca1d8:	0c101b74 	jal	0x406dd0
  5ca1dc:	240600e5 	li	a2,229
  5ca1e0:	08172856 	j	0x5ca158
  5ca1e4:	8e24000c 	lw	a0,12(s1)
  5ca1e8:	8c42cf58 	lw	v0,-12456(v0)
  5ca1ec:	14400015 	bnez	v0,0x5ca244
  5ca1f0:	00000000 	nop
  5ca1f4:	0c101f7c 	jal	0x407df0
  5ca1f8:	02202021 	move	a0,s1
  5ca1fc:	0817284b 	j	0x5ca12c
  5ca200:	00008021 	move	s0,zero
  5ca204:	3c020075 	lui	v0,0x75
  5ca208:	8c42cf58 	lw	v0,-12456(v0)
  5ca20c:	1040fff9 	beqz	v0,0x5ca1f4
  5ca210:	00000000 	nop
  5ca214:	0c16276a 	jal	0x589da8
  5ca218:	00000000 	nop
  5ca21c:	1040fff5 	beqz	v0,0x5ca1f4
  5ca220:	3c04006e 	lui	a0,0x6e
  5ca224:	3c05006f 	lui	a1,0x6f
  5ca228:	24848050 	addiu	a0,a0,-32688
  5ca22c:	24a50ff0 	addiu	a1,a1,4080
  5ca230:	240600db 	li	a2,219
  5ca234:	0c101b74 	jal	0x406dd0
  5ca238:	00000000 	nop
  5ca23c:	0817287d 	j	0x5ca1f4
  5ca240:	00000000 	nop
  5ca244:	0c16276a 	jal	0x589da8
  5ca248:	00000000 	nop
  5ca24c:	1040ffe9 	beqz	v0,0x5ca1f4
  5ca250:	3c04006e 	lui	a0,0x6e
  5ca254:	3c05006f 	lui	a1,0x6f
  5ca258:	248480d8 	addiu	a0,a0,-32552
  5ca25c:	24a50ff0 	addiu	a1,a1,4080
  5ca260:	0817288d 	j	0x5ca234
  5ca264:	240600d4 	li	a2,212
