; func cw_priv_ap_res_info_free @ 0x005a6e50 size=0x3c
  5a6e50:	27bdffe0 	addiu	sp,sp,-32
  5a6e54:	afb00018 	sw	s0,24(sp)
  5a6e58:	00808021 	move	s0,a0
  5a6e5c:	afbf001c 	sw	ra,28(sp)
  5a6e60:	8c840010 	lw	a0,16(a0)
  5a6e64:	10800005 	beqz	a0,0x5a6e7c
  5a6e68:	8fbf001c 	lw	ra,28(sp)
  5a6e6c:	0c101f7c 	jal	0x407df0
  5a6e70:	00000000 	nop
  5a6e74:	ae000010 	sw	zero,16(s0)
  5a6e78:	8fbf001c 	lw	ra,28(sp)
  5a6e7c:	00001021 	move	v0,zero
  5a6e80:	8fb00018 	lw	s0,24(sp)
  5a6e84:	03e00008 	jr	ra
  5a6e88:	27bd0020 	addiu	sp,sp,32
