; func cw_priv_rpt_para_free @ 0x005bde64 size=0x3c
  5bde64:	27bdffe0 	addiu	sp,sp,-32
  5bde68:	afb00018 	sw	s0,24(sp)
  5bde6c:	00808021 	move	s0,a0
  5bde70:	afbf001c 	sw	ra,28(sp)
  5bde74:	8c840010 	lw	a0,16(a0)
  5bde78:	10800005 	beqz	a0,0x5bde90
  5bde7c:	8fbf001c 	lw	ra,28(sp)
  5bde80:	0c101f7c 	jal	0x407df0
  5bde84:	00000000 	nop
  5bde88:	ae000010 	sw	zero,16(s0)
  5bde8c:	8fbf001c 	lw	ra,28(sp)
  5bde90:	00001021 	move	v0,zero
  5bde94:	8fb00018 	lw	s0,24(sp)
  5bde98:	03e00008 	jr	ra
  5bde9c:	27bd0020 	addiu	sp,sp,32
