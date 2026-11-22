; func cw_priv_mesh2_join_type_free @ 0x005b5bdc size=0x3c
  5b5bdc:	27bdffe0 	addiu	sp,sp,-32
  5b5be0:	afb00018 	sw	s0,24(sp)
  5b5be4:	00808021 	move	s0,a0
  5b5be8:	afbf001c 	sw	ra,28(sp)
  5b5bec:	8c840010 	lw	a0,16(a0)
  5b5bf0:	10800005 	beqz	a0,0x5b5c08
  5b5bf4:	8fbf001c 	lw	ra,28(sp)
  5b5bf8:	0c101f7c 	jal	0x407df0
  5b5bfc:	00000000 	nop
  5b5c00:	ae000010 	sw	zero,16(s0)
  5b5c04:	8fbf001c 	lw	ra,28(sp)
  5b5c08:	00001021 	move	v0,zero
  5b5c0c:	8fb00018 	lw	s0,24(sp)
  5b5c10:	03e00008 	jr	ra
  5b5c14:	27bd0020 	addiu	sp,sp,32
