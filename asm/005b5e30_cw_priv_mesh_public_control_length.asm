; func cw_priv_mesh_public_control_length @ 0x005b5e30 size=0x20
  5b5e30:	94830008 	lhu	v1,8(a0)
  5b5e34:	24020006 	li	v0,6
  5b5e38:	94840000 	lhu	a0,0(a0)
  5b5e3c:	24630004 	addiu	v1,v1,4
  5b5e40:	70821002 	mul	v0,a0,v0
  5b5e44:	00621021 	addu	v0,v1,v0
  5b5e48:	03e00008 	jr	ra
  5b5e4c:	3042ffff 	andi	v0,v0,0xffff
