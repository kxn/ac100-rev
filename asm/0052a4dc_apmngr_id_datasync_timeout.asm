; func apmngr_id_datasync_timeout @ 0x0052a4dc size=0x28
  52a4dc:	27bdffe0 	addiu	sp,sp,-32
  52a4e0:	afbf001c 	sw	ra,28(sp)
  52a4e4:	0c150cac 	jal	0x5432b0
  52a4e8:	00000000 	nop
  52a4ec:	3c020075 	lui	v0,0x75
  52a4f0:	8fbf001c 	lw	ra,28(sp)
  52a4f4:	2403ffff 	li	v1,-1
  52a4f8:	27bd0020 	addiu	sp,sp,32
  52a4fc:	03e00008 	jr	ra
  52a500:	ac43bf0c 	sw	v1,-16628(v0)
