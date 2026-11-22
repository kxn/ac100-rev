; func cw_priv_sta_assoc_rslt_create @ 0x005c2f98 size=0x184
  5c2f98:	27bdffd8 	addiu	sp,sp,-40
  5c2f9c:	24050014 	li	a1,20
  5c2fa0:	afb10020 	sw	s1,32(sp)
  5c2fa4:	afb0001c 	sw	s0,28(sp)
  5c2fa8:	afbf0024 	sw	ra,36(sp)
  5c2fac:	0c15c8cc 	jal	0x572330
  5c2fb0:	00808021 	move	s0,a0
  5c2fb4:	1040002a 	beqz	v0,0x5c3060
  5c2fb8:	00408821 	move	s1,v0
  5c2fbc:	ac40000c 	sw	zero,12(v0)
  5c2fc0:	ac400010 	sw	zero,16(v0)
  5c2fc4:	8e02000c 	lw	v0,12(s0)
  5c2fc8:	5040000b 	beqzl	v0,0x5c2ff8
  5c2fcc:	8e25000c 	lw	a1,12(s1)
  5c2fd0:	8e030010 	lw	v1,16(s0)
  5c2fd4:	50600008 	beqzl	v1,0x5c2ff8
  5c2fd8:	8e25000c 	lw	a1,12(s1)
  5c2fdc:	ae22000c 	sw	v0,12(s1)
  5c2fe0:	8e040010 	lw	a0,16(s0)
  5c2fe4:	0c15c8cc 	jal	0x572330
  5c2fe8:	9605000e 	lhu	a1,14(s0)
  5c2fec:	10400038 	beqz	v0,0x5c30d0
  5c2ff0:	ae220010 	sw	v0,16(s1)
  5c2ff4:	8e25000c 	lw	a1,12(s1)
  5c2ff8:	24040004 	li	a0,4
  5c2ffc:	02203021 	move	a2,s1
  5c3000:	24a50010 	addiu	a1,a1,16
  5c3004:	0c15c943 	jal	0x57250c
  5c3008:	30a5ffff 	andi	a1,a1,0xffff
  5c300c:	10400007 	beqz	v0,0x5c302c
  5c3010:	00408021 	move	s0,v0
  5c3014:	8fbf0024 	lw	ra,36(sp)
  5c3018:	02001021 	move	v0,s0
  5c301c:	8fb10020 	lw	s1,32(sp)
  5c3020:	8fb0001c 	lw	s0,28(sp)
  5c3024:	03e00008 	jr	ra
  5c3028:	27bd0028 	addiu	sp,sp,40
  5c302c:	3c020075 	lui	v0,0x75
  5c3030:	8c42cf58 	lw	v0,-12456(v0)
  5c3034:	1440001a 	bnez	v0,0x5c30a0
  5c3038:	00000000 	nop
  5c303c:	8e240010 	lw	a0,16(s1)
  5c3040:	10800003 	beqz	a0,0x5c3050
  5c3044:	00000000 	nop
  5c3048:	0c101f7c 	jal	0x407df0
  5c304c:	00000000 	nop
  5c3050:	0c101f7c 	jal	0x407df0
  5c3054:	02202021 	move	a0,s1
  5c3058:	08170c06 	j	0x5c3018
  5c305c:	8fbf0024 	lw	ra,36(sp)
  5c3060:	3c020075 	lui	v0,0x75
  5c3064:	8c42cf58 	lw	v0,-12456(v0)
  5c3068:	1040ffea 	beqz	v0,0x5c3014
  5c306c:	00008021 	move	s0,zero
  5c3070:	0c16276a 	jal	0x589da8
  5c3074:	00000000 	nop
  5c3078:	5040ffe7 	beqzl	v0,0x5c3018
  5c307c:	8fbf0024 	lw	ra,36(sp)
  5c3080:	3c04006d 	lui	a0,0x6d
  5c3084:	3c05006f 	lui	a1,0x6f
  5c3088:	248434fc 	addiu	a0,a0,13564
  5c308c:	24a5f9c0 	addiu	a1,a1,-1600
  5c3090:	0c101b74 	jal	0x406dd0
  5c3094:	240600f6 	li	a2,246
  5c3098:	08170c06 	j	0x5c3018
  5c309c:	8fbf0024 	lw	ra,36(sp)
  5c30a0:	0c16276a 	jal	0x589da8
  5c30a4:	00000000 	nop
  5c30a8:	5040ffe5 	beqzl	v0,0x5c3040
  5c30ac:	8e240010 	lw	a0,16(s1)
  5c30b0:	3c04006d 	lui	a0,0x6d
  5c30b4:	3c05006f 	lui	a1,0x6f
  5c30b8:	248447f0 	addiu	a0,a0,18416
  5c30bc:	24a5f9c0 	addiu	a1,a1,-1600
  5c30c0:	0c101b74 	jal	0x406dd0
  5c30c4:	2406010d 	li	a2,269
  5c30c8:	08170c10 	j	0x5c3040
  5c30cc:	8e240010 	lw	a0,16(s1)
  5c30d0:	3c020075 	lui	v0,0x75
  5c30d4:	8c42cf58 	lw	v0,-12456(v0)
  5c30d8:	14400005 	bnez	v0,0x5c30f0
  5c30dc:	00000000 	nop
  5c30e0:	0c101f7c 	jal	0x407df0
  5c30e4:	02202021 	move	a0,s1
  5c30e8:	08170c05 	j	0x5c3014
  5c30ec:	00008021 	move	s0,zero
  5c30f0:	0c16276a 	jal	0x589da8
  5c30f4:	00000000 	nop
  5c30f8:	1040fff9 	beqz	v0,0x5c30e0
  5c30fc:	3c04006f 	lui	a0,0x6f
  5c3100:	3c05006f 	lui	a1,0x6f
  5c3104:	2484f510 	addiu	a0,a0,-2800
  5c3108:	24a5f9c0 	addiu	a1,a1,-1600
  5c310c:	0c101b74 	jal	0x406dd0
  5c3110:	24060103 	li	a2,259
  5c3114:	08170c38 	j	0x5c30e0
  5c3118:	00000000 	nop
