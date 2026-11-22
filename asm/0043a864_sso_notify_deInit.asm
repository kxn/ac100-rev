; func sso_notify_deInit @ 0x0043a864 size=0x2c
  43a864:	27bdffe0 	addiu	sp,sp,-32
  43a868:	afb00018 	sw	s0,24(sp)
  43a86c:	3c100076 	lui	s0,0x76
  43a870:	afbf001c 	sw	ra,28(sp)
  43a874:	0c1020d8 	jal	0x408360
  43a878:	8e04a2dc 	lw	a0,-23844(s0)
  43a87c:	8fbf001c 	lw	ra,28(sp)
  43a880:	ae00a2dc 	sw	zero,-23844(s0)
  43a884:	8fb00018 	lw	s0,24(sp)
  43a888:	03e00008 	jr	ra
  43a88c:	27bd0020 	addiu	sp,sp,32
