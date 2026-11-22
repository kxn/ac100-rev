; func cw_priv_large_fireware_info_free @ 0x005b4a04 size=0x3c
  5b4a04:	27bdffe0 	addiu	sp,sp,-32
  5b4a08:	afb00018 	sw	s0,24(sp)
  5b4a0c:	00808021 	move	s0,a0
  5b4a10:	afbf001c 	sw	ra,28(sp)
  5b4a14:	8c840010 	lw	a0,16(a0)
  5b4a18:	10800005 	beqz	a0,0x5b4a30
  5b4a1c:	8fbf001c 	lw	ra,28(sp)
  5b4a20:	0c101f7c 	jal	0x407df0
  5b4a24:	00000000 	nop
  5b4a28:	ae000010 	sw	zero,16(s0)
  5b4a2c:	8fbf001c 	lw	ra,28(sp)
  5b4a30:	00001021 	move	v0,zero
  5b4a34:	8fb00018 	lw	s0,24(sp)
  5b4a38:	03e00008 	jr	ra
  5b4a3c:	27bd0020 	addiu	sp,sp,32
