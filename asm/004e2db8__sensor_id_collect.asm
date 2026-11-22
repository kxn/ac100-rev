; func _sensor_id_collect @ 0x004e2db8 size=0x44
  4e2db8:	10a00006 	beqz	a1,0x4e2dd4
  4e2dbc:	24020002 	li	v0,2
  4e2dc0:	8ca30000 	lw	v1,0(a1)
  4e2dc4:	8ca60004 	lw	a2,4(a1)
  4e2dc8:	0066302a 	slt	a2,v1,a2
  4e2dcc:	54c00003 	bnezl	a2,0x4e2ddc
  4e2dd0:	8ca60008 	lw	a2,8(a1)
  4e2dd4:	03e00008 	jr	ra
  4e2dd8:	00000000 	nop
  4e2ddc:	00031040 	sll	v0,v1,0x1
  4e2de0:	94840010 	lhu	a0,16(a0)
  4e2de4:	24630001 	addiu	v1,v1,1
  4e2de8:	00c21021 	addu	v0,a2,v0
  4e2dec:	a4440000 	sh	a0,0(v0)
  4e2df0:	00001021 	move	v0,zero
  4e2df4:	03e00008 	jr	ra
  4e2df8:	aca30000 	sw	v1,0(a1)
