; func cw_priv_sta_list_free @ 0x005c686c size=0x4c
  5c686c:	27bdffe0 	addiu	sp,sp,-32
  5c6870:	afb00018 	sw	s0,24(sp)
  5c6874:	afbf001c 	sw	ra,28(sp)
  5c6878:	8c820010 	lw	v0,16(a0)
  5c687c:	10400009 	beqz	v0,0x5c68a4
  5c6880:	00808021 	move	s0,a0
  5c6884:	8c440008 	lw	a0,8(v0)
  5c6888:	10800003 	beqz	a0,0x5c6898
  5c688c:	00000000 	nop
  5c6890:	0c101f7c 	jal	0x407df0
  5c6894:	00000000 	nop
  5c6898:	0c101f7c 	jal	0x407df0
  5c689c:	8e040010 	lw	a0,16(s0)
  5c68a0:	ae000010 	sw	zero,16(s0)
  5c68a4:	8fbf001c 	lw	ra,28(sp)
  5c68a8:	00001021 	move	v0,zero
  5c68ac:	8fb00018 	lw	s0,24(sp)
  5c68b0:	03e00008 	jr	ra
  5c68b4:	27bd0020 	addiu	sp,sp,32
