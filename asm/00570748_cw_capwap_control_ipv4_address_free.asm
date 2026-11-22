; func cw_capwap_control_ipv4_address_free @ 0x00570748 size=0x3c
  570748:	27bdffe0 	addiu	sp,sp,-32
  57074c:	afb00018 	sw	s0,24(sp)
  570750:	00808021 	move	s0,a0
  570754:	afbf001c 	sw	ra,28(sp)
  570758:	8c840010 	lw	a0,16(a0)
  57075c:	10800005 	beqz	a0,0x570774
  570760:	8fbf001c 	lw	ra,28(sp)
  570764:	0c101f7c 	jal	0x407df0
  570768:	00000000 	nop
  57076c:	ae000010 	sw	zero,16(s0)
  570770:	8fbf001c 	lw	ra,28(sp)
  570774:	00001021 	move	v0,zero
  570778:	8fb00018 	lw	s0,24(sp)
  57077c:	03e00008 	jr	ra
  570780:	27bd0020 	addiu	sp,sp,32
