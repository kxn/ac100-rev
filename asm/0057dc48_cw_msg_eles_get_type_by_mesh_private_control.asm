; func cw_msg_eles_get_type_by_mesh_private_control @ 0x0057dc48 size=0x7c
  57dc48:	27bdffd8 	addiu	sp,sp,-40
  57dc4c:	afb10020 	sw	s1,32(sp)
  57dc50:	00808821 	move	s1,a0
  57dc54:	afb0001c 	sw	s0,28(sp)
  57dc58:	00a08021 	move	s0,a1
  57dc5c:	10800007 	beqz	a0,0x57dc7c
  57dc60:	afbf0024 	sw	ra,36(sp)
  57dc64:	10a00006 	beqz	a1,0x57dc80
  57dc68:	8fbf0024 	lw	ra,36(sp)
  57dc6c:	0c101ff8 	jal	0x407fe0
  57dc70:	00a02021 	move	a0,a1
  57dc74:	14400006 	bnez	v0,0x57dc90
  57dc78:	00000000 	nop
  57dc7c:	8fbf0024 	lw	ra,36(sp)
  57dc80:	8fb10020 	lw	s1,32(sp)
  57dc84:	8fb0001c 	lw	s0,28(sp)
  57dc88:	03e00008 	jr	ra
  57dc8c:	27bd0028 	addiu	sp,sp,40
  57dc90:	0c10206c 	jal	0x4081b0
  57dc94:	02002021 	move	a0,s0
  57dc98:	0815f72d 	j	0x57dcb4
  57dc9c:	00000000 	nop
  57dca0:	8605000c 	lh	a1,12(s0)
  57dca4:	0c1652a1 	jal	0x594a84
  57dca8:	02202021 	move	a0,s1
  57dcac:	0c1021a0 	jal	0x408680
  57dcb0:	02002021 	move	a0,s0
  57dcb4:	1440fffa 	bnez	v0,0x57dca0
  57dcb8:	00408021 	move	s0,v0
  57dcbc:	0815f720 	j	0x57dc80
  57dcc0:	8fbf0024 	lw	ra,36(sp)
	...
