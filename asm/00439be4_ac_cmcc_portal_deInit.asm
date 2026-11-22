; func ac_cmcc_portal_deInit @ 0x00439be4 size=0x7c
  439be4:	27bdffe0 	addiu	sp,sp,-32
  439be8:	afb00018 	sw	s0,24(sp)
  439bec:	afbf001c 	sw	ra,28(sp)
  439bf0:	0c10cc4f 	jal	0x43313c
  439bf4:	3c100073 	lui	s0,0x73
  439bf8:	8e041254 	lw	a0,4692(s0)
  439bfc:	58800006 	blezl	a0,0x439c18
  439c00:	3c100073 	lui	s0,0x73
  439c04:	0c101be8 	jal	0x406fa0
  439c08:	00000000 	nop
  439c0c:	2402ffff 	li	v0,-1
  439c10:	ae021254 	sw	v0,4692(s0)
  439c14:	3c100073 	lui	s0,0x73
  439c18:	8e041258 	lw	a0,4696(s0)
  439c1c:	58800006 	blezl	a0,0x439c38
  439c20:	3c100076 	lui	s0,0x76
  439c24:	0c101be8 	jal	0x406fa0
  439c28:	00000000 	nop
  439c2c:	2402ffff 	li	v0,-1
  439c30:	ae021258 	sw	v0,4696(s0)
  439c34:	3c100076 	lui	s0,0x76
  439c38:	8e04a1c4 	lw	a0,-24124(s0)
  439c3c:	10800005 	beqz	a0,0x439c54
  439c40:	8fbf001c 	lw	ra,28(sp)
  439c44:	0c101f7c 	jal	0x407df0
  439c48:	00000000 	nop
  439c4c:	ae00a1c4 	sw	zero,-24124(s0)
  439c50:	8fbf001c 	lw	ra,28(sp)
  439c54:	8fb00018 	lw	s0,24(sp)
  439c58:	03e00008 	jr	ra
  439c5c:	27bd0020 	addiu	sp,sp,32
