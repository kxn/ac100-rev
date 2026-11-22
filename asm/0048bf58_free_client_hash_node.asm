; func free_client_hash_node @ 0x0048bf58 size=0x4c
  48bf58:	27bdffe0 	addiu	sp,sp,-32
  48bf5c:	afb00018 	sw	s0,24(sp)
  48bf60:	00808021 	move	s0,a0
  48bf64:	1080000b 	beqz	a0,0x48bf94
  48bf68:	afbf001c 	sw	ra,28(sp)
  48bf6c:	8c840008 	lw	a0,8(a0)
  48bf70:	50800004 	beqzl	a0,0x48bf84
  48bf74:	02002021 	move	a0,s0
  48bf78:	0c101f30 	jal	0x407cc0
  48bf7c:	00000000 	nop
  48bf80:	02002021 	move	a0,s0
  48bf84:	8fbf001c 	lw	ra,28(sp)
  48bf88:	8fb00018 	lw	s0,24(sp)
  48bf8c:	08101f7c 	j	0x407df0
  48bf90:	27bd0020 	addiu	sp,sp,32
  48bf94:	8fbf001c 	lw	ra,28(sp)
  48bf98:	8fb00018 	lw	s0,24(sp)
  48bf9c:	03e00008 	jr	ra
  48bfa0:	27bd0020 	addiu	sp,sp,32
