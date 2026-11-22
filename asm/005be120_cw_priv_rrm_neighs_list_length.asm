; func cw_priv_rrm_neighs_list_length @ 0x005be120 size=0x54
  5be120:	94850002 	lhu	a1,2(a0)
  5be124:	10a00011 	beqz	a1,0x5be16c
  5be128:	24020004 	li	v0,4
  5be12c:	8c840004 	lw	a0,4(a0)
  5be130:	1080000e 	beqz	a0,0x5be16c
  5be134:	00001021 	move	v0,zero
  5be138:	00001821 	move	v1,zero
  5be13c:	24020004 	li	v0,4
  5be140:	0816f858 	j	0x5be160
  5be144:	24060003 	li	a2,3
  5be148:	24630001 	addiu	v1,v1,1
  5be14c:	2484000c 	addiu	a0,a0,12
  5be150:	70e63802 	mul	a3,a3,a2
  5be154:	24e70008 	addiu	a3,a3,8
  5be158:	00471021 	addu	v0,v0,a3
  5be15c:	3042ffff 	andi	v0,v0,0xffff
  5be160:	0065382a 	slt	a3,v1,a1
  5be164:	54e0fff8 	bnezl	a3,0x5be148
  5be168:	90870007 	lbu	a3,7(a0)
  5be16c:	03e00008 	jr	ra
  5be170:	00000000 	nop
