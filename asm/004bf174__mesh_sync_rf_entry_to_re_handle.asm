; func _mesh_sync_rf_entry_to_re_handle @ 0x004bf174 size=0x30
  4bf174:	3c06004c 	lui	a2,0x4c
  4bf178:	27bdffe0 	addiu	sp,sp,-32
  4bf17c:	00002821 	move	a1,zero
  4bf180:	24c6f094 	addiu	a2,a2,-3948
  4bf184:	00003821 	move	a3,zero
  4bf188:	afbf001c 	sw	ra,28(sp)
  4bf18c:	0c12de5f 	jal	0x4b797c
  4bf190:	3084ffff 	andi	a0,a0,0xffff
  4bf194:	00001021 	move	v0,zero
  4bf198:	8fbf001c 	lw	ra,28(sp)
  4bf19c:	03e00008 	jr	ra
  4bf1a0:	27bd0020 	addiu	sp,sp,32
