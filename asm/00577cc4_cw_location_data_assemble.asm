; func cw_location_data_assemble @ 0x00577cc4 size=0xbc
  577cc4:	27bdffd8 	addiu	sp,sp,-40
  577cc8:	afb1001c 	sw	s1,28(sp)
  577ccc:	00808821 	move	s1,a0
  577cd0:	afb00018 	sw	s0,24(sp)
  577cd4:	00a08021 	move	s0,a1
  577cd8:	afbf0024 	sw	ra,36(sp)
  577cdc:	afb20020 	sw	s2,32(sp)
  577ce0:	8ca20010 	lw	v0,16(a1)
  577ce4:	8c450004 	lw	a1,4(v0)
  577ce8:	10a00005 	beqz	a1,0x577d00
  577cec:	94920004 	lhu	s2,4(a0)
  577cf0:	94420000 	lhu	v0,0(v0)
  577cf4:	9606000e 	lhu	a2,14(s0)
  577cf8:	10c20017 	beq	a2,v0,0x577d58
  577cfc:	00000000 	nop
  577d00:	3c020075 	lui	v0,0x75
  577d04:	8c42cf58 	lw	v0,-12456(v0)
  577d08:	10400005 	beqz	v0,0x577d20
  577d0c:	2410ffff 	li	s0,-1
  577d10:	0c16276a 	jal	0x589da8
  577d14:	00000000 	nop
  577d18:	14400008 	bnez	v0,0x577d3c
  577d1c:	3c04006e 	lui	a0,0x6e
  577d20:	8fbf0024 	lw	ra,36(sp)
  577d24:	02001021 	move	v0,s0
  577d28:	8fb20020 	lw	s2,32(sp)
  577d2c:	8fb1001c 	lw	s1,28(sp)
  577d30:	8fb00018 	lw	s0,24(sp)
  577d34:	03e00008 	jr	ra
  577d38:	27bd0028 	addiu	sp,sp,40
  577d3c:	3c05006e 	lui	a1,0x6e
  577d40:	248492b4 	addiu	a0,a0,-27980
  577d44:	24a59318 	addiu	a1,a1,-27880
  577d48:	0c101b74 	jal	0x406dd0
  577d4c:	24060095 	li	a2,149
  577d50:	0815df49 	j	0x577d24
  577d54:	8fbf0024 	lw	ra,36(sp)
  577d58:	0c15c856 	jal	0x572158
  577d5c:	00000000 	nop
  577d60:	96220004 	lhu	v0,4(s1)
  577d64:	00529023 	subu	s2,v0,s2
  577d68:	9602000e 	lhu	v0,14(s0)
  577d6c:	02428026 	xor	s0,s2,v0
  577d70:	2402ffff 	li	v0,-1
  577d74:	0010100a 	movz	v0,zero,s0
  577d78:	0815df48 	j	0x577d20
  577d7c:	00408021 	move	s0,v0
