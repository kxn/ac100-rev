; func cw_wtp_static_ip_address_information_create @ 0x00586e60 size=0xdc
  586e60:	27bdffd8 	addiu	sp,sp,-40
  586e64:	24050010 	li	a1,16
  586e68:	afb0001c 	sw	s0,28(sp)
  586e6c:	afbf0024 	sw	ra,36(sp)
  586e70:	0c15c8cc 	jal	0x572330
  586e74:	afb10020 	sw	s1,32(sp)
  586e78:	1040000d 	beqz	v0,0x586eb0
  586e7c:	00408021 	move	s0,v0
  586e80:	24040031 	li	a0,49
  586e84:	2405000d 	li	a1,13
  586e88:	0c15c943 	jal	0x57250c
  586e8c:	00403021 	move	a2,v0
  586e90:	10400017 	beqz	v0,0x586ef0
  586e94:	00408821 	move	s1,v0
  586e98:	8fbf0024 	lw	ra,36(sp)
  586e9c:	02201021 	move	v0,s1
  586ea0:	8fb10020 	lw	s1,32(sp)
  586ea4:	8fb0001c 	lw	s0,28(sp)
  586ea8:	03e00008 	jr	ra
  586eac:	27bd0028 	addiu	sp,sp,40
  586eb0:	3c020075 	lui	v0,0x75
  586eb4:	8c42cf58 	lw	v0,-12456(v0)
  586eb8:	1040fff7 	beqz	v0,0x586e98
  586ebc:	00008821 	move	s1,zero
  586ec0:	0c16276a 	jal	0x589da8
  586ec4:	00000000 	nop
  586ec8:	5040fff4 	beqzl	v0,0x586e9c
  586ecc:	8fbf0024 	lw	ra,36(sp)
  586ed0:	3c04006e 	lui	a0,0x6e
  586ed4:	3c05006e 	lui	a1,0x6e
  586ed8:	248485d4 	addiu	a0,a0,-31276
  586edc:	24a5dbe0 	addiu	a1,a1,-9248
  586ee0:	0c101b74 	jal	0x406dd0
  586ee4:	240600af 	li	a2,175
  586ee8:	08161ba7 	j	0x586e9c
  586eec:	8fbf0024 	lw	ra,36(sp)
  586ef0:	3c020075 	lui	v0,0x75
  586ef4:	8c42cf58 	lw	v0,-12456(v0)
  586ef8:	14400005 	bnez	v0,0x586f10
  586efc:	00000000 	nop
  586f00:	0c101f7c 	jal	0x407df0
  586f04:	02002021 	move	a0,s0
  586f08:	08161ba7 	j	0x586e9c
  586f0c:	8fbf0024 	lw	ra,36(sp)
  586f10:	0c16276a 	jal	0x589da8
  586f14:	00000000 	nop
  586f18:	1040fff9 	beqz	v0,0x586f00
  586f1c:	3c04006d 	lui	a0,0x6d
  586f20:	3c05006e 	lui	a1,0x6e
  586f24:	248447f0 	addiu	a0,a0,18416
  586f28:	24a5dbe0 	addiu	a1,a1,-9248
  586f2c:	0c101b74 	jal	0x406dd0
  586f30:	240600b7 	li	a2,183
  586f34:	08161bc0 	j	0x586f00
  586f38:	00000000 	nop
