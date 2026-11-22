; func cw_priv_vap_info_list_length @ 0x005ca4f0 size=0x44
  5ca4f0:	8c830004 	lw	v1,4(a0)
  5ca4f4:	1060000d 	beqz	v1,0x5ca52c
  5ca4f8:	24020001 	li	v0,1
  5ca4fc:	90850000 	lbu	a1,0(a0)
  5ca500:	00602021 	move	a0,v1
  5ca504:	08172948 	j	0x5ca520
  5ca508:	00001821 	move	v1,zero
  5ca50c:	9486fff0 	lhu	a2,-16(a0)
  5ca510:	24630001 	addiu	v1,v1,1
  5ca514:	24c60010 	addiu	a2,a2,16
  5ca518:	00461021 	addu	v0,v0,a2
  5ca51c:	3042ffff 	andi	v0,v0,0xffff
  5ca520:	0065302a 	slt	a2,v1,a1
  5ca524:	14c0fff9 	bnez	a2,0x5ca50c
  5ca528:	24840020 	addiu	a0,a0,32
  5ca52c:	03e00008 	jr	ra
  5ca530:	00000000 	nop
