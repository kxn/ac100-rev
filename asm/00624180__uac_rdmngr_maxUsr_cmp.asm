; func _uac_rdmngr_maxUsr_cmp @ 0x00624180 size=0x4c
  624180:	27bdffe0 	addiu	sp,sp,-32
  624184:	24020001 	li	v0,1
  624188:	afb00018 	sw	s0,24(sp)
  62418c:	00808021 	move	s0,a0
  624190:	afbf001c 	sw	ra,28(sp)
  624194:	12000009 	beqz	s0,0x6241bc
  624198:	00a02021 	move	a0,a1
  62419c:	10a00008 	beqz	a1,0x6241c0
  6241a0:	8fbf001c 	lw	ra,28(sp)
  6241a4:	0c101db4 	jal	0x4076d0
  6241a8:	00000000 	nop
  6241ac:	9603001a 	lhu	v1,26(s0)
  6241b0:	3042ffff 	andi	v0,v0,0xffff
  6241b4:	00621826 	xor	v1,v1,v0
  6241b8:	0003102b 	sltu	v0,zero,v1
  6241bc:	8fbf001c 	lw	ra,28(sp)
  6241c0:	8fb00018 	lw	s0,24(sp)
  6241c4:	03e00008 	jr	ra
  6241c8:	27bd0020 	addiu	sp,sp,32
