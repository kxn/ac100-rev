; func dhcpdef_str2upper @ 0x00466dbc size=0x48
  466dbc:	00801021 	move	v0,a0
  466dc0:	00852821 	addu	a1,a0,a1
  466dc4:	2404ffdf 	li	a0,-33
  466dc8:	24a5ffff 	addiu	a1,a1,-1
  466dcc:	00a2182b 	sltu	v1,a1,v0
  466dd0:	1460000a 	bnez	v1,0x466dfc
  466dd4:	00000000 	nop
  466dd8:	80a30000 	lb	v1,0(a1)
  466ddc:	2466ff9f 	addiu	a2,v1,-97
  466de0:	30c600ff 	andi	a2,a2,0xff
  466de4:	2cc6001a 	sltiu	a2,a2,26
  466de8:	50c0fff8 	beqzl	a2,0x466dcc
  466dec:	24a5ffff 	addiu	a1,a1,-1
  466df0:	00641824 	and	v1,v1,a0
  466df4:	08119b72 	j	0x466dc8
  466df8:	a0a30000 	sb	v1,0(a1)
  466dfc:	03e00008 	jr	ra
  466e00:	00000000 	nop
