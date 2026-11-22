; func _mesh_cb_child_collect @ 0x004bda44 size=0x3c
  4bda44:	10a00005 	beqz	a1,0x4bda5c
  4bda48:	24020002 	li	v0,2
  4bda4c:	8ca30000 	lw	v1,0(a1)
  4bda50:	28660032 	slti	a2,v1,50
  4bda54:	54c00003 	bnezl	a2,0x4bda64
  4bda58:	00031040 	sll	v0,v1,0x1
  4bda5c:	03e00008 	jr	ra
  4bda60:	00000000 	nop
  4bda64:	9484000c 	lhu	a0,12(a0)
  4bda68:	24630001 	addiu	v1,v1,1
  4bda6c:	00a21021 	addu	v0,a1,v0
  4bda70:	a4440004 	sh	a0,4(v0)
  4bda74:	00001021 	move	v0,zero
  4bda78:	03e00008 	jr	ra
  4bda7c:	aca30000 	sw	v1,0(a1)
