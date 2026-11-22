; func cw_priv_ndp_para_free @ 0x005b7a70 size=0x3c
  5b7a70:	27bdffe0 	addiu	sp,sp,-32
  5b7a74:	afb00018 	sw	s0,24(sp)
  5b7a78:	00808021 	move	s0,a0
  5b7a7c:	afbf001c 	sw	ra,28(sp)
  5b7a80:	8c840010 	lw	a0,16(a0)
  5b7a84:	10800005 	beqz	a0,0x5b7a9c
  5b7a88:	8fbf001c 	lw	ra,28(sp)
  5b7a8c:	0c101f7c 	jal	0x407df0
  5b7a90:	00000000 	nop
  5b7a94:	ae000010 	sw	zero,16(s0)
  5b7a98:	8fbf001c 	lw	ra,28(sp)
  5b7a9c:	00001021 	move	v0,zero
  5b7aa0:	8fb00018 	lw	s0,24(sp)
  5b7aa4:	03e00008 	jr	ra
  5b7aa8:	27bd0020 	addiu	sp,sp,32
