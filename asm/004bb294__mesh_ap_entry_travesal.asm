; func _mesh_ap_entry_travesal @ 0x004bb294 size=0x44
  4bb294:	27bdffe0 	addiu	sp,sp,-32
  4bb298:	3c06004c 	lui	a2,0x4c
  4bb29c:	00a03821 	move	a3,a1
  4bb2a0:	afbf001c 	sw	ra,28(sp)
  4bb2a4:	00002821 	move	a1,zero
  4bb2a8:	94840010 	lhu	a0,16(a0)
  4bb2ac:	0c12de5f 	jal	0x4b797c
  4bb2b0:	24c6b32c 	addiu	a2,a2,-19668
  4bb2b4:	24030001 	li	v1,1
  4bb2b8:	10430003 	beq	v0,v1,0x4bb2c8
  4bb2bc:	38420002 	xori	v0,v0,0x2
  4bb2c0:	24030002 	li	v1,2
  4bb2c4:	0002180b 	movn	v1,zero,v0
  4bb2c8:	8fbf001c 	lw	ra,28(sp)
  4bb2cc:	00601021 	move	v0,v1
  4bb2d0:	03e00008 	jr	ra
  4bb2d4:	27bd0020 	addiu	sp,sp,32
