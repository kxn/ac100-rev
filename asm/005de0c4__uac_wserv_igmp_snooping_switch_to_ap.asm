; func _uac_wserv_igmp_snooping_switch_to_ap @ 0x005de0c4 size=0x1e8
  5de0c4:	27bdffa8 	addiu	sp,sp,-88
  5de0c8:	afb10050 	sw	s1,80(sp)
  5de0cc:	3c11007d 	lui	s1,0x7d
  5de0d0:	afb0004c 	sw	s0,76(sp)
  5de0d4:	afbf0054 	sw	ra,84(sp)
  5de0d8:	afa00038 	sw	zero,56(sp)
  5de0dc:	afa0003c 	sw	zero,60(sp)
  5de0e0:	afa00040 	sw	zero,64(sp)
  5de0e4:	afa00044 	sw	zero,68(sp)
  5de0e8:	8e22bee0 	lw	v0,-16672(s1)
  5de0ec:	14400025 	bnez	v0,0x5de184
  5de0f0:	00808021 	move	s0,a0
  5de0f4:	27a4003c 	addiu	a0,sp,60
  5de0f8:	afa0003c 	sw	zero,60(sp)
  5de0fc:	afa00040 	sw	zero,64(sp)
  5de100:	afa00044 	sw	zero,68(sp)
  5de104:	0c146b62 	jal	0x51ad88
  5de108:	afb00038 	sw	s0,56(sp)
  5de10c:	3c05005d 	lui	a1,0x5d
  5de110:	27a60038 	addiu	a2,sp,56
  5de114:	24a57b64 	addiu	a1,a1,31588
  5de118:	0c1776e8 	jal	0x5ddba0
  5de11c:	02002021 	move	a0,s0
  5de120:	27a40028 	addiu	a0,sp,40
  5de124:	afa00028 	sw	zero,40(sp)
  5de128:	afa0002c 	sw	zero,44(sp)
  5de12c:	afa00030 	sw	zero,48(sp)
  5de130:	0c16683d 	jal	0x59a0f4
  5de134:	afa00034 	sw	zero,52(sp)
  5de138:	1040001f 	beqz	v0,0x5de1b8
  5de13c:	3c02015f 	lui	v0,0x15f
  5de140:	0c166906 	jal	0x59a418
  5de144:	27a40028 	addiu	a0,sp,40
  5de148:	08177858 	j	0x5de160
  5de14c:	00000000 	nop
  5de150:	0c102140 	jal	0x408500
  5de154:	02002021 	move	a0,s0
  5de158:	0c101f7c 	jal	0x407df0
  5de15c:	02002021 	move	a0,s0
  5de160:	0c10206c 	jal	0x4081b0
  5de164:	27a4003c 	addiu	a0,sp,60
  5de168:	1440fff9 	bnez	v0,0x5de150
  5de16c:	00408021 	move	s0,v0
  5de170:	8fbf0054 	lw	ra,84(sp)
  5de174:	8fb10050 	lw	s1,80(sp)
  5de178:	8fb0004c 	lw	s0,76(sp)
  5de17c:	03e00008 	jr	ra
  5de180:	27bd0058 	addiu	sp,sp,88
  5de184:	0c16276a 	jal	0x589da8
  5de188:	00000000 	nop
  5de18c:	5040ffda 	beqzl	v0,0x5de0f8
  5de190:	27a4003c 	addiu	a0,sp,60
  5de194:	3c04006f 	lui	a0,0x6f
  5de198:	3c05006f 	lui	a1,0x6f
  5de19c:	24843bdc 	addiu	a0,a0,15324
  5de1a0:	24a56f70 	addiu	a1,a1,28528
  5de1a4:	24061310 	li	a2,4880
  5de1a8:	0c101b74 	jal	0x406dd0
  5de1ac:	02003821 	move	a3,s0
  5de1b0:	0817783e 	j	0x5de0f8
  5de1b4:	27a4003c 	addiu	a0,sp,60
  5de1b8:	27a50028 	addiu	a1,sp,40
  5de1bc:	afa20010 	sw	v0,16(sp)
  5de1c0:	24020001 	li	v0,1
  5de1c4:	24060001 	li	a2,1
  5de1c8:	afa20014 	sw	v0,20(sp)
  5de1cc:	24070001 	li	a3,1
  5de1d0:	2402002b 	li	v0,43
  5de1d4:	3204ffff 	andi	a0,s0,0xffff
  5de1d8:	0c14da0a 	jal	0x536828
  5de1dc:	afa20018 	sw	v0,24(sp)
  5de1e0:	14400013 	bnez	v0,0x5de230
  5de1e4:	8e22bee0 	lw	v0,-16672(s1)
  5de1e8:	8fa20030 	lw	v0,48(sp)
  5de1ec:	1440001e 	bnez	v0,0x5de268
  5de1f0:	3c02007d 	lui	v0,0x7d
  5de1f4:	8c42bee4 	lw	v0,-16668(v0)
  5de1f8:	1040ffd1 	beqz	v0,0x5de140
  5de1fc:	00000000 	nop
  5de200:	0c16276a 	jal	0x589da8
  5de204:	00000000 	nop
  5de208:	1040ffcd 	beqz	v0,0x5de140
  5de20c:	3c04006f 	lui	a0,0x6f
  5de210:	3c05006f 	lui	a1,0x6f
  5de214:	24843590 	addiu	a0,a0,13712
  5de218:	24a56f70 	addiu	a1,a1,28528
  5de21c:	24061324 	li	a2,4900
  5de220:	0c101b74 	jal	0x406dd0
  5de224:	02003821 	move	a3,s0
  5de228:	08177850 	j	0x5de140
  5de22c:	00000000 	nop
  5de230:	1040ffc3 	beqz	v0,0x5de140
  5de234:	00000000 	nop
  5de238:	0c16276a 	jal	0x589da8
  5de23c:	00000000 	nop
  5de240:	1040ffbf 	beqz	v0,0x5de140
  5de244:	3c04006f 	lui	a0,0x6f
  5de248:	3c05006f 	lui	a1,0x6f
  5de24c:	24845568 	addiu	a0,a0,21864
  5de250:	24a56f70 	addiu	a1,a1,28528
  5de254:	2406131f 	li	a2,4895
  5de258:	0c101b74 	jal	0x406dd0
  5de25c:	00000000 	nop
  5de260:	08177850 	j	0x5de140
  5de264:	00000000 	nop
  5de268:	27a40028 	addiu	a0,sp,40
  5de26c:	0c17a07f 	jal	0x5e81fc
  5de270:	27a50038 	addiu	a1,sp,56
  5de274:	1040ffb2 	beqz	v0,0x5de140
  5de278:	3c020075 	lui	v0,0x75
  5de27c:	8c42fe70 	lw	v0,-400(v0)
  5de280:	1040ffaf 	beqz	v0,0x5de140
  5de284:	00000000 	nop
  5de288:	0c16276a 	jal	0x589da8
  5de28c:	00000000 	nop
  5de290:	1040ffab 	beqz	v0,0x5de140
  5de294:	3c04006f 	lui	a0,0x6f
  5de298:	3c05006f 	lui	a1,0x6f
  5de29c:	248455a4 	addiu	a0,a0,21924
  5de2a0:	24a56f70 	addiu	a1,a1,28528
  5de2a4:	08177896 	j	0x5de258
  5de2a8:	24061329 	li	a2,4905
