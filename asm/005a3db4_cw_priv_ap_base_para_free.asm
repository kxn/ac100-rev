; func cw_priv_ap_base_para_free @ 0x005a3db4 size=0x3c
  5a3db4:	27bdffe0 	addiu	sp,sp,-32
  5a3db8:	afb00018 	sw	s0,24(sp)
  5a3dbc:	00808021 	move	s0,a0
  5a3dc0:	afbf001c 	sw	ra,28(sp)
  5a3dc4:	8c840010 	lw	a0,16(a0)
  5a3dc8:	10800005 	beqz	a0,0x5a3de0
  5a3dcc:	8fbf001c 	lw	ra,28(sp)
  5a3dd0:	0c101f7c 	jal	0x407df0
  5a3dd4:	00000000 	nop
  5a3dd8:	ae000010 	sw	zero,16(s0)
  5a3ddc:	8fbf001c 	lw	ra,28(sp)
  5a3de0:	00001021 	move	v0,zero
  5a3de4:	8fb00018 	lw	s0,24(sp)
  5a3de8:	03e00008 	jr	ra
  5a3dec:	27bd0020 	addiu	sp,sp,32
