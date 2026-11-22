; func wsta_db_print_ap_all @ 0x00639dbc size=0x80
  639dbc:	27bdffd8 	addiu	sp,sp,-40
  639dc0:	3c040067 	lui	a0,0x67
  639dc4:	afb10020 	sw	s1,32(sp)
  639dc8:	24846b8c 	addiu	a0,a0,27532
  639dcc:	3c11007d 	lui	s1,0x7d
  639dd0:	afbf0024 	sw	ra,36(sp)
  639dd4:	afb0001c 	sw	s0,28(sp)
  639dd8:	0c101dd4 	jal	0x407750
  639ddc:	00008021 	move	s0,zero
  639de0:	2622c6b8 	addiu	v0,s1,-14664
  639de4:	2405ffff 	li	a1,-1
  639de8:	0c1020b4 	jal	0x4082d0
  639dec:	8c440004 	lw	a0,4(v0)
  639df0:	0818e784 	j	0x639e10
  639df4:	00000000 	nop
  639df8:	8c64002c 	lw	a0,44(v1)
  639dfc:	00101080 	sll	v0,s0,0x2
  639e00:	02002821 	move	a1,s0
  639e04:	26100001 	addiu	s0,s0,1
  639e08:	0c18e704 	jal	0x639c10
  639e0c:	00822021 	addu	a0,a0,v0
  639e10:	0c1506a9 	jal	0x541aa4
  639e14:	00000000 	nop
  639e18:	0202102a 	slt	v0,s0,v0
  639e1c:	1440fff6 	bnez	v0,0x639df8
  639e20:	2623c6b8 	addiu	v1,s1,-14664
  639e24:	8fbf0024 	lw	ra,36(sp)
  639e28:	8fb10020 	lw	s1,32(sp)
  639e2c:	8fb0001c 	lw	s0,28(sp)
  639e30:	27bd0028 	addiu	sp,sp,40
  639e34:	08101fcc 	j	0x407f30
  639e38:	8c640004 	lw	a0,4(v1)
