; func cw_priv_ap_user_free @ 0x005a9a94 size=0x3c
  5a9a94:	27bdffe0 	addiu	sp,sp,-32
  5a9a98:	afb00018 	sw	s0,24(sp)
  5a9a9c:	00808021 	move	s0,a0
  5a9aa0:	afbf001c 	sw	ra,28(sp)
  5a9aa4:	8c840010 	lw	a0,16(a0)
  5a9aa8:	10800005 	beqz	a0,0x5a9ac0
  5a9aac:	8fbf001c 	lw	ra,28(sp)
  5a9ab0:	0c101f7c 	jal	0x407df0
  5a9ab4:	00000000 	nop
  5a9ab8:	ae000010 	sw	zero,16(s0)
  5a9abc:	8fbf001c 	lw	ra,28(sp)
  5a9ac0:	00001021 	move	v0,zero
  5a9ac4:	8fb00018 	lw	s0,24(sp)
  5a9ac8:	03e00008 	jr	ra
  5a9acc:	27bd0020 	addiu	sp,sp,32
