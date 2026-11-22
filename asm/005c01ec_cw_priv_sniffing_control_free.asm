; func cw_priv_sniffing_control_free @ 0x005c01ec size=0x3c
  5c01ec:	27bdffe0 	addiu	sp,sp,-32
  5c01f0:	afb00018 	sw	s0,24(sp)
  5c01f4:	00808021 	move	s0,a0
  5c01f8:	afbf001c 	sw	ra,28(sp)
  5c01fc:	8c840010 	lw	a0,16(a0)
  5c0200:	10800005 	beqz	a0,0x5c0218
  5c0204:	8fbf001c 	lw	ra,28(sp)
  5c0208:	0c101f7c 	jal	0x407df0
  5c020c:	00000000 	nop
  5c0210:	ae000010 	sw	zero,16(s0)
  5c0214:	8fbf001c 	lw	ra,28(sp)
  5c0218:	00001021 	move	v0,zero
  5c021c:	8fb00018 	lw	s0,24(sp)
  5c0220:	03e00008 	jr	ra
  5c0224:	27bd0020 	addiu	sp,sp,32
