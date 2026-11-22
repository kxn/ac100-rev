; func cw_ac_name_assemble @ 0x0056ed0c size=0xbc
  56ed0c:	27bdffd8 	addiu	sp,sp,-40
  56ed10:	afb1001c 	sw	s1,28(sp)
  56ed14:	00808821 	move	s1,a0
  56ed18:	afb00018 	sw	s0,24(sp)
  56ed1c:	00a08021 	move	s0,a1
  56ed20:	afbf0024 	sw	ra,36(sp)
  56ed24:	afb20020 	sw	s2,32(sp)
  56ed28:	8ca20010 	lw	v0,16(a1)
  56ed2c:	8c450004 	lw	a1,4(v0)
  56ed30:	10a00005 	beqz	a1,0x56ed48
  56ed34:	94920004 	lhu	s2,4(a0)
  56ed38:	94420000 	lhu	v0,0(v0)
  56ed3c:	9606000e 	lhu	a2,14(s0)
  56ed40:	10c20017 	beq	a2,v0,0x56eda0
  56ed44:	00000000 	nop
  56ed48:	3c020075 	lui	v0,0x75
  56ed4c:	8c42cf58 	lw	v0,-12456(v0)
  56ed50:	10400005 	beqz	v0,0x56ed68
  56ed54:	2410ffff 	li	s0,-1
  56ed58:	0c16276a 	jal	0x589da8
  56ed5c:	00000000 	nop
  56ed60:	14400008 	bnez	v0,0x56ed84
  56ed64:	3c04006d 	lui	a0,0x6d
  56ed68:	8fbf0024 	lw	ra,36(sp)
  56ed6c:	02001021 	move	v0,s0
  56ed70:	8fb20020 	lw	s2,32(sp)
  56ed74:	8fb1001c 	lw	s1,28(sp)
  56ed78:	8fb00018 	lw	s0,24(sp)
  56ed7c:	03e00008 	jr	ra
  56ed80:	27bd0028 	addiu	sp,sp,40
  56ed84:	3c05006d 	lui	a1,0x6d
  56ed88:	248470e0 	addiu	a0,a0,28896
  56ed8c:	24a57134 	addiu	a1,a1,28980
  56ed90:	0c101b74 	jal	0x406dd0
  56ed94:	2406008d 	li	a2,141
  56ed98:	0815bb5b 	j	0x56ed6c
  56ed9c:	8fbf0024 	lw	ra,36(sp)
  56eda0:	0c15c856 	jal	0x572158
  56eda4:	00000000 	nop
  56eda8:	96220004 	lhu	v0,4(s1)
  56edac:	00529023 	subu	s2,v0,s2
  56edb0:	9602000e 	lhu	v0,14(s0)
  56edb4:	02428026 	xor	s0,s2,v0
  56edb8:	2402ffff 	li	v0,-1
  56edbc:	0010100a 	movz	v0,zero,s0
  56edc0:	0815bb5a 	j	0x56ed68
  56edc4:	00408021 	move	s0,v0
	...
