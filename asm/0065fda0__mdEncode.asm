; func _mdEncode @ 0x0065fda0 size=0x48
  65fda0:	08197f75 	j	0x65fdd4
  65fda4:	00001021 	move	v0,zero
  65fda8:	24420004 	addiu	v0,v0,4
  65fdac:	a0830000 	sb	v1,0(a0)
  65fdb0:	8ca30000 	lw	v1,0(a1)
  65fdb4:	00031a02 	srl	v1,v1,0x8
  65fdb8:	a0830001 	sb	v1,1(a0)
  65fdbc:	94a30000 	lhu	v1,0(a1)
  65fdc0:	a0830002 	sb	v1,2(a0)
  65fdc4:	90a30000 	lbu	v1,0(a1)
  65fdc8:	24a50004 	addiu	a1,a1,4
  65fdcc:	a0830003 	sb	v1,3(a0)
  65fdd0:	24840004 	addiu	a0,a0,4
  65fdd4:	0046182b 	sltu	v1,v0,a2
  65fdd8:	5460fff3 	bnezl	v1,0x65fda8
  65fddc:	8ca30000 	lw	v1,0(a1)
  65fde0:	03e00008 	jr	ra
  65fde4:	00000000 	nop
  65fde8:	00001021 	move	v0,zero
  65fdec:	24030040 	li	v1,64
  65fdf0:	90a80001 	lbu	t0,1(a1)
  65fdf4:	00823021 	addu	a2,a0,v0
  65fdf8:	90a70002 	lbu	a3,2(a1)
  65fdfc:	24420004 	addiu	v0,v0,4
  65fe00:	00084200 	sll	t0,t0,0x8
  65fe04:	00073c00 	sll	a3,a3,0x10
  65fe08:	01073825 	or	a3,t0,a3
  65fe0c:	90a80000 	lbu	t0,0(a1)
  65fe10:	00e83825 	or	a3,a3,t0
  65fe14:	90a80003 	lbu	t0,3(a1)
  65fe18:	24a50004 	addiu	a1,a1,4
  65fe1c:	00084600 	sll	t0,t0,0x18
  65fe20:	00e83825 	or	a3,a3,t0
  65fe24:	1443fff2 	bne	v0,v1,0x65fdf0
  65fe28:	acc70000 	sw	a3,0(a2)
  65fe2c:	03e00008 	jr	ra
  65fe30:	00000000 	nop
