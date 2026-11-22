; func mesh_clear_discover_list @ 0x004bd8cc size=0x28
  4bd8cc:	27bdffe0 	addiu	sp,sp,-32
  4bd8d0:	3c020073 	lui	v0,0x73
  4bd8d4:	2403ffff 	li	v1,-1
  4bd8d8:	00002021 	move	a0,zero
  4bd8dc:	afbf001c 	sw	ra,28(sp)
  4bd8e0:	0c12e486 	jal	0x4b9218
  4bd8e4:	ac431a94 	sw	v1,6804(v0)
  4bd8e8:	8fbf001c 	lw	ra,28(sp)
  4bd8ec:	0812e7e1 	j	0x4b9f84
  4bd8f0:	27bd0020 	addiu	sp,sp,32
