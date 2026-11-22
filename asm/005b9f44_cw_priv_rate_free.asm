; func cw_priv_rate_free @ 0x005b9f44 size=0x3c
  5b9f44:	27bdffe0 	addiu	sp,sp,-32
  5b9f48:	afb00018 	sw	s0,24(sp)
  5b9f4c:	00808021 	move	s0,a0
  5b9f50:	afbf001c 	sw	ra,28(sp)
  5b9f54:	8c840010 	lw	a0,16(a0)
  5b9f58:	10800005 	beqz	a0,0x5b9f70
  5b9f5c:	8fbf001c 	lw	ra,28(sp)
  5b9f60:	0c101f7c 	jal	0x407df0
  5b9f64:	00000000 	nop
  5b9f68:	ae000010 	sw	zero,16(s0)
  5b9f6c:	8fbf001c 	lw	ra,28(sp)
  5b9f70:	00001021 	move	v0,zero
  5b9f74:	8fb00018 	lw	s0,24(sp)
  5b9f78:	03e00008 	jr	ra
  5b9f7c:	27bd0020 	addiu	sp,sp,32
