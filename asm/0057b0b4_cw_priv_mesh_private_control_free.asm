; func cw_priv_mesh_private_control_free @ 0x0057b0b4 size=0x3c
  57b0b4:	27bdffe0 	addiu	sp,sp,-32
  57b0b8:	afb00018 	sw	s0,24(sp)
  57b0bc:	00808021 	move	s0,a0
  57b0c0:	afbf001c 	sw	ra,28(sp)
  57b0c4:	8c840010 	lw	a0,16(a0)
  57b0c8:	10800005 	beqz	a0,0x57b0e0
  57b0cc:	8fbf001c 	lw	ra,28(sp)
  57b0d0:	0c15ec0e 	jal	0x57b038
  57b0d4:	00000000 	nop
  57b0d8:	ae000010 	sw	zero,16(s0)
  57b0dc:	8fbf001c 	lw	ra,28(sp)
  57b0e0:	00001021 	move	v0,zero
  57b0e4:	8fb00018 	lw	s0,24(sp)
  57b0e8:	03e00008 	jr	ra
  57b0ec:	27bd0020 	addiu	sp,sp,32
