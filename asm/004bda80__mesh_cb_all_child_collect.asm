; func _mesh_cb_all_child_collect @ 0x004bda80 size=0x44
  4bda80:	10a00006 	beqz	a1,0x4bda9c
  4bda84:	24020002 	li	v0,2
  4bda88:	8ca30000 	lw	v1,0(a1)
  4bda8c:	8ca60004 	lw	a2,4(a1)
  4bda90:	0066302a 	slt	a2,v1,a2
  4bda94:	54c00003 	bnezl	a2,0x4bdaa4
  4bda98:	8ca60008 	lw	a2,8(a1)
  4bda9c:	03e00008 	jr	ra
  4bdaa0:	00000000 	nop
  4bdaa4:	00031040 	sll	v0,v1,0x1
  4bdaa8:	94840010 	lhu	a0,16(a0)
  4bdaac:	24630001 	addiu	v1,v1,1
  4bdab0:	00c21021 	addu	v0,a2,v0
  4bdab4:	a4440000 	sh	a0,0(v0)
  4bdab8:	00001021 	move	v0,zero
  4bdabc:	03e00008 	jr	ra
  4bdac0:	aca30000 	sw	v1,0(a1)
