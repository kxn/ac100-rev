; func cw_priv_cwver_free @ 0x005aeb68 size=0x3c
  5aeb68:	27bdffe0 	addiu	sp,sp,-32
  5aeb6c:	afb00018 	sw	s0,24(sp)
  5aeb70:	00808021 	move	s0,a0
  5aeb74:	afbf001c 	sw	ra,28(sp)
  5aeb78:	8c840010 	lw	a0,16(a0)
  5aeb7c:	10800005 	beqz	a0,0x5aeb94
  5aeb80:	8fbf001c 	lw	ra,28(sp)
  5aeb84:	0c101f7c 	jal	0x407df0
  5aeb88:	00000000 	nop
  5aeb8c:	ae000010 	sw	zero,16(s0)
  5aeb90:	8fbf001c 	lw	ra,28(sp)
  5aeb94:	00001021 	move	v0,zero
  5aeb98:	8fb00018 	lw	s0,24(sp)
  5aeb9c:	03e00008 	jr	ra
  5aeba0:	27bd0020 	addiu	sp,sp,32
