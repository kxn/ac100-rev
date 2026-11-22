; func cw_msg_eles_get_type_by_wtp_board @ 0x00583bd0 size=0x60
  583bd0:	27bdffd8 	addiu	sp,sp,-40
  583bd4:	afb10020 	sw	s1,32(sp)
  583bd8:	00808821 	move	s1,a0
  583bdc:	afbf0024 	sw	ra,36(sp)
  583be0:	1080000e 	beqz	a0,0x583c1c
  583be4:	afb0001c 	sw	s0,28(sp)
  583be8:	10a0000d 	beqz	a1,0x583c20
  583bec:	8fbf0024 	lw	ra,36(sp)
  583bf0:	0c10206c 	jal	0x4081b0
  583bf4:	24a40004 	addiu	a0,a1,4
  583bf8:	08160f05 	j	0x583c14
  583bfc:	00000000 	nop
  583c00:	8605000c 	lh	a1,12(s0)
  583c04:	0c1652a1 	jal	0x594a84
  583c08:	02202021 	move	a0,s1
  583c0c:	0c1021a0 	jal	0x408680
  583c10:	02002021 	move	a0,s0
  583c14:	1440fffa 	bnez	v0,0x583c00
  583c18:	00408021 	move	s0,v0
  583c1c:	8fbf0024 	lw	ra,36(sp)
  583c20:	8fb10020 	lw	s1,32(sp)
  583c24:	8fb0001c 	lw	s0,28(sp)
  583c28:	03e00008 	jr	ra
  583c2c:	27bd0028 	addiu	sp,sp,40
