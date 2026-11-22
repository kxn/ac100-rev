; func _opensocket @ 0x004b5b68 size=0x34
  4b5b68:	27bdffe0 	addiu	sp,sp,-32
  4b5b6c:	afbf001c 	sw	ra,28(sp)
  4b5b70:	afb00018 	sw	s0,24(sp)
  4b5b74:	00808021 	move	s0,a0
  4b5b78:	8cc50004 	lw	a1,4(a2)
  4b5b7c:	8cc40000 	lw	a0,0(a2)
  4b5b80:	0c101e18 	jal	0x407860
  4b5b84:	8cc60008 	lw	a2,8(a2)
  4b5b88:	8fbf001c 	lw	ra,28(sp)
  4b5b8c:	ae020000 	sw	v0,0(s0)
  4b5b90:	8fb00018 	lw	s0,24(sp)
  4b5b94:	03e00008 	jr	ra
  4b5b98:	27bd0020 	addiu	sp,sp,32
