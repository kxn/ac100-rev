; func cw_priv_capwap_retrans_para_free @ 0x005ace60 size=0x3c
  5ace60:	27bdffe0 	addiu	sp,sp,-32
  5ace64:	afb00018 	sw	s0,24(sp)
  5ace68:	00808021 	move	s0,a0
  5ace6c:	afbf001c 	sw	ra,28(sp)
  5ace70:	8c840010 	lw	a0,16(a0)
  5ace74:	10800005 	beqz	a0,0x5ace8c
  5ace78:	8fbf001c 	lw	ra,28(sp)
  5ace7c:	0c101f7c 	jal	0x407df0
  5ace80:	00000000 	nop
  5ace84:	ae000010 	sw	zero,16(s0)
  5ace88:	8fbf001c 	lw	ra,28(sp)
  5ace8c:	00001021 	move	v0,zero
  5ace90:	8fb00018 	lw	s0,24(sp)
  5ace94:	03e00008 	jr	ra
  5ace98:	27bd0020 	addiu	sp,sp,32
