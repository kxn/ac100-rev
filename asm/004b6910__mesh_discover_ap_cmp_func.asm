; func _mesh_discover_ap_cmp_func @ 0x004b6910 size=0x30
  4b6910:	27bdffe0 	addiu	sp,sp,-32
  4b6914:	00001021 	move	v0,zero
  4b6918:	10800006 	beqz	a0,0x4b6934
  4b691c:	afbf001c 	sw	ra,28(sp)
  4b6920:	10a00004 	beqz	a1,0x4b6934
  4b6924:	2484000c 	addiu	a0,a0,12
  4b6928:	0c101e4c 	jal	0x407930
  4b692c:	24060006 	li	a2,6
  4b6930:	2c420001 	sltiu	v0,v0,1
  4b6934:	8fbf001c 	lw	ra,28(sp)
  4b6938:	03e00008 	jr	ra
  4b693c:	27bd0020 	addiu	sp,sp,32
