; func sensor_test_db_stage_nested_mem_free @ 0x0050284c size=0x7c
  50284c:	27bdffe0 	addiu	sp,sp,-32
  502850:	afb00018 	sw	s0,24(sp)
  502854:	00808021 	move	s0,a0
  502858:	10800013 	beqz	a0,0x5028a8
  50285c:	afbf001c 	sw	ra,28(sp)
  502860:	8c840004 	lw	a0,4(a0)
  502864:	50800005 	beqzl	a0,0x50287c
  502868:	8e04000c 	lw	a0,12(s0)
  50286c:	92020011 	lbu	v0,17(s0)
  502870:	14400011 	bnez	v0,0x5028b8
  502874:	00000000 	nop
  502878:	8e04000c 	lw	a0,12(s0)
  50287c:	50800005 	beqzl	a0,0x502894
  502880:	8e040008 	lw	a0,8(s0)
  502884:	0c101f7c 	jal	0x407df0
  502888:	00000000 	nop
  50288c:	ae00000c 	sw	zero,12(s0)
  502890:	8e040008 	lw	a0,8(s0)
  502894:	10800005 	beqz	a0,0x5028ac
  502898:	8fbf001c 	lw	ra,28(sp)
  50289c:	0c101f7c 	jal	0x407df0
  5028a0:	00000000 	nop
  5028a4:	ae000008 	sw	zero,8(s0)
  5028a8:	8fbf001c 	lw	ra,28(sp)
  5028ac:	8fb00018 	lw	s0,24(sp)
  5028b0:	03e00008 	jr	ra
  5028b4:	27bd0020 	addiu	sp,sp,32
  5028b8:	0c101f7c 	jal	0x407df0
  5028bc:	00000000 	nop
  5028c0:	08140a1e 	j	0x502878
  5028c4:	ae000004 	sw	zero,4(s0)
