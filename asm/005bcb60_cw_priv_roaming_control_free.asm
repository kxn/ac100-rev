; func cw_priv_roaming_control_free @ 0x005bcb60 size=0x3c
  5bcb60:	27bdffe0 	addiu	sp,sp,-32
  5bcb64:	afb00018 	sw	s0,24(sp)
  5bcb68:	00808021 	move	s0,a0
  5bcb6c:	afbf001c 	sw	ra,28(sp)
  5bcb70:	8c840010 	lw	a0,16(a0)
  5bcb74:	10800005 	beqz	a0,0x5bcb8c
  5bcb78:	8fbf001c 	lw	ra,28(sp)
  5bcb7c:	0c101f7c 	jal	0x407df0
  5bcb80:	00000000 	nop
  5bcb84:	ae000010 	sw	zero,16(s0)
  5bcb88:	8fbf001c 	lw	ra,28(sp)
  5bcb8c:	00001021 	move	v0,zero
  5bcb90:	8fb00018 	lw	s0,24(sp)
  5bcb94:	03e00008 	jr	ra
  5bcb98:	27bd0020 	addiu	sp,sp,32
