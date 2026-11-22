; func _uac_rdmngr_bw_mode_cmp @ 0x006241cc size=0x4c
  6241cc:	27bdffe0 	addiu	sp,sp,-32
  6241d0:	24020001 	li	v0,1
  6241d4:	afb00018 	sw	s0,24(sp)
  6241d8:	00808021 	move	s0,a0
  6241dc:	afbf001c 	sw	ra,28(sp)
  6241e0:	12000009 	beqz	s0,0x624208
  6241e4:	00a02021 	move	a0,a1
  6241e8:	10a00008 	beqz	a1,0x62420c
  6241ec:	8fbf001c 	lw	ra,28(sp)
  6241f0:	0c101db4 	jal	0x4076d0
  6241f4:	00000000 	nop
  6241f8:	9203000a 	lbu	v1,10(s0)
  6241fc:	304200ff 	andi	v0,v0,0xff
  624200:	00621826 	xor	v1,v1,v0
  624204:	0003102b 	sltu	v0,zero,v1
  624208:	8fbf001c 	lw	ra,28(sp)
  62420c:	8fb00018 	lw	s0,24(sp)
  624210:	03e00008 	jr	ra
  624214:	27bd0020 	addiu	sp,sp,32
