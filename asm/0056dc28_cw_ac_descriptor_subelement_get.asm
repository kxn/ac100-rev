; func cw_ac_descriptor_subelement_get @ 0x0056dc28 size=0xd4
  56dc28:	27bdffd8 	addiu	sp,sp,-40
  56dc2c:	afb10020 	sw	s1,32(sp)
  56dc30:	30b1ffff 	andi	s1,a1,0xffff
  56dc34:	afbf0024 	sw	ra,36(sp)
  56dc38:	1080001a 	beqz	a0,0x56dca4
  56dc3c:	afb0001c 	sw	s0,28(sp)
  56dc40:	0c10206c 	jal	0x4081b0
  56dc44:	2484000c 	addiu	a0,a0,12
  56dc48:	50400009 	beqzl	v0,0x56dc70
  56dc4c:	3c020075 	lui	v0,0x75
  56dc50:	94430010 	lhu	v1,16(v0)
  56dc54:	5071000d 	beql	v1,s1,0x56dc8c
  56dc58:	00408021 	move	s0,v0
  56dc5c:	0c1021a0 	jal	0x408680
  56dc60:	00402021 	move	a0,v0
  56dc64:	5440fffb 	bnezl	v0,0x56dc54
  56dc68:	94430010 	lhu	v1,16(v0)
  56dc6c:	3c020075 	lui	v0,0x75
  56dc70:	8c42cf58 	lw	v0,-12456(v0)
  56dc74:	10400005 	beqz	v0,0x56dc8c
  56dc78:	00008021 	move	s0,zero
  56dc7c:	0c16276a 	jal	0x589da8
  56dc80:	00000000 	nop
  56dc84:	14400015 	bnez	v0,0x56dcdc
  56dc88:	3c04006d 	lui	a0,0x6d
  56dc8c:	8fbf0024 	lw	ra,36(sp)
  56dc90:	02001021 	move	v0,s0
  56dc94:	8fb10020 	lw	s1,32(sp)
  56dc98:	8fb0001c 	lw	s0,28(sp)
  56dc9c:	03e00008 	jr	ra
  56dca0:	27bd0028 	addiu	sp,sp,40
  56dca4:	3c020075 	lui	v0,0x75
  56dca8:	8c42cf58 	lw	v0,-12456(v0)
  56dcac:	1040fff7 	beqz	v0,0x56dc8c
  56dcb0:	00008021 	move	s0,zero
  56dcb4:	0c16276a 	jal	0x589da8
  56dcb8:	00000000 	nop
  56dcbc:	5040fff4 	beqzl	v0,0x56dc90
  56dcc0:	8fbf0024 	lw	ra,36(sp)
  56dcc4:	3c04006d 	lui	a0,0x6d
  56dcc8:	3c05006d 	lui	a1,0x6d
  56dccc:	24846b24 	addiu	a0,a0,27428
  56dcd0:	24a56bc0 	addiu	a1,a1,27584
  56dcd4:	0815b73b 	j	0x56dcec
  56dcd8:	2406027c 	li	a2,636
  56dcdc:	3c05006d 	lui	a1,0x6d
  56dce0:	24846b48 	addiu	a0,a0,27464
  56dce4:	24a56bc0 	addiu	a1,a1,27584
  56dce8:	2406028a 	li	a2,650
  56dcec:	0c101b74 	jal	0x406dd0
  56dcf0:	00000000 	nop
  56dcf4:	0815b724 	j	0x56dc90
  56dcf8:	8fbf0024 	lw	ra,36(sp)
  56dcfc:	00000000 	nop
