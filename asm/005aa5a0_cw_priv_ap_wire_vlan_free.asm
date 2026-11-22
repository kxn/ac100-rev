; func cw_priv_ap_wire_vlan_free @ 0x005aa5a0 size=0x3c
  5aa5a0:	27bdffe0 	addiu	sp,sp,-32
  5aa5a4:	afb00018 	sw	s0,24(sp)
  5aa5a8:	00808021 	move	s0,a0
  5aa5ac:	afbf001c 	sw	ra,28(sp)
  5aa5b0:	8c840010 	lw	a0,16(a0)
  5aa5b4:	10800005 	beqz	a0,0x5aa5cc
  5aa5b8:	8fbf001c 	lw	ra,28(sp)
  5aa5bc:	0c101f7c 	jal	0x407df0
  5aa5c0:	00000000 	nop
  5aa5c4:	ae000010 	sw	zero,16(s0)
  5aa5c8:	8fbf001c 	lw	ra,28(sp)
  5aa5cc:	00001021 	move	v0,zero
  5aa5d0:	8fb00018 	lw	s0,24(sp)
  5aa5d4:	03e00008 	jr	ra
  5aa5d8:	27bd0020 	addiu	sp,sp,32
