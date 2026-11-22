; func cw_priv_igmp_query_config_free @ 0x005b2080 size=0x3c
  5b2080:	27bdffe0 	addiu	sp,sp,-32
  5b2084:	afb00018 	sw	s0,24(sp)
  5b2088:	00808021 	move	s0,a0
  5b208c:	afbf001c 	sw	ra,28(sp)
  5b2090:	8c840010 	lw	a0,16(a0)
  5b2094:	10800005 	beqz	a0,0x5b20ac
  5b2098:	8fbf001c 	lw	ra,28(sp)
  5b209c:	0c101f7c 	jal	0x407df0
  5b20a0:	00000000 	nop
  5b20a4:	ae000010 	sw	zero,16(s0)
  5b20a8:	8fbf001c 	lw	ra,28(sp)
  5b20ac:	00001021 	move	v0,zero
  5b20b0:	8fb00018 	lw	s0,24(sp)
  5b20b4:	03e00008 	jr	ra
  5b20b8:	27bd0020 	addiu	sp,sp,32
