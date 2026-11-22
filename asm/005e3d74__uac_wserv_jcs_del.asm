; func _uac_wserv_jcs_del @ 0x005e3d74 size=0x398
  5e3d74:	27bdfdb8 	addiu	sp,sp,-584
  5e3d78:	afbf0244 	sw	ra,580(sp)
  5e3d7c:	afb50240 	sw	s5,576(sp)
  5e3d80:	00a0a821 	move	s5,a1
  5e3d84:	afb4023c 	sw	s4,572(sp)
  5e3d88:	3c140067 	lui	s4,0x67
  5e3d8c:	afb30238 	sw	s3,568(sp)
  5e3d90:	afb20234 	sw	s2,564(sp)
  5e3d94:	3c12007d 	lui	s2,0x7d
  5e3d98:	afb10230 	sw	s1,560(sp)
  5e3d9c:	00808821 	move	s1,a0
  5e3da0:	afb0022c 	sw	s0,556(sp)
  5e3da4:	0c1506a9 	jal	0x541aa4
  5e3da8:	afa00018 	sw	zero,24(sp)
  5e3dac:	0c1506a9 	jal	0x541aa4
  5e3db0:	00408021 	move	s0,v0
  5e3db4:	3042001f 	andi	v0,v0,0x1f
  5e3db8:	00108143 	sra	s0,s0,0x5
  5e3dbc:	0002202b 	sltu	a0,zero,v0
  5e3dc0:	02042021 	addu	a0,s0,a0
  5e3dc4:	24050004 	li	a1,4
  5e3dc8:	0c1020a8 	jal	0x4082a0
  5e3dcc:	24060aa2 	li	a2,2722
  5e3dd0:	10400041 	beqz	v0,0x5e3ed8
  5e3dd4:	00409821 	move	s3,v0
  5e3dd8:	26856acc 	addiu	a1,s4,27340
  5e3ddc:	0c101eac 	jal	0x407ab0
  5e3de0:	02202021 	move	a0,s1
  5e3de4:	10400081 	beqz	v0,0x5e3fec
  5e3de8:	00408021 	move	s0,v0
  5e3dec:	0c101bfc 	jal	0x406ff0
  5e3df0:	00402021 	move	a0,v0
  5e3df4:	24030003 	li	v1,3
  5e3df8:	1043004e 	beq	v0,v1,0x5e3f34
  5e3dfc:	02002021 	move	a0,s0
  5e3e00:	0c101bfc 	jal	0x406ff0
  5e3e04:	00000000 	nop
  5e3e08:	24030002 	li	v1,2
  5e3e0c:	10430042 	beq	v0,v1,0x5e3f18
  5e3e10:	00000000 	nop
  5e3e14:	3c020075 	lui	v0,0x75
  5e3e18:	8c42be90 	lw	v0,-16752(v0)
  5e3e1c:	1440006b 	bnez	v0,0x5e3fcc
  5e3e20:	2411ffff 	li	s1,-1
  5e3e24:	8e42bee0 	lw	v0,-16672(s2)
  5e3e28:	1440005b 	bnez	v0,0x5e3f98
  5e3e2c:	27a4001c 	addiu	a0,sp,28
  5e3e30:	00002821 	move	a1,zero
  5e3e34:	0c101cf0 	jal	0x4073c0
  5e3e38:	24060205 	li	a2,517
  5e3e3c:	27a5001c 	addiu	a1,sp,28
  5e3e40:	0c17af88 	jal	0x5ebe20
  5e3e44:	02202021 	move	a0,s1
  5e3e48:	1040003e 	beqz	v0,0x5e3f44
  5e3e4c:	24040003 	li	a0,3
  5e3e50:	0c101d34 	jal	0x4074d0
  5e3e54:	02202021 	move	a0,s1
  5e3e58:	26856acc 	addiu	a1,s4,27340
  5e3e5c:	00403021 	move	a2,v0
  5e3e60:	0c101d78 	jal	0x4075e0
  5e3e64:	02a02021 	move	a0,s5
  5e3e68:	8e42bee0 	lw	v0,-16672(s2)
  5e3e6c:	1440000e 	bnez	v0,0x5e3ea8
  5e3e70:	00000000 	nop
  5e3e74:	12600004 	beqz	s3,0x5e3e88
  5e3e78:	8fbf0244 	lw	ra,580(sp)
  5e3e7c:	0c101f7c 	jal	0x407df0
  5e3e80:	02602021 	move	a0,s3
  5e3e84:	8fbf0244 	lw	ra,580(sp)
  5e3e88:	8fb50240 	lw	s5,576(sp)
  5e3e8c:	8fb4023c 	lw	s4,572(sp)
  5e3e90:	8fb30238 	lw	s3,568(sp)
  5e3e94:	8fb20234 	lw	s2,564(sp)
  5e3e98:	8fb10230 	lw	s1,560(sp)
  5e3e9c:	8fb0022c 	lw	s0,556(sp)
  5e3ea0:	03e00008 	jr	ra
  5e3ea4:	27bd0248 	addiu	sp,sp,584
  5e3ea8:	0c16276a 	jal	0x589da8
  5e3eac:	00000000 	nop
  5e3eb0:	1040fff0 	beqz	v0,0x5e3e74
  5e3eb4:	3c05006f 	lui	a1,0x6f
  5e3eb8:	3c04006f 	lui	a0,0x6f
  5e3ebc:	24845264 	addiu	a0,a0,21092
  5e3ec0:	24a57374 	addiu	a1,a1,29556
  5e3ec4:	24060ad1 	li	a2,2769
  5e3ec8:	0c101b74 	jal	0x406dd0
  5e3ecc:	02203821 	move	a3,s1
  5e3ed0:	08178f9d 	j	0x5e3e74
  5e3ed4:	00000000 	nop
  5e3ed8:	3c020075 	lui	v0,0x75
  5e3edc:	8c42fe70 	lw	v0,-400(v0)
  5e3ee0:	1040ffdb 	beqz	v0,0x5e3e50
  5e3ee4:	2411ffff 	li	s1,-1
  5e3ee8:	0c16276a 	jal	0x589da8
  5e3eec:	00000000 	nop
  5e3ef0:	1040ffd7 	beqz	v0,0x5e3e50
  5e3ef4:	3c04006f 	lui	a0,0x6f
  5e3ef8:	3c05006f 	lui	a1,0x6f
  5e3efc:	24843e54 	addiu	a0,a0,15956
  5e3f00:	24a57374 	addiu	a1,a1,29556
  5e3f04:	24060aa5 	li	a2,2725
  5e3f08:	0c101b74 	jal	0x406dd0
  5e3f0c:	00000000 	nop
  5e3f10:	08178f94 	j	0x5e3e50
  5e3f14:	00000000 	nop
  5e3f18:	0c101c54 	jal	0x407150
  5e3f1c:	02002021 	move	a0,s0
  5e3f20:	00602821 	move	a1,v1
  5e3f24:	0c101f0c 	jal	0x407c30
  5e3f28:	00402021 	move	a0,v0
  5e3f2c:	08178f89 	j	0x5e3e24
  5e3f30:	00408821 	move	s1,v0
  5e3f34:	0c101d10 	jal	0x407440
  5e3f38:	00000000 	nop
  5e3f3c:	08178f89 	j	0x5e3e24
  5e3f40:	00408821 	move	s1,v0
  5e3f44:	0c178462 	jal	0x5e1188
  5e3f48:	27a5001c 	addiu	a1,sp,28
  5e3f4c:	3c05005e 	lui	a1,0x5e
  5e3f50:	02202021 	move	a0,s1
  5e3f54:	0c17b3bb 	jal	0x5eceec
  5e3f58:	24a59320 	addiu	a1,a1,-27872
  5e3f5c:	2403ffff 	li	v1,-1
  5e3f60:	14430032 	bne	v0,v1,0x5e402c
  5e3f64:	3c020075 	lui	v0,0x75
  5e3f68:	8c42fe70 	lw	v0,-400(v0)
  5e3f6c:	1040ffb8 	beqz	v0,0x5e3e50
  5e3f70:	00000000 	nop
  5e3f74:	0c16276a 	jal	0x589da8
  5e3f78:	00000000 	nop
  5e3f7c:	1040ffb4 	beqz	v0,0x5e3e50
  5e3f80:	3c04006f 	lui	a0,0x6f
  5e3f84:	3c05006f 	lui	a1,0x6f
  5e3f88:	248447fc 	addiu	a0,a0,18428
  5e3f8c:	24a57374 	addiu	a1,a1,29556
  5e3f90:	08178fc2 	j	0x5e3f08
  5e3f94:	24060ab9 	li	a2,2745
  5e3f98:	0c16276a 	jal	0x589da8
  5e3f9c:	00000000 	nop
  5e3fa0:	5040ffa3 	beqzl	v0,0x5e3e30
  5e3fa4:	27a4001c 	addiu	a0,sp,28
  5e3fa8:	3c04006f 	lui	a0,0x6f
  5e3fac:	3c05006f 	lui	a1,0x6f
  5e3fb0:	24846664 	addiu	a0,a0,26212
  5e3fb4:	24a57374 	addiu	a1,a1,29556
  5e3fb8:	24060aad 	li	a2,2733
  5e3fbc:	0c101b74 	jal	0x406dd0
  5e3fc0:	02203821 	move	a3,s1
  5e3fc4:	08178f8c 	j	0x5e3e30
  5e3fc8:	27a4001c 	addiu	a0,sp,28
  5e3fcc:	3c040067 	lui	a0,0x67
  5e3fd0:	3c05006f 	lui	a1,0x6f
  5e3fd4:	24846a80 	addiu	a0,a0,27264
  5e3fd8:	24a57374 	addiu	a1,a1,29556
  5e3fdc:	0c101b74 	jal	0x406dd0
  5e3fe0:	24060aab 	li	a2,2731
  5e3fe4:	08178f8a 	j	0x5e3e28
  5e3fe8:	8e42bee0 	lw	v0,-16672(s2)
  5e3fec:	3c020075 	lui	v0,0x75
  5e3ff0:	8c42fe70 	lw	v0,-400(v0)
  5e3ff4:	1040ff96 	beqz	v0,0x5e3e50
  5e3ff8:	2411ffff 	li	s1,-1
  5e3ffc:	0c16276a 	jal	0x589da8
  5e4000:	00000000 	nop
  5e4004:	1040ff92 	beqz	v0,0x5e3e50
  5e4008:	3c04006f 	lui	a0,0x6f
  5e400c:	3c05006f 	lui	a1,0x6f
  5e4010:	248438cc 	addiu	a0,a0,14540
  5e4014:	24a57374 	addiu	a1,a1,29556
  5e4018:	24060aaa 	li	a2,2730
  5e401c:	0c101b74 	jal	0x406dd0
  5e4020:	26876acc 	addiu	a3,s4,27340
  5e4024:	08178f94 	j	0x5e3e50
  5e4028:	00000000 	nop
  5e402c:	0c1506a9 	jal	0x541aa4
  5e4030:	00000000 	nop
  5e4034:	0c1506a9 	jal	0x541aa4
  5e4038:	00408021 	move	s0,v0
  5e403c:	3042001f 	andi	v0,v0,0x1f
  5e4040:	00108143 	sra	s0,s0,0x5
  5e4044:	0002302b 	sltu	a2,zero,v0
  5e4048:	02063021 	addu	a2,s0,a2
  5e404c:	27a70018 	addiu	a3,sp,24
  5e4050:	02202021 	move	a0,s1
  5e4054:	0c17b5bb 	jal	0x5ed6ec
  5e4058:	02602821 	move	a1,s3
  5e405c:	10400011 	beqz	v0,0x5e40a4
  5e4060:	8fa50018 	lw	a1,24(sp)
  5e4064:	3c020075 	lui	v0,0x75
  5e4068:	8c42fe70 	lw	v0,-400(v0)
  5e406c:	1040000d 	beqz	v0,0x5e40a4
  5e4070:	00000000 	nop
  5e4074:	0c16276a 	jal	0x589da8
  5e4078:	00000000 	nop
  5e407c:	10400009 	beqz	v0,0x5e40a4
  5e4080:	8fa50018 	lw	a1,24(sp)
  5e4084:	3c04006f 	lui	a0,0x6f
  5e4088:	3c05006f 	lui	a1,0x6f
  5e408c:	248449cc 	addiu	a0,a0,18892
  5e4090:	24a57374 	addiu	a1,a1,29556
  5e4094:	24060abf 	li	a2,2751
  5e4098:	0c101b74 	jal	0x406dd0
  5e409c:	02203821 	move	a3,s1
  5e40a0:	8fa50018 	lw	a1,24(sp)
  5e40a4:	0c175fc6 	jal	0x5d7f18
  5e40a8:	02602021 	move	a0,s3
  5e40ac:	8e42bee0 	lw	v0,-16672(s2)
  5e40b0:	1440000a 	bnez	v0,0x5e40dc
  5e40b4:	00000000 	nop
  5e40b8:	0c17b23b 	jal	0x5ec8ec
  5e40bc:	02202021 	move	a0,s1
  5e40c0:	2403ffff 	li	v1,-1
  5e40c4:	5043ff62 	beql	v0,v1,0x5e3e50
  5e40c8:	2411ffff 	li	s1,-1
  5e40cc:	0c176bd3 	jal	0x5daf4c
  5e40d0:	00000000 	nop
  5e40d4:	08178f94 	j	0x5e3e50
  5e40d8:	00000000 	nop
  5e40dc:	0c16276a 	jal	0x589da8
  5e40e0:	00000000 	nop
  5e40e4:	1040fff4 	beqz	v0,0x5e40b8
  5e40e8:	3c04006f 	lui	a0,0x6f
  5e40ec:	3c05006f 	lui	a1,0x6f
  5e40f0:	24845224 	addiu	a0,a0,21028
  5e40f4:	24a57374 	addiu	a1,a1,29556
  5e40f8:	24060ac4 	li	a2,2756
  5e40fc:	0c101b74 	jal	0x406dd0
  5e4100:	02203821 	move	a3,s1
  5e4104:	0817902e 	j	0x5e40b8
  5e4108:	00000000 	nop
