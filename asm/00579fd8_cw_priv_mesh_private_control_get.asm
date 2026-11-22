; func cw_priv_mesh_private_control_get @ 0x00579fd8 size=0x60
  579fd8:	27bdffe0 	addiu	sp,sp,-32
  579fdc:	00001021 	move	v0,zero
  579fe0:	afb00018 	sw	s0,24(sp)
  579fe4:	30b0ffff 	andi	s0,a1,0xffff
  579fe8:	1080000f 	beqz	a0,0x57a028
  579fec:	afbf001c 	sw	ra,28(sp)
  579ff0:	2e03001c 	sltiu	v1,s0,28
  579ff4:	1060000d 	beqz	v1,0x57a02c
  579ff8:	8fbf001c 	lw	ra,28(sp)
  579ffc:	0c10206c 	jal	0x4081b0
  57a000:	00000000 	nop
  57a004:	10400009 	beqz	v0,0x57a02c
  57a008:	8fbf001c 	lw	ra,28(sp)
  57a00c:	9443000c 	lhu	v1,12(v0)
  57a010:	50700005 	beql	v1,s0,0x57a028
  57a014:	8c420010 	lw	v0,16(v0)
  57a018:	0c1021a0 	jal	0x408680
  57a01c:	00402021 	move	a0,v0
  57a020:	5440fffb 	bnezl	v0,0x57a010
  57a024:	9443000c 	lhu	v1,12(v0)
  57a028:	8fbf001c 	lw	ra,28(sp)
  57a02c:	8fb00018 	lw	s0,24(sp)
  57a030:	03e00008 	jr	ra
  57a034:	27bd0020 	addiu	sp,sp,32
