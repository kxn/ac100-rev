; func cw_priv_image_update_result_free @ 0x005b3dd4 size=0x3c
  5b3dd4:	27bdffe0 	addiu	sp,sp,-32
  5b3dd8:	afb00018 	sw	s0,24(sp)
  5b3ddc:	00808021 	move	s0,a0
  5b3de0:	afbf001c 	sw	ra,28(sp)
  5b3de4:	8c840010 	lw	a0,16(a0)
  5b3de8:	10800005 	beqz	a0,0x5b3e00
  5b3dec:	8fbf001c 	lw	ra,28(sp)
  5b3df0:	0c101f7c 	jal	0x407df0
  5b3df4:	00000000 	nop
  5b3df8:	ae000010 	sw	zero,16(s0)
  5b3dfc:	8fbf001c 	lw	ra,28(sp)
  5b3e00:	00001021 	move	v0,zero
  5b3e04:	8fb00018 	lw	s0,24(sp)
  5b3e08:	03e00008 	jr	ra
  5b3e0c:	27bd0020 	addiu	sp,sp,32
