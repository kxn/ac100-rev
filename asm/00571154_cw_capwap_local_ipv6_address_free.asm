; func cw_capwap_local_ipv6_address_free @ 0x00571154 size=0x3c
  571154:	27bdffe0 	addiu	sp,sp,-32
  571158:	afb00018 	sw	s0,24(sp)
  57115c:	00808021 	move	s0,a0
  571160:	afbf001c 	sw	ra,28(sp)
  571164:	8c840010 	lw	a0,16(a0)
  571168:	10800005 	beqz	a0,0x571180
  57116c:	8fbf001c 	lw	ra,28(sp)
  571170:	0c101f7c 	jal	0x407df0
  571174:	00000000 	nop
  571178:	ae000010 	sw	zero,16(s0)
  57117c:	8fbf001c 	lw	ra,28(sp)
  571180:	00001021 	move	v0,zero
  571184:	8fb00018 	lw	s0,24(sp)
  571188:	03e00008 	jr	ra
  57118c:	27bd0020 	addiu	sp,sp,32
