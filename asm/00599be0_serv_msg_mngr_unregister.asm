; func serv_msg_mngr_unregister @ 0x00599be0 size=0x98
  599be0:	27bdffd8 	addiu	sp,sp,-40
  599be4:	afb20020 	sw	s2,32(sp)
  599be8:	30b2ffff 	andi	s2,a1,0xffff
  599bec:	afb1001c 	sw	s1,28(sp)
  599bf0:	00c08821 	move	s1,a2
  599bf4:	afbf0024 	sw	ra,36(sp)
  599bf8:	0c1666e2 	jal	0x599b88
  599bfc:	afb00018 	sw	s0,24(sp)
  599c00:	00402021 	move	a0,v0
  599c04:	10800010 	beqz	a0,0x599c48
  599c08:	2402ffff 	li	v0,-1
  599c0c:	0c10206c 	jal	0x4081b0
  599c10:	24840004 	addiu	a0,a0,4
  599c14:	0816670f 	j	0x599c3c
  599c18:	00000000 	nop
  599c1c:	9602000c 	lhu	v0,12(s0)
  599c20:	14520004 	bne	v0,s2,0x599c34
  599c24:	02002021 	move	a0,s0
  599c28:	8e020010 	lw	v0,16(s0)
  599c2c:	1051000c 	beq	v0,s1,0x599c60
  599c30:	00000000 	nop
  599c34:	0c1021a0 	jal	0x408680
  599c38:	00000000 	nop
  599c3c:	1440fff7 	bnez	v0,0x599c1c
  599c40:	00408021 	move	s0,v0
  599c44:	00001021 	move	v0,zero
  599c48:	8fbf0024 	lw	ra,36(sp)
  599c4c:	8fb20020 	lw	s2,32(sp)
  599c50:	8fb1001c 	lw	s1,28(sp)
  599c54:	8fb00018 	lw	s0,24(sp)
  599c58:	03e00008 	jr	ra
  599c5c:	27bd0028 	addiu	sp,sp,40
  599c60:	0c102140 	jal	0x408500
  599c64:	00000000 	nop
  599c68:	0c101f7c 	jal	0x407df0
  599c6c:	02002021 	move	a0,s0
  599c70:	08166712 	j	0x599c48
  599c74:	00001021 	move	v0,zero
