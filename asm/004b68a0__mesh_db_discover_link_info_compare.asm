; func _mesh_db_discover_link_info_compare @ 0x004b68a0 size=0x70
  4b68a0:	10800014 	beqz	a0,0x4b68f4
  4b68a4:	00001021 	move	v0,zero
  4b68a8:	10a00012 	beqz	a1,0x4b68f4
  4b68ac:	24030001 	li	v1,1
  4b68b0:	90820004 	lbu	v0,4(a0)
  4b68b4:	50430011 	beql	v0,v1,0x4b68fc
  4b68b8:	90a60004 	lbu	a2,4(a1)
  4b68bc:	24060002 	li	a2,2
  4b68c0:	5046000a 	beql	v0,a2,0x4b68ec
  4b68c4:	90a60004 	lbu	a2,4(a1)
  4b68c8:	80840005 	lb	a0,5(a0)
  4b68cc:	80a30005 	lb	v1,5(a1)
  4b68d0:	10830008 	beq	a0,v1,0x4b68f4
  4b68d4:	00001021 	move	v0,zero
  4b68d8:	24020001 	li	v0,1
  4b68dc:	2405ffff 	li	a1,-1
  4b68e0:	0064182a 	slt	v1,v1,a0
  4b68e4:	03e00008 	jr	ra
  4b68e8:	00a3100a 	movz	v0,a1,v1
  4b68ec:	14c3fff6 	bne	a2,v1,0x4b68c8
  4b68f0:	2402ffff 	li	v0,-1
  4b68f4:	03e00008 	jr	ra
  4b68f8:	00000000 	nop
  4b68fc:	24030002 	li	v1,2
  4b6900:	14c3fff1 	bne	a2,v1,0x4b68c8
  4b6904:	24020001 	li	v0,1
  4b6908:	0812da3d 	j	0x4b68f4
  4b690c:	00000000 	nop
