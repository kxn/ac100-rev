; func cw_decryption_error_report_period_free @ 0x00573c40 size=0x3c
  573c40:	27bdffe0 	addiu	sp,sp,-32
  573c44:	afb00018 	sw	s0,24(sp)
  573c48:	00808021 	move	s0,a0
  573c4c:	afbf001c 	sw	ra,28(sp)
  573c50:	8c840010 	lw	a0,16(a0)
  573c54:	10800005 	beqz	a0,0x573c6c
  573c58:	8fbf001c 	lw	ra,28(sp)
  573c5c:	0c101f7c 	jal	0x407df0
  573c60:	00000000 	nop
  573c64:	ae000010 	sw	zero,16(s0)
  573c68:	8fbf001c 	lw	ra,28(sp)
  573c6c:	00001021 	move	v0,zero
  573c70:	8fb00018 	lw	s0,24(sp)
  573c74:	03e00008 	jr	ra
  573c78:	27bd0020 	addiu	sp,sp,32
