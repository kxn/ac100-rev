; func cw_priv_ap_wire_vlan_2_free @ 0x005aa8a0 size=0x3c
  5aa8a0:	27bdffe0 	addiu	sp,sp,-32
  5aa8a4:	afb00018 	sw	s0,24(sp)
  5aa8a8:	00808021 	move	s0,a0
  5aa8ac:	afbf001c 	sw	ra,28(sp)
  5aa8b0:	8c840010 	lw	a0,16(a0)
  5aa8b4:	10800005 	beqz	a0,0x5aa8cc
  5aa8b8:	8fbf001c 	lw	ra,28(sp)
  5aa8bc:	0c101f7c 	jal	0x407df0
  5aa8c0:	00000000 	nop
  5aa8c4:	ae000010 	sw	zero,16(s0)
  5aa8c8:	8fbf001c 	lw	ra,28(sp)
  5aa8cc:	00001021 	move	v0,zero
  5aa8d0:	8fb00018 	lw	s0,24(sp)
  5aa8d4:	03e00008 	jr	ra
  5aa8d8:	27bd0020 	addiu	sp,sp,32
