; func _uac_wserv_rd_bind_status_cmp @ 0x005d5d54 size=0x60
  5d5d54:	27bdffd8 	addiu	sp,sp,-40
  5d5d58:	24020001 	li	v0,1
  5d5d5c:	afb20020 	sw	s2,32(sp)
  5d5d60:	00809021 	move	s2,a0
  5d5d64:	afb1001c 	sw	s1,28(sp)
  5d5d68:	00c02021 	move	a0,a2
  5d5d6c:	afbf0024 	sw	ra,36(sp)
  5d5d70:	00a08821 	move	s1,a1
  5d5d74:	10c00009 	beqz	a2,0x5d5d9c
  5d5d78:	afb00018 	sw	s0,24(sp)
  5d5d7c:	0c101db4 	jal	0x4076d0
  5d5d80:	00000000 	nop
  5d5d84:	02202021 	move	a0,s1
  5d5d88:	02402821 	move	a1,s2
  5d5d8c:	0c17ce7d 	jal	0x5f39f4
  5d5d90:	00408021 	move	s0,v0
  5d5d94:	02021026 	xor	v0,s0,v0
  5d5d98:	0002102b 	sltu	v0,zero,v0
  5d5d9c:	8fbf0024 	lw	ra,36(sp)
  5d5da0:	8fb20020 	lw	s2,32(sp)
  5d5da4:	8fb1001c 	lw	s1,28(sp)
  5d5da8:	8fb00018 	lw	s0,24(sp)
  5d5dac:	03e00008 	jr	ra
  5d5db0:	27bd0028 	addiu	sp,sp,40
