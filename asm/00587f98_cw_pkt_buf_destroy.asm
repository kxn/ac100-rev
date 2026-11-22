; func cw_pkt_buf_destroy @ 0x00587f98 size=0x4c
  587f98:	27bdffe0 	addiu	sp,sp,-32
  587f9c:	afb00018 	sw	s0,24(sp)
  587fa0:	00808021 	move	s0,a0
  587fa4:	1080000b 	beqz	a0,0x587fd4
  587fa8:	afbf001c 	sw	ra,28(sp)
  587fac:	8c840000 	lw	a0,0(a0)
  587fb0:	50800004 	beqzl	a0,0x587fc4
  587fb4:	02002021 	move	a0,s0
  587fb8:	0c101f7c 	jal	0x407df0
  587fbc:	00000000 	nop
  587fc0:	02002021 	move	a0,s0
  587fc4:	8fbf001c 	lw	ra,28(sp)
  587fc8:	8fb00018 	lw	s0,24(sp)
  587fcc:	08101f7c 	j	0x407df0
  587fd0:	27bd0020 	addiu	sp,sp,32
  587fd4:	8fbf001c 	lw	ra,28(sp)
  587fd8:	8fb00018 	lw	s0,24(sp)
  587fdc:	03e00008 	jr	ra
  587fe0:	27bd0020 	addiu	sp,sp,32
