; func isAddrExcecuted @ 0x005d2c10 size=0x58
  5d2c10:	3c02007c 	lui	v0,0x7c
  5d2c14:	24426a54 	addiu	v0,v0,27220
  5d2c18:	08174b0a 	j	0x5d2c28
  5d2c1c:	24435208 	addiu	v1,v0,21000
  5d2c20:	1043000f 	beq	v0,v1,0x5d2c60
  5d2c24:	00000000 	nop
  5d2c28:	8c450000 	lw	a1,0(v0)
  5d2c2c:	0085282b 	sltu	a1,a0,a1
  5d2c30:	14a00005 	bnez	a1,0x5d2c48
  5d2c34:	8c450004 	lw	a1,4(v0)
  5d2c38:	00a4282b 	sltu	a1,a1,a0
  5d2c3c:	10a00006 	beqz	a1,0x5d2c58
  5d2c40:	00000000 	nop
  5d2c44:	8c450004 	lw	a1,4(v0)
  5d2c48:	54a0fff5 	bnezl	a1,0x5d2c20
  5d2c4c:	2442008c 	addiu	v0,v0,140
  5d2c50:	03e00008 	jr	ra
  5d2c54:	00001021 	move	v0,zero
  5d2c58:	03e00008 	jr	ra
  5d2c5c:	24020001 	li	v0,1
  5d2c60:	03e00008 	jr	ra
  5d2c64:	00001021 	move	v0,zero
