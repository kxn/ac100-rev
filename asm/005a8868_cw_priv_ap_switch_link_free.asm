; func cw_priv_ap_switch_link_free @ 0x005a8868 size=0x3c
  5a8868:	27bdffe0 	addiu	sp,sp,-32
  5a886c:	afb00018 	sw	s0,24(sp)
  5a8870:	00808021 	move	s0,a0
  5a8874:	afbf001c 	sw	ra,28(sp)
  5a8878:	8c840010 	lw	a0,16(a0)
  5a887c:	10800005 	beqz	a0,0x5a8894
  5a8880:	8fbf001c 	lw	ra,28(sp)
  5a8884:	0c101f7c 	jal	0x407df0
  5a8888:	00000000 	nop
  5a888c:	ae000010 	sw	zero,16(s0)
  5a8890:	8fbf001c 	lw	ra,28(sp)
  5a8894:	00001021 	move	v0,zero
  5a8898:	8fb00018 	lw	s0,24(sp)
  5a889c:	03e00008 	jr	ra
  5a88a0:	27bd0020 	addiu	sp,sp,32
