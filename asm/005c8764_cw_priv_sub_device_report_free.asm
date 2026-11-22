; func cw_priv_sub_device_report_free @ 0x005c8764 size=0x48
  5c8764:	27bdffe0 	addiu	sp,sp,-32
  5c8768:	afbf001c 	sw	ra,28(sp)
  5c876c:	afb00018 	sw	s0,24(sp)
  5c8770:	8c900010 	lw	s0,16(a0)
  5c8774:	12000009 	beqz	s0,0x5c879c
  5c8778:	8fbf001c 	lw	ra,28(sp)
  5c877c:	8e040008 	lw	a0,8(s0)
  5c8780:	10800003 	beqz	a0,0x5c8790
  5c8784:	00000000 	nop
  5c8788:	0c101f7c 	jal	0x407df0
  5c878c:	00000000 	nop
  5c8790:	0c101f7c 	jal	0x407df0
  5c8794:	02002021 	move	a0,s0
  5c8798:	8fbf001c 	lw	ra,28(sp)
  5c879c:	00001021 	move	v0,zero
  5c87a0:	8fb00018 	lw	s0,24(sp)
  5c87a4:	03e00008 	jr	ra
  5c87a8:	27bd0020 	addiu	sp,sp,32
