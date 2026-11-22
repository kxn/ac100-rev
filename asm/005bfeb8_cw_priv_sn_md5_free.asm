; func cw_priv_sn_md5_free @ 0x005bfeb8 size=0x3c
  5bfeb8:	27bdffe0 	addiu	sp,sp,-32
  5bfebc:	afb00018 	sw	s0,24(sp)
  5bfec0:	00808021 	move	s0,a0
  5bfec4:	afbf001c 	sw	ra,28(sp)
  5bfec8:	8c840010 	lw	a0,16(a0)
  5bfecc:	10800005 	beqz	a0,0x5bfee4
  5bfed0:	8fbf001c 	lw	ra,28(sp)
  5bfed4:	0c101f7c 	jal	0x407df0
  5bfed8:	00000000 	nop
  5bfedc:	ae000010 	sw	zero,16(s0)
  5bfee0:	8fbf001c 	lw	ra,28(sp)
  5bfee4:	00001021 	move	v0,zero
  5bfee8:	8fb00018 	lw	s0,24(sp)
  5bfeec:	03e00008 	jr	ra
  5bfef0:	27bd0020 	addiu	sp,sp,32
