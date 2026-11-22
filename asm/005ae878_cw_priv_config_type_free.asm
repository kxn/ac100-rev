; func cw_priv_config_type_free @ 0x005ae878 size=0x3c
  5ae878:	27bdffe0 	addiu	sp,sp,-32
  5ae87c:	afb00018 	sw	s0,24(sp)
  5ae880:	00808021 	move	s0,a0
  5ae884:	afbf001c 	sw	ra,28(sp)
  5ae888:	8c840010 	lw	a0,16(a0)
  5ae88c:	10800005 	beqz	a0,0x5ae8a4
  5ae890:	8fbf001c 	lw	ra,28(sp)
  5ae894:	0c101f7c 	jal	0x407df0
  5ae898:	00000000 	nop
  5ae89c:	ae000010 	sw	zero,16(s0)
  5ae8a0:	8fbf001c 	lw	ra,28(sp)
  5ae8a4:	00001021 	move	v0,zero
  5ae8a8:	8fb00018 	lw	s0,24(sp)
  5ae8ac:	03e00008 	jr	ra
  5ae8b0:	27bd0020 	addiu	sp,sp,32
