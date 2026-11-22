; func uac_wservice_uninit @ 0x005e0fa0 size=0xf0
  5e0fa0:	27bdffe0 	addiu	sp,sp,-32
  5e0fa4:	afbf001c 	sw	ra,28(sp)
  5e0fa8:	0c17a2f3 	jal	0x5e8bcc
  5e0fac:	afb00018 	sw	s0,24(sp)
  5e0fb0:	1040000d 	beqz	v0,0x5e0fe8
  5e0fb4:	3c020075 	lui	v0,0x75
  5e0fb8:	8c42fe70 	lw	v0,-400(v0)
  5e0fbc:	10400005 	beqz	v0,0x5e0fd4
  5e0fc0:	2410ffff 	li	s0,-1
  5e0fc4:	0c16276a 	jal	0x589da8
  5e0fc8:	00000000 	nop
  5e0fcc:	1440001a 	bnez	v0,0x5e1038
  5e0fd0:	3c04006f 	lui	a0,0x6f
  5e0fd4:	8fbf001c 	lw	ra,28(sp)
  5e0fd8:	02001021 	move	v0,s0
  5e0fdc:	8fb00018 	lw	s0,24(sp)
  5e0fe0:	03e00008 	jr	ra
  5e0fe4:	27bd0020 	addiu	sp,sp,32
  5e0fe8:	0c17e4b2 	jal	0x5f92c8
  5e0fec:	00000000 	nop
  5e0ff0:	10400016 	beqz	v0,0x5e104c
  5e0ff4:	3c020075 	lui	v0,0x75
  5e0ff8:	8c42fe70 	lw	v0,-400(v0)
  5e0ffc:	1040fff5 	beqz	v0,0x5e0fd4
  5e1000:	2410ffff 	li	s0,-1
  5e1004:	0c16276a 	jal	0x589da8
  5e1008:	00000000 	nop
  5e100c:	5040fff2 	beqzl	v0,0x5e0fd8
  5e1010:	8fbf001c 	lw	ra,28(sp)
  5e1014:	3c04006f 	lui	a0,0x6f
  5e1018:	3c05006f 	lui	a1,0x6f
  5e101c:	24846150 	addiu	a0,a0,24912
  5e1020:	24a57450 	addiu	a1,a1,29776
  5e1024:	240617fb 	li	a2,6139
  5e1028:	0c101b74 	jal	0x406dd0
  5e102c:	00000000 	nop
  5e1030:	081783f6 	j	0x5e0fd8
  5e1034:	8fbf001c 	lw	ra,28(sp)
  5e1038:	3c05006f 	lui	a1,0x6f
  5e103c:	24846110 	addiu	a0,a0,24848
  5e1040:	24a57450 	addiu	a1,a1,29776
  5e1044:	0817840a 	j	0x5e1028
  5e1048:	240617f5 	li	a2,6133
  5e104c:	0c17ac69 	jal	0x5eb1a4
  5e1050:	00008021 	move	s0,zero
  5e1054:	1040ffdf 	beqz	v0,0x5e0fd4
  5e1058:	3c020075 	lui	v0,0x75
  5e105c:	8c42fe70 	lw	v0,-400(v0)
  5e1060:	1040ffdc 	beqz	v0,0x5e0fd4
  5e1064:	2410ffff 	li	s0,-1
  5e1068:	0c16276a 	jal	0x589da8
  5e106c:	00000000 	nop
  5e1070:	5040ffd9 	beqzl	v0,0x5e0fd8
  5e1074:	8fbf001c 	lw	ra,28(sp)
  5e1078:	3c04006f 	lui	a0,0x6f
  5e107c:	3c05006f 	lui	a1,0x6f
  5e1080:	2484618c 	addiu	a0,a0,24972
  5e1084:	24a57450 	addiu	a1,a1,29776
  5e1088:	0817840a 	j	0x5e1028
  5e108c:	24061801 	li	a2,6145
