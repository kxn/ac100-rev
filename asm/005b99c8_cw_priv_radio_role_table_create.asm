; func cw_priv_radio_role_table_create @ 0x005b99c8 size=0x204
  5b99c8:	3c02007c 	lui	v0,0x7c
  5b99cc:	27bdffd8 	addiu	sp,sp,-40
  5b99d0:	8c425988 	lw	v0,22920(v0)
  5b99d4:	afb1001c 	sw	s1,28(sp)
  5b99d8:	00808821 	move	s1,a0
  5b99dc:	afbf0024 	sw	ra,36(sp)
  5b99e0:	afb20020 	sw	s2,32(sp)
  5b99e4:	14400023 	bnez	v0,0x5b9a74
  5b99e8:	afb00018 	sw	s0,24(sp)
  5b99ec:	24050008 	li	a1,8
  5b99f0:	0c15c8cc 	jal	0x572330
  5b99f4:	02202021 	move	a0,s1
  5b99f8:	10400038 	beqz	v0,0x5b9adc
  5b99fc:	00408021 	move	s0,v0
  5b9a00:	ac400004 	sw	zero,4(v0)
  5b9a04:	92220000 	lbu	v0,0(s1)
  5b9a08:	5040000c 	beqzl	v0,0x5b9a3c
  5b9a0c:	00008821 	move	s1,zero
  5b9a10:	8e320004 	lw	s2,4(s1)
  5b9a14:	12400055 	beqz	s2,0x5b9b6c
  5b9a18:	3c020075 	lui	v0,0x75
  5b9a1c:	0c16e621 	jal	0x5b9884
  5b9a20:	02202021 	move	a0,s1
  5b9a24:	02402021 	move	a0,s2
  5b9a28:	3045ffff 	andi	a1,v0,0xffff
  5b9a2c:	0c15c8cc 	jal	0x572330
  5b9a30:	00408821 	move	s1,v0
  5b9a34:	10400045 	beqz	v0,0x5b9b4c
  5b9a38:	ae020004 	sw	v0,4(s0)
  5b9a3c:	26250001 	addiu	a1,s1,1
  5b9a40:	2404007f 	li	a0,127
  5b9a44:	30a5ffff 	andi	a1,a1,0xffff
  5b9a48:	0c15c943 	jal	0x57250c
  5b9a4c:	02003021 	move	a2,s0
  5b9a50:	10400014 	beqz	v0,0x5b9aa4
  5b9a54:	00408821 	move	s1,v0
  5b9a58:	8fbf0024 	lw	ra,36(sp)
  5b9a5c:	02201021 	move	v0,s1
  5b9a60:	8fb20020 	lw	s2,32(sp)
  5b9a64:	8fb1001c 	lw	s1,28(sp)
  5b9a68:	8fb00018 	lw	s0,24(sp)
  5b9a6c:	03e00008 	jr	ra
  5b9a70:	27bd0028 	addiu	sp,sp,40
  5b9a74:	0c16276a 	jal	0x589da8
  5b9a78:	00000000 	nop
  5b9a7c:	5040ffdc 	beqzl	v0,0x5b99f0
  5b9a80:	24050008 	li	a1,8
  5b9a84:	3c04006f 	lui	a0,0x6f
  5b9a88:	3c05006f 	lui	a1,0x6f
  5b9a8c:	2484d33c 	addiu	a0,a0,-11460
  5b9a90:	24a5d3e0 	addiu	a1,a1,-11296
  5b9a94:	0c101b74 	jal	0x406dd0
  5b9a98:	2406010e 	li	a2,270
  5b9a9c:	0816e67c 	j	0x5b99f0
  5b9aa0:	24050008 	li	a1,8
  5b9aa4:	3c020075 	lui	v0,0x75
  5b9aa8:	8c42cf58 	lw	v0,-12456(v0)
  5b9aac:	1440001b 	bnez	v0,0x5b9b1c
  5b9ab0:	00000000 	nop
  5b9ab4:	8e040004 	lw	a0,4(s0)
  5b9ab8:	10800004 	beqz	a0,0x5b9acc
  5b9abc:	00000000 	nop
  5b9ac0:	0c101f7c 	jal	0x407df0
  5b9ac4:	00000000 	nop
  5b9ac8:	ae000004 	sw	zero,4(s0)
  5b9acc:	0c101f7c 	jal	0x407df0
  5b9ad0:	02002021 	move	a0,s0
  5b9ad4:	0816e697 	j	0x5b9a5c
  5b9ad8:	8fbf0024 	lw	ra,36(sp)
  5b9adc:	3c020075 	lui	v0,0x75
  5b9ae0:	8c42cf58 	lw	v0,-12456(v0)
  5b9ae4:	1040ffdc 	beqz	v0,0x5b9a58
  5b9ae8:	00008821 	move	s1,zero
  5b9aec:	0c16276a 	jal	0x589da8
  5b9af0:	00000000 	nop
  5b9af4:	5040ffd9 	beqzl	v0,0x5b9a5c
  5b9af8:	8fbf0024 	lw	ra,36(sp)
  5b9afc:	3c04006d 	lui	a0,0x6d
  5b9b00:	3c05006f 	lui	a1,0x6f
  5b9b04:	248434fc 	addiu	a0,a0,13564
  5b9b08:	24a5d3e0 	addiu	a1,a1,-11296
  5b9b0c:	0c101b74 	jal	0x406dd0
  5b9b10:	24060118 	li	a2,280
  5b9b14:	0816e697 	j	0x5b9a5c
  5b9b18:	8fbf0024 	lw	ra,36(sp)
  5b9b1c:	0c16276a 	jal	0x589da8
  5b9b20:	00000000 	nop
  5b9b24:	5040ffe4 	beqzl	v0,0x5b9ab8
  5b9b28:	8e040004 	lw	a0,4(s0)
  5b9b2c:	3c04006d 	lui	a0,0x6d
  5b9b30:	3c05006f 	lui	a1,0x6f
  5b9b34:	248447f0 	addiu	a0,a0,18416
  5b9b38:	24a5d3e0 	addiu	a1,a1,-11296
  5b9b3c:	0c101b74 	jal	0x406dd0
  5b9b40:	24060137 	li	a2,311
  5b9b44:	0816e6ae 	j	0x5b9ab8
  5b9b48:	8e040004 	lw	a0,4(s0)
  5b9b4c:	3c020075 	lui	v0,0x75
  5b9b50:	8c42cf58 	lw	v0,-12456(v0)
  5b9b54:	14400014 	bnez	v0,0x5b9ba8
  5b9b58:	00000000 	nop
  5b9b5c:	0c101f7c 	jal	0x407df0
  5b9b60:	02002021 	move	a0,s0
  5b9b64:	0816e696 	j	0x5b9a58
  5b9b68:	00008821 	move	s1,zero
  5b9b6c:	8c42cf58 	lw	v0,-12456(v0)
  5b9b70:	1040fffa 	beqz	v0,0x5b9b5c
  5b9b74:	00000000 	nop
  5b9b78:	0c16276a 	jal	0x589da8
  5b9b7c:	00000000 	nop
  5b9b80:	1040fff6 	beqz	v0,0x5b9b5c
  5b9b84:	3c04006e 	lui	a0,0x6e
  5b9b88:	3c05006f 	lui	a1,0x6f
  5b9b8c:	248480d8 	addiu	a0,a0,-32552
  5b9b90:	24a5d3e0 	addiu	a1,a1,-11296
  5b9b94:	24060123 	li	a2,291
  5b9b98:	0c101b74 	jal	0x406dd0
  5b9b9c:	00000000 	nop
  5b9ba0:	0816e6d7 	j	0x5b9b5c
  5b9ba4:	00000000 	nop
  5b9ba8:	0c16276a 	jal	0x589da8
  5b9bac:	00000000 	nop
  5b9bb0:	1040ffea 	beqz	v0,0x5b9b5c
  5b9bb4:	3c04006e 	lui	a0,0x6e
  5b9bb8:	3c05006f 	lui	a1,0x6f
  5b9bbc:	24848050 	addiu	a0,a0,-32688
  5b9bc0:	24a5d3e0 	addiu	a1,a1,-11296
  5b9bc4:	0816e6e6 	j	0x5b9b98
  5b9bc8:	2406012d 	li	a2,301
