; func _a2x @ 0x00435b40 size=0x58
  435b40:	28820047 	slti	v0,a0,71
  435b44:	10400007 	beqz	v0,0x435b64
  435b48:	2483ff9f 	addiu	v1,a0,-97
  435b4c:	28820041 	slti	v0,a0,65
  435b50:	5440000b 	bnezl	v0,0x435b80
  435b54:	2484ffd0 	addiu	a0,a0,-48
  435b58:	2484ffc9 	addiu	a0,a0,-55
  435b5c:	03e00008 	jr	ra
  435b60:	308200ff 	andi	v0,a0,0xff
  435b64:	24020005 	li	v0,5
  435b68:	0043102b 	sltu	v0,v0,v1
  435b6c:	1040fffb 	beqz	v0,0x435b5c
  435b70:	2484ffa9 	addiu	a0,a0,-87
  435b74:	00001021 	move	v0,zero
  435b78:	03e00008 	jr	ra
  435b7c:	00000000 	nop
  435b80:	24020009 	li	v0,9
  435b84:	0044102b 	sltu	v0,v0,a0
  435b88:	1040fff4 	beqz	v0,0x435b5c
  435b8c:	00000000 	nop
  435b90:	03e00008 	jr	ra
  435b94:	00001021 	move	v0,zero
