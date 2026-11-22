; func radius_pair_get @ 0x00449b94 size=0x40
  449b94:	00801021 	move	v0,a0
  449b98:	1040000c 	beqz	v0,0x449bcc
  449b9c:	00000000 	nop
  449ba0:	8c430044 	lw	v1,68(v0)
  449ba4:	00a32026 	xor	a0,a1,v1
  449ba8:	3084ffff 	andi	a0,a0,0xffff
  449bac:	54800005 	bnezl	a0,0x449bc4
  449bb0:	8c420150 	lw	v0,336(v0)
  449bb4:	00031c02 	srl	v1,v1,0x10
  449bb8:	10660004 	beq	v1,a2,0x449bcc
  449bbc:	00000000 	nop
  449bc0:	8c420150 	lw	v0,336(v0)
  449bc4:	5440fff7 	bnezl	v0,0x449ba4
  449bc8:	8c430044 	lw	v1,68(v0)
  449bcc:	03e00008 	jr	ra
  449bd0:	00000000 	nop
	...
