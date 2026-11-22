; func cw_priv_mesh_public_control_free @ 0x005b6884 size=0x3c
  5b6884:	27bdffe0 	addiu	sp,sp,-32
  5b6888:	afb00018 	sw	s0,24(sp)
  5b688c:	00808021 	move	s0,a0
  5b6890:	afbf001c 	sw	ra,28(sp)
  5b6894:	8c840010 	lw	a0,16(a0)
  5b6898:	10800005 	beqz	a0,0x5b68b0
  5b689c:	8fbf001c 	lw	ra,28(sp)
  5b68a0:	0c16d9fd 	jal	0x5b67f4
  5b68a4:	00000000 	nop
  5b68a8:	ae000010 	sw	zero,16(s0)
  5b68ac:	8fbf001c 	lw	ra,28(sp)
  5b68b0:	00001021 	move	v0,zero
  5b68b4:	8fb00018 	lw	s0,24(sp)
  5b68b8:	03e00008 	jr	ra
  5b68bc:	27bd0020 	addiu	sp,sp,32
