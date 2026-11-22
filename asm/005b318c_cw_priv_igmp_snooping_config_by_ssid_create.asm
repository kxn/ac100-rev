; func cw_priv_igmp_snooping_config_by_ssid_create @ 0x005b318c size=0x1b4
  5b318c:	27bdffd8 	addiu	sp,sp,-40
  5b3190:	24050008 	li	a1,8
  5b3194:	afb10020 	sw	s1,32(sp)
  5b3198:	afb0001c 	sw	s0,28(sp)
  5b319c:	afbf0024 	sw	ra,36(sp)
  5b31a0:	0c15c8cc 	jal	0x572330
  5b31a4:	00808021 	move	s0,a0
  5b31a8:	10400029 	beqz	v0,0x5b3250
  5b31ac:	00408821 	move	s1,v0
  5b31b0:	ac400004 	sw	zero,4(v0)
  5b31b4:	8e020000 	lw	v0,0(s0)
  5b31b8:	1040000a 	beqz	v0,0x5b31e4
  5b31bc:	00000000 	nop
  5b31c0:	8e040004 	lw	a0,4(s0)
  5b31c4:	5080003e 	beqzl	a0,0x5b32c0
  5b31c8:	3c020075 	lui	v0,0x75
  5b31cc:	24050003 	li	a1,3
  5b31d0:	70452802 	mul	a1,v0,a1
  5b31d4:	0c15c8cc 	jal	0x572330
  5b31d8:	30a5ffff 	andi	a1,a1,0xffff
  5b31dc:	1040003f 	beqz	v0,0x5b32dc
  5b31e0:	ae220004 	sw	v0,4(s1)
  5b31e4:	0c16cbec 	jal	0x5b2fb0
  5b31e8:	02202021 	move	a0,s1
  5b31ec:	24040071 	li	a0,113
  5b31f0:	00402821 	move	a1,v0
  5b31f4:	0c15c943 	jal	0x57250c
  5b31f8:	02203021 	move	a2,s1
  5b31fc:	10400007 	beqz	v0,0x5b321c
  5b3200:	00408021 	move	s0,v0
  5b3204:	8fbf0024 	lw	ra,36(sp)
  5b3208:	02001021 	move	v0,s0
  5b320c:	8fb10020 	lw	s1,32(sp)
  5b3210:	8fb0001c 	lw	s0,28(sp)
  5b3214:	03e00008 	jr	ra
  5b3218:	27bd0028 	addiu	sp,sp,40
  5b321c:	3c020075 	lui	v0,0x75
  5b3220:	8c42cf58 	lw	v0,-12456(v0)
  5b3224:	1440001a 	bnez	v0,0x5b3290
  5b3228:	00000000 	nop
  5b322c:	8e240004 	lw	a0,4(s1)
  5b3230:	10800003 	beqz	a0,0x5b3240
  5b3234:	00000000 	nop
  5b3238:	0c101f7c 	jal	0x407df0
  5b323c:	00000000 	nop
  5b3240:	0c101f7c 	jal	0x407df0
  5b3244:	02202021 	move	a0,s1
  5b3248:	0816cc82 	j	0x5b3208
  5b324c:	8fbf0024 	lw	ra,36(sp)
  5b3250:	3c020075 	lui	v0,0x75
  5b3254:	8c42cf58 	lw	v0,-12456(v0)
  5b3258:	1040ffea 	beqz	v0,0x5b3204
  5b325c:	00008021 	move	s0,zero
  5b3260:	0c16276a 	jal	0x589da8
  5b3264:	00000000 	nop
  5b3268:	5040ffe7 	beqzl	v0,0x5b3208
  5b326c:	8fbf0024 	lw	ra,36(sp)
  5b3270:	3c04006d 	lui	a0,0x6d
  5b3274:	3c05006f 	lui	a1,0x6f
  5b3278:	248434fc 	addiu	a0,a0,13564
  5b327c:	24a5b910 	addiu	a1,a1,-18160
  5b3280:	0c101b74 	jal	0x406dd0
  5b3284:	240600d8 	li	a2,216
  5b3288:	0816cc82 	j	0x5b3208
  5b328c:	8fbf0024 	lw	ra,36(sp)
  5b3290:	0c16276a 	jal	0x589da8
  5b3294:	00000000 	nop
  5b3298:	5040ffe5 	beqzl	v0,0x5b3230
  5b329c:	8e240004 	lw	a0,4(s1)
  5b32a0:	3c04006d 	lui	a0,0x6d
  5b32a4:	3c05006f 	lui	a1,0x6f
  5b32a8:	248447f0 	addiu	a0,a0,18416
  5b32ac:	24a5b910 	addiu	a1,a1,-18160
  5b32b0:	0c101b74 	jal	0x406dd0
  5b32b4:	240600f3 	li	a2,243
  5b32b8:	0816cc8c 	j	0x5b3230
  5b32bc:	8e240004 	lw	a0,4(s1)
  5b32c0:	8c42cf58 	lw	v0,-12456(v0)
  5b32c4:	14400015 	bnez	v0,0x5b331c
  5b32c8:	00000000 	nop
  5b32cc:	0c101f7c 	jal	0x407df0
  5b32d0:	02202021 	move	a0,s1
  5b32d4:	0816cc81 	j	0x5b3204
  5b32d8:	00008021 	move	s0,zero
  5b32dc:	3c020075 	lui	v0,0x75
  5b32e0:	8c42cf58 	lw	v0,-12456(v0)
  5b32e4:	1040fff9 	beqz	v0,0x5b32cc
  5b32e8:	00000000 	nop
  5b32ec:	0c16276a 	jal	0x589da8
  5b32f0:	00000000 	nop
  5b32f4:	1040fff5 	beqz	v0,0x5b32cc
  5b32f8:	3c04006f 	lui	a0,0x6f
  5b32fc:	3c05006f 	lui	a1,0x6f
  5b3300:	248488e4 	addiu	a0,a0,-30492
  5b3304:	24a5b910 	addiu	a1,a1,-18160
  5b3308:	240600e9 	li	a2,233
  5b330c:	0c101b74 	jal	0x406dd0
  5b3310:	00000000 	nop
  5b3314:	0816ccb3 	j	0x5b32cc
  5b3318:	00000000 	nop
  5b331c:	0c16276a 	jal	0x589da8
  5b3320:	00000000 	nop
  5b3324:	1040ffe9 	beqz	v0,0x5b32cc
  5b3328:	3c04006f 	lui	a0,0x6f
  5b332c:	3c05006f 	lui	a1,0x6f
  5b3330:	24848824 	addiu	a0,a0,-30684
  5b3334:	24a5b910 	addiu	a1,a1,-18160
  5b3338:	0816ccc3 	j	0x5b330c
  5b333c:	240600e2 	li	a2,226
