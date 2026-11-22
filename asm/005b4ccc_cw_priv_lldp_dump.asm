; func cw_priv_lldp_dump @ 0x005b4ccc size=0x3c
  5b4ccc:	27bdffd8 	addiu	sp,sp,-40
  5b4cd0:	afbf0024 	sw	ra,36(sp)
  5b4cd4:	8c820010 	lw	v0,16(a0)
  5b4cd8:	3c04006f 	lui	a0,0x6f
  5b4cdc:	2484c140 	addiu	a0,a0,-16064
  5b4ce0:	90450000 	lbu	a1,0(v0)
  5b4ce4:	90460001 	lbu	a2,1(v0)
  5b4ce8:	90470002 	lbu	a3,2(v0)
  5b4cec:	90420003 	lbu	v0,3(v0)
  5b4cf0:	0c101b74 	jal	0x406dd0
  5b4cf4:	afa20010 	sw	v0,16(sp)
  5b4cf8:	00001021 	move	v0,zero
  5b4cfc:	8fbf0024 	lw	ra,36(sp)
  5b4d00:	03e00008 	jr	ra
  5b4d04:	27bd0028 	addiu	sp,sp,40
