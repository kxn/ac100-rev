; func add_client_hash_node @ 0x00491cc4 size=0x30
  491cc4:	00801021 	move	v0,a0
  491cc8:	10400008 	beqz	v0,0x491cec
  491ccc:	00a02021 	move	a0,a1
  491cd0:	10a00006 	beqz	a1,0x491cec
  491cd4:	00000000 	nop
  491cd8:	8c420008 	lw	v0,8(v0)
  491cdc:	10400003 	beqz	v0,0x491cec
  491ce0:	00000000 	nop
  491ce4:	08101c74 	j	0x4071d0
  491ce8:	00402821 	move	a1,v0
  491cec:	03e00008 	jr	ra
  491cf0:	00000000 	nop
