; func mesh_child_rd_disable @ 0x004ac7f0 size=0x20
  4ac7f0:	27bdffe0 	addiu	sp,sp,-32
  4ac7f4:	afbf001c 	sw	ra,28(sp)
  4ac7f8:	0c18cf90 	jal	0x633e40
  4ac7fc:	00000000 	nop
  4ac800:	8fbf001c 	lw	ra,28(sp)
  4ac804:	0002102b 	sltu	v0,zero,v0
  4ac808:	03e00008 	jr	ra
  4ac80c:	27bd0020 	addiu	sp,sp,32
