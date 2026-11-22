; func mesh_db_single_ap_entry_parent_dump @ 0x004b83d4 size=0x30
  4b83d4:	27bdffd8 	addiu	sp,sp,-40
  4b83d8:	3c06004c 	lui	a2,0x4c
  4b83dc:	27a70018 	addiu	a3,sp,24
  4b83e0:	24050001 	li	a1,1
  4b83e4:	afbf0024 	sw	ra,36(sp)
  4b83e8:	24c68834 	addiu	a2,a2,-30668
  4b83ec:	afa00018 	sw	zero,24(sp)
  4b83f0:	0c12df03 	jal	0x4b7c0c
  4b83f4:	3084ffff 	andi	a0,a0,0xffff
  4b83f8:	8fbf0024 	lw	ra,36(sp)
  4b83fc:	03e00008 	jr	ra
  4b8400:	27bd0028 	addiu	sp,sp,40
